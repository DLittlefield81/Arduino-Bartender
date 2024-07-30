#include <Wire.h> // Include Wire library for I2C

// Devices
// 0. Webserver
#include "WiFiS3.h"
#include "arduino_secrets.h" 

char ssid[] = SECRET_SSID;    // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;             // your network key index number (needed only for WEP)
int status = WL_IDLE_STATUS;  // initialize wifi status to idle
WiFiServer server(80);


// 1. EL-SM-008 LCD 
int lcd_sck = 7;
int lcd_sda = 6;

// 2. COM-07950 passive buzzer
int buzzer = 12;

// 3. HX711 load_cell
int load_clk = 9;
int load_dat = 8;

// 4. HC_SR04 ultraSonic sensor
int sonic_trig = 11;
int sonic_echo = 10;

// 5. 16CH Relay (Using I2C relay board)
const int relay_address = 0x20; // Example I2C address for relay board

// 6. YF-S401 flow sensor
int flow_pin = 13;    // This is the input pin on the Arduino
double flow_rate;     // This is the value we intend to calculate
volatile int flow_count; // This integer needs to be set as volatile to ensure it updates correctly during the interrupt process

void setup() {
  // Start Webserver 
    Serial.begin(9600);      // initialize serial communication

// check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();                           // start the web server on port 80
  printWifiStatus();                        // you're connected now, so print out the status


// Setup Devices
  // Initialize I2C for LCD and Relay
  Wire.begin(); // Join I2C bus

  // Initialize the LCD
  pinMode(lcd_sck, OUTPUT);
  pinMode(lcd_sda, OUTPUT);

  // Initialize the buzzer
  pinMode(buzzer, OUTPUT);

  // Initialize the load cell
  pinMode(load_clk, OUTPUT);
  pinMode(load_dat, INPUT);

  // Initialize the ultrasonic sensor
  pinMode(sonic_trig, OUTPUT);
  pinMode(sonic_echo, INPUT);

  // Initialize the relays via I2C
  Wire.beginTransmission(relay_address);
  // Set up the relay board as needed
  Wire.endTransmission();

  // Initialize the flow sensor
  pinMode(flow_pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(flow_pin), flowSensorISR, RISING); // Interrupt on rising edge
  flow_count = 0;

  // Begin Serial Communication for debugging
  Serial.begin(9600); 
}

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
//  TODO:  Refactor code 
  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out to the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn the LED on<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/L\">here</a> turn the LED off<br></p>");
            
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED_BUILTIN, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED_BUILTIN, LOW);                // GET /L turns the LED off
        }
      }
      
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

// Interrupt Service Routine for flow sensor
void flowSensorISR() {
  flow_count++;
}


void flowSensorISR() {
  
}

/*
Notes:
Frontend: React
Backend: Express / SQL
*/





/* TODO: 1. Standby
(LCD.print(QR.IPaddress / hostname))
*/

/* TODO: 2. User Connected
If (user.firstTime) == (Request User.register)
(registeredUser)
(LCD.print("Welcome " + registeredUser.name);)
(buzzer.beep();)
(LCD.print("Please place a cup"))
(cupSize)==(load.value) && (sonic.value)
(LCD.print(Show Cup Icon : Shot || Drink)) 
(buzzer.beep(2);)
(RegisteredUser.web.drinkList[filtered:cupSize].select)
(LCD.print("Pouring " + SelectedDrink.name);)


*/

/* TODO: Database Info
cupDB = index | cupSize: Shot || Drink | loadcell.value | sonic.value
drinDB = index | drinkName | ingredients | steps | flowRate.value | mL
*/
/* TODO: Error Types
Bottle.Empty = Pump[]==HIGH && flow==0
Cup Removed: loadCell==0 && sonic>threshold
No Cup: loadCell==0 && sonic>threshold
Spill Detected: flow>threshold


*/



void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}