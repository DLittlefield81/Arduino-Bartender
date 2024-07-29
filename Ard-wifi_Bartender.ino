//  Libraries 

#include <Wire.h> // Include Wire library for I2C

// Devices
// 0. Webserver

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

void setup() {
/* 1. Boot Sequence
LCD / BUZZER: "Checking Devices" *Chime: Post Beep
LCD / BUZZER: "Ensure Dispenser platform is empty" *Chime: Confirmation Beep
LCD / BUZZER: "Calibrating..." *Chime: Post Beep
WEIGHT: Set Default "EMPTY" value
ULTRASONIC: Set Default "EMPTY" value
FLOW: Set Counter to '0'
LCD / BUZZER: "Checking Pumps..." *Chime: Post Beep
RELAY: 
PUMP[]: 
LCD / Buzzer: "Loading Webserver" *Chime: Post Beep
WEBSERVER: LOAD
LCD / BUZZER: "READY" *Chime: Boot Complete - Ready
*/
}


void loop() {
/* 1. Wait for Connection
LCD: QR Barcode to connect
WEBSERVER: Waiting for connection
*/

/* 2.Connection Established
WEBSERVER: Connect to %USER%
LCD: Show Connection to %USER%
BUZZER: Beep on connect
WEIGHT: check for change from default
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/* 3.User Selects Beverage
WEBSERVER:
LCD:
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/* 3.Create Beverage
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




// Wait for user to connect
// user connects to webserver
// Webserver instructs user to select a cup and place under dispenser 
// weight sensor checks: 'cup weight empty'
// ultrasonic sensor checks: 'cup height empty' 
// Webserver displays cup size, then displays the available drink options
// user selects beverage
// pump begins to pump
// flow rate sensor checks amount dispensed
// ultrasonic checks liquid height
// weight sensor stops process if cup is removed


}



