#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

const int sensorPorta = 8;
const int ledOK = 7;
const int ledWarn = 6;
const int bomba = 5;

int estadodaporta = 1;
int ledOKState = LOW;
int ledWarnState = LOW;
const long interval = 84000;
unsigned long previousMillis = 0;
bool nfc = false;
bool portaFechada = true;

void setup() {
  Serial.begin(9600); // Inicia a serial
  SPI.begin();        // Inicia  SPI bus
  mfrc522.PCD_Init(); // Inicia MFRC522
  pinMode(sensorPorta, INPUT);
  pinMode(ledOK, OUTPUT);
  pinMode(ledWarn, OUTPUT);
  pinMode(bomba, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  verificaNFC();
  estadodaporta = digitalRead(sensorPorta);
  if (estadodaporta == LOW || !portaFechada) {
    portaFechada = false;
    if (!portaFechada) {
      Serial.println("Porta aberta");
      digitalWrite(ledWarn, HIGH);
      portaAberta(currentMillis);
    }
  }
}

void portaAberta(unsigned long currentMillis) {
  if (nfc) {
    digitalWrite(ledOK, HIGH);
    Serial.println("Porta Fechada");
    return;
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digitalWrite(bomba, LOW);
    digitalWrite(ledOK, LOW);
  }
}

void verificaNFC() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    nfc = false;
    return;
  }
  // Seleciona o cartao RFID
  if (!mfrc522.PICC_ReadCardSerial()) {
    nfc = false;
    return;
  }

  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  conteudo.toUpperCase();
  if (conteudo.substring(1) == "95 11 95 A5" || conteudo.substring(1) == "D5 FF 08 88") {
    nfc = true;
    portaFechada = true;
    digitalWrite(bomba, HIGH);
    digitalWrite(ledOK, HIGH);
    digitalWrite(ledWarn, LOW);
  }
}