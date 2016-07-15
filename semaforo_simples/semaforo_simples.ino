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
const int led_verde_pedestre = 9; // led verde do pedestre no pino 9
const int led_vermelho = 10; // led vermelho no pino 10
const int led_amarelo = 11; // led amarelo no pino 11
const int led_verde = 12; // led verde no pino 12
const int led_vermelho_pedestre = 13; // led vermelho do pedestre no pino 13
int estadodobotao = 0; // estado do botão do semáforo


void setup() {
  pinMode(led_vermelho, OUTPUT); // pino do led_vermelho em modo de saída
  pinMode(led_amarelo, OUTPUT); // pino do led_amarelo em modo de saída
  pinMode(led_verde, OUTPUT); // pino do led_verde em modo de saída
  pinMode(led_vermelho_pedestre, OUTPUT); // pino do led_vermelho_pedestre em modo de saída
  pinMode(led_verde_pedestre, OUTPUT); // pino do led_verde_pedestre em modo de saída
  pinMode(botao, INPUT); // pino do botão em modo de entrada

}

void loop() {
 
  estadodobotao = digitalRead(botao); // atribui o valor da leitura do pino do botão ao estadodobotao
  if (estadodobotao == HIGH) { // se o estado do botão for HIGH (alto, 1)
    delay(10000); // inicia uma contagem de 10 segundos    
    digitalWrite(led_verde, LOW); // após a contagem de 10 segundos, apaga o led verde
    digitalWrite(led_amarelo, HIGH); // após apagar o led vede, acende o amarelo
    delay(5000); // inicia uma contagem de 5 segundos
    digitalWrite(led_amarelo, LOW); // após a contagem de 5 segundos, apaga o led amarelo
    digitalWrite(led_vermelho_pedestre, LOW); // após a contagem de 5 segundos, apaga o led vermelho para o padestre
    digitalWrite(led_vermelho, HIGH); // após a contagem de 5 segundos, acende o led vermelho para os veículos
    delay(750); // delay de segurança para acender o led verde para os pedestres
    digitalWrite(led_verde_pedestre, HIGH); // após a contagem de 75 milisegundos, acende o led verde para o pedestre
    delay(15000); // inicia uma contagem de 15 segundos
    digitalWrite(led_vermelho, LOW); // após a contagem de 15 segundos, apaga o led vermelho
    digitalWrite(led_verde_pedestre, LOW); // após a contagem de 15 segundos, apaga o led verde do padestre
      
  }
  else { // senão 
    
     digitalWrite(led_verde, HIGH); // assim que o programa iniciar, ligará o led verde para os veículos
     digitalWrite(led_vermelho_pedestre, HIGH); // assim que o programa iniciar, ligará o led vermelho para o padestre
  }

}
