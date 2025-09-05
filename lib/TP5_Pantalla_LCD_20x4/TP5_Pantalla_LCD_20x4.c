#include <stm32f103xb.h>
#include <TP5_PANTALLA_LCD_20X4.h>
#include <delay.h>
//PINES:
//{RS = 1, RW = 2, DB7 = 3, DB6 = 4, DB5 = 5, DB4 = 6, DB3 = 7, DB2 = 8, DB1 = 9, DB0 = 10};
int pines[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int Enable = 11;
int dir;
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
    GPIOA->BSRR |= (1 << Enable); //Inicio el pin de habilitacion en ON desde el principio
    GPIOA->BSRR |= (1 << pines[6]); //DL = 1: 8 bits, DL = 0: 4 bits
    GPIOA->BSRR |= (1 << pines[7]); //N = 1: 2 lineas, DL = 0: 1 lines
    GPIOA->BSRR |= (1 << (pines[8] + 16)); //F = 0: resolucion de 5 x 8, F = 1: resolucion de 5 x 10
    delay_ms(1);
}
void lcd_send(char datos, int rs_state){
    if(rs_state){
        //pines[0] = RS
        GPIOA->BSRR|=(1 << pines[0]);
    }else{
        GPIOA->BSRR|=(1 << (pines[0] + 16)); 
        GPIOA->BSRR|=(0x7F << (pines[10])); //pines[10] = DB0
        GPIOA->BSRR|=(datos << pines[10]);
    }
}
void lcd_comando(char cmd){
    lcd_send(cmd, 0); //si RS=1, manda un caracter
} 
void lcd_car(char car){
    lcd_send(car, 1); //si RS=0, manda un comando (punteros)
}
void lcd_print(char *str){
    while(str){
        lcd_car(*str++);//va avanzando en la posicion para poner cada caracter
    }
}
void lcd_clear(){
    /*Para limpiar el display, hay que setear todos los pines en 0 excepto por DB0*/
    for(int i = 1; i < 10; i++){
        GPIOA -> BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA -> BSRR |= (1 << pines[10]); 
    delay_ms(2);
}
void lcd_setCursor(int col, int row){
    int filas[4] = {0x80, 0xC0, 0x94, 0xD4};
    int pos = filas[row] + col;
    for(int i = 0; i < 5; i++){
        GPIOA-> BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA-> BSRR |= (1 << pines[6]);//DB4
    lcd_comando(pos);

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
    delay_ms(1);
}
void lcd_scrollDisplayRight(){
    for(int i = 0; i < 5; i++){
        GPIOA->BSRR |= (1 << (pines[i] + 16));
    }
    GPIOA->BSRR |= (1 << pines[6]);//DB4
    GPIOA->BSRR |= (1 << pines[7]);//DB3
    GPIOA->BSRR |= (1 << pines[8]);//DB2
    delay_ms(1);
}
void lcd_createChar(char posMem, char newChar[8]){
    lcd_comando(posMem*8+0x40);
    for(int i = 0; i < 8; i++){
        lcd_car(newChar[i]);
    }
    delay_ms(1);
}
