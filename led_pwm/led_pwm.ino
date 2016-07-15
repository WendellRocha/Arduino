/************************************************************************ 
 *  Feito por: Wendell Stanley Araújo Rocha                             *
 * Link para o repositório: https://github.com/WendellRocha/Arduino     *
 * Código desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu código.                                                       *
 * Varia o brilho do led variando a tensão da porta PWN.                *
 * Por favor, não retire os créditos.                                   *
 ************************************************************************/
 
int ledPin = 11;
float sinVal;
int ledVal;
 
void setup() 
{
  pinMode(ledPin, OUTPUT);
}
 
void loop() 
{
  for (int x=0; x<180; x++) 
  {
    // converte graus para radianos e então obtém o valor do seno
    sinVal = (sin(x*(3.1412/180)));
    ledVal = int(sinVal*255);
    analogWrite(ledPin, ledVal);
    delay(25);
  }
}
