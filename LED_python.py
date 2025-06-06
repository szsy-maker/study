"""
点亮LED的树莓派Python程序实例程序
"""
import RPi.GPIO as GPIO
import time

LED_PIN = 18
GPIO.setmode(GPIO.BCM)  
GPIO.setup(LED_PIN, GPIO.OUT)
print("程序开始运行，按Ctrl+C停止")
for i in range(50):
    # 点亮LED (输出高电平)
    GPIO.output(LED_PIN, GPIO.HIGH)
    print("LED亮")
    time.sleep(1)  
    
    # 熄灭LED (输出低电平)
    GPIO.output(LED_PIN, GPIO.LOW)
    print("LED灭")
    time.sleep(1)  


GPIO.cleanup()
print("GPIO资源已清理") #释放引脚
