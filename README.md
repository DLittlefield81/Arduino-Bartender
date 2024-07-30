# Orbital Oasis

Orbital Oasis is an automated bartender project built using Arduino Uno R4 WiFi. It utilizes various sensors and components to dispense drinks based on user selection from a web interface. The project integrates React.js for the frontend, Express.js for the backend, and SQL for database management.

## Table of Contents

- [Project Description](#project-description)
- [Components](#components)
- [Wiring Diagrams](#wiring-diagrams)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Project Description

Orbital Oasis is designed to automate the drink dispensing process. Users can interact with the machine via a web interface to select their desired drink. The system uses an ultrasonic sensor to detect the presence of a glass, a load cell to measure the weight, and flow rate sensors to control the amount of liquid dispensed. The project also features an LCD for display and relays to control the pumps.

## Components

- Arduino Uno R4 WiFi
- Ultrasonic Sensor
- Load Cell
- Flow Rate Sensor
- LCD Display
- Relays
- Pumps
- Web Server (Node.js with Express.js)
- Frontend (React.js)
- SQL Database

## Wiring Diagrams

Below are the wiring diagrams for the project. Ensure all connections are made correctly to avoid any issues.

![Fritzing Diagram 1](diagrams/diagram1.png)

## Installation

To get started with Orbital Oasis, follow the steps below:

### Arduino Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
2. Connect your Arduino Uno R4 WiFi to your computer.
3. Upload the provided Arduino code to the board.

## Usage

Once everything is set up, open your web browser and navigate to `http://127.0.0.1`, or scan the barcode on the LCD of the device. Follow the on-screen instructions to select your drink. The machine will dispense the drink based on your selection.
