"""
小按钮模块实例程序
"""
import RPi.GPIO as GPIO
import time
GPIOin=18
GPIO.setmode(GPIO.BCM)
GPIO.setup(GPIOin,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setwarnings(False)
while True:
    time.sleep(0.01)
    if GPIO.input(GPIOin)==GPIO.HIGH:
        print("按压")
    elif GPIO.input(GPIOin)==GPIO.LOW:
        print("未按压")
    else:
        print("请检查查询")
