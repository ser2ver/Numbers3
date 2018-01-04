#include "DisplayNumber.h"


DisplayNumber &DisplayNumber::showNumber(uint8_t aEndPos, const Number &aNum) {
    if (!(aNum.opt() & N3_NUMBER_UNUSED))
        showNum(aEndPos - aNum.size(), aNum.x(), aNum.size(), aNum.acc(), (aNum.opt() & N3_NUMBER_ZFILL));
    return *this;
}


void DisplayNumber::init() {
    DisplayDigit::init();
}

DisplayNumber& DisplayNumber::draw() {
    showNumber(6,  num1());
    showNumber(12, num2());
    showNumber(18, num3());
    DisplayDigit::draw();
    return *this;
}
