#include "bluetooth.h"


void UART_Init(void) {
    TRISC6 = 1;  // TX ???????
    TRISC7 = 1;  // RX ???????
    
    
    RCSTAbits.SPEN = 1;  // ????
    TXSTAbits.TXEN = 1;  // ????
    RCSTAbits.CREN = 1;  // ????
    PIR1bits.TXIF = 1;
    PIR1bits.RCIF = 1;
    
    TXSTAbits.SYNC = 0;   
    TXSTAbits.BRGH = 1;  // ???????
    BAUDCONbits.BRG16 = 1;  
    SPBRG = 25;  // ??? 9600??? FOSC=1MHz
//    
    PIE1bits.RCIE = 1;
    IPR1bits.RCIP = 1;
}

// ????
void UART_Write(char data) {
    while (!TXSTAbits.TRMT);  // ?????????
    TXREG = data;
}

// ????
char UART_Read(void) {
    while (!PIR1bits.RCIF);  // ????????
    
    if (RCREG == '\r')
            UART_Write('\n');
    
    UART_Write(RCREG);
    return RCREG;
}
