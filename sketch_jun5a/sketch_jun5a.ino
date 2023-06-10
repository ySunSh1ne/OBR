#include <NewPing.h>

#include <Config.h>
#include <Action.h>

// Definição das variáveis dos componentes
int currentCode = 0; // Código atual do robô

void setup() {
  // Configuração dos pinos dos motores da ponte H
  motor1.setSpeed(255);  // Define a velocidade máxima para o motor1
  motor2.setSpeed(255);  // Define a velocidade máxima para o motor2

  // Configuração dos pinos dos LEDs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  // Configuração dos pinos dos LEDs RGB
  pinMode(ledPin1Red, OUTPUT);
  pinMode(ledPin1Green, OUTPUT);
  pinMode(ledPin1Blue, OUTPUT);
  pinMode(ledPin2Red, OUTPUT);
  pinMode(ledPin2Green, OUTPUT);
  pinMode(ledPin2Blue, OUTPUT);
  
  // Configuração dos pinos dos sensores LRD como entradas
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);
  pinMode(sensorPin5, INPUT);

  // Configuração dos pinos dos botões como entradas com pull-up internos ativados
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(powerButtonPin, INPUT_PULLUP);

  // Configuração dos pinos dos sensores ultrassônicos como saídas
  pinMode(trigger_pin1, OUTPUT);
  pinMode(echo_pin1, INPUT);
  pinMode(trigger_pin2, OUTPUT);
  pinMode(echo_pin2, INPUT);

  // Inicialização dos valores das leituras dos sensores
  for (int i = 0; i < sample_size; i++) {
    readings1[i] = 0;
    readings2[i] = 0;
  }

  // Realiza as leituras iniciais dos sensores ultrassônicos
  for (int i = 0; i < sample_size; i++) {
    total1 += sonar1.ping_cm();
    total2 += sonar2.ping_cm();
    delay(10);
  }

  // Cálculo da média das leituras iniciais dos sensores ultrassônicos
  average1 = total1 / sample_size;
  average2 = total2 / sample_size;

  // Outras configurações iniciais
  // ...
}

void loop() {
  // Realiza a leitura dos sensores
  distance1 = sonar1.ping_cm();
  distance2 = sonar2.ping_cm();

  // Verifica se há um obstáculo a uma distância de 5cm à frente
  if (distance1 <= 5) {
    desviarObstaculo();  // Executa o desvio de obstáculo
  } else {
    moverParaFrente(forca);  // Move para frente com uma velocidade padrão
  }

  if (sensorPin3 >= white && sensorPin4 <= black &&sensorPin5 >= white) {
      //Linha reta seguir em frente
      moverParaFrente(forca)
  } else if (sensorPin3 >= black && sensorPin4 <= white &&sensorPin5 >= white) {
      // Virar para a Esquerda
      moverEsquerda(forca_Baixa)
  } else if (sensorPin3 >= white && sensorPin4 <= white &&sensorPin5 >= black) {
      // Virar para a Direita
      moverDireita(forca_Baixa)
  } else if (sensorPin3 >= black && sensorPin4 <= black &&sensorPin5 >= black) {
      // T a frente 
      moverParaTras(forca_Baixa)
      verificarVerde1()
      if  (groundColor1 = 2) {
        //
      } else if (groundColor1 = 1)
        // curva verde esquerda 
        curva90Esquerda(forca_Curva)
      { else (groundColor1 = 0)
      
      }
      
 
}





