#include"OLED.h"

void OLED_Command(unsigned char cmd) {
    I2C_Start();                   
    I2C_Write(OLED_ADDRESS);       
    I2C_Write(0x00);               
    I2C_Write(cmd);                
    I2C_Stop();                    
}


void OLED_Init() {
    __delay_ms(100);               
    OLED_Command(0xAE);            
    __delay_us(50);
    OLED_Command(0xD5);            // ?????????/????
    __delay_us(50);
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
    I2C_Start();                   
    I2C_Write(OLED_ADDRESS);       
    I2C_Write(0x40);               
    I2C_Write(data);               
    I2C_Stop();                    
}

/*
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
 */


void OLED_Display_Look_Forward() {
    
    I2C_Start();                   
    I2C_Write(OLED_ADDRESS);       
    I2C_Write(0x40);  
    for (unsigned char page = 0; page < 8; page++) {
        OLED_Command(0xB0 + page); // ?????
        OLED_Command(0x00);       // ??????
        OLED_Command(0x10);       // ??????
        
        
        I2C_Start();                   
        I2C_Write(OLED_ADDRESS);       
        I2C_Write(0x40);  
        for (unsigned char col = 0; col < 128; col++) {
            
            if (page >= 2  && page <= 6 && ((col>=30 && col<=50) || (col>=80 && col<=100))) {
                I2C_Write(0xFF);  // ??????????
            } else {
                I2C_Write(0x00); // ??
            }
        }
        I2C_Stop();  
        
    }
}



void OLED_Display_Look_Right() {
    for (unsigned char page = 0; page < 8; page++) {
        OLED_Command(0xB0 + page); // ?????
        OLED_Command(0x00);       // ??????
        OLED_Command(0x10);       // ??????
        for (unsigned char col = 0; col < 128; col++) {
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
        for (unsigned char col = 0; col < 128; col++) {
            if (page >= 2  && page <= 6 && ((col>=10 && col<=30) || (col>=60 && col<=80))) {
                OLED_Data(0xFF);  // ??????????
            } else {
                OLED_Data(0x00);  // ??
            }
        }
    }
}

void OLED_Display_Array(const uint8_t data[]) {
    for (unsigned char page = 0; page < 8; page++) {
        /*
        I2C_Start();                   
        I2C_Write(OLED_ADDRESS);       
        I2C_Write(0x00);               
        I2C_Write(0xB0 + page); 
        I2C_Write(0x00); 
        I2C_Write(0x10); 
        I2C_Stop();    
        */
        OLED_Command(0xB0 + page);
        OLED_Command(0x00);
        OLED_Command(0x10);
//        I2C_Start();                   
//        I2C_Write(OLED_ADDRESS);       
//        I2C_Write(0x40); 
        
        for (unsigned char col = 0; col < 128; col++) {
            
                OLED_Data(data[page*128+col]);  // ??????????
                //I2C_Write(data[page*128+col]);
            
        }
        __delay_us(50);
        //I2C_Stop(); 
    }
}