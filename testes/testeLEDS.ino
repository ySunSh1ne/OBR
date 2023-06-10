// Pinos dos LEDs padrão
int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;
int ledPin5 = 6;

// Pinos dos LEDs RGB
int rgbLed1RedPin = 9;
int rgbLed1GreenPin = 10;
int rgbLed1BluePin = 11;
int rgbLed2RedPin = 12;
int rgbLed2GreenPin = 13;
int rgbLed2BluePin = A0;

// Variáveis para controlar as cores dos LEDs RGB
int rgbLed1RedValue = 0;
int rgbLed1GreenValue = 0;
int rgbLed1BlueValue = 0;
int rgbLed2RedValue = 0;
int rgbLed2GreenValue = 0;
int rgbLed2BlueValue = 0;

void setup() {
  // Define os pinos dos LEDs padrão como saída
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  // Define os pinos dos LEDs RGB como saída
  pinMode(rgbLed1RedPin, OUTPUT);
  pinMode(rgbLed1GreenPin, OUTPUT);
  pinMode(rgbLed1BluePin, OUTPUT);
  pinMode(rgbLed2RedPin, OUTPUT);
  pinMode(rgbLed2GreenPin, OUTPUT);
  pinMode(rgbLed2BluePin, OUTPUT);
}

void loop() {
  // Liga e desliga os LEDs padrão em sequência
  digitalWrite(ledPin1, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);

  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2, LOW);

  digitalWrite(ledPin3, HIGH);
  delay(500);
  digitalWrite(ledPin3, LOW);

  digitalWrite(ledPin4, HIGH);
  delay(500);
  digitalWrite(ledPin4, LOW);

  digitalWrite(ledPin5, HIGH);
  delay(500);
  digitalWrite(ledPin5, LOW);

  // Testa as cores dos LEDs RGB individualmente
  testRgbLed1Red();
  delay(1000);
  testRgbLed1Green();
  delay(1000);
  testRgbLed1Blue();
  delay(1000);
  testRgbLed2Red();
  delay(1000);
  testRgbLed2Green();
  delay(1000);
  testRgbLed2Blue();
  delay(1000);
}

// Função para testar a cor vermelha do LED RGB 1
void testRgbLed1Red() {
  // Desliga as outras cores
  analogWrite(rgbLed1GreenPin, 0);
  analogWrite(rgbLed1BluePin, 0);

  // Ajusta a intensidade da cor vermelha
  for (int i = 0; i <= 255; i++) {
    analogWrite(rgbLed1RedPin, i);
    delay(10);
  }
}

// Função para testar a cor verde do LED RGB 1
void testRgbLed1Green() {
  // Desliga as outras cores
  analogWrite(rgbLed1RedPin, 0);
  analogWrite(rgbLed1BluePin, 0);

  // Ajusta a intensidade da cor verde
  for (int i = 0; i <= 255; i++) {
    analogWrite(rgbLed1GreenPin, i);
    delay(10);
  }
}

// Função para testar a cor azul do LED RGB 1
void testRgbLed1Blue() {
  // Desliga as outras cores
  analogWrite(rgbLed1RedPin, 0);
  analogWrite(rgbLed1GreenPin, 0);

  // Ajusta a intensidade da cor azul
  for (int i = 0; i <= 255; i++) {
    analogWrite(rgbLed1BluePin, i);
    delay(10);
  }
}

// Função para testar a cor vermelha do LED RGB 2
void testRgbLed2Red() {
  // Desliga as outras cores
  analogWrite(rgbLed2GreenPin, 0);
  analogWrite(rgbLed2BluePin, 0);

  // Ajusta a intensidade da cor vermelha
  for (int i = 0; i <= 255; i++) {
    analogWrite(rgbLed2RedPin, i);
    delay(10);
  }
}

// Função para testar a cor verde do LED RGB 2
void testRgbLed2Green() {
  // Desliga as outras cores
  analogWrite(rgbLed2RedPin, 0);
  analogWrite(rgbLed2BluePin, 0);

  // Ajusta a intensidade da cor verde
  for (int i = 0; i <= 255; i++) {
    analogWrite(rgbLed2GreenPin, i);
    delay(10);
  }
}

// Função para testar a cor azul do LED RGB 2
void testRgbLed2Blue() {
  // Desliga as outras cores
  analogWrite(rgbLed2RedPin, 0);
  analogWrite(rgbLed2GreenPin, 0);

  // Ajusta a intensidade da cor azul
  for (int i = 0; i <= 255; i++) {
    analogWrite(rgbLed2BluePin, i);
    delay(10);
  }
}
