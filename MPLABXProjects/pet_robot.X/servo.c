#include "servo.h"
#define Move_delay 400
void Timer0_Initialize(void) {
    T0CON = 0x88;       // ?? Timer0
    TMR0H = 0xFE;       // ????500µs?
    TMR0L = 0x0C;
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
        __delay_ms(Move_delay);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);    
}

void setsit(){
        setServoAngle(2, 2000);
        setServoAngle(3, 1000); 
        __delay_ms(Move_delay);
        setServoAngle(0, 1500);
        setServoAngle(1, 1500);
         
}

void setlaydown(){
        setServoAngle(0, 2000);
        setServoAngle(1, 1000);
        __delay_ms(Move_delay);
        setServoAngle(2, 1000);
        setServoAngle(3, 2000);    
}

void walk(){
        // 1
        setServoAngle(0, 2000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1000);  
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
        // 2
        setServoAngle(0, 2000);
        setServoAngle(1, 2000);
        setServoAngle(2, 1000);  
        setServoAngle(3, 1000);
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
        // 3
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 1000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
        // 5
        setServoAngle(0, 1500);  
        setServoAngle(1, 1000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
        // 6
        setServoAngle(0, 1000);  
        setServoAngle(1, 1000);
        setServoAngle(2, 2000);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
        // 7
        setServoAngle(0, 1000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
        // 8
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 3 && mode != 'a') return;
}
void back_walk(){
    // 1
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4 && mode != 'c') return;
        // 2
        setServoAngle(0, 1000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 4 && mode != 'c') return;
        // 3
        setServoAngle(0, 1000);  
        setServoAngle(1, 1000);
        setServoAngle(2, 2000);
        setServoAngle(3, 2000);  
        __delay_ms(Move_delay);
        if(mode != 4 && mode != 'c') return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4 && mode != 'c') return;
        // 5
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4 && mode != 'c') return;
        // 6
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 1000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 4 && mode != 'c') return;
        // 7
       setServoAngle(0, 2000);
        setServoAngle(1, 2000);
        setServoAngle(2, 1000);  
        setServoAngle(3, 1000);
        __delay_ms(Move_delay);
        if(mode != 4 && mode != 'c') return;
        // 8
        setServoAngle(0, 2000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1000);  
        __delay_ms(Move_delay);
       if(mode != 4 && mode != 'c') return;
}
void turn_right(){
            // 1
        setServoAngle(0, 1000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1000);  
        __delay_ms(Move_delay);
        if(mode != 5 && mode != 'b') return;
        // 2
        setServoAngle(0, 1000);
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);  
        setServoAngle(3, 1000);
        __delay_ms(Move_delay);
        if(mode != 5 && mode != 'b') return;
        // 3
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
       if(mode != 5 && mode != 'b') return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 5 && mode != 'b') return;
}

void turn_left(){
        // 1
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 6 && mode != 'd') return;
        // 2
        setServoAngle(0, 1000);
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);  
        setServoAngle(3, 1000);
        __delay_ms(Move_delay);
        if(mode != 6 && mode != 'd') return;
        // 3
        setServoAngle(0, 1000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1000);  
        __delay_ms(Move_delay);
        if(mode != 6 && mode != 'd') return;
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(Move_delay);
        if(mode != 6 && mode != 'd') return;
}

void handshaking(){
    setServoAngle(2, 2000);
    setServoAngle(3, 1000); 
    __delay_ms(Move_delay);
    setServoAngle(0, 1500);
    setServoAngle(1, 1500);
    __delay_ms(Move_delay);
    while(mode==7 || mode=='h'){
        setServoAngle(0, 2500);
        __delay_ms(Move_delay);
        if(mode != 7 && mode != 'h') return;
        setServoAngle(0, 1500);
        __delay_ms(Move_delay);
    }
}