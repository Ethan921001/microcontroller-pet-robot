#include "servo.h"
#define Move_delay 15
void Timer0_Initialize(void) {
    T0CON = 0x88;       // ?? Timer0
    TMR0H = 0xFF;       // ????50�s?
    TMR0L = 193;
    INTCONbits.TMR0IE = 1; // ?? Timer0 ??
    INTCONbits.GIE = 1;    // ??????
    INTCONbits.PEIE = 1;   // ??????
    INTCON2bits.TMR0IP = 0;
    RCONbits.IPEN = 1;
}

void setServoAngle(uint8_t servo, uint16_t pulseWidth) {
    if (servo < 4 && pulseWidth >= 500 && pulseWidth <= 2500) {
        servoPulse[servo] = pulseWidth;
    }
}

void setstand(){
        setServoAngle(0, 1500);
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);    
}

void setsit(){
        setServoAngle(0, 1500);
        setServoAngle(1, 1500);
        setServoAngle(2, 2500);
        setServoAngle(3, 500);    
}

void setlaydown(){
        setServoAngle(0, 2500);
        setServoAngle(1, 500);
        setServoAngle(2, 500);
        setServoAngle(3, 2500);    
}

void walk(){
        // 1
        setServoAngle(0, 2000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1005);  
        __delay_ms(Move_delay);
        if(mode != 3) return;
        // 2
        setServoAngle(0, 2000);
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);  
        setServoAngle(3, 1005);
        __delay_ms(Move_delay);
        if(mode != 3) return;
        // 3
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3) return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3) return;
        // 5
        setServoAngle(0, 1500);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3) return;
        // 6
        setServoAngle(0, 1005);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 3) return;
        // 7
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 3) return;
        // 8
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3) return;
}
void back_walk(){
    // 1
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4) return;
        // 2
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 4) return;
        // 3
        setServoAngle(0, 1005);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 4) return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4) return;
        // 5
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4) return;
        // 6
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4) return;
        // 7
       setServoAngle(0, 2000);
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);  
        setServoAngle(3, 1005);
        __delay_ms(Move_delay);
        if(mode != 4) return;
        // 8
        setServoAngle(0, 2000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1005);  
        __delay_ms(Move_delay);
        if(mode != 4) return;
}
void turn_right(){
            // 1
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1005);  
        __delay_ms(Move_delay);
        if(mode != 5) return;
        // 2
        setServoAngle(0, 1005);
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);  
        setServoAngle(3, 1005);
        __delay_ms(Move_delay);
        if(mode != 5) return;
        // 3
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 5) return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 5) return;
}

void turn_left(){
        // 1
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 6) return;
        // 2
        setServoAngle(0, 1005);
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);  
        setServoAngle(3, 1005);
        __delay_ms(Move_delay);
        if(mode != 6) return;
        // 3
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1005);  
        __delay_ms(Move_delay);
        if(mode != 6) return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 6) return;
}