import RPi.GPIO as GPIO
import time
from MotorDriver import MotorDriver

# PU- DR- MF- to GND
Motor = MotorDriver(1)
try:
    Motor.TurnStep(Dir='forward', steps=300, stepdelay = 0.002)
    time.sleep(0.5)
    Motor.TurnStep(Dir='backward', steps=600, stepdelay = 0.002)
    Motor.Stop()
    
except:
    # GPIO.cleanup()
    print "\nMotor stop"
    Motor.Stop()
    exit()