/* Desafio do sem?foro com sem?foro para padestres                      *
 * Wendell Rocha, 115210754                                             *
 * Inicia??o ? Computa??o, 2015.2                                       *
 * wendell.rocha@ccc.ufcg.edu.br                                        *
 * Feito por: Wendell Stanley Ara?jo Rocha                              *
 * Link para o reposit?rio: https://github.com/WendellRocha/Arduino     *
 * C?digo desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu c?digo.                                                       *
 * Por favor, n?o retire os cr?ditos.                                   *
 ************************************************************************/ 

const int botao = 8; // bot?o do sem?foro no pino 8
const int leds[] = {9, 10, 11, 12, 13}
int estadodobotao = 0; // estado do bot?o do sem?foro

/**
  led verde do pedestre no pino 9
  led vermelho no pino 10
  led amarelo no pino 11
  led verde no pino 12
  led vermelho do pedestre no pino 13
  */


void setup() {
   for(int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(botao, INPUT); // pino do bot?o em modo de entrada

}

void loop() {
 
  estadodobotao = digitalRead(botao); // atribui o valor da leitura do pino do bot?o ao estadodobotao
  if (estadodobotao == HIGH) { // se o estado do bot?o for HIGH (alto, 1)
    delay(10000); // inicia uma contagem de 10 segundos    
    digitalWrite(leds[3], LOW); // ap?s a contagem de 10 segundos, apaga o led verde
    digitalWrite(leds[2], HIGH); // ap?s apagar o led vede, acende o amarelo
    delay(5000); // inicia uma contagem de 5 segundos
    digitalWrite(leds[2], LOW); // ap?s a contagem de 5 segundos, apaga o led amarelo
    digitalWrite(leds[4], LOW); // ap?s a contagem de 5 segundos, apaga o led vermelho para o padestre
    digitalWrite(led_red, HIGH); // ap?s a contagem de 5 segundos, acende o led vermelho para os ve?culos
    delay(750); // delay de seguran?a para acender o led verde para os pedestres
    digitalWrite(leds[0], HIGH); // ap?s a contagem de 75 milisegundos, acende o led verde para o pedestre
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
      
  }
  else { // sen?o 
    
     digitalWrite(led_green, HIGH); // assim que o programa iniciar, ligar? o led verde para os ve?culos
     digitalWrite(led_red_ped, HIGH); // assim que o programa iniciar, ligar? o led vermelho para o padestre
  }

}