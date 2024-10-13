/*
 * led.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#include "led.h"
#include "gpio.h"

/*
 * Function to initialize the LED pins as output.
 * It configures the red, green, and blue LED pins as output pins.
 */
void LED_init(void)
{
    // Set the direction of the red, green, and blue LED pins to output
    GPIO_setupPinDirection(RED_PORT_ID, RED_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(GREEN_PORT_ID, GREEN_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(BLUE_PORT_ID, BLUE_PIN_ID, PIN_OUTPUT);
}

/*
 * Function to turn on a specific LED.
 * It takes the LED ID (RED, GREEN, or BLUE) and turns it on.
 *
 * @param id: The ID of the LED to turn on (LED_RED, LED_GREEN, or LED_BLUE).
 */
void LED_on(LED_ID id)
{
    switch (id)
    {
        case LED_RED:
            GPIO_writePin(RED_PORT_ID, RED_PIN_ID, LED_ON); // Turn on the red LED
            break;
        case LED_GREEN:
            GPIO_writePin(GREEN_PORT_ID, GREEN_PIN_ID, LED_ON); // Turn on the green LED
            break;
        case LED_BLUE:
            GPIO_writePin(BLUE_PORT_ID, BLUE_PIN_ID, LED_ON); // Turn on the blue LED
            break;
        default:
            break;
    }
}

/*
 * Function to turn off a specific LED.
 * It takes the LED ID (RED, GREEN, or BLUE) and turns it off.
 *
 * @param id: The ID of the LED to turn off (LED_RED, LED_GREEN, or LED_BLUE).
 */
void LED_off(LED_ID id)
{
    switch (id)
    {
        case LED_RED:
            GPIO_writePin(RED_PORT_ID, RED_PIN_ID, LED_OFF); // Turn off the red LED
            break;
        case LED_GREEN:
            GPIO_writePin(GREEN_PORT_ID, GREEN_PIN_ID, LED_OFF); // Turn off the green LED
            break;
        case LED_BLUE:
            GPIO_writePin(BLUE_PORT_ID, BLUE_PIN_ID, LED_OFF); // Turn off the blue LED
            break;
        default:
            break;
    }
}
