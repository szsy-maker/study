/*****************************************************************************
* | File        :   MotorDriver.h
* | Author      :   Waveshare team
* | Function    :   
* | Info        :
*                
*----------------
* |	This version:   V1.0
* | Date        :   2018-11-24
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __MOTORDRIVER_H_
#define __MOTORDRIVER_H_

#include "DEV_Config.h"

//Motor Dir
#define FORWARD 0
#define BACKWARD 1

typedef struct {
    UBYTE EnablePin;
    UBYTE DirPin;
    UBYTE StepPin;
    UBYTE Positive;// positive connection = 1
    UBYTE Negative;// negative connection = 0
} MOTOR;

void Motor_Init(void);
void Motor_Stop(void);
void Motor_TurnStep(UBYTE dir, UWORD steps, UWORD stepdelay);
#endif