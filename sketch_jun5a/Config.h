#include <Arduino.h>
#include <NewPing.h>
#include <AFMotor.h>

AF_DCMotor motor1(motorEsquerdo);
AF_DCMotor motor2(motorDireito);
// Objeto para controlar a ponte H

NewPing sonar1(trigger_pin1, echo_pin1, max_distance);  // Objeto do sensor ultrassônico 1
NewPing sonar2(trigger_pin2, echo_pin2, max_distance);  // Objeto do sensor ultrassônico 2

#define motorEsquerdo 1
#define motorDireito 2
// Pinos de controle da ponte H

#define buttonPin1 2 // Pino do primeiro botão
#define buttonPin2 3 // Pino do segundo botão
#define buttonPin3 4 // Pino do terceiro botão
#define powerButtonPin 5 // Pino do botão de ligar o robô
// Definindo as portas dos Botoes

#define ledPin2 3
#define ledPin3 4
#define ledPin4 5
// Pinos dos LEDs padrão

// Definindo os pinos dos sensores LDR
#define ldrPin1 A0
#define ldrPin2 A1
#define ldrPin3 A0
#define ldrPin4 A1
#define ldrPin5 A0


// Definindo os pinos dos LEDs RGB
#define ledPin1Red 9
#define ledPin1Green 10
#define ledPin1Blue 11
#define ledPin2Red 5
#define ledPin2Green 6
#define ledPin2Blue 7

#define trigger_pin1 2  // Pino de trigger do sensor ultrassônico 1
#define echo_pin1 3     // Pino de eco do sensor ultrassônico 1
#define trigger_pin2 4  // Pino de trigger do sensor ultrassônico 2
#define echo_pin2 5     // Pino de eco do sensor ultrassônico 2
#define max_distance 200 // Distância máxima suportada pelos sensores (em centímetros)

#define sample_size 5  // Tamanho da janela do filtro de média móvel
// Definindo as portas dos sensores de presença


//**************************** Variaveis Uteis **************************************

int forca_Curva = 120; 
int forca = 110;
int forca_Baixa = 70;
int forca_Baixa_Curva = 100;
// Parâmetros de velocidade

int readings1[sample_size];  // Array de leituras para o sensor 1
int readings2[sample_size];  // Array de leituras para o sensor 2
int index = 0;               // Índice atual do array de leituras
int total1 = 0;              // Soma total das leituras do sensor 1
int total2 = 0;              // Soma total das leituras do sensor 2

int distance1 = sonar1.ping_cm();
int distance2 = sonar2.ping_cm();
// Realiza a leitura dos sensores


int average1 = total1 / sample_size;
int average2 = total2 / sample_size;
// Calcula a média das leituras suavizadas

int ldrValue1 = 0;
int ldrValue2 = 0;
// Definindo variáveis para armazenar os valores dos sensores LDR

int groundColor1 = 0;
int groundColor2 = 0;
// Definindo variável para armazenar a cor do chão