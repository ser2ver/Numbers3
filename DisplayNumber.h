#ifndef N3_DISPLAY_NUMBER_H
#define N3_DISPLAY_NUMBER_H

#include "DisplayDigit.h"

#define N3_NUMBER_VALUE 0
#define N3_NUMBER_ZFILL 1
#define N3_NUMBER_UNUSED 2

class Number {
private:
    float mX;
    uint8_t mAcc;
    uint8_t mSize;
    uint8_t mOpt;

public:
    explicit Number(uint8_t aOpt=N3_NUMBER_VALUE) :
            mX(0), mAcc(2), mSize(6), mOpt(aOpt) {}
    explicit Number(float aX, uint8_t aAcc=2, uint8_t aSize=6, uint8_t aOpt=N3_NUMBER_VALUE) :
            mX(aX), mAcc(aAcc), mSize(aSize), mOpt(aOpt) {}
    virtual ~Number() {}

    float x() const { return mX; }
    Number& x(float aX) { mX = aX; return *this; }

    uint8_t acc() const { return mAcc; }
    Number& acc(uint8_t aAcc) { mAcc = aAcc; return *this; }

    uint8_t size() const { return mSize; }
    Number& size(uint8_t aSize) { mSize = aSize; return *this; }

    uint8_t opt() const { return mOpt; }
    Number& opt(uint8_t aOpt) { mOpt = aOpt; return *this; }
};

class DisplayNumber : public DisplayDigit {
private:
    Number mX1;
    Number mX2;
    Number mX3;

public:
    DisplayNumber() :
            DisplayDigit(),
            mX1(), mX2(), mX3() {}
    virtual ~DisplayNumber() {}

    Number& num1() { return mX1; }
    Number& num2() { return mX2; }
    Number& num3() { return mX3; }

    float x1() const { return mX1.x(); }
    float x2() const { return mX2.x(); }
    float x3() const { return mX3.x(); }

    DisplayNumber& x1(float aX) { mX1.x(aX); return *this; }
    DisplayNumber& x2(float aX) { mX2.x(aX); return *this; }
    DisplayNumber& x3(float aX) { mX3.x(aX); return *this; }

    uint8_t x1acc() const { return mX1.acc(); }
    uint8_t x2acc() const { return mX2.acc(); }
    uint8_t x3acc() const { return mX3.acc(); }

    DisplayNumber& x1acc(uint8_t aAcc) { mX1.acc(aAcc); return *this; }
    DisplayNumber& x2acc(uint8_t aAcc) { mX2.acc(aAcc); return *this; }
    DisplayNumber& x3acc(uint8_t aAcc) { mX3.acc(aAcc); return *this; }

    uint8_t x1size() const { return mX1.size(); }
    uint8_t x2size() const { return mX2.size(); }
    uint8_t x3size() const { return mX3.size(); }

    DisplayNumber& x1size(uint8_t aSize) { mX1.size(aSize); return *this; }
    DisplayNumber& x2size(uint8_t aSize) { mX2.size(aSize); return *this; }
    DisplayNumber& x3size(uint8_t aSize) { mX3.size(aSize); return *this; }

    uint8_t x1opt() const { return mX1.opt(); }
    uint8_t x2opt() const { return mX2.opt(); }
    uint8_t x3opt() const { return mX3.opt(); }

    DisplayNumber& x1opt(uint8_t aOpt) { mX1.opt(aOpt); return *this; }
    DisplayNumber& x2opt(uint8_t aOpt) { mX2.opt(aOpt); return *this; }
    DisplayNumber& x3opt(uint8_t aOpt) { mX3.opt(aOpt); return *this; }

    DisplayNumber& showNumber(uint8_t aEndPos, const Number &aNum);

    virtual void init();
    virtual DisplayNumber& draw();
};

#endif //N3_DISPLAY_NUMBER_H
