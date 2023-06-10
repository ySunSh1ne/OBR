// Biblioteca para controlar a ponte H
#include <AFMotor.h>

// Pinos de controle da ponte H
#define motorEsquerdo 1
#define motorDireito 2

// Objeto para controlar a ponte H
AF_DCMotor motor1(motorEsquerdo);
AF_DCMotor motor2(motorDireito);

// Parâmetros de velocidade
int forca_Curva = 120; // força da curva no obstáculo
int forca = 110;
int forca_Baixa = 70;
int forca_Baixa_Curva = 100;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Exemplo de movimento: frente
  moverParaFrente(forca);

  // Aguarda 2 segundos antes de mudar a direção
  delay(2000);

  // Exemplo de movimento: curva à direita
  curvaDireita(forca_Curva);

  // Aguarda 2 segundos antes de mudar a direção
  delay(2000);

  // Exemplo de movimento: curva à esquerda com velocidade baixa
  curvaEsquerda(forca_Baixa_Curva);

  // Aguarda 2 segundos antes de mudar a direção
  delay(2000);

  // Exemplo de movimento: ré com velocidade baixa
  moverParaTras(forca_Baixa);

  // Aguarda 2 segundos antes de parar os motores
  delay(2000);

  // Parar os motores
  pararMotores();

  // Aguarda 2 segundos antes de repetir
  delay(2000);
}

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

// Função para fazer uma curva à direita
void curvaDireita(int velocidade) {
  motor1.setSpeed(velocidade);
  motor2.setSpeed(0);
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  Serial.println("Curva à direita");
}

// Função para fazer uma curva à esquerda
void curvaEsquerda(int velocidade) {
  motor1.setSpeed(0);
  motor2.setSpeed(velocidade);
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  Serial.println("Curva à esquerda");
}

// Função para parar os motores
void pararMotores() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  Serial.println("Motores parados");
}
