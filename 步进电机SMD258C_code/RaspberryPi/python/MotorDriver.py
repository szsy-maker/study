import RPi.GPIO as GPIO
import time

MotorDir = [
    'forward',
    'backward',
]

class MotorDriver():
    def __init__(self, mode):
        self.dir_pin = 13
        self.step_pin = 19        
        self.enable_pin = 12
        self.mode = mode
        # mode = 0 : Positive PU- DR- MF- to GND
        # mode = 1 : Negative PU- DR- MF- to 5V
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        GPIO.setup(self.dir_pin, GPIO.OUT)
        GPIO.setup(self.step_pin, GPIO.OUT)
        GPIO.setup(self.enable_pin, GPIO.OUT)
                
    def digital_write(self, pin, value):
        GPIO.output(pin, value)
        
    def Stop(self):
        self.digital_write(self.enable_pin, ~self.mode)
    
    def TurnStep(self, Dir, steps, stepdelay=0.002):       
        if (steps == 0):
            return
            
        self.digital_write(self.enable_pin, self.mode)
        if self.mode == 0 :
            self.digital_write(self.dir_pin, 0 if (Dir == MotorDir[0]) else 1)
        else:
            self.digital_write(self.dir_pin, 1 if (Dir == MotorDir[0]) else 0)
            
        print "turn step:",steps
        for i in range(steps):
            self.digital_write(self.step_pin, False)
            time.sleep(stepdelay)
            self.digital_write(self.step_pin, True)
            time.sleep(stepdelay)