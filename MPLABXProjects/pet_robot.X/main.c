#include <xc.h>
#include <pic18f4520.h>

#include"I2C.h"
#include"OLED.h"
#include"servo.h"
#include"bluetooth.h"
// ??? (??????????)
#pragma config OSC = INTIO67  // ?????
#pragma config WDT = OFF      // ?????
#pragma config PWRT = OFF       // Power-up Enable bit
#pragma config BOREN = ON       // Brown-out Reset Enable bit
#pragma config PBADEN = OFF     // Watchdog Timer Enable bit 
#pragma config LVP = OFF      // ???????
#pragma config CPD = OFF        // Data EEPROM?Memory Code Protection bit (Data EEPROM code protection off)

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000    // ???????? 1 MH
#endif
// ?? SH1106 OLED ? I²C ???7 ????????? 0x78?
#ifndef OLED_ADDRESS
#define OLED_ADDRESS 0x78
#endif
// I²C ?????????

// 0 : stand
// 1 : sit
// 2 : laydown
// 3 : walk
// 4 : back_walk
// 5 : turn right
// 6 : turn left
void Interupt0_Initialize(void){
    INTCONbits.INT0IF = 0;
    INTCONbits.GIE = 1;
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 = 1;
    ADCON1 = 0x0F;
}

void __interrupt(high_priority) H_ISR(void){
    /*
    if (INTCONbits.INT0IF) {
        LATA = 0x01;
        mode = (mode + 1) % 7;
        INTCONbits.INT0IF = 0;
        __delay_ms(2);
        LATA = 0x00;
    }
    */
    if(PIR1bits.RCIF){
        //int data = UART_Read();
        int data = RCREG;
        //mode = data;
        if('0' <= data && data <= '6' ){
            mode = data - '0';
        }
        
        if('a' <= data && data <= 'g'){
            mode = data;
        }
        if(data == 0) mode = 0;
        UART_Write(data);
//        if(data == '0'){
//            mode = 0;
//        }else if(data == 'a'){
//            mode = 3;
//        }
    }
}

void __interrupt(low_priority) L_ISR(void) {
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        TMR0H = 0xFE;
        TMR0L = 0x0C;

        pwmCounter += 500;

        if (pwmCounter < servoPulse[0]) SERVO1 = 1; else SERVO1 = 0;
        if (pwmCounter < servoPulse[1]) SERVO2 = 1; else SERVO2 = 0;
        if (pwmCounter < servoPulse[2]) SERVO3 = 1; else SERVO3 = 0;
        if (pwmCounter < servoPulse[3]) SERVO4 = 1; else SERVO4 = 0;

        if (pwmCounter >= 20000) pwmCounter = 0;
    }
}


// ???
void main() {
    //OSCCON = 0x60;                 // ???????? 1 MHz
    //I2C_Master_Init(100000);       // ??? I²C?????? 100 kHz
    //OLED_Init();                   // ??? OLED
    OSCCON = 0x60; //4MHZ osc
    Timer0_Initialize();
    //Interupt0_Initialize();
    TRISB= 0x01;
    TRISA = 0x00;
    LATA = 0;
    LATB = 0b00000000;
        UART_Init();
        I2C_Master_Init(400000);
        OLED_Init();
//    while(1){
//        UART_Read();
//        UART_Write('r');
//    }
    OLED_Display_Array(originalFaceData); 
    while(1){
        if(mode == 0 || mode == 'e'){
            OLED_Display_Array(originalFaceData); 
            while(mode==0 || mode == 'e'){
                setstand();
            }
            
        }else if(mode == 1 || mode == 'f'){
            
            OLED_Display_Array(happyFaceData); 
            while(mode==1 || mode == 'f'){
                setsit();
            }
                
            
        }else if(mode == 2 || mode == 'g'){
            setlaydown();
        }else if(mode == 3 || mode == 'a'){
            walk();
        }else if(mode == 4 || mode == 'c'){
            back_walk();
        }else if(mode == 5 || mode == 'b'){
            turn_right();
        }else if(mode == 6 || mode =='d'){
            turn_left();
        }
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