
#include <SPI.h>
#include <RFID.h>
#define SDA_DIO 9
#define RESET_DIO 8
RFID RC522(SDA_DIO, RESET_DIO); 

// display
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// buzzer
int buzzer = 7;

// led verde
int ledverde = 13;

// led vermelho
int ledvermelho = 40;

// A função setup é executada uma vez quando forem pressionados os botões de reset ou de power on na placa
void setup()
{
  Serial.begin(9600);
  SPI.begin(); 
  RC522.init();

  lcd.begin(16, 2);
  
  pinMode(buzzer,OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
}

// A função loop é executada de forma repetida sem parada
void loop()
{
   if (RC522.isCard()){
    // Encontra o ID do cartão/tag
    RC522.readCardSerial();

    String idRFID = getID(RC522.serNum);
    Serial.println("ID: " + idRFID);

    lcd.clear();

    if(idRFID == "25101952735"){
      digitalWrite(ledverde, HIGH);         // Liga o LED  (HIGH é o nível alto de tensão)
      
      lcd.setCursor(3, 0);
      lcd.print("Autorizado");    //Display LCD: Escreve no display a string "INF - IFRS"

      tocaPermitido();

    } else{
      digitalWrite(ledvermelho, HIGH);         // Liga o LED  (HIGH é o nível alto de tensão)
      lcd.setCursor(5, 0);
      lcd.print("Negado");    //Display LCD: Escreve no display a string "INF - IFRS"

      tocaNegado();
    }
    lcd.setCursor(2, 1);        //Display LCD: Posiciona o cursor na coluna 3, linha 1
    lcd.print(idRFID);    //Display LCD: Escreve no display a string "DisplayLCD"
    delay(3000);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledvermelho, LOW);
    lcd.clear();
    
  }
}

String getID(unsigned char serNum[5]) {
    String returnable = "";
    for(int i = 0; i < 5; i++) { // Impressão do ID do cartão/tag em decimal
      returnable += serNum[i];
    }
    return returnable;
}

 
String tocaPermitido() {
 tone(buzzer, 523);  // Nota C5
  delay(150);
  noTone(buzzer);
  delay(150);
  tone(buzzer, 659);  // Nota E5
  delay(150);
  noTone(buzzer);
  delay(150);
  tone(buzzer, 784);  // Nota G5
  delay(300);
  noTone(buzzer);

  // Toca a segunda parte da melodia (Acesso Permitido)
  delay(200);  // Pausa entre as partes
  tone(buzzer, 784);  // Nota G5
  delay(150);
  noTone(buzzer);
  delay(150);
  tone(buzzer, 659);  // Nota E5
  delay(150);
  noTone(buzzer);
  delay(150);
  tone(buzzer, 523);  // Nota C5
  delay(300);
  noTone(buzzer);
}


String tocaNegado() {
    tone(buzzer, 110);
    delay(200);
    noTone(buzzer);
    
    // Toca a segunda nota (165 Hz) por 200 milissegundos
    tone(buzzer, 165);
    delay(200);
    noTone(buzzer);
    
    // Toca a terceira nota (220 Hz) por 400 milissegundos
    tone(buzzer, 220);
    delay(400);
    noTone(buzzer);
    
    // Toca a quarta nota (165 Hz) por 200 milissegundos
    tone(buzzer, 165);
    delay(200);
    noTone(buzzer);
    
    // Toca a quinta nota (110 Hz) por 600 milissegundos
    tone(buzzer, 110);
    delay(600);
    noTone(buzzer);
 
}
