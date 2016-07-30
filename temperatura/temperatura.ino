/************************************************************************
 * Feito por: Wendell Stanley Ara�jo Rocha                              *
 * Link para o reposit�rio: https://github.com/WendellRocha/Arduino     *
 * C�digo desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu c�digo.                                                       *
 * Sistema de controle da rota��o do cooler de acordo com a temperatura *
 * Por favor, n�o retire os cr�ditos.                                   *
 ************************************************************************/

const int lm35 = 0;
const int cooler = 11;
int temperatura = 0;
int samples[8];

void setup() {
  Serial.begin(9600);
  pinMode(cooler, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 7; i++) {
    samples[i] = (5.0 * analogRead(lm35) * 100.0) / 1024.0;
    temperatura += samples[i];
    delay(100);
  }

  temperatura /= 8.0;

  if (temperatura > 27.0) {
    analogWrite(cooler, 255);
  }

  else if (temperatura >= 25.0 && temperatura <= 27.0) {
    analogWrite(cooler, 127);
  }

  else {
    analogWrite(cooler, 0);
  }

  Serial.print(temperatura, DEC);
  Serial.print(" Cels. \n");

  temperatura = 0;
  delay(1000);
}