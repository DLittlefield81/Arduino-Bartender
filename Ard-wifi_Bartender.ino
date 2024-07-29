//  Libraries 

// Devices
// 0. Webserver
// 1. LCD 
const LCD = pin;
// 2. Buzzer
const passiveBuzzer = 12 ;
// 3. Weight Sensor
const weight_clk = 9;
const weight_dat = 8;
// 4. UltraSonic Sensor
const ultraSonicTrig = 11;
const ultraSonicEcho = 10;
// 5. Relay
const powerRelay = pin;
const pump[] = [];
// 6. Flow rate Sensor
int flowPin = 13;    //This is the input pin on the Arduino
double flowRate;    //This is the value we intend to calculate.
volatile int count; //This integer needs to be set as volatile to ensure it updates correctly during the interrupt process.

void setup() {
/* 
1. Plug-in machine
2. LCD: "Booting" 
3. Weight Sensor: Set Default "EMPTY" value
4. Ultrasonic Sensor: Set Default "EMPTY" value
5. Flow Rate Sensor: Set Default "EMPTY" value
6. Webserver: Load


*/
}


void loop() {
/*
1. Wait for Connection
WEBSERVER:
LCD: QR Barcode to connect
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/*
2.Connection Established
WEBSERVER:
LCD:
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/*
3.User Selects Beverage
WEBSERVER:
LCD:
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/*
3.Create Beverage
WEBSERVER:
LCD:
BUZZER:
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
*/

/*
3.Reset
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



