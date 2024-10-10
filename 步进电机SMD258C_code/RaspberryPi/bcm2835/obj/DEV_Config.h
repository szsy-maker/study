/*****************************************************************************
* | File        :   DEV_Config.h
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master 
*                and enhance portability
*----------------
* |	This version:   V1.0
* | Date        :   2018-09-03
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __DEV_CONFIG_H_
#define __DEV_CONFIG_H_

#include <bcm2835.h>
#include <stdint.h>

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/**
 * GPIO
**/
#define ENABLE_PIN 12   // PU pin
#define DIR_PIN 13      // DR pin
#define STEP_PIN 19     // MF pin

#define DEV_Digital_Write(_pin, _value) bcm2835_gpio_write(_pin, _value)

/*------------------------------------------------------------------------------------------------------*/

UBYTE DEV_ModuleInit(void);
void DEV_ModuleExit(void);

void DEV_Delay_ms(UDOUBLE xms);
void DEV_Delay_us(UDOUBLE xus);

#endif