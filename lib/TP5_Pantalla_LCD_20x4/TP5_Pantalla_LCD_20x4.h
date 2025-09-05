<<<<<<< HEAD
#ifndef TP5_PANTALLA_LCD_20X4
#define TP5_PANTALLA_LCD_20X4
    void lcd_init();/*Inicializa el modulo adaptador LCD a I2C, esta función internamente configura e inicializa el
I2C y el LCD.*/
    void lcd_clear();/*Borra la pantalla LCD y posiciona el cursor en la esquina superior izquierda (posición (0,0)).*/
    void lcd_setCursor(int col, int row);/*Posiciona el cursor del LCD en la posición indicada por col y row(x,y); es
decir, establecer la ubicación en la que se mostrará posteriormente texto escrito para la pantalla LCD.*/
    void lcd_print(char *str);/*Escribe un texto o mensaje en el LCD, su uso es similar a un Serial.print*/
    void lcd_scrollDisplayLeft();/*Se desplaza el contenido de la pantalla (texto y el cursor) un espacio hacia la
izquierda.*/
    void lcd_scrollDisplayRight();/*Se desplaza el contenido de la pantalla (texto y el cursor) un espacio a la
derecha.*/
    void lcd_backlight();/*Enciende la Luz del Fondo del LCD.*/
    void lcd_noBacklight();/*Apaga la Luz del Fondo del LCD.*/
    void lcd_createChar(char posMem, char newChar[8]);/*Crea un carácter personalizado para su uso en la pantalla LCD. Se
admiten hasta ocho caracteres de 5x8 píxeles (numeradas del 0 al 7). Dónde: num es el número de
carácter y datos es una matriz que contienen los pixeles del carácter.*/
    void lcd_send(char datos, int rs_state);
    void lcd_comando(char cmd); // *adr = puntero (una variable que guarda la direccion de la memoria de otra variable)
    void lcd_car(char car);
#endif
=======
#ifndef TP5_PANTALLA_LCD_20X4
#define TP5_PANTALLA_LCD_20X4
    void lcd_init();/*Inicializa el modulo adaptador LCD a I2C, esta función internamente configura e inicializa el
I2C y el LCD.*/
    void lcd_clear();/*Borra la pantalla LCD y posiciona el cursor en la esquina superior izquierda (posición (0,0)).*/
    void lcd_setCursor(int col, int row);/*Posiciona el cursor del LCD en la posición indicada por col y row(x,y); es
decir, establecer la ubicación en la que se mostrará posteriormente texto escrito para la pantalla LCD.*/
    void lcd_print(char *str);/*Escribe un texto o mensaje en el LCD, su uso es similar a un Serial.print*/
    void lcd_scrollDisplayLeft();/*Se desplaza el contenido de la pantalla (texto y el cursor) un espacio hacia la
izquierda.*/
    void lcd_scrollDisplayRight();/*Se desplaza el contenido de la pantalla (texto y el cursor) un espacio a la
derecha.*/
    void lcd_backlight();/*Enciende la Luz del Fondo del LCD.*/
    void lcd_noBacklight();/*Apaga la Luz del Fondo del LCD.*/
    void lcd_createChar(char posMem, char newChar[8]);/*Crea un carácter personalizado para su uso en la pantalla LCD. Se
admiten hasta ocho caracteres de 5x8 píxeles (numeradas del 0 al 7). Dónde: num es el número de
carácter y datos es una matriz que contienen los pixeles del carácter.*/
    void lcd_send(char datos, int rs_state);
    void lcd_comando(char cmd); // *adr = puntero (una variable que guarda la direccion de la memoria de otra variable)
    void lcd_car(char car);
#endif
>>>>>>> 564e265487416abaeed5e738bf50f23860c78228
