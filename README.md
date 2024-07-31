# Arduino Bartender

Arduino Bartender is an automated bartender project built using Arduino Uno R4 WiFi. It utilizes various sensors and components to dispense drinks based on user selection from a web interface. The project integrates React.js for the frontend, Express.js for the backend, and SQL for database management.

## Table of Contents

- [Project Description](#project-description)
- [Operational Modes](#operational-modes)
- [Components](#components)
- [Wiring Diagrams](#wiring-diagrams)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Project Description

Arduino Bartender is designed to automate the drink dispensing process. Users can interact with the machine via a web interface to select their desired drink. The system uses a load cell to detect that a glass was placed, an ultrasonic sensor to detect the height of the glass, and flow rate sensors to control the amount of liquid dispensed. The project also features an LCD for display and relays to control the pumps.

## Operational Modes
| Imp. [Y/N] | Mode | Role | Description | How to activate |
|-|-|-|-|-|
| N | Cleaning | Admin | System will run cleaning cycle where all pumps flush with cleaning solution | WebApp>AdminMenu |
| N | Create Drink | Admin | Create a custom drink and save to the menu | WebApp>AdminMenu |
| N | Make it a double | User | Double the amount of a alcohol in the selected drink | Long Press on {drink.item} during selection |
| N | Roulette Mode | User | Randomly selects and dispenses a drink from the menu | Party Menu |
| N ||||

## Default Drink list Required Liquids

- Vodka, Gin, Rum, Tequila, Whiskey, Triple sec, Sweet Vermouth, Dry Vermouth, Lime Juice, Simple Syrup.
The default drinks list includes:




## Components

- Arduino Uno R4 WiFi
- LCD Display
- Passive Buzzer
- Load Cell
- Ultrasonic Sensor
- Flow Rate Sensor
- I2C Expansion
- 16ch Relay
- Peristaltic pumps
- Web Server (Node.js with Express.js)
- Frontend (React.js)
- SQL Database

## Wiring Diagrams

Below are the wiring diagrams for the project. Ensure all connections are made correctly to avoid any issues.

![Fritzing Diagram 1](diagrams/diagram1.png)

## Installation

To get started with Arduino Bartender, follow the steps below:

### Arduino Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
2. Connect your Arduino Uno R4 WiFi to your computer.
3. Upload the provided Arduino code to the board.

## Usage

Once everything is set up, open your web browser and navigate to `http://127.0.0.1`, or scan the barcode on the LCD of the device. Follow the on-screen instructions to select your drink. The machine will dispense the drink based on your selection.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.