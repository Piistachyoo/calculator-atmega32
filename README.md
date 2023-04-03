# Calculator-Atmega32
## Project Description
Project was consisted of a microcontroller (AVR Atmega32) connected to a LCD screen to display i/o, and a keypad to enter numbers and choose operations.

## Project Design
Program starts with initializing the LCD and keypad, and initializing the calculator to start accepting inputs for first operand.

Every operand can consist of 5 digits and have a maximum of 65,535 because the variable is unsigned 16 bit integer.

The program doesn't support floats or negative values. If you make a subtraction operation, the program checks which operand is bigger and calculates the difference between them, avoiding negative values.

#### The calculator is designed as a state machine with 3 states:

 1. State_FirstOp
 2. State_SecondOp
 3. State_result

After initializing, the program's state is set to State_FirstOp, and waits for input from the keypad, the input is saved in an 8 bit array of size 5, and is flushed into a 16 bit unsigned integer.

When you press an operand "+,-,*,/", program saves the input numbers in the array into a variable and jumps to State_SecondOp state.

While in State_SecondOp state and after entering the second operand, 

If you press on = the program jumps to State_result state and shows the result.

If you press on another operand, the program understands that you need to do another calculation based on that result, so it makes the current calculation then put the result as the first operand, and wait to take an input for the second operand to do the new calculation.


## Configurations and Connections

 **All Configurations are available for change in /Application/application.h**

4x4 Keypad connected to port D.

LCD is connected to port C and working in 4-bit mode..

## Files

 - **Application:** Contains program main
 - **HAL:** Hardware architecture layer: contains software related to any on-board hardware element
 - **MCAL:** Microcontroller architecture layer: contains software related to any peripheral inside the microcontroller
 - **Services:** Contains my data types and some bit math operations
