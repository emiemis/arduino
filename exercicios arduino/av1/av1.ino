#include <PushButton.h>

// Inicialização do objeto do tipo PushButton e associação ao pino 2 (input)
PushButton diminuir(30);
PushButton aumentar(31);
int led = 9;  
int contador = 25;
int brightness = 100;

// A função setup é executada uma vez quando forem pressionados os botões de reset ou de power on na placa
void setup() {
 // Inicialização da comunicação serial (9600 bps)
 Serial.begin(9600);
 pinMode(led, OUTPUT);
}

// A função loop é executada de forma repetida sem parada
void loop() {
  if(diminuir.pressionadoPorPulso()){
    brightness = brightness - contador;
    if(brightness < 0){
      brightness = 0;
    }
  }

  if(aumentar.pressionadoPorPulso()){
    brightness = brightness + contador;
    if(brightness >250){
      brightness = 250;
    }
  }
   Serial.println(brightness);
   analogWrite(led, brightness);
   delay(50);
}
