#include <xc.h> // include processor files - each processor file is guarded.  
#include<pic18f4520.h>
#include"I2C.h"

#ifndef OLED_ADDRESS
#define OLED_ADDRESS 0x78
#endif

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 1000000    // ???????? 1 MHz
#endif

void OLED_Command(unsigned char cmd);

// ??? OLED ??
void OLED_Init();

// ? OLED ????
void OLED_Data(unsigned char data);

// ??????
void OLED_Display_Look_Forward();

void OLED_Display_Look_Right();

void OLED_Display_Look_Left();