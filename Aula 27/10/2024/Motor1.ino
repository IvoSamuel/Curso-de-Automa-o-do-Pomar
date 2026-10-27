#include <Servo.h>

Servo meuServo;

const int botaoEsq = 5;     
const int botaoDir = 4;     
const int servoPin = 9;     

int angulo = 90; 

void setup() {
  pinMode(botaoEsq, INPUT_PULLUP);
  pinMode(botaoDir, INPUT_PULLUP);

  meuServo.attach(servoPin);
  delay(200); // Pequena pausa para estabilizar o servo ao iniciar
  meuServo.write(angulo); // Força a posição central (90°)
}

void loop() {
  bool estadoEsq = digitalRead(botaoEsq);
  bool estadoDir = digitalRead(botaoDir);

  if (estadoEsq == LOW && estadoDir == HIGH) {
    angulo = 20;              
    meuServo.write(angulo);
    delay(150);               
  }
  else if (estadoEsq == HIGH && estadoDir == LOW) {
    angulo = 160;             
    meuServo.write(angulo);
    delay(150);               
  }
  else {
    // Mantém parado se nenhum ou os dois forem premidos
  }
}