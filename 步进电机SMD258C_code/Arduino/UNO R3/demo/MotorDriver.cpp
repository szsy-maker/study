/*****************************************************************************
  | File        :   MotorDriver.cpp
  | Author      :   Waveshare team
  | Function    :
  | Info        :

  ----------------
  |	This version:   V1.0
  | Date        :   2018-10-13
  | Info        :   Basic version

******************************************************************************/
#include "MotorDriver.h"
#include "Debug.h"  //DEBUG()
MOTOR Motor;

/**
   Select motor

   @param name: motor.

   Example:
   Motor_Init();

*/
void Motor_Init(void)
{
  Motor.EnablePin = ENABLE_PIN;
  Motor.DirPin = DIR_PIN;
  Motor.StepPin = STEP_PIN;

  // PU- DR- MF- to GND
  Motor.Positive = 1;
  Motor.Negative = 0;

  // PU+ DR+ MF+ to VCC
  // Motor.Negative = 0;
  // Motor.Positive = 1;
}

/**
   The motor stops rotating and the driver chip is disabled.

*/
void Motor_Stop(void)
{
  DEV_Digital_Write(Motor.EnablePin, Motor.Positive);
}

/**
   turn.

   @param dir: direction.
   @param steps: Step count.
   @param stepdelay: step delay.

   Example:
   Motor_TurnStep()
*/
void Motor_TurnStep(UBYTE dir, UWORD steps, UWORD stepdelay)
{
  if (dir == FORWARD) {
    DEV_Digital_Write(Motor.EnablePin, Motor.Negative);
    DEV_Digital_Write(Motor.DirPin, Motor.Negative);
  } else if (dir == BACKWARD) {
    DEV_Digital_Write(Motor.EnablePin, Motor.Negative);
    DEV_Digital_Write(Motor.DirPin, Motor.Positive);
  } else {
    DEV_Digital_Write(Motor.EnablePin, Motor.Positive);
  }

  if (steps == 0)
    return;

  UWORD i = 0;
  for (i = 0; i < steps; i++) {
    DEV_Digital_Write(Motor.StepPin, 1);
    DEV_Delay_ms(stepdelay);
    DEV_Digital_Write(Motor.StepPin, 0);
    DEV_Delay_ms(stepdelay);
  }

}
