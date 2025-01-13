
#include <xc.h> // include processor files - each processor file is guarded.  
#include<pic18f4520.h>

#define _XTAL_FREQ 4000000 
// TODO Insert appropriate #include <>
void I2C_Master_Init(unsigned long clock);

void I2C_Start();

void I2C_Stop();

void I2C_Write(unsigned char data);




