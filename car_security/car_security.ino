const int biometrico = 13;
const int sensorPorta = 12;
const int ledOK = 11;
const int ledWarn = 10;
const int bomba = 9;

int estadodaporta = 1;
int estadodobiometrico = 0;
int ledOKState = LOW;
int ledWarnState = LOW;
const long interval = 84000;
unsigned long previousMillis = 0;
bool biometria = false;
bool portaFechada = true;

void setup() {
  pinMode(biometrico, INPUT);
  pinMode(sensorPorta, INPUT);
  pinMode(ledOK, OUTPUT);
  pinMode(ledWarn, OUTPUT);
  pinMode(bomba, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  verificaDigital();
  estadodaporta = digitalRead(sensorPorta);
  if(estadodaporta == LOW || !portaFechada) {
    portaFechada = false;
    if(!portaFechada) {
      digitalWrite(ledWarn, HIGH);
      portaAberta(currentMillis);
    }
  }
}

void portaAberta(unsigned long currentMillis) {
  if(biometria) {
    digitalWrite(ledOK, HIGH);
    return;
  }
  
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digitalWrite(bomba, LOW);
    digitalWrite(ledOK, LOW);
  }
}

void verificaDigital() {
  estadodobiometrico = digitalRead(biometrico);
  if(estadodobiometrico == HIGH) {
    digitalWrite(bomba, HIGH);
    digitalWrite(ledOK, HIGH);
    digitalWrite(ledWarn, LOW);
    biometria = true;
    portaFechada = true;
  } else {
    biometria = false;
  }
}
