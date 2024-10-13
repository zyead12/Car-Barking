/*
 * ultrasonic_sensor.h
 *
 *  Created on: Oct 13, 2024
 *      Author: elouf
 */

#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "std_types.h"

// Define the port and pin for the ultrasonic sensor's trigger pin
#define ULTRASONIC_SENSOR_TRIG_PORT_ID  PORTD_ID
#define ULTRASONIC_SENSOR_TRIG_PIN_ID   PIN7_ID

/*
 * Function to initialize the ultrasonic sensor.
 * It configures the trigger pin and sets up the ICU (Input Capture Unit) for edge detection.
 */
void Ultarsonic_sensor_init();

/*
 * Function to send a trigger pulse to the ultrasonic sensor.
 * It sends a 10-microsecond pulse to the sensor's trigger pin.
 */
void Ultrasonic_Trigger(void);

/*
 * Callback function for edge detection.
 * This function is called by the ICU when an edge is detected (either rising or falling).
 */
void Ultrasonic_edgeProcessing(void);

/*
 * Function to read the distance measured by the ultrasonic sensor.
 * It sends a trigger pulse, waits for the echo, and calculates the distance in centimeters.
 *
 * @return Distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_SENSOR_H_ */
