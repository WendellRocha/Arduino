#include <Time.h>
#include <TimeLib.h>
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
time_t t;
bool nfc = false;
bool portaFechada = true;

void setup() {
  Serial.begin(9600);
  SPI.begin();        // Inicia  SPI bus
  mfrc522.PCD_Init(); // Inicia MFRC522
  pinMode(sensorPorta, INPUT);
  pinMode(ledOK, OUTPUT);
  pinMode(ledWarn, OUTPUT);
  pinMode(bomba, OUTPUT);
}

void loop() {
  verificaNFC();
  estadodaporta = digitalRead(sensorPorta);
  if (estadodaporta == LOW || !portaFechada) {
    t = now();
    portaFechada = false;
    if (!portaFechada) {
      digitalWrite(ledWarn, HIGH);
      portaAberta(t);
    }
  }

  if(portaFechada || minute(t) > 2) {
    setTime(0,0,0,1,1,00);
  }
}

void portaAberta(time_t t) {
  if (nfc) {
    digitalWrite(ledOK, HIGH);
    return;
  }

  time_t minutet1 = minute(t);
  Serial.println(minutet1); 
  if (minute(t) == 2) {
    digitalWrite(bomba, LOW);
    digitalWrite(ledOK, LOW);
    setTime(0,0,0,1,1,00);
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
