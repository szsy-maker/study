#include "MotorDriver.h"

void setup()
{
  DEV_ModuleInit();
  Motor_Init();

  //Subdivision Set D1-ON D2-ON D3-ON D4-ON
  //Current Set D1-OFF D2-OFF D3-ON D4-ON
  Motor_TurnStep(BACKWARD, 200 , 2);
  DEV_Delay_ms(500);
  
  Motor_TurnStep(FORWARD, 200 , 2);
  DEV_Delay_ms(500);
  
  Motor_Stop();
}

void loop()
{
}
