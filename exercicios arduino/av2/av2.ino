#include <PushButton.h>

// sensor luz
int portaLDR = A0;

// buzzer
int buzzer = 8;

// leds
int verde = 12;  
int amarelo = 11;  
int vermelho = 10;  
int brightness = 0;

// A função setup é executada uma vez quando forem pressionados os botões de reset ou de power on na placa
void setup() {
 // Inicialização da comunicação serial (9600 bps)
 Serial.begin(9600);
 
 pinMode(verde, OUTPUT);
 pinMode(amarelo, OUTPUT);
 pinMode(vermelho, OUTPUT);
 
 pinMode(buzzer,OUTPUT);   
}

// A função loop é executada de forma repetida sem parada
void loop() {
   brightness = analogRead(portaLDR);
   Serial.println(brightness);
   

   // brightness < 70 : acende os 3 leds
   if (brightness < 70){
      analogWrite(verde, 255);
      analogWrite(amarelo, 255);
      analogWrite(vermelho, 255);
      // brightness < 40 : ativa o buzzer
      if (brightness < 40){
         tone(buzzer,261);   
         delay(200);
         noTone(buzzer);
      }
   // brightness < 200 : acende os 2 leds
   } else if (brightness < 200){
     analogWrite(amarelo, 255);
     analogWrite(vermelho, 255);
    
   // brightness >= 200 : acende o 1 led
   } else if (brightness >= 200){
     analogWrite(vermelho, 255);
   }

   delay (100);
   
      analogWrite(verde, 0);
      analogWrite(amarelo, 0);
      analogWrite(vermelho, 0);
}
