/************************************************************************ 
 * Feito por: Wendell Stanley Araújo Rocha                              *
 * Link para o repositório: https://github.com/WendellRocha/Arduino     *
 * Código desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu código.                                                       *
 * Por favor, não retire os créditos.                                   *
 ************************************************************************/

const int ledRed =  13;
const int ledYellow = 12;
const int ledGreen = 11;
const int buzzer = 10; //porta pwn



void setup()
{
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
 
void loop()
{
  int valor_recebido;
  valor_recebido = Serial.read();
  if(valor_recebido == '1')
  {
    Serial.println("O led conectado ao pino 13 foi ligado!");
    for (int x = 0; x < 60; x++) {
      digitalWrite(ledRed, HIGH);
      delay(150);
      digitalWrite(ledRed, LOW);
      delay(150);
    }
  }
  else if (valor_recebido == '2') {
    const int led = random(11, 14);
    Serial.println("O led random foi ligado!");
    digitalWrite(led, HIGH);
    delay(5000);
    digitalWrite(led, LOW);
  }

  else if (valor_recebido == '3') {
    Serial.println("O buzzer conectado ao pino 10 foi ligado!");
    for (int x = 0; x < 20; x++) {
     digitalWrite(buzzer, HIGH);
     delay(150);
     digitalWrite(buzzer, LOW);
     delay(150);
    }

  }
    
  else if (valor_recebido == '4') {
    Serial.println("Os leds conectados aos pinos 11, 12 e 13 foram ligados!");
    for (int x = 0; x < 60; x++) {
      digitalWrite(ledRed, HIGH);
      delay(100);
      digitalWrite(ledRed, LOW);
      delay(100);
      digitalWrite(ledYellow, HIGH);
      delay(100);
      digitalWrite(ledYellow, LOW);
      delay(100);
      digitalWrite(ledGreen, HIGH);
      delay(100);  
      digitalWrite(ledGreen, LOW);
      delay(100);
    }
  }

  else if (valor_recebido == '5') {
    Serial.println("Os leds conectados aos pinos 11 e 13 e o buzzer no pino 10 foram ligados!");
    for (int x = 0; x < 60; x++) {
      digitalWrite(ledRed, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledGreen, HIGH);
      delay(350);
      digitalWrite(ledRed, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledGreen, LOW);
      delay(350);
    
    }
  }
}
