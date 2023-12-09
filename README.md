# aes-lab5
This lab uses an oscilloscope to measure the jitter and drift of different time keeping methods. 
## Activity 0
Using a disco board, the oscilloscope should be connected to pin PA0, then running (pio run -t upload -e sleep/interrupt/rtc/kernel) in order to run different time keeping methods. 

sleep jitter: 0.193ms
kernel.c jitter: 0.015ms
busy.c jitter: 0.001ms
rtc.c jitter: 1.54ms
Agilent jitter: 0.00072ms

sleep.c drift: 0.7199s of deviation
kernel.c drift: 0.384s of deviation
busy.c drift: 0.012s of deviation
rtc.c drift: 4.48s of deviation

sleep.c drift with 2000µs  of delay: 4.76s of deviation
kernel.c drift with 2000µs of delay: 4.5s of deviation
busy.c drift with 2000µs of delay: 4.22s of deviation
rtc.c drift with 2000µs of delay: 4.47s of deviation

## Activity 1
Using a disco board, signal generator and oscilloscope, attach the sync output of the signal generator to the oscilloscope and use it as a trigger. Make sure the signal generator is creating a 3.3V amplitude square wave with 50% duty cycle at 1 kHz frequency. Connect the output of the signal generator to pin PA1. run (pio run -t upload -e interrupt) to measure the delay.

GPIO_Interrupt delay: 9.332µs
GPIO_Interrupt delay with 500µs of delay: 510.143µs

## Activity 2
With the same experimental setup, run (pio run -t upload -e msgq_interrupt) to measure the delay after introducing a message queue


Message queue GPIO_Interrupt delay: 26.675µs
Message queue GPIO_Interrupt 500µs delay: 525.234µs


