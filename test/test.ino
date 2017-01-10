const int red = 13;
const int white = 12;
const int botao = 11;
int check = 0;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
  check = digitalRead(botao);
  if(check == HIGH) {
    digitalWrite(white, LOW);
    digitalWrite(red, LOW);
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(white, HIGH);
  }
}
