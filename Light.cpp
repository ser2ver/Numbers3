#include "Light.h"

void Light::init() {
    pinMode(N3_PIN_LIGHT_1, OUTPUT);
    pinMode(N3_PIN_LIGHT_2, OUTPUT);
    pinMode(N3_PIN_LIGHT_3, OUTPUT);
    pinMode(N3_PIN_LIGHT_4, OUTPUT);
    pinMode(N3_PIN_LIGHT_5, OUTPUT);
    pinMode(N3_PIN_LIGHT_ON,OUTPUT);

    digitalWrite(N3_PIN_LIGHT_1, LOW);
    digitalWrite(N3_PIN_LIGHT_2, LOW);
    digitalWrite(N3_PIN_LIGHT_3, LOW);
    digitalWrite(N3_PIN_LIGHT_4, LOW);
    digitalWrite(N3_PIN_LIGHT_5, LOW);

    digitalWrite(N3_PIN_LIGHT_ON, HIGH);

    analogWrite(N3_PIN_LIGHT_A, mVal / 4);
}

void Light::reload() {
    uint16_t newVal = analogRead(N3_PIN_LSENSOR);
    if (abs(mVal - newVal) > 100)
        mVal = newVal;

    analogWrite(N3_PIN_LIGHT_A, (1023 - mVal) / 4);

    digitalWrite(N3_PIN_LIGHT_1, (mVal < 1000) ? HIGH : LOW);
    digitalWrite(N3_PIN_LIGHT_2, (mVal <  800) ? HIGH : LOW);
    digitalWrite(N3_PIN_LIGHT_3, (mVal <  600) ? HIGH : LOW);
    digitalWrite(N3_PIN_LIGHT_4, (mVal <  400) ? HIGH : LOW);
    digitalWrite(N3_PIN_LIGHT_5, (mVal <  200) ? HIGH : LOW);
}

