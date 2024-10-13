/*
 * led.h
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

// Definitions for the red, green, and blue LED ports and pins
#define RED_PORT_ID   PORTC_ID
#define RED_PIN_ID    PIN0_ID

#define GREEN_PORT_ID PORTC_ID
#define GREEN_PIN_ID  PIN1_ID

#define BLUE_PORT_ID  PORTC_ID
#define BLUE_PIN_ID   PIN2_ID

// Enum for identifying the different LEDs (red, green, and blue)
typedef enum
{
    LED_RED = 1,  // Red LED ID
    LED_GREEN,    // Green LED ID
    LED_BLUE      // Blue LED ID
} LED_ID;

// Macros to define LED states
#define LED_ON  LOGIC_HIGH  // LED is turned on
#define LED_OFF LOGIC_LOW   // LED is turned off

/*
 * Function to initialize the LED pins as output.
 * It configures the red, green, and blue LED pins for output mode.
 */
void LED_init(void);

/*
 * Function to turn off a specific LED.
 *
 * @param id: The ID of the LED to turn off (LED_RED, LED_GREEN, or LED_BLUE).
 */
void LED_off(LED_ID id);

/*
 * Function to turn on a specific LED.
 *
 * @param id: The ID of the LED to turn on (LED_RED, LED_GREEN, or LED_BLUE).
 */
void LED_on(LED_ID id);

#endif /* LED_H_ */
