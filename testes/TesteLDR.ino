const int numSensores = 7;   // Número de sensores LDR
const int numLeituras = 10;  // Número de leituras para o filtro de média móvel

int pinosLDR[numSensores] = {A0, A1, A2, A3, A4, A5, A6};  // Pinos analógicos dos sensores LDR
int valoresLDR[numSensores];                             // Valores brutos dos sensores LDR
float mediaMovel[numSensores];                            // Valores filtrados dos sensores LDR

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Ler os valores brutos dos sensores LDR
  for (int i = 0; i < numSensores; i++) {
    valoresLDR[i] = analogRead(pinosLDR[i]);
  }

  // Aplicar o filtro de média móvel
  for (int i = 0; i < numSensores; i++) {
    mediaMovel[i] = calcularMediaMovel(i, valoresLDR[i]);
  }

  // Imprimir os valores filtrados no monitor serial
  Serial.print("Valores filtrados: ");
  for (int i = 0; i < numSensores; i++) {
    Serial.print(mediaMovel[i]);
    Serial.print(" ");
  }
  Serial.println();

  delay(1000);  // Aguardar 1 segundo
}

float calcularMediaMovel(int indice, int novoValor) {
  static int leituras[numSensores][numLeituras];
  static int indiceLeitura[numSensores] = {0};

  leituras[indice][indiceLeitura[indice]] = novoValor;
  indiceLeitura[indice] = (indiceLeitura[indice] + 1) % numLeituras;

  float soma = 0.0;
  for (int i = 0; i < numLeituras; i++) {
    soma += leituras[indice][i];
  }
  return soma / numLeituras;
}
