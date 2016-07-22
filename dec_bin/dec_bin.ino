/************************************************************************ 
 *  C�digo base retirado do site Electro Schematics                     *
 * (http://www.electroschematics.com/9809/arduino-8-bit-binary-led/)    *
 * C�digo adaptado para se adequar ao uso.                              *
 * Modifica��es: Wendell Stanley Ara�jo Rocha                           *
 * Link para o reposit�rio: https://github.com/WendellRocha/Arduino     *
 * C�digo desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu c�digo.                                                       *
 * Por favor, n�o retire os cr�ditos.                                   *
 ************************************************************************/

int letra = 0;    // variable to store number of conversoes
const byte numbarra = 10; // n�mero de leds da barra
int state;        // usado para o estado HIGH ou LOW
 // barra de leds
byte barra[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  
  for(int i = 0; i < numbarra; i++) {
    pinMode(barra[i], OUTPUT);
  }
  
  Serial.begin(9600);

}

void loop() {
  
  if (Serial.available() > 0) {
    letra = Serial.read();    
  }
  
  String binNumber = String(letra, BIN);
  int binLength = binNumber.length();
  for(int i = 0, x = 1; i < binLength; i++, x+=2) {
    if(binNumber[i] == '0') state = LOW;
    if(binNumber[i] == '1') state = HIGH;
      digitalWrite(barra[i] + binLength - x, state);
    }
}