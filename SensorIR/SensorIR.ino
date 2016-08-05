#include <IRremote.h>
#include <IRremoteInt.h>

const int leds[] = {9, 10, 11, 12};
const int IR = 8;
int estado;
float armazenaValor;

IRrecv irrecv(IR);
decode_results results;

void setup() {
  for(int i = 0; i < leds; i++) {
    pinMode(leds[i], OUTPUT);
  }

  Serial.begin(9600);
  irrecv.enableIRIn(); // inicializa o sensor IR
}

void loop() {
  if(irrecv.decode(&results)) {
    Serial.print("Valor lido: ");
    Serial.println(results.value, HEX);
    armazenaValor = results.value;
    irrecv.resume();
    

    if(armazenaValor == 0xF720DF) {
      Serial.println("Led vermelho ligado!");
      digitalWrite(leds[3], HIGH);
    }

    if(armazenaValor == 0xF7A05F) {
      Serial.println("Led verde ligado!");
      digitalWrite(leds[3], LOW);
      digitalWrite(leds[1], HIGH);
    }

    if(armazenaValor == 0xF7E01F) {
      Serial.println("Led branco ligado!");
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[0], HIGH);
    }

    if(armazenaValor == 0xF728D7) {
      Serial.println("Led amarelo ligado!");
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[2], HIGH);
    }

    if(armazenaValor == 0xF740BF) {
      Serial.println("Todos os leds foram desligados");
      for(int i = 0; i < leds; i++) {
        digitalWrite(leds[i], LOW);
      }
    }
  }
}
