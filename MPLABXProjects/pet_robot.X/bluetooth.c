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
    
    if('0'<=RCREG && RCREG<='9'){
        LATB = RCREG-48;
        //LATC = RCREG;
    }
    
    if(RCREG == 'a'){
        LATB = 0;
    }
    else if(RCREG == 'b'){
        LATB = 7;
    }
    UART_Write(RCREG);
    return RCREG;
}
