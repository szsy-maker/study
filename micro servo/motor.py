"""
GPIO库舵机驱动，适应180度模拟舵机
"""
import RPi.GPIO as GPIO
import time
fPWM =50
max=180
#初始化
GPIO.setmode(GPIO.BCM)#设置编码规范
GPIO.setwarnings(False)#去粗GPIO警告
GPIO.setup(18,GPIO.OUT)#设置相应的引脚为输出模式
pwm =GPIO.PWM(18,fPWM)#设置相应的引脚的频率
pwm.start(0)
#脉冲比换算公式
def math(d):
    return 10 / max * d +2.5

pwm.ChangeDutyCycle(math(180))#转到90度
time.sleep(1)
pwm.ChangeDutyCycle(math(0))#转到0度
time.sleep(1)
GPIO.cleanup()#释放所以引脚


