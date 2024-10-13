/*
 * car_parking.c
 *
 *  Created on: Oct 13, 2024
 *      Author: elouf
 */

#include "lcd.h"
#include "ultrasonic_sensor.h"
#include "avr/io.h"
#include "led.h"
#include "util/delay.h"
#include "buzzer.h"

uint16 Car_parking_distance = 0; // Variable to store distance measured by the ultrasonic sensor

int main(void)
{
    // Initialize the ultrasonic sensor, LEDs, buzzer, and LCD
    Ultarsonic_sensor_init();
    LED_init();
    BUZZER_init();
    LCD_init();

    // Enable global interrupts
    SREG |= (1 << 7);

    while(1)
    {
        // Read the distance from the ultrasonic sensor
        Car_parking_distance = Ultrasonic_readDistance();

        // Display the distance on the LCD
        LCD_displayStringRowColumn(0, 1, "Distance="); // Display "Distance=" at row 0, column 1
        LCD_moveCursor(0, 10); // Move cursor to column 10 in row 0
        LCD_intgerToString(Car_parking_distance); // Display the measured distance
        LCD_displayCharacter(' '); // Display space after the number
        LCD_displayString("cm"); // Display "cm" for distance units
        LCD_displayCharacter(' ');

        // If the distance is less than or equal to 5 cm, display "STOP!" and activate the buzzer and LEDs
        if(Car_parking_distance <= 5)
        {
            LCD_displayStringRowColumn(1, 6, "STOP!"); // Display "STOP!" at row 1, column 6
            BUZZER_on(); // Turn on the buzzer
            LCD_moveCursor(1, 6);
            LED_on(LED_RED); // Turn on the red LED
            LED_on(LED_GREEN); // Turn on the green LED
            LED_on(LED_BLUE); // Turn on the blue LED
            _delay_ms(250); // Wait for 250 ms
            LED_off(LED_RED); // Turn off the red LED
            LED_off(LED_GREEN); // Turn off the green LED
            LED_off(LED_BLUE); // Turn off the blue LED
            _delay_ms(250); // Wait for 250 ms
        }

        // If the distance is greater than 5 cm, turn off the buzzer and clear the "STOP!" message
        if(Car_parking_distance > 5)
        {
            LCD_displayStringRowColumn(1, 6, "     "); // Clear the "STOP!" message
            BUZZER_off(); // Turn off the buzzer
        }

        // If the distance is between 6 and 10 cm, turn on all LEDs
         if(Car_parking_distance >= 6 && Car_parking_distance <= 10)
        {
            LED_on(LED_RED); // Turn on the red LED
            LED_on(LED_GREEN); // Turn on the green LED
            LED_on(LED_BLUE); // Turn on the blue LED
        }

        // If the distance is between 11 and 15 cm, turn on the red and green LEDs and turn off the blue LED
         else if(Car_parking_distance >= 11 && Car_parking_distance <= 15)
        {
            LED_on(LED_RED); // Turn on the red LED
            LED_on(LED_GREEN); // Turn on the green LED
            LED_off(LED_BLUE); // Turn off the blue LED
        }

        // If the distance is between 16 and 20 cm, turn on the red LED and turn off the green and blue LEDs
         else if(Car_parking_distance >= 16 && Car_parking_distance <= 20)
        {
            LED_on(LED_RED); // Turn on the red LED
            LED_off(LED_GREEN); // Turn off the green LED
            LED_off(LED_BLUE); // Turn off the blue LED
        }

        // If the distance is greater than 20 cm, turn off all LEDs
         else  if(Car_parking_distance > 20)
        {
            LED_off(LED_RED); // Turn off the red LED
            LED_off(LED_GREEN); // Turn off the green LED
            LED_off(LED_BLUE); // Turn off the blue LED
        }
    }
}
