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
const int led_green_ped = 9; // led verde do pedestre no pino 9
const int led_red = 10; // led vermelho no pino 10
const int led_yellow = 11; // led amarelo no pino 11
const int led_green = 12; // led verde no pino 12
const int led_red_ped = 13; // led vermelho do pedestre no pino 13
int estadodobotao = 0; // estado do botão do semáforo


void setup() {
  pinMode(led_red, OUTPUT); // pino do led_red em modo de saída
  pinMode(led_yellow, OUTPUT); // pino do led_yellow em modo de saída
  pinMode(led_green, OUTPUT); // pino do led_green em modo de saída
  pinMode(led_red_ped, OUTPUT); // pino do led_red_ped em modo de saída
  pinMode(led_green_ped, OUTPUT); // pino do led_green_ped em modo de saída
  pinMode(botao, INPUT); // pino do botão em modo de entrada

}

void loop() {
 
  estadodobotao = digitalRead(botao); // atribui o valor da leitura do pino do botão ao estadodobotao
  if (estadodobotao == HIGH) { // se o estado do botão for HIGH (alto, 1)
    delay(10000); // inicia uma contagem de 10 segundos    
    digitalWrite(led_green, LOW); // após a contagem de 10 segundos, apaga o led verde
    digitalWrite(led_yellow, HIGH); // após apagar o led vede, acende o amarelo
    delay(5000); // inicia uma contagem de 5 segundos
    digitalWrite(led_yellow, LOW); // após a contagem de 5 segundos, apaga o led amarelo
    digitalWrite(led_red_ped, LOW); // após a contagem de 5 segundos, apaga o led vermelho para o padestre
    digitalWrite(led_red, HIGH); // após a contagem de 5 segundos, acende o led vermelho para os veículos
    delay(750); // delay de segurança para acender o led verde para os pedestres
    digitalWrite(led_green_ped, HIGH); // após a contagem de 75 milisegundos, acende o led verde para o pedestre
    delay(15000); // inicia uma contagem de 15 segundos

    for (int y = 0; y<1; y++) { // para y igual a zero; y menor que 1; use y e depois incremente                    /* laço para piscar o led vermelho no final da contagem */
      digitalWrite(led_red, LOW); // apaga o led vermelho dos veículos
      delay(250); // conta 25 milisegundos
      digitalWrite(led_red, HIGH); // acende o led vermelho dos veículos
    }
       
    for (int x=0; x<10; x++) { // para x igual a zero; x menor que dez; use x e depois incremete                    /* laço para piscar o led vermelho no final da contagem */
      digitalWrite(led_green_ped, HIGH); // acende o led verde do padestre
      delay(250); // conta 25 milisegundos
      digitalWrite(led_green_ped, LOW); // apaga o lede verde do padestre
      delay(250); // conta 2,5 segundos
    }
    
    digitalWrite(led_red, LOW); // após a contagem de 15 segundos, apaga o led vermelho
    digitalWrite(led_green_ped, LOW); // após a contagem de 15 segundos, apaga o led verde do padestre
      
  }
  else { // senão 
    
     digitalWrite(led_green, HIGH); // assim que o programa iniciar, ligará o led verde para os veículos
     digitalWrite(led_red_ped, HIGH); // assim que o programa iniciar, ligará o led vermelho para o padestre
  }

}
