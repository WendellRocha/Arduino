/* Desafio do semáforo com semáforo para padestres                      *
 * Wendell Rocha, 115210754                                             *
 * Iniciação à Computação, 2015.2                                       *
 * wendell.rocha@ccc.ufcg.edu.br                                        *
 * Feito por: Wendell Stanley Araújo Rocha                              *
 * Link para o repositório: https://github.com/WendellRocha/Arduino     *
 * Código desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu código.                                                       *
 * Por favor, não retire os créditos.                                   *
 ************************************************************************/ 

const int botao = 8; // botão do semáforo no pino 8
const int leds[] = {9, 10, 11, 12, 13}
int estadodobotao = 0; // estado do botão do semáforo

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
  pinMode(botao, INPUT); // pino do botão em modo de entrada

}

void loop() {
 
  estadodobotao = digitalRead(botao); // atribui o valor da leitura do pino do botão ao estadodobotao
  if (estadodobotao == HIGH) { // se o estado do botão for HIGH (alto, 1)
    delay(10000); // inicia uma contagem de 10 segundos    
    digitalWrite(leds[3], LOW); // após a contagem de 10 segundos, apaga o led verde
    digitalWrite(leds[2], HIGH); // após apagar o led vede, acende o amarelo
    delay(5000); // inicia uma contagem de 5 segundos
    digitalWrite(leds[2], LOW); // após a contagem de 5 segundos, apaga o led amarelo
    digitalWrite(leds[4], LOW); // após a contagem de 5 segundos, apaga o led vermelho para o padestre
    digitalWrite(led_red, HIGH); // após a contagem de 5 segundos, acende o led vermelho para os veículos
    delay(750); // delay de segurança para acender o led verde para os pedestres
    digitalWrite(leds[0], HIGH); // após a contagem de 75 milisegundos, acende o led verde para o pedestre
    delay(15000); // inicia uma contagem de 15 segundos

    for (int y = 0; y < 1; y++) { // para y igual a zero; y menor que 1; use y e depois incremente                    /* laço para piscar o led vermelho no final da contagem */
      digitalWrite(leds[1], LOW); // apaga o led vermelho dos veículos
      delay(250); // conta 25 milisegundos
      digitalWrite(leds[3], HIGH); // acende o led vermelho dos veículos
    }
       
    for (int x = 0; x < 10; x++) { // para x igual a zero; x menor que dez; use x e depois incremete                    /* laço para piscar o led vermelho no final da contagem */
      digitalWrite(leds[4], HIGH); // acende o led verde do padestre
      delay(250); // conta 25 milisegundos
      digitalWrite(leds[4], LOW); // apaga o lede verde do padestre
      delay(250); // conta 2,5 segundos
    }
    
    digitalWrite(leds[1], LOW); // após a contagem de 15 segundos, apaga o led vermelho
    digitalWrite(leds[0], LOW); // após a contagem de 15 segundos, apaga o led verde do padestre
      
  }
  else { // senão 
    
     digitalWrite(led_green, HIGH); // assim que o programa iniciar, ligará o led verde para os veículos
     digitalWrite(led_red_ped, HIGH); // assim que o programa iniciar, ligará o led vermelho para o padestre
  }

}
