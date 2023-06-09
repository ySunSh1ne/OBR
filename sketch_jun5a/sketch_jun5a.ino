#include <NewPing.h>

#include <Config.h>
#include <Action.h>

// Definição das variáveis dos componentes
int currentCode = 0; // Código atual do robô

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP); // Configura o primeiro botão como entrada com pull-up interno
  pinMode(buttonPin2, INPUT_PULLUP); // Configura o segundo botão como entrada com pull-up interno
  pinMode(buttonPin3, INPUT_PULLUP); // Configura o terceiro botão como entrada com pull-up interno
  pinMode(powerButtonPin, INPUT_PULLUP); // Configura o botão de ligar o robô como entrada com pull-up interno

  pinMode(sensorPin1, INPUT); // Configura o primeiro sensor LRD como entrada
  pinMode(sensorPin2, INPUT); // Configura o segundo sensor LRD como entrada
  pinMode(sensorPin3, INPUT); // Configura o terceiro sensor LRD como entrada
  pinMode(sensorPin4, INPUT); // Configura o primeiro sensor LRD como entrada
  pinMode(sensorPin5, INPUT); // Configura o segundo sensor LRD como entrada
  pinMode(sensorPin6, INPUT); // Configura o terceiro sensor LRD como entrada
  pinMode(sensorPin7, INPUT); // Configura o terceiro sensor LRD como entrada
  // Configurando as portas do sensor LRD 

  pinMode(ledPin1, OUTPUT); // Configura o primeiro LED como saída
  pinMode(ledPin2, OUTPUT); // Configura o segundo LED como saída
  pinMode(ledPin3, OUTPUT); // Configura o terceiro LED como saída
  pinMode(ledPin4, OUTPUT); // Configura o quarto LED como saída
  pinMode(ledPin5, OUTPUT); // Configura o quinto LED como saída
  // Configurando as portas dos LEDs

  pinMode(motorEsqFrente, OUTPUT); // Configura o pino 1 do Motor 1 como saída
  pinMode(motorEsqTras, OUTPUT); // Configura o pino 2 do Motor 1 como saída
  pinMode(motorEsqSpd, OUTPUT); // Configura o pino 3 do Motor 1 (pino de velocidade) como saída

  pinMode(motorDirFrente, OUTPUT); // Configura o pino 1 do Motor 2 como saída
  pinMode(motorDirTras, OUTPUT); // Configura o pino 2 do Motor 2 como saída
  pinMode(motorDirSpd, OUTPUT); // Configura o pino 3 do Motor 2 (pino de velocidade) como saída
  // Configurando as portas dos motores


  Serial.begin(9600); // Inicia a comunicação serial
}

void loop() {
  int button1State = digitalRead(buttonPin1);  // Lê o estado do botão 1

  switch (button1State) {
    case LOW:  // Botão 1 pressionado
      currentCode = 1;  // Define o código atual como 1
      seguelinha();  // Executa a função "seguelinha"
      break;
    case HIGH:  // Botão 1 não pressionado
      // Outras ações ou códigos aqui
      break;
  }


}


