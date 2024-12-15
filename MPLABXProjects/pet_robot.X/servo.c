#include "servo.h"

void Timer0_Initialize(void) {
    T0CON = 0x88;       // ?? Timer0
    TMR0H = 0xFF;       // ????50µs?
    TMR0L = 193;
    INTCONbits.TMR0IE = 1; // ?? Timer0 ??
    INTCONbits.GIE = 1;    // ??????
    INTCONbits.PEIE = 1;   // ??????
}

//void __interrupt() ISR(void) {
//    if (INTCONbits.TMR0IF) {
//        INTCONbits.TMR0IF = 0;
//        TMR0H = 0xFF;
//        TMR0L = 0x193;
//
//        pwmCounter += 500;
//
//        if (pwmCounter <= servoPulse[0]) SERVO1 = 1; else SERVO1 = 0;
//        if (pwmCounter <= servoPulse[1]) SERVO2 = 1; else SERVO2 = 0;
//        if (pwmCounter <= servoPulse[2]) SERVO3 = 1; else SERVO3 = 0;
//        if (pwmCounter <= servoPulse[3]) SERVO4 = 1; else SERVO4 = 0;
//
//        if (pwmCounter >= 20000) pwmCounter = 0;
//    }
//}

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
        __delay_ms(60);
        // 2
        setServoAngle(0, 2000);
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);  
        setServoAngle(3, 1005);
        __delay_ms(60);
        // 3
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);
        setServoAngle(3, 1500);  
        __delay_ms(60);
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(60);
        // 5
        setServoAngle(0, 1500);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(60);
        // 6
        setServoAngle(0, 1005);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 2000);  
        __delay_ms(60);
        // 7
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 2000);  
        __delay_ms(60);
        // 8
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(60);
}
void back_walk(){
    // 1
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(250);
        // 2
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 2000);  
        __delay_ms(250);
        // 3
        setServoAngle(0, 1005);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 2000);  
        __delay_ms(250);
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1005);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(250);
        // 5
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(250);
        // 6
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);
        setServoAngle(3, 1500);  
        __delay_ms(250);
        // 7
       setServoAngle(0, 2000);
        setServoAngle(1, 2000);
        setServoAngle(2, 1005);  
        setServoAngle(3, 1005);
        __delay_ms(250);
        // 8
        setServoAngle(0, 2000);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1005);  
        __delay_ms(250);
}
void turn_right(){
            // 1
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1005);  
        __delay_ms(250);
        // 2
        setServoAngle(0, 1005);
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);  
        setServoAngle(3, 1005);
        __delay_ms(250);
        // 3
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(250);
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(250);
}

void turn_left(){
        // 1
        setServoAngle(0, 1500);  
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);
        setServoAngle(3, 1500);  
        __delay_ms(250);
        // 2
        setServoAngle(0, 1005);
        setServoAngle(1, 2000);
        setServoAngle(2, 2000);  
        setServoAngle(3, 1005);
        __delay_ms(250);
        // 3
        setServoAngle(0, 1005);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1005);  
        __delay_ms(250);
        // 4
        setServoAngle(0, 1500);  
        setServoAngle(1, 1500);
        setServoAngle(2, 1500);
        setServoAngle(3, 1500);  
        __delay_ms(250);
}
//void main(void) {
//    // 0-> right front leg
//    // 1 -> left front leg
//    // 2 -> right back leg
//    // 3 -> left back leg
//    TRISB = 0x01;
//    LATB = 0x00;  
//    Timer0_Init();
//
//    while (1) {
//        setstand();
////        while(1){
////            if((RB0 == 0b0)) break;
////            walk();
////        }
////        setstand();
//                __delay_ms(400);
//        while(1){
//            if((RB0 == 0b0)) break;
//                   turn_right();
//        }
//                      __delay_ms(400);
////        while(RB0 == 0b1);
////        setstand();
////        __delay_ms(400);
////        
////        while(RB0 == 0b1);
////        setlaydown();
////        __delay_ms(400);
////        
////               while(RB0 == 0b1);
////        setstand();
////        __delay_ms(400);
////        
////        while(RB0 == 0b1);
////        setsit();
////        __delay_ms(400);
//    }
//}