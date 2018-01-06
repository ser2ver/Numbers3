#include "Display.h"

Display display;

void setup() {
    Serial.begin(9600);
    display.init();
}

void loop() {
    display.draw();
    delay(500);
}
