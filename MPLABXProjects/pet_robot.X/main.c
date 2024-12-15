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
/*
void I2C_Master_Init(unsigned long clock) {
    SSPCON1 = 0b00101000; // I²C ???
    SSPCON2 = 0x00;      // ?? SSPCON2
    SSPADD = (_XTAL_FREQ / (4 * clock)) - 1; // ?????
    SSPSTAT = 0x00;      // ?? SSPSTAT
    TRISC3 = 1;          // SCL ???
    TRISC4 = 1;          // SDA ???
}

// ??????
void I2C_Start() {
    SEN = 1;             // ?? SEN ????????
    while (SEN);         // ????????
}

// ??????
void I2C_Stop() {
    PEN = 1;             // ?? PEN ????????
    while (PEN);         // ????????
}

// ??????
void I2C_Write(unsigned char data) {
    SSPBUF = data;       // ????? SSPBUF
    while (BF);          // ???????
    while (SSPCON2 & 0x1F); // ?? ACK/NACK ????
}

// ?? OLED ??
void OLED_Command(unsigned char cmd) {
    I2C_Start();                   // ??????
    I2C_Write(OLED_ADDRESS);       // ???????????
    I2C_Write(0x00);               // ?????? (0x00 ????)
    I2C_Write(cmd);                // ????
    I2C_Stop();                    // ??????
}

// ??? OLED ??
void OLED_Init() {
    __delay_ms(100);               // ?? OLED ??
    OLED_Command(0xAE);            // ????
    OLED_Command(0xD5);            // ?????????/????
    OLED_Command(0x80);            // ???
    OLED_Command(0xA8);            // ???????
    OLED_Command(0x3F);            // 1/64 ???
    OLED_Command(0xD3);            // ??????
    OLED_Command(0x00);            // ???
    OLED_Command(0x40);            // ???????
    OLED_Command(0x8D);            // ?????
    OLED_Command(0x14);            // ?????
    OLED_Command(0x20);            // ????????
    OLED_Command(0x00);            // ??????
    OLED_Command(0xA1);            // ??????
    OLED_Command(0xC8);            // ????????????
    OLED_Command(0xDA);            // ?? COM ??????
    OLED_Command(0x12);            // ???
    OLED_Command(0x81);            // ?????
    OLED_Command(0x7F);            // ????
    OLED_Command(0xD9);            // ???????
    OLED_Command(0xF1);            // ???
    OLED_Command(0xDB);            // ?? VCOMH ????
    OLED_Command(0x40);            // ???
    OLED_Command(0xA4);            // ??????
    OLED_Command(0xA6);            // ???????????
    OLED_Command(0xAF);            // ????
}

// ? OLED ????
void OLED_Data(unsigned char data) {
    I2C_Start();                   // ??????
    I2C_Write(OLED_ADDRESS);       // ???????????
    I2C_Write(0x40);               // ?????? (0x40 ????)
    I2C_Write(data);               // ????
    I2C_Stop();                    // ??????
}

// ??????
void OLED_Display_Look_Forward() {
    for (unsigned char page = 0; page < 8; page++) {
        OLED_Command(0xB0 + page); // ?????
        OLED_Command(0x00);       // ??????
        OLED_Command(0x10);       // ??????
        for (unsigned char col = 0; col < 132; col++) {
            if (page >= 2  && page <= 6 && ((col>=30 && col<=50) || (col>=80 && col<=100))) {
                OLED_Data(0xFF);  // ??????????
            } else {
                OLED_Data(0x00);  // ??
            }
        }
    }
}

void OLED_Display_Look_Right() {
    for (unsigned char page = 0; page < 8; page++) {
        OLED_Command(0xB0 + page); // ?????
        OLED_Command(0x00);       // ??????
        OLED_Command(0x10);       // ??????
        for (unsigned char col = 0; col < 132; col++) {
            if (page >= 2  && page <= 6 && ((col>=50 && col<=70) || (col>=100 && col<=120))) {
                OLED_Data(0xFF);  // ??????????
            } else {
                OLED_Data(0x00);  // ??
            }
        }
    }
}

void OLED_Display_Look_Left() {
    for (unsigned char page = 0; page < 8; page++) {
        OLED_Command(0xB0 + page); // ?????
        OLED_Command(0x00);       // ??????
        OLED_Command(0x10);       // ??????
        for (unsigned char col = 0; col < 132; col++) {
            if (page >= 2  && page <= 6 && ((col>=10 && col<=30) || (col>=60 && col<=80))) {
                OLED_Data(0xFF);  // ??????????
            } else {
                OLED_Data(0x00);  // ??
            }
        }
    }
}
*/
void __interrupt() ISR(void) {
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