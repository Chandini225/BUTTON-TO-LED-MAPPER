# BUTTON-TO-LED-MAPPER

🎮 Smart Button Handler with Function Pointer Mapping
An advanced button handling system that demonstrates professional embedded systems design patterns using struct-based mapping tables and function pointers for scalable, maintainable input handling.

📋 Overview
This project transforms basic button handling from nested if/else statements into a clean, professional architecture. Each button is mapped to specific actions through function pointers, creating a system that's easy to extend and maintain - just like real-world embedded products!

🚀 Key Features
Mapping Table Design: Buttons mapped to functions using struct arrays
Function Pointers: Clean separation of button detection from action execution
Short/Long Press Support: Different actions for brief and extended button presses
Debounced Inputs: Reliable button detection with software debouncing
Scalable Architecture: Easy to add new buttons and functions
Professional Patterns: Industry-standard approach used in commercial products

🛠️ Hardware Requirements
Arduino Uno or compatible board
3 Push Buttons
3 LEDs (any color)
220Ω Resistors (3) for LED current limiting
10kΩ Resistors (3) for button pull-up
Breadboard and Jumper Wires


🎮 Smart Button Handler with Function Pointer Mapping
An advanced button handling system that demonstrates professional embedded systems design patterns using struct-based mapping tables and function pointers for scalable, maintainable input handling.

📋 Overview
This project transforms basic button handling from nested if/else statements into a clean, professional architecture. Each button is mapped to specific actions through function pointers, creating a system that's easy to extend and maintain - just like real-world embedded products!

🚀 Key Features
Mapping Table Design: Buttons mapped to functions using struct arrays
Function Pointers: Clean separation of button detection from action execution
Short/Long Press Support: Different actions for brief and extended button presses
Debounced Inputs: Reliable button detection with software debouncing
Scalable Architecture: Easy to add new buttons and functions
Professional Patterns: Industry-standard approach used in commercial products

🛠️ Hardware Requirements
Arduino Uno or compatible board
3 Push Buttons
3 LEDs (any color)
220Ω Resistors (3) for LED current limiting
10kΩ Resistors (3) for button pull-up
Breadboard and Jumper Wires

🔧 Hardware Connections
Button Connections (Active Low with Pull-up)
BUTTON 1: Digital Pin 2 ↔ GND (with 10kΩ pull-up to 5V)
BUTTON 2: Digital Pin 3 ↔ GND (with 10kΩ pull-up to 5V)  
BUTTON 3: Digital Pin 4 ↔ GND (with 10kΩ pull-up to 5V)

LED Connections
LED 1: Digital Pin 8 → Anode (with 220Ω resistor to GND)
LED 2: Digital Pin 9 → Anode (with 220Ω resistor to GND)
LED 3: Digital Pin 10 → Anode (with 220Ω resistor to GND)

🎯 Button Functions
Button 1 (Pin 2)
Short Press (<1 second): Toggle LED1 on/off
Long Press (≥1 second): Rapid blink LED1 (5 quick blinks)
Button 2 (Pin 3)
Short Press: Toggle LED2 on/off
Long Press: Medium blink LED2 (3 blinks)
Button 3 (Pin 4)
Short Press: Toggle LED3 on/off
Long Press: Turn ON all LEDs simultaneously
