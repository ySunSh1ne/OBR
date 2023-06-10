#include <Arduino.h>


#define black  0 // Valor para a cor Preto
#define green 1 // Valor para a cor Verde
#define white  2 // Valor para a cor Branco

#define buttonPin1 2 // Pino do primeiro botão
#define buttonPin2 3 // Pino do segundo botão
#define buttonPin3 4 // Pino do terceiro botão
#define powerButtonPin 5 // Pino do botão de ligar o robô
// Definindo as portas dos Botoes

#define sensorPin1 A0 // Pino do primeiro sensor LRD
#define sensorPin2 A1 // Pino do segundo sensor LRD
#define sensorPin3 A2 // Pino do terceiro sensor LRD
#define sensorPin4 A3 // Pino do quarto sensor LRD
#define sensorPin5 A4 // Pino do quinto sensor LRD
#define sensorPin6 A5 // Pino do sexto sensor LRD
#define sensorPin7 A6 // Pino do setimo sensor LRD
// Defininindo as portas dos sensores LRD


#define ledPin1 6 // Pino do primeiro LED
#define ledPin2 7 // Pino do segundo LED
#define ledPin3 8 // Pino do terceiro LED
#define ledPin4 9 // Pino do quarto LED
#define ledPin5 10 // Pino do quinto LED
// Definindo as portas dos LEDS

#define motorEsqFrente 11 // 
#define motorEsqTras 12 // Pino 2 do Motor 1
#define motorEsqSpd 13 // Pino 3 do Motor 1 Pino de velocidade

#define motorDirFrente 14 // Pino 1 do Motor 2
#define motorDirTras 15 // Pino 2 do Motor 2
#define motorDirSpd 16 // Pino 3 do Motor 2 Pino de velocidade
// Definindo as portas dos motores

#define trigger_pin1 17 // Pino do Arduino conectado ao pino de disparo do sensor ultrassônico.
#define echo_pin1 18 // Pino do Arduino conectado ao pino de eco do sensor ultrassônico.
#define max_distance1 200 // Distância máxima para realizar o eco (em centímetros). A distância máxima do sensor é de 400-500cm.

#define trigger_pin2 19 // Pino do Arduino conectado ao pino de disparo do segundo sensor ultrassônico.
#define echo_pin2 20 // Pino do Arduino conectado ao pino de eco do segundo sensor ultrassônico.
#define max_distance2 200 // Distância máxima para realizar o eco (em centímetros). A distância máxima do sensor é de 400-500cm.
// Definindo as portas dos sensores de presença


//**************************** Variaveis Uteis **************************************

int forca_Curva = 120; // forca da curva no obstaculo
int forca = 110;
int forca_Baixa = 70;
int forca_Baixa_Curva = 100;

