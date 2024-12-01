#include <xc.h>
#include <pic18f4520.h>

#pragma config OSC = INTIO67    // Oscillator Selection bits
#pragma config WDT = OFF       // Watchdog Timer Enable bit 
#pragma config PWRT = OFF       // Power-up Enable bit
#pragma config BOREN = ON       // Brown-out Reset Enable bit
#pragma config PBADEN = OFF    // Watchdog Timer Enable bit 
#pragma config LVP = OFF        // Low Voltage (single -supply) In-Circute Serial Pragramming Enable bit
#pragma config CPD = OFF        // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)

#define _XTAL_FREQ 250000

// ????
#define SERVO1 LATBbits.LATB1
#define SERVO2 LATBbits.LATB2
#define SERVO3 LATBbits.LATB3
#define SERVO4 LATBbits.LATB4

volatile uint16_t servoPulse[4] = {1500, 1500, 1500, 1500}; // ????
volatile uint16_t pwmCounter = 0;

void Timer0_Init(void) {
    T0CON = 0x88;       // ?? Timer0
    TMR0H = 0xFF;       // ????50µs?
    TMR0L = 193;
    INTCONbits.TMR0IE = 1; // ?? Timer0 ??
    INTCONbits.GIE = 1;    // ??????
    INTCONbits.PEIE = 1;   // ??????
}

void __interrupt() ISR(void) {
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        TMR0H = 0xFF;
        TMR0L = 0x193;

        pwmCounter += 500;

        if (pwmCounter <= servoPulse[0]) SERVO1 = 1; else SERVO1 = 0;
        if (pwmCounter <= servoPulse[1]) SERVO2 = 1; else SERVO2 = 0;
        if (pwmCounter <= servoPulse[2]) SERVO3 = 1; else SERVO3 = 0;
        if (pwmCounter <= servoPulse[3]) SERVO4 = 1; else SERVO4 = 0;

        if (pwmCounter >= 20000) pwmCounter = 0;
    }
}

void setServoAngle(uint8_t servo, uint16_t pulseWidth) {
    if (servo < 4 && pulseWidth >= 500 && pulseWidth <= 2500) {
        servoPulse[servo] = pulseWidth;
    }
}

void main(void) {
    TRISB = 0x01; 
    LATB = 0x00;  
    Timer0_Init();

    while (1) {
        while(RB0 == 0b1);
        setServoAngle(0, 500); 
        __delay_ms(1000);
        
        while(RB0 == 0b1);
        setServoAngle(0, 1500);
        __delay_ms(1000);
        
        while(RB0 == 0b1);
        setServoAngle(0, 2500);
        __delay_ms(1000);
        
        while(RB0 == 0b1);
        setServoAngle(0, 1500);
        __delay_ms(1000);
    }
}