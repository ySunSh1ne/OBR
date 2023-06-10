// Definindo os pinos dos sensores LDR
const int ldrPin1 = A0;
const int ldrPin2 = A1;

// Definindo os pinos dos LEDs RGB
const int ledPin1Red = 9;
const int ledPin1Green = 10;
const int ledPin1Blue = 11;
const int ledPin2Red = 5;
const int ledPin2Green = 6;
const int ledPin2Blue = 7;

// Definindo variáveis para armazenar os valores dos sensores LDR
int ldrValue1 = 0;
int ldrValue2 = 0;

// Definindo variável para armazenar a cor do chão
int groundColor = 0;

// Função para calcular a média dos valores lidos pelo sensor LDR
float calculateAverage(int sensorPin) {
  int sum = 0;
  int readings = 10;  // número de leituras para a média
  
  for (int i = 0; i < readings; i++) {
    sum += analogRead(sensorPin);
    delay(10);
  }
  
  return (float)sum / readings;
}

// Função para desligar todos os LEDs
void turnOffLEDs() {
  digitalWrite(ledPin1Red, LOW);
  digitalWrite(ledPin1Green, LOW);
  digitalWrite(ledPin1Blue, LOW);
  digitalWrite(ledPin2Red, LOW);
  digitalWrite(ledPin2Green, LOW);
  digitalWrite(ledPin2Blue, LOW);
}

// Função para atualizar a cor do LED RGB 1
void updateLED1(int color) {
  turnOffLEDs();
  if (color == 0) {
    digitalWrite(ledPin1Red, HIGH);
  } else if (color == 1) {
    digitalWrite(ledPin1Green, HIGH);
  } else if (color == 2) {
    digitalWrite(ledPin1Blue, HIGH);
  }
}

// Função para atualizar a cor do LED RGB 2
void updateLED2(int color) {
  turnOffLEDs();
  if (color == 0) {
    digitalWrite(ledPin2Red, HIGH);
  } else if (color == 1) {
    digitalWrite(ledPin2Green, HIGH);
  } else if (color == 2) {
    digitalWrite(ledPin2Blue, HIGH);
  }
}

void setup() {
  // Configurando os pinos dos LEDs RGB como saída
  pinMode(ledPin1Red, OUTPUT);
  pinMode(ledPin1Green, OUTPUT);
  pinMode(ledPin1Blue, OUTPUT);
  pinMode(ledPin2Red, OUTPUT);
  pinMode(ledPin2Green, OUTPUT);
  pinMode(ledPin2Blue, OUTPUT);
  
  // Inicializando a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lendo os valores dos sensores LDR
  ldrValue1 = calculateAverage(ldrPin1);
  ldrValue2 = calculateAverage(ldrPin2);

  // Exibindo os valores lidos no monitor serial
  Serial.print("Sensor 1: ");
  Serial.print(ldrValue1);
  Serial.print("\tSensor 2: ");
  Serial.println(ldrValue2);
  
  // Verificando a cor do chão com base nos valores dos sensores LDR
  if (ldrValue1 > 500 && ldrValue2 > 500) {
    // Chão Branco
    groundColor = 2;
    updateLED1(2);  // Azul
    updateLED2(2);  // Azul
  } else if (ldrValue1 > 500 || ldrValue2 > 500) {
    // Chão Verde
    groundColor = 1;
    updateLED1(1);  // Verde
    updateLED2(1);  // Verde
  } else {
    // Chão Preto
    groundColor = 0;
    updateLED1(0);  // Vermelho
    updateLED2(0);  // Vermelho
  }
  
  // Exibindo a cor do chão no monitor serial
  Serial.print("Cor do Chão: ");
  if (groundColor == 2) {
    Serial.println("Branco");
  } else if (groundColor == 1) {
    Serial.println("Verde");
  } else {
    Serial.println("Preto");
  }
  
  delay(500);  // Aguarda 0,5 segundos antes de fazer a próxima leitura
}
