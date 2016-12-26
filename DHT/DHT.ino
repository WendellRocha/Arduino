#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h> 
 
#define DHTPIN A0
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);

/*
 * Led red = 11;
 * Led yellow = 10;
 * Led green = 9;
*/

const int red = 11;
const int yellow = 10;
const int green = 9;                                           
const int buzzer = 12;
 
byte grau[8] ={ B00001100,
                B00010010,
                B00010010,
                B00001100,
                B00000000,
                B00000000,
                B00000000,
                B00000000,};


LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  lcd.begin (16,2);
  lcd.clear();
  lcd.createChar(0, grau);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  lcd.setBacklight(HIGH);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if((t > 26.5 && t <= 28.5) || (h > 65.0 && h <= 70.0) || (t < 16 && t >= 15) || (h < 30 && h >= 25)) {
    warn();
  }
  
  if((t > 28.5) || (h > 70) || (t < 15) || (h < 30)) {
    alarm();
  }
  
  if((t <= 26.5) && (h <= 65)) {
    ok();
  }
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(" ");
  lcd.setCursor(7,0);
  lcd.print(t,1);
  lcd.setCursor(12,0);
  lcd.write((byte)0);
  lcd.setCursor(0,1);
  lcd.print("Umi: ");
  lcd.print(" ");
  lcd.setCursor(7,1);
  lcd.print(h,1);
  lcd.setCursor(12,1);
  lcd.print("%");
}

void warn() {
    digitalWrite(yellow, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    digitalWrite(buzzer, LOW);
}

void alarm() {
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW); 
}

void ok() {
    digitalWrite(green, HIGH);
    delay(3000);
    digitalWrite(green, LOW);
}

