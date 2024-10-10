#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include "DEV_Config.h"
#include "MotorDriver.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    Motor_Stop();
    DEV_ModuleExit();

    exit(0);
}

int main(void)
{
    //1.System Initialization
    if(DEV_ModuleInit())
        exit(0);
    
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    
    Motor_Init(0);
    
    //Subdivision Set D1-ON D2-ON D3-ON D4-ON
    //Current Set D1-OFF D2-OFF D3-ON D4-ON
    Motor_TurnStep(BACKWARD, 200 , 2);
    Motor_TurnStep(FORWARD, 200 , 2);
    Motor_Stop();
    
    //3.System Exit
    DEV_ModuleExit();
    return 0;
}

