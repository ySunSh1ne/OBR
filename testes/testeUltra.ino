#include <NewPing.h>

#define trigger_pin1 2  // Pino de trigger do sensor ultrassônico 1
#define echo_pin1 3     // Pino de eco do sensor ultrassônico 1
#define trigger_pin2 4  // Pino de trigger do sensor ultrassônico 2
#define echo_pin2 5     // Pino de eco do sensor ultrassônico 2
#define max_distance 200 // Distância máxima suportada pelos sensores (em centímetros)

#define sample_size 5  // Tamanho da janela do filtro de média móvel

NewPing sonar1(trigger_pin1, echo_pin1, max_distance);  // Objeto do sensor ultrassônico 1
NewPing sonar2(trigger_pin2, echo_pin2, max_distance);  // Objeto do sensor ultrassônico 2

int readings1[sample_size];  // Array de leituras para o sensor 1
int readings2[sample_size];  // Array de leituras para o sensor 2
int index = 0;               // Índice atual do array de leituras
int total1 = 0;              // Soma total das leituras do sensor 1
int total2 = 0;              // Soma total das leituras do sensor 2

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Realiza a leitura dos sensores
  int distance1 = sonar1.ping_cm();
  int distance2 = sonar2.ping_cm();

  // Subtrai o valor mais antigo do array de leituras e adiciona o novo valor
  total1 = total1 - readings1[index] + distance1;
  total2 = total2 - readings2[index] + distance2;
  readings1[index] = distance1;
  readings2[index] = distance2;

  // Incrementa o índice e verifica se chegou ao final do array
  index++;
  if (index >= sample_size) {
    index = 0;
  }

  // Calcula a média das leituras suavizadas
  int average1 = total1 / sample_size;
  int average2 = total2 / sample_size;

  // Imprime as leituras suavizadas no Serial Monitor
  Serial.print("Sensor 1: ");
  Serial.print(average1);
  Serial.print(" cm\t");
  Serial.print("Sensor 2: ");
  Serial.print(average2);
  Serial.println(" cm");

  // Envia as leituras suavizadas para o Serial Plotter
  Serial.print(average1);
  Serial.print(",");
  Serial.println(average2);

  delay(100); // Atraso entre leituras
}
