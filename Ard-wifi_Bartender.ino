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
WEBSERVER: Waiting for connection
LCD: QR Barcode to connect
BUZZER: 
WEIGHT:
ULTRASONIC:
RELAY:
PUMP[]:
FLOW:
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



