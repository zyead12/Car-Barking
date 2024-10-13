/*
 * ultarsonic_sensor.c
 *
 *  Created on: Oct 13, 2024
 *      Author: elouf
 */

#include "ultrasonic_sensor.h"
#include "gpio.h"
#include "icu.h"
#include "util/delay.h"

// Configuration for the ICU (Input Capture Unit) to use with the ultrasonic sensor
ICU_ConfigType ICU_CONGIG_ON_ULTRASONIC = {F_CPU_8, RAISING};

// Static variables to store edge count, pulse duration (time high), and the calculated distance
uint8 static g_num_call = 0;
uint16 static time_high = 0;
uint16 static Ultarsonic_g_distance = 0;

/*
 * Function to initialize the ultrasonic sensor by setting up the trigger pin
 * and configuring the ICU to detect edges and capture times.
 */
void Ultarsonic_sensor_init()
{
    // Set the trigger pin of the ultrasonic sensor as output
    GPIO_setupPinDirection(ULTRASONIC_SENSOR_TRIG_PORT_ID, ULTRASONIC_SENSOR_TRIG_PIN_ID, PIN_OUTPUT);

    // Initialize the ICU with the configured settings
    ICU_init(&ICU_CONGIG_ON_ULTRASONIC);

    // Set the callback function for edge processing (will be called on edge detection)
    ICU_setCallBack(Ultrasonic_edgeProcessing);
}

/*
 * Function to send a trigger pulse to the ultrasonic sensor.
 * It sends a 10 microsecond HIGH pulse to the sensor's trigger pin.
 */
void Ultrasonic_Trigger(void)
{
    // Send a HIGH pulse to the trigger pin for 10 microseconds
    GPIO_writePin(ULTRASONIC_SENSOR_TRIG_PORT_ID, ULTRASONIC_SENSOR_TRIG_PIN_ID, LOGIC_HIGH);
    _delay_us(10);

    // Send a LOW signal to complete the trigger pulse
    GPIO_writePin(ULTRASONIC_SENSOR_TRIG_PORT_ID, ULTRASONIC_SENSOR_TRIG_PIN_ID, LOGIC_LOW);
}

/*
 * Interrupt Service Routine (ISR) for edge detection.
 * This function is called each time an edge is detected (rising or falling).
 */
void Ultrasonic_edgeProcessing(void)
{
    g_num_call++;  // Increment the call count for each detected edge

    switch(g_num_call)
    {
        case 1: // First rising edge detected
            ICU_clearTimerValue(); // Clear the ICU timer to start timing the pulse
            ICU_setEdgeDetectionType(FALLING); // Set the ICU to detect the falling edge
            break;

        case 2: // First falling edge detected
            time_high = ICU_getInputCaptureValue(); // Capture the pulse duration (time high)
            ICU_setEdgeDetectionType(RAISING); // Set the ICU back to detecting the next rising edge
            break;
    }
}

/*
 * Function to read the distance measured by the ultrasonic sensor.
 * It sends a trigger pulse and waits for the echo pulse to be captured by the ICU.
 */
uint16 Ultrasonic_readDistance(void)
{
    // Send the trigger pulse to start the measurement
    Ultrasonic_Trigger();

    // Wait until both rising and falling edges are detected (i.e., the echo is received)
    while(g_num_call != 2);

    // Reset the edge count for the next measurement
    g_num_call = 0;

    // Calculate the distance based on the pulse duration (time_high)
    // The formula (time_high / 117.6) converts the pulse time into distance in centimeters
    Ultarsonic_g_distance = (uint16)(time_high / 117.6);

    // Return the measured distance (adding 1 for rounding purposes)
    return Ultarsonic_g_distance + 1;
}
