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
    
   // Leitura da humidade
    float humidade = dht.readHumidity();
   // Leitura da temperatura
   float temperatura = dht.readTemperature();
   // Leitura da luz
   int luz = analogRead(portaLDR);
    
    Serial.println(luz);
    Serial.println(temperatura);
    Serial.println(humidade);
    
    lcd.setCursor(0, 0);
    lcd.print("Luz:");
  
    lcd.setCursor(5, 0);
    lcd.print(luz);
         
    lcd.setCursor(9, 0);
    lcd.print("C:");
  
    lcd.setCursor(12, 0);
    lcd.print(temperatura);

    lcd.setCursor(0, 1);
    lcd.print("humidade:");
  
    lcd.setCursor(10, 1);
    lcd.print(humidade);
    
    delay(2000);
}
