# aes-lab5
This lab uses an oscilloscope to measure the jitter and drift of different time keeping methods. 
## Activity 0
Using a disco board, the oscilloscope should be connected to pin PA0, then running (pio run -t upload -e sleep/interrupt/rtc/kernel) in order to run different time keeping methods. 

## Activity 1
Using a disco board, signal generator and oscilloscope, attach the sync output of the signal generator to the oscilloscope and use it as a trigger. Make sure the signal generator is creating a 3.3V amplitude square wave with 50% duty cycle at 1 kHz frequency. Connect the output of the signal generator to pin PA1. run (pio run -t upload -e interrupt) to measure the delay.

## Activity 2
With the same experimental setup, run (pio run -t upload -e msgq_interrupt) to measure the delay after introducing a message queue