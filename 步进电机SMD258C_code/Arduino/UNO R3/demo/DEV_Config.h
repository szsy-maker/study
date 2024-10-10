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

#include <SPI.h>
#include <Wire.h>
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
#define STEP_PIN 5
#define DIR_PIN 6
#define ENABLE_PIN 7

#define DEV_Digital_Write(_pin, _value) digitalWrite(_pin, _value)

/*------------------------------------------------------------------------------------------------------*/
UBYTE DEV_ModuleInit(void);

void DEV_Delay_ms(UDOUBLE xms);
void DEV_Delay_us(UDOUBLE xus);

#endif
