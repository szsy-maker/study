/*****************************************************************************
* | File        :   MotorDriver.c
* | Author      :   Waveshare team
* | Function    :
* | Info        :
*
*----------------
* |	This version:   V1.0
* | Date        :   2018-10-13
* | Info        :   Basic version
*
******************************************************************************/
#include "MotorDriver.h"
#include "Debug.h"  //DEBUG()
#include <stdlib.h> //exit()
#include <stdio.h>  //printf()
#include <string.h> //strcmp()

MOTOR Motor;

/**
 * Select motor
 *
 * @param name: motor.
 *
 * Example:
 * Motor_Init();
 *
 */
void Motor_Init(UBYTE mode)
{
    Motor.EnablePin = ENABLE_PIN;
    Motor.DirPin = DIR_PIN;
    Motor.StepPin = STEP_PIN;

    // # mode = 0 : Positive PU- DR- MF- to GND
    // # mode = 1 : Negative PU- DR- MF- to 5V
    Motor.Mode = mode;
}

/**
 * The motor stops rotating and the driver chip is disabled.
 *
 */
void Motor_Stop(void)
{
    DEV_Digital_Write(Motor.EnablePin, Motor.Mode == 0? 1 : 0);
}

/**
 * turn.
 *
 * @param dir: direction.
 * @param steps: Step count.
 * @param stepdelay: step delay.
 *
 * Example:
 * Motor_TurnStep()
 */
void Motor_TurnStep(UBYTE dir, UWORD steps, UWORD stepdelay)
{
    DEV_Digital_Write(Motor.EnablePin, Motor.Mode == 0? 0 : 1);
    if(dir == FORWARD) {        
        DEV_Digital_Write(Motor.DirPin, Motor.Mode == 0? 0 : 1);
    } else {
        DEV_Digital_Write(Motor.DirPin, Motor.Mode == 0? 1 : 0);
    }

    if(steps == 0)
        return;

    UWORD i = 0;
    DEBUG("turn %d steps\r\n", steps);
    for(i = 0; i < steps; i++) {
        DEV_Digital_Write(Motor.StepPin, 1);
        DEV_Delay_ms(stepdelay);
        DEV_Digital_Write(Motor.StepPin, 0);
        DEV_Delay_ms(stepdelay);
    }

}
