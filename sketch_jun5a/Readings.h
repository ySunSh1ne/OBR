#include <Arduino.h>

int lerVerde(int lado) {
  // LER SENSOR VERDE DA ESQUERDA
  if (lado == ESQUERDA) {
    return analogRead(sensorVerdeEsquerda);
  }

  // LER SENSOR VERDE DA DIREITA
  if (lado == DIREITA) {
    return analogRead(sensorVerdeDireita);
  }

}