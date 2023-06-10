#include <Arduino.h>
#include <AFMotor.h>
#include <Config.h>
//Funçoes de Ação

// Função para mover os motores para frente
void moverParaFrente(int velocidade) {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(velocidade);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  Serial.println("Movendo para frente");
}

// Função para mover os motores para trás
void moverParaTras(int velocidade) {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(velocidade);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  Serial.println("Movendo para trás");
}

// Função para fazer um pequeno movimento para a direita
void moverDireita(int velocidade) {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(0);
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  Serial.println("Movimento para a direita");
}

// Função para fazer um pequeno movimento para a esquerda
void moverEsquerda(int velocidade) {
  motor1.setSpeed(0);
  motor2.setSpeed(velocidade);
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  Serial.println("Movimento para a esquerda");
}

// Função para parar os motores
void pararMotores() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  Serial.println("Motores parados");
}

void curva90Esquerda(int velocidade) {
  motor1.write(0);  // Define a velocidade do motor1 como 0 (desligado)
  motor2.write(velocidade);  // Define a velocidade do motor2 como a velocidade fornecida
  delay(500);  // Aguarda meio segundo para iniciar a curva
  pararMotores();  // Para os motores após a curva
  delay(500);  // Aguarda meio segundo antes de continuar o movimento
  moverParaFrente(velocidade);  // Move para frente após a curva
}

void curva90Direita(int velocidade) {
  motor1.write(velocidade);  // Define a velocidade do motor1 como a velocidade fornecida
  motor2.write(0);  // Define a velocidade do motor2 como 0 (desligado)
  delay(500);  // Aguarda meio segundo para iniciar a curva
  pararMotores();  // Para os motores após a curva
  delay(500);  // Aguarda meio segundo antes de continuar o movimento
  moverParaFrente(velocidade);  // Move para frente após a curva
}

void curvaDireita45(int velocidade) {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(0);
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  delay(250);  // Aguarda um quarto de segundo para iniciar a curva
  pararMotores();  // Para os motores após a curva
  delay(250);  // Aguarda um quarto de segundo antes de continuar o movimento
  moverParaFrente(velocidade);  // Move para frente após a curva
}

void curvaDireita45(int velocidade) {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(0);
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  delay(250);  // Aguarda um quarto de segundo para iniciar a curva
  pararMotores();  // Para os motores após a curva
  delay(250);  // Aguarda um quarto de segundo antes de continuar o movimento
  moverParaFrente(velocidade);  // Move para frente após a curva
}

void curva180(int velocidade) {
  curvaDireita(velocidade);  // Faz a curva de 90 graus à direita
  delay(500);  // Aguarda meio segundo antes de iniciar a segunda curva
  curvaEsquerda(velocidade);  // Faz a curva de 90 graus à esquerda
}

void desviarObstaculo() {
  moverParaTras(forca_Baixa);  // Move para trás com uma velocidade reduzida
  delay(500);  // Aguarda meio segundo para recuar
  pararMotores();  // Para os motores
  delay(500);  // Aguarda meio segundo antes de iniciar o desvio
  curvaEsquerda(forca_Curva);  // Faz uma curva à esquerda com velocidade alta
  delay(1000);  // Aguarda um segundo para completar a curva
}

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

void verificarVerde1() {
  // Lendo os valores dos sensores LDR
  ldrValue1 = calculateAverage(ldrPin1);

  // Exibindo os valores lidos no monitor serial
  Serial.print("Sensor 1: ");
  Serial.print(ldrValue1);
  
  // Verificando a cor do chão com base nos valores dos sensores LDR
  if (ldrValue1 == 500) {
    // Chão Branco
    groundColor1 = 0;
  } else if (ldrValue1 == 500) {
    // Chão Verde
    groundColor1 = 1;
  } else {
    // Chão Preto
    groundColor1 = 2;
  }

void verificarVerde2() {
  // Lendo os valores dos sensores LDR
  ldrValue2 = calculateAverage(ldrPin2);

  // Exibindo os valores lidos no monitor serial
  Serial.print("\tSensor 2: ");
  Serial.println(ldrValue2);
  
  // Verificando a cor do chão com base nos valores dos sensores LDR
  if (ldrValue2 == 500) {
    // Chão Branco
    groundColor2 = 0;
  } else if (ldrValue2 == 500) {
    // Chão Verde
    groundColor2 = 1;
  } else {
    // Chão Preto
    groundColor2 = 2;
  }
}