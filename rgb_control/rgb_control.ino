/*
Projeto Arduino controla led RGB com botões.
Por Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/
 
//Declaração das constantes
const int ledAzul = 8;      //ledAzul refere-se ao pino digital 8.
const int ledVerde = 9;     //ledVerde refere-se ao pino digital 9.
const int ledVermelho = 10; //ledVermelho refere-se ao pino digital 10.
 
const int botaoAzul = 2;     //botaoAzul refere-se ao pino digital 2.
const int botaoVerde = 3;    //botaoVerde refere-se ao pino digital 3.
const int botaoVermelho = 4; //botaoVermelho refere-se ao pino digital 4.
 
//Variáveis que conterão os estados dos botões (pressionados ou não).
int estadoBotaoAzul;
int estadoBotaoVerde;
int estadoBotaoVermelho;
 
//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  //Definindo os pinos digitais (8, 9, 10) como de saída.
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT);    
   
  //Definindo os pinos digitais (2, 3, 4) como de entrada.
  pinMode(botaoAzul,INPUT);
  pinMode(botaoVerde,INPUT);
  pinMode(botaoVermelho,INPUT);
}
 
//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {   
 
  //Lendo o estado dos botões através dos pinos digitais.
  estadoBotaoAzul = digitalRead(botaoAzul);
  estadoBotaoVerde = digitalRead(botaoVerde);
  estadoBotaoVermelho = digitalRead(botaoVermelho);
     
  //Acendendo o led RGB conforme os botões pressionados.
  //Tratando a cor azul
  if (estadoBotaoAzul == HIGH) {
    digitalWrite(ledAzul,HIGH);
  } else {    
    digitalWrite(ledAzul,LOW);
  }
   
  //Tratando a cor verde
  if (estadoBotaoVerde == HIGH) {
    digitalWrite(ledVerde,HIGH);
  } else {
    digitalWrite(ledVerde,LOW);
  }
   
  //Tratando a cor vermelha
  if (estadoBotaoVermelho == HIGH) {
    digitalWrite(ledVermelho,HIGH);
  } else {
    digitalWrite(ledVermelho,LOW);        
  }
}
