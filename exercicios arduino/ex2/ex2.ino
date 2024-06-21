
#include <SPI.h>
#include <RFID.h>
#define SDA_DIO 9
#define RESET_DIO 8
RFID RC522(SDA_DIO, RESET_DIO); 

// display
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// A função setup é executada uma vez quando forem pressionados os botões de reset ou de power on na placa
void setup()
{
  Serial.begin(9600);
  SPI.begin(); 
  RC522.init();

  lcd.begin(16, 2);
}

// A função loop é executada de forma repetida sem parada
void loop()
{
   if (RC522.isCard()){
    // Encontra o ID do cartão/tag
    RC522.readCardSerial();

    String idRFID = getID(RC522.serNum);
    Serial.print("ID: " + idRFID);

    lcd.clear();

    if(idRFID == "2315210760216"){
      lcd.setCursor(3, 0);
      lcd.print("Autorizado");    //Display LCD: Escreve no display a string "INF - IFRS"
    } else{
      lcd.setCursor(5, 0);
      lcd.print("Negado");    //Display LCD: Escreve no display a string "INF - IFRS"
    }
    lcd.setCursor(2, 1);        //Display LCD: Posiciona o cursor na coluna 3, linha 1
    lcd.print(idRFID);    //Display LCD: Escreve no display a string "DisplayLCD"
    delay(5000);
    
    lcd.clear();
    
  }
  delay(1000);

  
}

String getID(unsigned char serNum[5]) {
    String returnable = "";
    for(int i = 0; i < 5; i++) { // Impressão do ID do cartão/tag em decimal
      returnable += serNum[i];
    }
    return returnable;
}