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

// 2. COM-07950 Passive Buzzer
int buzzer = 12;

// 3. HX711_Load_Cell
int load_clk = 9;
int load_dat = 8;

// 4. HC_SR04_UltraSonic Sensor
int sonic_trig = 11;
int sonic_echo = 10;

// 5. 16CH Relay (Using I2C relay board)
const int relay_address = 0x20; // Example I2C address for relay board

// 6. yf-s401-flow-sensor
int flow_pin = 13;    // This is the input pin on the Arduino
double flow_rate;     // This is the value we intend to calculate
volatile int flow_count; // This integer needs to be set as volatile to ensure it updates correctly during the interrupt process

void setup() {
  // Start Webserver 

    Serial.begin(9600);      // initialize serial communication
  pinMode(led, OUTPUT);      // set the LED pin mode
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
  // Add code to handle the devices
}

// Interrupt Service Routine for flow sensor
void flowSensorISR() {
  flow_count++;
}



/* 1. Standby
LCD: QR Barcode to connect
WEBSERVER: Waiting for connection
*/

/* 2. User Connected
WEBSERVER: Connect to %USER%
LCD: Show Connection to %USER%
BUZZER: Beep on connect
WEIGHT: check for change from default
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/* 3.Beverave List
WEBSERVER:
LCD:
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/* 3.Pour Beverage
WEBSERVER:
LCD:
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/* 3.Reset
WEBSERVER:
LCD:
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/