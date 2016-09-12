/************************************************************************ 
 *  Código base retirado do site Electro Schematics                     *
 * (http://www.electroschematics.com/9809/arduino-8-bit-binary-led/)    *
 * Código adaptado para se adequar ao uso.                              *
 * Modificações: Wendell Stanley Araújo Rocha                           *
 * Link para o repositório: https://github.com/WendellRocha/Arduino     *
 * Código desponibilizado para ser utilizado e alterado para se adequar *
 * ao seu código.                                                       *
 * Por favor, não retire os créditos.                                   *
 ************************************************************************/

int letra = 0;    // variable to store number of conversoes
const byte numbarra = 8; // número de leds da barra
int state;        // usado para o estado HIGH ou LOW
 // barra de leds
byte barra[] = {6, 7, 8, 9, 10, 11, 12, 13};

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
