#ifndef TP5_PANTALLA_LCD_20X4
#define TP5_PANTALLA_LCD_20X4
    void LCD_I2C(int lcd_Addr, int lcd_cols, int lcd_rows); /*Función constructor, crea un objeto de la clase
LiquidCrystal_I2C, con dirección, columnas y filas indicadas. Donde lcd_Addr va a ser 0x27.*/
    void lcd_init();/*Inicializa el modulo adaptador LCD a I2C, esta función internamente configura e inicializa el
I2C y el LCD.*/
    void lcd_clear();/*Borra la pantalla LCD y posiciona el cursor en la esquina superior izquierda (posición (0,0)).*/
    void lcd_setCursor(int col, int row);/*Posiciona el cursor del LCD en la posición indicada por col y row(x,y); es
decir, establecer la ubicación en la que se mostrará posteriormente texto escrito para la pantalla LCD.*/
    void lcd_print();/*Escribe un texto o mensaje en el LCD, su uso es similar a un Serial.print*/
    void lcd_scrollDisplayLeft();/*Se desplaza el contenido de la pantalla (texto y el cursor) un espacio hacia la
izquierda.*/
    void lcd_scrollDisplayRight();/*Se desplaza el contenido de la pantalla (texto y el cursor) un espacio a la
derecha.*/
    void lcd_backlight();/*Enciende la Luz del Fondo del LCD.*/
    void lcd_noBacklight();/*Apaga la Luz del Fondo del LCD.*/
    void lcd_createChar(int num, int datos);/*Crea un carácter personalizado para su uso en la pantalla LCD. Se
admiten hasta ocho caracteres de 5x8 píxeles (numeradas del 0 al 7). Dónde: num es el número de
carácter y datos es una matriz que contienen los pixeles del carácter.*/
#endif
