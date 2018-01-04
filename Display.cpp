#include "Display.h"

uint16_t _N3_COUNTER = 0;

void Display::init() {
    DisplayNumber::init();
    mTermo.init();
    mLight.init();

    dot2(true);
    x1size(5);
    x2size(5);
    x3size(5);
}

Display &Display::draw() {
    mTermo.reload();
    mLight.reload();

    if (mTermo.getNumDev() > 0) {
        digit(0, 1);
        x1opt(N3_NUMBER_VALUE);
        x1(mTermo.getTermC(0));
    } else {
        digit(0, N3_DIGIT_SPC);
        x1opt(N3_NUMBER_UNUSED);
    }

    if (mTermo.getNumDev() > 1) {
        digit(6, 2);
        x2(mTermo.getTermC(1));
    } else {
        digit(6, N3_DIGIT_L);
        x2(mLight.value() / 100.0);
    }

    if (mTermo.getNumDev() > 2) {
        digit(12, 3);
        dot1(true);
        x3acc(2);
        x3(mTermo.getTermC(2));
    } else {
        digit(12, N3_DIGIT_C);
        dot1(false);
        x3acc(0);
        x3(_N3_COUNTER);
    }

    DisplayNumber::draw();
    ++_N3_COUNTER;

    return *this;
}
