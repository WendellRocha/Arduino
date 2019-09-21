const int botao = 8; // bot?o do sem?foro no pino 8
const int leds[] = {9, 10, 11, 12, 13};
boolean abre = false;

/**
  led verde do pedestre no pino 9
  led vermelho no pino 10
  led amarelo no pino 11
  led verde no pino 12
  led vermelho do pedestre no pino 13
*/


void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  
  if (abre) { // se o estado do bot?o for HIGH (alto, 1)
    delay(10000); // inicia uma contagem de 10 segundos
    digitalWrite(leds[3], LOW); // apos a contagem de 10 segundos, apaga o led verde
    digitalWrite(leds[2], HIGH); // apos apagar o led vede, acende o amarelo
    delay(5000); // inicia uma contagem de 5 segundos
    digitalWrite(leds[2], LOW); // apos a contagem de 5 segundos, apaga o led amarelo
    digitalWrite(leds[4], LOW); // apos a contagem de 5 segundos, apaga o led vermelho para o padestre
    digitalWrite(leds[1], HIGH); // apos a contagem de 5 segundos, acende o led vermelho para os veiculoso
    delay(750); // delay de seguranca para acender o led verde para os pedestres
    digitalWrite(leds[0], HIGH); // apos a contagem de 75 milisegundos, acende o led verde para o pedestre
    delay(15000); // inicia uma contagem de 15 segundos

    for (int y = 0; y < 1; y++) { // para y igual a zero; y menor que 1; use y e depois incremente                    /* la?o para piscar o led vermelho no final da contagem */
      digitalWrite(leds[1], LOW); // apaga o led vermelho dos ve?culos
      delay(250); // conta 25 milisegundos
      digitalWrite(leds[3], HIGH); // acende o led vermelho dos ve?culos
    }

    for (int x = 0; x < 10; x++) { // para x igual a zero; x menor que dez; use x e depois incremete                    /* la?o para piscar o led vermelho no final da contagem */
      digitalWrite(leds[4], HIGH); // acende o led verde do padestre
      delay(250); // conta 25 milisegundos
      digitalWrite(leds[4], LOW); // apaga o lede verde do padestre
      delay(250); // conta 2,5 segundos
    }

    digitalWrite(leds[1], LOW); // ap?s a contagem de 15 segundos, apaga o led vermelho
    digitalWrite(leds[0], LOW); // ap?s a contagem de 15 segundos, apaga o led verde do padestre

  } else { // sen?o

    digitalWrite(leds[3], HIGH); // assim que o programa iniciar, ligar? o led verde para os ve?culos
    digitalWrite(leds[4], HIGH); // assim que o programa iniciar, ligar? o led vermelho para o padestre
    delay(1000);
    abre = true;
  }

}
