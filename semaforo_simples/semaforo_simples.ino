const int verde_pedestre = 8;
const int vermelho_pedestre = 9;
const int verde_veiculo = 10;
const int amarelo_veiculo = 11;
const int vermelho_veiculo = 12;

boolean abre = false;

void setup() {
  pinMode(verde_pedestre, OUTPUT);
  pinMode(vermelho_pedestre, OUTPUT);
  pinMode(verde_veiculo, OUTPUT);
  pinMode(amarelo_veiculo, OUTPUT);
  pinMode(vermelho_veiculo, OUTPUT);
}

void loop() {

  if (abre) {
    // fechado para pedestre, amarelo para os veículos
    digitalWrite(verde_pedestre, LOW);
    digitalWrite(vermelho_veiculo, LOW);
    digitalWrite(amarelo_veiculo, HIGH);
    digitalWrite(verde_veiculo, LOW);
    digitalWrite(vermelho_pedestre, HIGH);

    delay(8000); // conta 8 segundos
    //fecha para os veículos, abre para os pedetres
    digitalWrite(vermelho_veiculo, HIGH);
    digitalWrite(amarelo_veiculo, LOW);
    digitalWrite(verde_veiculo, LOW);
    digitalWrite(vermelho_pedestre, LOW);
    delay(750);
    digitalWrite(verde_pedestre, HIGH);

    delay(18000);

    // pisca 10 vezes o vermelho do veículo antes de abrir
    for (int i = 0; i <= 10; i++) {
      digitalWrite(vermelho_veiculo, LOW);
      digitalWrite(verde_pedestre, LOW);
      delay(250);
      digitalWrite(vermelho_veiculo, HIGH);
      digitalWrite(verde_pedestre, HIGH);
      delay(250);
    }

    digitalWrite(amarelo_veiculo, LOW);
    digitalWrite(verde_veiculo, LOW);
    digitalWrite(vermelho_pedestre, HIGH);
    digitalWrite(vermelho_veiculo, LOW);
    digitalWrite(verde_pedestre, LOW);


    delay(1000);
    abre = false;

  } else {
    digitalWrite(verde_pedestre, LOW);
    digitalWrite(vermelho_pedestre, HIGH);
    digitalWrite(vermelho_veiculo, LOW);
    digitalWrite(amarelo_veiculo, LOW);
    digitalWrite(verde_veiculo, HIGH);
    delay(10000);

    for (int i = 0; i <= 10; i++) {
      digitalWrite(verde_veiculo, LOW);
      delay(250);
      digitalWrite(verde_veiculo, HIGH);
      delay(250);
    }
    abre = true;
  }
}
