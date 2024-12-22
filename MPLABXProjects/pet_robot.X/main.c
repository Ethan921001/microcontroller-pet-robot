#include <xc.h>
#include <pic18f4520.h>

#include"I2C.h"
#include"OLED.h"
#include"servo.h"
// ??? (??????????)
#pragma config OSC = INTIO67  // ?????
#pragma config WDT = OFF      // ?????
#pragma config PWRT = OFF       // Power-up Enable bit
#pragma config BOREN = ON       // Brown-out Reset Enable bit
#pragma config PBADEN = OFF     // Watchdog Timer Enable bit 
#pragma config LVP = OFF      // ???????
#pragma config CPD = OFF        // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 1000000    // ???????? 1 MHz
#endif
// ?? SH1106 OLED ? I²C ???7 ????????? 0x78?
#ifndef OLED_ADDRESS
#define OLED_ADDRESS 0x78
#endif
// I²C ?????????
int mode = 0;
// 0 : stand
// 1 : sit
// 2 : laydown
// 3 : walk
// 4 : back_walk

void __interrupt(high_priority) H_ISR(void){
    
}

void __interrupt(low_priority) L_ISR(void) {
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        TMR0H = 0xFF;
        TMR0L = 193;

        pwmCounter += 500;

        if (pwmCounter <= servoPulse[0]) SERVO1 = 1; else SERVO1 = 0;
        if (pwmCounter <= servoPulse[1]) SERVO2 = 1; else SERVO2 = 0;
        if (pwmCounter <= servoPulse[2]) SERVO3 = 1; else SERVO3 = 0;
        if (pwmCounter <= servoPulse[3]) SERVO4 = 1; else SERVO4 = 0;

        if (pwmCounter >= 20000) pwmCounter = 0;
    }
}


// ???
void main() {
    //OSCCON = 0x60;                 // ???????? 1 MHz
    //I2C_Master_Init(100000);       // ??? I²C?????? 100 kHz
    //OLED_Init();                   // ??? OLED
    Timer0_Initialize();
    TRISB= 0x01;
    PORTB = 0b00000000;
    
    while(1){
        __delay_ms(100); 
        while(RB0 == 0b1){
            walk();
            //__delay_ms(50);
        }
        setsit();
        __delay_ms(100); 
        while(RB0 == 0b1);
    }
    
//    while (1) {
//        setstand();
//        OLED_Display_Look_Forward();      // ??????
//        __delay_ms(1000); 
//        
//        while(RB0 == 0b1); 
//        setsit();
//        OLED_Display_Look_Right();
//        __delay_ms(1000);          // ?? 1 ?
//        
//        while(RB0 == 0b1);
//        setstand();
//        OLED_Display_Look_Forward();
//        __delay_ms(1000); 
//        
//        while(RB0 == 0b1);
//        setlaydown();
//        OLED_Display_Look_Left();
//        __delay_ms(1000); 
//        
//        while(RB0 == 0b1);
//        setsit();
//        OLED_Display_Array(originFaceData);
//        __delay_ms(1000);
//        
//        while(RB0 == 0b1);
//    }
}