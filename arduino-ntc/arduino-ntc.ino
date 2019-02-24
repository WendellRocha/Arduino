#include "Thermistor.h"

Thermistor temp(A0);
const int buzzer = 12;
const int cooler = 11;

void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(cooler, OUTPUT);
}

void loop() {
    if(readTemp() >= 29) {
        digitalWrite(cooler, HIGH);
    } else {
        digitalWrite(cooler, LOW);
    }

    if(readTemp() >= 32) {
        digitalWrite(buzzer, HIGH);
    } else {
        digitalWrite(buzzer, LOW);
    }
}

int readTemp() {
    int temperature = temp.getTemp();
    delay(1000);
    return temperature;
}
