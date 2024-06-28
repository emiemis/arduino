// display
#include <Servo.h>
Servo myservo;

#include <Ultrasonic.h>

Ultrasonic ultrassom(8,7); //Inicializa o objeto para manipulação do sensor ultrassônico
long distance;


void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  distance = ultrassom.Ranging(CM);
  Serial.print(distance);
  Serial.println("cm");
  if(distance < 5){
    myservo.write(90);
    delay(5000);
  }
  myservo.write(0);
  delay(1000);  
}
