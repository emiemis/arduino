// display
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// coiso lá
int portaLDR = A0;

#include "DHT.h"

#define DHTPIN 8     // Pino digital conectado ao sensor DHT11
#define DHTTYPE DHT11   // Tipo de sensor: DHT 11

DHT dht(DHTPIN, DHTTYPE);

// A função setup é executada uma vez quando forem pressionados os botões de reset ou de power on na placa
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);  
  dht.begin();
}

// A função loop é executada de forma repetida sem parada
void loop() {

   lcd.clear();

   // luz
   int luminosity = analogRead(portaLDR);
   Serial.println(luminosity);

   // humildade
   float humidade = dht.readHumidity();
   Serial.println(humidade);
  
   // calor
   float temperatura = dht.readTemperature();
   Serial.println(temperatura);

    
    lcd.setCursor(0, 0);
    lcd.print("Luz:");
  
    lcd.setCursor(5, 0);
    lcd.print(luminosity);
         
    lcd.setCursor(0, 1);
    lcd.print("calor:");
  
    lcd.setCursor(7, 1);
    lcd.print(temperatura);
    
    lcd.setCursor(0, 2);
    lcd.print("humildade:");
  
    lcd.setCursor(11, 2);
    lcd.print(humidade);

    delay(2000);

 
}
