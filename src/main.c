#include<TP5_Pantalla_LCD_20x4.h>
#include<stm32f103xb.h>
#include<delay.h> 
char estrella[8] = {
    0b00000,
    0b00100,
    0b11111,
    0b01110,
    0b01110,
    0b11011,
    0b00000,
    0b00000,
};
char ohm[8] = {
    0b00000,
    0b00000,
    0b01110,
    0b10001,
    0b10001,
    0b01010,
    0b11011,
    0b00000,
};
int main(void){
    lcd_init();
    while(1){
        lcd_clear();
        lcd_setCursor(2, 2);    
        lcd_print("Hola mundo!");
        lcd_createChar(0, estrella);
        lcd_setCursor(18, 2); 
        lcd_comando(0);
        lcd_createChar(1, ohm);
        lcd_setCursor(19, 2); 
        lcd_comando(1);
        lcd_setCursor(2, 3);    
        lcd_print("Hello world!");
        lcd_setCursor(18, 3); 
        lcd_comando(1);
        lcd_setCursor(19, 3); 
        lcd_comando(0);
        delay_ms(1000);
        lcd_scrollDisplayLeft();
        delay_ms(1000);
        lcd_scrollDisplayRight();
        delay_ms(1000);
        lcd_noBacklight();
        delay_ms(1000);
        lcd_backlight;
        delay_ms(1000);
    }
    return 0;
}
