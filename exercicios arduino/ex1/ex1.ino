#include <PushButton.h>

int led = 3;           // associar o pino 9 (PWM) ao LED
int brightness = 0.0;    // luminosidade do LED (8 bits - 0 a 255)
bool estado = false;
PushButton btn(2);

// A função setup é executada uma vez quando forem pressionados os botões de reset ou de power on na placa
void setup() {
  // Inicialização da comunicação serial (9600 bps)
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// A função loop é executada de forma repetida sem parada
void loop() {
  
  if(btn.pressionadoPorPulso()) {
    estado = !estado;
  }

  if(!estado){
    brightness = 0;
  } else {
    int sensorValue = analogRead(A0);
    brightness = (sensorValue*255.0)/1023.0;
  }
  
  analogWrite(led, brightness);
  delay(100);        // Delay entre leituras para estabilidade
}