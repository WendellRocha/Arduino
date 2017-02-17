const int {
  biometrico = 13;
  cartao = 12;
  sensorPorta = 11;
  ledOK = 10;
  ledWarn = 9;
  buzina = 8;
  bomba = 7;
}

int estadodaporta = 0;
int estadodabomba = 0;
int ledOKState = LOW;
int ledWarnState = LOW;
unsigned long previousMillis = 0;
boolean cartaoLido = false;
boolean biometria = false;

void setup() {
  pinMode(biometrico, INPUT);
  pinMode(cartao, INPUT);
  pinMode(sensorPorta, INPUT);
  pinMode(ledOK, OUTPUT);
  pinMode(ledWarn, OUTPUT);
  pinMode(buzina, OUTPUT);
  pinMode(bomba, OUTPUT);    
}

void loop() {
  unsigned long currentMillis = millis();
  estadodaporta = digitalRead(sensorPorta);
  if(sensorPorta == HIGH and !cartaoLido) {
    portaAberta(currentMillis);  
  }
}

void portaAberta(unsigned long currentMillis) {
  estadodabomba = digitalRead(bomba);
  if(currentMillis - previousMillis >= 78000) {
    previousMillis = currentMillis;
    if(estadodabomba == HIGH) {
      digitalWrite(bomba, LOW);
    }
      if(ledOKState == LOW) {
        digitalWrite(ledWarn, HIGH);
        } else {
        digitalWrite(ledWarn, LOW);
      }
   }
}
