#include"I2C.h"


void I2C_Master_Init(unsigned long clock) {
    SSPCON1 = 0b00101000; // I�C ???
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