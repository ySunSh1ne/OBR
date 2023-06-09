#include <Arduino.h>

//Funçoes de Ação

void pararMotor() {
  //Motores da Esquerda
  analogWrite(motorEsqFrente, 255);
  analogWrite(motorEsqTras, 255);

  //Motores da Direita
  analogWrite(motorDirFrente, 255);
  analogWrite(motorDirFrente, 255);

};

void mover(int a, int b) {

  if (a > 0) { // se for maior que zero o movimento é para frente 
    analogWrite(motorEsqFrente, a);
    analogWrite(motorEsqTras, 0);

  }

  else if (a == 0) { // se for igual a zero o movimento é parado
    analogWrite(motorEsqFrente, 0);
    analogWrite(motorEsqTras, 0);
  }

  else { // se for menos que zero o movimento é pra tras
    analogWrite(motorEsqFrente, 0);
    analogWrite(motorEsqTras, abs(a)); //a função analogWrite não aceita um valor negativo, portanto usar abs(a) garante que mesmo queo valor de 'a' seja negativo, a função analogWrite recebera um valor positivo 
  }
  
  if (b > 0) {
    analogWrite(motorDirFrente, b);
    analogWrite(motorDirFrente, 0);
  }
  else if (b == 0) {
    analogWrite(motorDirFrente, 0);
    anaogWrite(motorDirTras, 0);
  }
  else {
    analogWrite(motorDirFrente, 0);
    analogWrite(motorDirTras, abs(b));
  }
};


void Curva90Graus(int lado, int tipo) {

  // faz a curva dependendo do lado passado no parâmetro
  if (lado == ESQUERDA) {

    Serial.println("---------------------------- Curva ESQUERDA --------------------");
    pararMotores();
    delay(500);  // Aguarda um breve intervalo para parar completamente

    // Realiza a curva para a esquerda
    mover(forca_Curva * -1, forca_Curva);

    // Aguarda até que os sensores LDR 3 e 5 não detectem mais a linha preta
    while (digitalRead(sensorPin3) == black || digitalRead(sensorPin5) == black) {
      // Continua a curva enquanto pelo menos um dos sensores detectar a linha preta
    }

    pararMotores();
    delay(500);  // Aguarda um breve intervalo para parar completamente

    Serial.println("------------- FIM CURVA ESQUERDA ----------------");

  }
  else if (lado == DIREITA) {

    Serial.println("---------------------------- Curva DIREITA --------------------");
    pararMotores();
    delay(500);  // Aguarda um breve intervalo para parar completamente

    // Realiza a curva para a direita
    mover(forca_Curva, forca_Curva * -1);

    // Aguarda até que os sensores LDR 3 e 5 não detectem mais a linha preta
    while (digitalRead(sensorPin3) == black || digitalRead(sensorPin5) == black) {
      // Continua a curva enquanto pelo menos um dos sensores detectar a linha preta
    }

    pararMotores();
    delay(500);  // Aguarda um breve intervalo para parar completamente

    Serial.println("------------- FIM CURVA DIREITA ----------------");
  }
  pararMotores();
}

void T(int lado) {
  // Anda um pouco para frente para verificar se é um T ou 90 graus
  Mover(3, forca_Baixa, FRENTE);
  
  // Robô para
  pararMotores();
  delay(1000);
  
  // Verifica se está tudo branco; se sim, ele volta e faz a curva
  if (() == 0 || () == 7000) {
    Mover(3, forca_Baixa * -1, FRENTE);
    pararMotores();
    delay(500);
    
    if (lado == ESQUERDA) {
      Mover(2, forca, FRENTE);
      Curva90Graus(ESQUERDA, LIN);
      Mover(7, forca * -1, FRENTE);
    }
    
    if (lado == DIREITA) {
      Mover(2, forca, FRENTE);
      Curva90Graus(DIREITA, LIN);
      Mover(7, forca * -1, FRENTE);
    }
  }
}

void Gap(int estado) {
  LED1.turnOff();
  
  if (estado == ST_PRINCIPAL) {
    mover(forca_Baixa, forca_Baixa);
  } else if (estado == ST_RAMPA) {
    mover(forcaRampa, forcaRampa);
  }
  
  LED1.turnOn();
}

boolean Verde(int lado) {
  boolean sucesso = false;

  if (lado == ESQUERDA) {
    andarCM(3, forca);
    delay(300);

    pararMotores();
    delay(300);

    Curva90Graus(ESQUERDA, LIN);
    delay(300);

    andarCM(7, forca * -1);

    Buzzer.turnOff();
    LED3.turnOff();

    sucesso = true;
  }

  if (lado == DIREITA) {
    andarCM(3, forca);
    delay(300);
    pararMotores();
    delay(300);

    Curva90Graus(DIREITA, LIN);
    delay(300);

    andarCM(7, forca * -1);

    Buzzer.turnOff();
    LED4.turnOff();

    sucesso = true;
  }

  return sucesso;
}

void Desvio(int lado) {
  mover(forca_Baixa * -1, forca_Baixa * -1);
  delay(400);

  int forca_inicial = 30;

  mover(-40, 80);
  delay(800);

  mover(50, 80);
  delay(1700);

  mover(110, -55);
  delay(2100);

  while (verificaGap() == true) {
    mover(forca_Baixa, forca_Baixa);
  }
  
  while (1) {
    pararMotores();
  }
}


