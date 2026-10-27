// Definição dos pinos do Sensor HC-SR04
const int trigPin = 7;
const int echoPin = 6;

// Definição dos pinos dos LEDs
const int ledRed = 10;
const int ledYellow = 9;
const int ledGreen = 8;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Configura os pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  // 1. Garante o TRIG limpo em LOW (conforme datasheet)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // 2. Dispara o pulso TRIG em HIGH por exatos 10 microssegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. Lê o tempo de eco com timeout de segurança (30ms = 30000us)
  unsigned long duration = pulseIn(echoPin, HIGH, 30000);

  // 4. Verifica se houve retorno válido
  if (duration == 0) {
    Serial.println("Fora de alcance (0)");
    // Acende apenas o LED verde indicando espaço livre
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
  } else {
    // 5. Cálculo oficial da distância em centímetros (Velocidade do som = 0.0343 cm/us / 2)
    float distance = (duration * 0.0343) / 2.0;

    // Exibe no Monitor Serial
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");

    // 6. Controle dos LEDs baseado na distância medida
    if (distance > 0 && distance < 10) {
      // Menor que 10 cm: LED Vermelho aceso (Alerta)
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, LOW);
    } 
    else if (distance >= 10 && distance < 25) {
      // Entre 10 cm e 25 cm: LED Amarelo aceso (Atenção)
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledGreen, LOW);
    } 
    else {
      // Maior ou igual a 25 cm: LED Verde aceso (Seguro)
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, HIGH);
    }
  }

  // 7. Intervalo recomendado pelo datasheet (> 60ms) para evitar eco residual
  delay(100);
}