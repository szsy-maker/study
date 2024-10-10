/*****************************************************************************
* | File        :   DEV_Config.cpp
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
#include "DEV_Config.h"
#include "Debug.h"  //DEBUG()

/**
 * Module Initialize, use BCM2835 library.
 *
 */
UBYTE DEV_ModuleInit(void)
{
    //set pin
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);
    
    //set Serial
    Serial.begin(115200);
    
    return 0;
}

/**
 * Millisecond delay.
 *
 * @param xms: time.
 *
 * Example:
 * DEV_Delay_ms(500);//delay 500ms
 */
void DEV_Delay_ms(UDOUBLE xms)
{
    delay(xms);
}

/**
 * Microsecond delay.
 *
 * @param xus: time.
 *
 * Example:
 * DEV_Delay_us(500);//delay 500us
 */
void DEV_Delay_us(UDOUBLE xus)
{
    int j;
    for(j=xus; j > 0; j--);
}
