#include <EEPROM.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

const int ledInfo = 8;
const int ledOk = 7;
const int ledWarn = 6;
const int wipeB = 4;

boolean equal = false;

int successRead;  // variable integer to keep if we have successful read from
                  // reader

byte readCard[4];    // stores scanned ID read from rfid module
byte masterCard[4];  // stores master card's ID read from EEPROM

void setup() {
  Serial.begin(9600);  // Inicia a serial
  SPI.begin();         // Inicia  SPI bus
  mfrc522.PCD_Init();  // Inicia MFRC522

  ShowReaderDetails();

  // Configuração dos pinos do arduino
  pinMode(ledOk, OUTPUT);
  pinMode(ledWarn, OUTPUT);
  pinMode(ledInfo, OUTPUT);
  pinMode(wipeB, INPUT_PULLUP);

  // garantindo que tudo estará desligado enquanto o arduino reseta ou durante a
  // inicialização
  digitalWrite(ledOk, LOW);
  digitalWrite(ledWarn, LOW);
  digitalWrite(ledInfo, LOW);

  // se o botão for pressionado durante a inicialização do arduino, a EEPROM
  // será apagada
  if (digitalRead(wipeB) == HIGH) {
    digitalWrite(ledWarn, HIGH);
    Serial.println(F("Botão de reset pressionado"));
    Serial.println(F("Você tem 15 segundos para cancelar"));
    Serial.println(
        F("Todos os cartões serão apagados e esse processo não poderá ser "
          "desfeito"));
    delay(15000);
    if (digitalRead(wipeB) == HIGH) {
      digitalWrite(ledOk, HIGH);
      Serial.println(F("Apagando os dados da EEPROM"));
      for (int x = 0; x < EEPROM.length(); x++) {
        if (EEPROM.read(x) == 0) {
          /* não faz nada, o endereço já está limpo. Vai para o próximo endereço
           para reduzir o tempo e economizar ciclos de I/O na EEPROM */
        } else {
          EEPROM.write(x, 0);  // se não escreve 0 para limpar. Isso leva 3.3ms
        }
      }
      Serial.println(F("EEPROM apagada"));
      digitalWrite(ledOk, LOW);
      digitalWrite(ledWarn, LOW);
      delay(200);
      digitalWrite(ledOk, HIGH);
      digitalWrite(ledWarn, HIGH);
      delay(200);
      digitalWrite(ledOk, LOW);
      digitalWrite(ledWarn, LOW);
      delay(200);
      digitalWrite(ledOk, HIGH);
      digitalWrite(ledWarn, HIGH);
      delay(200);
      digitalWrite(ledOk, LOW);
      digitalWrite(ledWarn, LOW);
      delay(200);
    } else {
      Serial.println(F("Processo cancelado"));
      digitalWrite(ledWarn, LOW);
    }
  }

  /* Checa se há um master card definido, caso não deixa o usuário escolher um
    master card. Isso é eficiente para redefinir o master card. You can keep
    other EEPROM records just write other than 143 to EEPROM address 1 EEPROM
    address 1 should hold magical number which is '143'
  */
  if (EEPROM.read(1) != 143) {
    Serial.println(F("Não há master card definido"));
    Serial.println(F("Escaneie um cartão para definí-lo como master card"));
    do {
      successRead = getID();  // sets successRead to 1 when we get read from
                              // reader otherwise 0
      digitalWrite(ledInfo, HIGH);  // Visualize Master Card need to be defined
      delay(200);
      digitalWrite(ledInfo, LOW);
      delay(200);
    } while (!successRead);  // Program will not go further while you not get a
                             // successful read
    for (int j = 0; j < 4; j++) {
      EEPROM.write(2 + j, readCard[j]);
    }
    EEPROM.write(1, 143);
    Serial.println(F("Master card definido"));
  }
  Serial.println(F("--------------------------"));
  Serial.println(F("Master Card UID"));
  for (int k = 0; k < 4; k++) {          // read master card's UID from EEPROM
    masterCard[k] = EEPROM.read(2 + k);  // write it to masterCard
    Serial.print(masterCard[k], HEX);
  }

  Serial.println("");
  Serial.println(F("-----------------------"));
  Serial.println(F("Sistema pronto"));
  Serial.println(F("Aguardando o cartão ser escaneado"));

  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
}

void loop() {
  getID();
}

void denied() {
  for (int i = 0; i <= 10; i++) {
    digitalWrite(ledWarn, HIGH);
    delay(200);
    digitalWrite(ledWarn, LOW);
    delay(200);
  }
}

int getID() {
  // Getting ready for Reading PICCs
  if (!mfrc522.PICC_IsNewCardPresent()) {  // If a new PICC placed to RFID
                                           // reader continue
    equal = false;
    return 0;
  }
  if (!mfrc522.PICC_ReadCardSerial()) {  // Since a PICC placed get Serial and
                                         // continue
    equal = false;
    return 0;
  }
  // There are Mifare PICCs which have 4 byte or 7 byte UID care if you use 7
  // byte PICC I think we should assume every PICC as they have 4 byte UID Until
  // we support 7 byte PICCs
  Serial.println(F("Scanned PICC's UID:"));
  for (int i = 0; i < 4; i++) {  //
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
  }
  Serial.println("");
  mfrc522.PICC_HaltA();  // Stop reading

  for (int i = 0; i < 4; i++) {
    if (readCard[i] != masterCard[i]) {
      equal = false;
      denied();
      break;  // no equal
    }
    equal = true;
    digitalWrite(ledOk, HIGH);
    digitalWrite(ledWarn, LOW);
  }
  return 1;
}

void ShowReaderDetails() {
  // Get the MFRC522 software version
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F(" = v2.0"));
  else
    Serial.print(F(" (unknown),probably a chinese clone?"));
  Serial.println("");
  // When 0x00 or 0xFF is returned, communication probably failed
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F(
        "WARNING: Communication failure, is the MFRC522 properly connected?"));
    Serial.println(F("SYSTEM HALTED: Check connections."));
    while (true)
      ;  // do not go further
  }
}