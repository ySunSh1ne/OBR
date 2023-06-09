#include <Arduino.h>

const int encoderPin = 2; // Pino do encoder
volatile int contadorPulsos = 0; // Variável do contador de pulsos

// Definição dos pinos dos motores
#define motorEsqFrente 11
#define motorEsqTras 12
#define motorDirFrente 14
#define motorDirTras 15

void contarPulso() {
  contadorPulsos++;
}

void mover(float pulsos, int forcaMotorEsq, int forcaMotorDir) {
  int contadorPulsos = 0; // Variável para contar os pulsos
  int limitePulsos = int(pulsos); // Converter o valor de pulsos para um inteiro
  
  // Definir a direção dos motores com base na força fornecida
  if (forcaMotorEsq > 0) {
    analogWrite(motorEsqFrente, forcaMotorEsq);
    analogWrite(motorEsqTras, 0);
  } else if (forcaMotorEsq == 0) {
    analogWrite(motorEsqFrente, 0);
    analogWrite(motorEsqTras, 0);
  } else {
    analogWrite(motorEsqFrente, 0);
    analogWrite(motorEsqTras, abs(forcaMotorEsq));
  }
  
  if (forcaMotorDir > 0) {
    analogWrite(motorDirFrente, forcaMotorDir);
    analogWrite(motorDirTras, 0);
  } else if (forcaMotorDir == 0) {
    analogWrite(motorDirFrente, 0);
    analogWrite(motorDirTras, 0);
  } else {
    analogWrite(motorDirFrente, 0);
    analogWrite(motorDirTras, abs(forcaMotorDir));
  }

  // Realizar os pulsos até atingir o limite desejado
  while (contadorPulsos < limitePulsos) {
    // Lógica para contar os pulsos
    // ...
    contadorPulsos++;
  }
  
  // Parar os motores após atingir o número de pulsos desejado
  analogWrite(motorEsqFrente, 0);
  analogWrite(motorEsqTras, 0);
  analogWrite(motorDirFrente, 0);
  analogWrite(motorDirTras, 0);
}

void setup() {
  pinMode(encoderPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPin), contarPulso, RISING);
  
  pinMode(motorEsqFrente, OUTPUT);
  pinMode(motorEsqTras, OUTPUT);
  pinMode(motorDirFrente, OUTPUT);
  pinMode(motorDirTras, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Realizar movimento de teste
  mover(100, 255, 255); // Mover para frente por 100 pulsos com força máxima
  
  // Exibir o contador de pulsos no monitor serial
  Serial.print("Contador de Pulsos: ");
  Serial.println(contadorPulsos);
  
  // Aguardar um curto período de tempo para evitar leituras muito rápidas
  delay(100);
}
