#include"I2C.h"


void I2C_Master_Init(unsigned long clock) {
    SSPCON1 = 0b00101000; 
    SSPCON2 = 0x00;      
    SSPADD = (_XTAL_FREQ / (4 * clock)) - 1; 
    SSPSTAT = 0x00;      
    TRISC3 = 1;          
    TRISC4 = 1;          
}


void I2C_Start() {
    SEN = 1;             
    while (SEN);         
}

void I2C_Stop() {
    PEN = 1;             
    while (PEN);        
}

void I2C_Write(unsigned char data) {
    SSPBUF = data;      
    while (BF);          
    while (SSPCON2 & 0x1F); 
}