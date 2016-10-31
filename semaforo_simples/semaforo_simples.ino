/* Desafio do sem�foro com sem�foro para padestres                      *
 * Wendell Rocha, 115210754                                             *
 * Inicia��o � Computa��o, 2015.2                                       *
 * wendell.rocha@ccc.ufcg.edu.br                                        *
 * Feito por: Wendell Stanley Ara�jo Rocha                              *
 * Link para o reposit�rio: https://github.com/WendellRocha/Arduino     *
 * C�digo desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu c�digo.                                                       *
 * Por favor, n�o retire os cr�ditos.                                   *
 ************************************************************************/
#include <Arduino.h>

const int botao = 8; // bot�o do sem�foro no pino 8
const int led_verde_pedestre = 9; // led verde do pedestre no pino 9
const int led_vermelho = 10; // led vermelho no pino 10
const int led_amarelo = 11; // led amarelo no pino 11
const int led_verde = 12; // led verde no pino 12
const int led_vermelho_pedestre = 13; // led vermelho do pedestre no pino 13
int estadodobotao = 0; // estado do bot�o do sem�foro


void setup() {
  pinMode(led_vermelho, OUTPUT); // pino do led_vermelho em modo de sa�da
  pinMode(led_amarelo, OUTPUT); // pino do led_amarelo em modo de sa�da
  pinMode(led_verde, OUTPUT); // pino do led_verde em modo de sa�da
  pinMode(led_vermelho_pedestre, OUTPUT); // pino do led_vermelho_pedestre em modo de sa�da
  pinMode(led_verde_pedestre, OUTPUT); // pino do led_verde_pedestre em modo de sa�da
  pinMode(botao, INPUT); // pino do bot�o em modo de entrada

}

void loop() {

  estadodobotao = digitalRead(botao); // atribui o valor da leitura do pino do bot�o ao estadodobotao
  if (estadodobotao == HIGH) { // se o estado do bot�o for HIGH (alto, 1)
    delay(10000); // inicia uma contagem de 10 segundos
    digitalWrite(led_verde, LOW); // ap�s a contagem de 10 segundos, apaga o led verde
    digitalWrite(led_amarelo, HIGH); // ap�s apagar o led vede, acende o amarelo
    delay(5000); // inicia uma contagem de 5 segundos
    digitalWrite(led_amarelo, LOW); // ap�s a contagem de 5 segundos, apaga o led amarelo
    digitalWrite(led_vermelho_pedestre, LOW); // ap�s a contagem de 5 segundos, apaga o led vermelho para o padestre
    digitalWrite(led_vermelho, HIGH); // ap�s a contagem de 5 segundos, acende o led vermelho para os ve�culos
    delay(750); // delay de seguran�a para acender o led verde para os pedestres
    digitalWrite(led_verde_pedestre, HIGH); // ap�s a contagem de 75 milisegundos, acende o led verde para o pedestre
    delay(15000); // inicia uma contagem de 15 segundos
    digitalWrite(led_vermelho, LOW); // ap�s a contagem de 15 segundos, apaga o led vermelho
    digitalWrite(led_verde_pedestre, LOW); // ap�s a contagem de 15 segundos, apaga o led verde do padestre

  }
  else { // sen�o

     digitalWrite(led_verde, HIGH); // assim que o programa iniciar, ligar� o led verde para os ve�culos
     digitalWrite(led_vermelho_pedestre, HIGH); // assim que o programa iniciar, ligar� o led vermelho para o padestre
  }

}
