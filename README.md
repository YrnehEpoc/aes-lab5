# aes-lab5
Drift is the difference in period between the measured and ideal signal period

## Activity 1
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

## Activity 2
GPIO_Interrupt delay: 9.332µs
GPIO_Interrupt delay with 500µs of delay: 510.143µs

## Activity 3
Message queue GPIO_Interrupt delay: 26.675µs
Message queue GPIO_Interrupt 500µs delay: 525.234µs
