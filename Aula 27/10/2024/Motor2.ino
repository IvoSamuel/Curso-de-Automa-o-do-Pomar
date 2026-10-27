#include <Servo.h>

// Cria o objeto para o servomotor
Servo meuServo;

// Definição dos pinos dos botões e do servo
const int botaoEsq = 5;     // Botão esquerdo no pino 5[cite: 6]
const int botaoDir = 4;     // Botão direito no pino 4[cite: 6]
const int servoPin = 9;     // Sinal do servo no pino 9[cite: 6]

// Posição inicial do servo (centro, em 90 graus)
int angulo = 90; 

void setup() {
  // Configura os botões usando pull-up interno (pressionado = LOW)
  pinMode(botaoEsq, INPUT_PULLUP);
  pinMode(botaoDir, INPUT_PULLUP);

  // Anexa o servo ao pino correspondente
  meuServo.attach(servoPin);
  meuServo.write(angulo); // Inicia na posição central
}

void loop() {
  // Lê o estado dos botões
  bool estadoEsq = digitalRead(botaoEsq);
  bool estadoDir = digitalRead(botaoDir);

  // Se o botão esquerdo estiver a ser pressionado E o ângulo for maior que 0
  if (estadoEsq == LOW && estadoDir == HIGH) {
    if (angulo > 0) {
      angulo--;              // Diminui o ângulo gradualmente rumo ao mínimo (0°)
      meuServo.write(angulo);
      delay(15);             // Velocidade do movimento (quanto menor, mais rápido)
    }
  }
  
  // Se o botão direito estiver a ser pressionado E o ângulo for menor que 180
  else if (estadoEsq == HIGH && estadoDir == LOW) {
    if (angulo < 180) {
      angulo++;              // Aumenta o ângulo gradualmente rumo ao máximo (180°)
      meuServo.write(angulo);
      delay(15);             // Velocidade do movimento
    }
  }
}