#include <pic18f4520.h>
#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000    // ???????? 1 MHz
#endif


void UART_Init(void);

// ????
void UART_Write(char data);

// ????
char UART_Read(void);
