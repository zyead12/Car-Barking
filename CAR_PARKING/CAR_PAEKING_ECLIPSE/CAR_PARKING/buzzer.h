/*
 * buzzer.h
 *
 *  Created on: Oct 5, 2024
 *      Author: elouf
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

// Define the port and pin for the buzzer
#define BUZZER_PORT_ID  PORTC_ID
#define BUZZER_PIN_ID   PIN5_ID

// Macros to define buzzer states
#define BUZZER_ON  LOGIC_HIGH  // Buzzer is turned on (logic high)
#define BUZZER_OFF LOGIC_LOW   // Buzzer is turned off (logic low)

/*
 * Function to initialize the buzzer.
 * It sets the buzzer pin as an output and turns it off initially.
 */
void BUZZER_init();

/*
 * Function to turn on the buzzer.
 * It sets the buzzer pin to a high logic state, activating the buzzer.
 */
void BUZZER_on();

/*
 * Function to turn off the buzzer.
 * It sets the buzzer pin to a low logic state, deactivating the buzzer.
 */
void BUZZER_off();

#endif /* BUZZER_H_ */
