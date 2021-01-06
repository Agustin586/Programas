#include "U8glib.h"//Librería para el control del display oled
#include <FreqCount.h>
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);// I2C / TWI // Se habilita esta linea según el display a usar en este caso el driver SH1106    
unsigned long count=0;
void setup() {
  Serial.begin(115200);//Velocidad del puerto serial(se puede cambiar según las necesidades)
  FreqCount.begin(1000);
}

void loop() {
  if (FreqCount.available()) {//Devuelve verdadero cuando hay una nueva medida disponible
    count = FreqCount.read();//Devuelve la medición más reciente, la medición se hace por defecto en el pin numero 5 del arduino
    Serial.println(count);//Imprime el valor de la frecuencia obtenida en el monitor serial
     u8g.firstPage();  
  do {
    draw();//Llama a la función draw
  } while( u8g.nextPage() );
  // Reconstruir la imagen después de un tiempo
  delay(50);
  }
}
void draw(void) {
  //Imprimimos en pantalla el valor de la frecuencia obtenida
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 20); 
  u8g.print("Freq:");
  u8g.print(count);
  u8g.print(" Herz");
}
