#include "Wire.h"
#include <LiquidCrystal_I2C.h>

#define DS1307_ADDRESS 0x68

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

byte zero = 0x00; 

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  lcd.begin (16,2);
  
  //SelecionaDataeHora(); 
}

void loop()
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

  lcd.setCursor(0,0);
  lcd.print("    ");

  if (horas <10)
    lcd.print("0");
  lcd.print(horas);
  lcd.print(":");

  if (minutos < 10)
     lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");
  
  if (segundos < 10)
    lcd.print("0");
  lcd.print(segundos);
  lcd.setCursor(2,1);

  switch(diadasemana)
    {
      case 0:lcd.print("Dom");
      break;
      case 1:lcd.print("Seg");
      break;
      case 2:lcd.print("Ter");
      break;
      case 3:lcd.print("Qua");
      break;
      case 4:lcd.print("Qui");
      break;
      case 5:lcd.print("Sex");
      break;
      case 6:lcd.print("Sab");
    }
    lcd.setCursor(6,1);

    if (diadomes < 10)
      lcd.print("0");
    lcd.print(diadomes);
    lcd.print("/");

    if (mes < 10)
      lcd.print("0");
    lcd.print(mes);
    lcd.print("/");
    lcd.print(ano);
}

void SelecionaDataeHora()   
{
  byte segundos = 00; 
  byte minutos = 53;
  byte horas = 20; 
  byte diadasemana = 3; 
  byte diadomes = 28; 
  byte mes = 12; 
  byte ano = 16; 
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); 
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  Wire.write(zero);
  Wire.endTransmission(); 
}

byte ConverteParaBCD(byte val)
{ 
  return ( (val/10*16) + (val%10) );
}

byte ConverteparaDecimal(byte val)  
{ 
  return ( (val/16*10) + (val%16) );
}
