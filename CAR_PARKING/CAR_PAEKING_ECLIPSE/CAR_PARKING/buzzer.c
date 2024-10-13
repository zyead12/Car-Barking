/*
 * buzzer.c
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#include "buzzer.h"
#include "gpio.h"

/*
 * Function to initialize the buzzer.
 * It sets up the buzzer pin as an output and turns the buzzer off initially.
 */
void BUZZER_init()
{
    // Configure the buzzer pin as output
    GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);

    // Ensure the buzzer is off initially
    BUZZER_off();
}

/*
 * Function to turn the buzzer on.
 * It sets the buzzer pin to the high state (logic high).
 */
void BUZZER_on()
{
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BUZZER_ON);
}

/*
 * Function to turn the buzzer off.
 * It sets the buzzer pin to the low state (logic low).
 */
void BUZZER_off()
{
    GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BUZZER_OFF);
}
