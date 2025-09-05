#include <stm32f103xb.h>
#include <TP5_PANTALLA_LCD_20X4.h>
//PINES:
//{RS = 1, RW = 2, DB7 = 3, DB6 = 4, DB5 = 5, DB4 = 6, DB3 = 7, DB2 = 8, DB1 = 9, DB0 = 10};
int pines[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int Enable = 11;
int dir;
void LCD_I2C(int lcd_Addr, int lcd_cols, int lcd_rows){

}
//INICIALIZACION DE PINES
void lcd_init(){
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    for(int i = 0; i < 11; i++){
        if(i <= 7){
            GPIOA -> CRL &= ~(0xF << (i * 4));
            GPIOA -> CRL |= (0b0100 << (i * 4));
        }else if(i >= 11){
            GPIOA -> CRH &= ~(0xF << (i * 4));
            GPIOA -> CRH |= (0b0100 << (i * 4));
        }
    }
    GPIOA->BSRR |= (1 << (Enable * 4)); //Inicio el pin de habilitacion en ON desde el principio
}
void lcd_clear(){
    /*Para limpiar el display, hay que setear todos los pines en 0 excepto por DB0*/
    for(int i = 1; i < 10; i++){
        GPIOA -> BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA -> BSRR |= (1 << pines[10]); 
}
void lcd_setCursor(int col, int row){
    for(int i = 0; i < 5; i++){
        GPIOA-> BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA-> BSRR |= (1 << pines[6]);//DB4
    switch (row){
        case 0: //fila 0
            dir = 0x80 + col;
        break;
        case 1: //fila 1
            dir = 0xC0 + col;
        break;
        case 2: //fila 2
            dir = 0x94 + col;
        break;
        case 3: //fila 3
            dir = + col;
        break;
        //debo retornar "dir" al display para que el cursor tome la posicion ingresada
    }
}
void lcd_print(){

}
void lcd_backlight(){
    for(int i = 0; i < 6; i++){
        GPIOA-> BSRR |= (1 << (pines[i] + 16));
    }
    for(int i = 7; i > 10; i++){
        GPIOA-> BSRR |= (1 << pines[i]);//Prendo pin DB3, DB2, DB1 y DB0
    }
}
void lcd_noBacklight(){
    for(int i = 0; i > 6; i++){
        GPIOA-> BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA-> BSRR |= (1 << pines[7]);//Prendo pin DB3
    for(int i = 8; i < 10; i++){
        GPIOA-> BSRR |= (1 << (pines[i] + 16));//Apago DB0, DB1 y DB2
    }
}
void lcd_scrollDisplayLeft(){
    for(int i = 0; i < 5; i++){
        GPIOA->BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA->BSRR |= (1 << pines[6]);//DB4
    GPIOA->BSRR |= (1 << pines[7]);//DB3
    GPIOA->BSRR |= (1 << (pines[8] + 16));//DB2
}
void lcd_scrollDisplayRight(){
    for(int i = 0; i < 5; i++){
        GPIOA->BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA->BSRR |= (1 << pines[6]);//DB4
    GPIOA->BSRR |= (1 << pines[7]);//DB3
    GPIOA->BSRR |= (1 << pines[8]);//DB2
}
void lcd_createChar(int num, int datos){

}
