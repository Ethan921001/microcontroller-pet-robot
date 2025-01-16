#include <xc.h>
#include <pic18f4520.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000    // ???????? 1 MHz
#endif

#define SERVO1 LATBbits.LATB1
#define SERVO2 LATBbits.LATB2
#define SERVO3 LATBbits.LATB3
#define SERVO4 LATBbits.LATB4

//setting
volatile uint16_t servoPulse[4] = {1500, 1500, 1500, 1500}; // ????
volatile uint16_t pwmCounter = 0;
void Timer0_Initialize(void);
//void __interrupt() ISR(void);
void setServoAngle(uint8_t servo, uint16_t pulseWidth);
extern int mode = 0;
extern int old_mode = 0;

// action
void setstand();
void setsit();
void setlaydown();
void walk();
void back_walk();
void turn_right();
void turn_left();
void handshaking();

