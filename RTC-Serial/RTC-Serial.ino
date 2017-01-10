// Programa : Data e Hora com DS1307
// Autor : Arduino e Cia

#include "Wire.h"

#define DS1307_ADDRESS 0x68

byte zero = 0x00; 

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  //A linha abaixo pode ser retirada apos setar a data e hora
  //SelecionaDataeHora(); 
}

void loop()
{
  Mostrarelogio();
  delay(1000);
}

void SelecionaDataeHora()   //Seta a data e a hora do DS1307
{
  byte segundos = 0; //Valores de 0 a 59
  byte minutos = 36; //Valores de 0 a 59
  byte horas = 20; //Valores de 0 a 23
  byte diadasemana = 3; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
  byte diadomes = 28; //Valores de 1 a 31
  byte mes = 12; //Valores de 1 a 12
  byte ano = 16; //Valores de 0 a 99
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //Stop no CI para que o mesmo possa receber os dados

  //As linhas abaixo escrevem no CI os valores de 
  //data e hora que foram colocados nas variaveis acima
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  Wire.write(zero); //Start no CI
  Wire.endTransmission(); 
}

byte ConverteParaBCD(byte val){ //Converte o número de decimal para BCD
  return ( (val/10*16) + (val%10) );
}

byte ConverteparaDecimal(byte val)  { //Converte de BCD para decimal
  return ( (val/16*10) + (val%16) );
}

void Mostrarelogio()
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  int segundos = ConverteparaDecimal(Wire.read());
  int minutos = ConverteparaDecimal(Wire.read());
  int horas = ConverteparaDecimal(Wire.read() & 0b111111); 
  int diadasemana = ConverteparaDecimal(Wire.read()); 
  int diadomes = ConverteparaDecimal(Wire.read());
  int mes = ConverteparaDecimal(Wire.read());
  int ano = ConverteparaDecimal(Wire.read());
  //Mostra a data no Serial Monitor
  Serial.print("Data: ");
  Serial.print(diadomes);
  Serial.print("/");
  Serial.print(mes);
  Serial.print("/");
  Serial.print(ano);
  Serial.print(" ");
  Serial.print("Hora : ");
  Serial.print(horas);
  Serial.print(":");
  Serial.print(minutos);
  Serial.print(":");
  Serial.print(segundos);
  switch(diadasemana)
    {
      case 0:Serial.println(", Domingo");
      break;
      case 1:Serial.println(", Segunda");
      break;
      case 2:Serial.println(", Terca");
      break;
      case 3:Serial.println(", Quarta");
      break;
      case 4:Serial.println(", Quinta");
      break;
      case 5:Serial.println(", Sexta");
      break;
      case 6:Serial.println(", Sabado");
    }
}
