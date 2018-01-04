#ifndef N3_DISPLAY_DIGIT_H
#define N3_DISPLAY_DIGIT_H

#include "Settings.h"

#define N3_DIGIT_A 10
#define N3_DIGIT_B 11
#define N3_DIGIT_C 12
#define N3_DIGIT_D 13
#define N3_DIGIT_E 14
#define N3_DIGIT_F 15
#define N3_DIGIT_G 16
#define N3_DIGIT_H 17
#define N3_DIGIT_I 18
#define N3_DIGIT_J 19
#define N3_DIGIT_K 20
#define N3_DIGIT_L 21
#define N3_DIGIT_M 22
#define N3_DIGIT_N 23
#define N3_DIGIT_O 24
#define N3_DIGIT_P 25
#define N3_DIGIT_Q 26
#define N3_DIGIT_R 27
#define N3_DIGIT_S 28
#define N3_DIGIT_T 29
#define N3_DIGIT_U 30
#define N3_DIGIT_V 31
#define N3_DIGIT_W 32
#define N3_DIGIT_X 33
#define N3_DIGIT_Y 34
#define N3_DIGIT_Z 35

#define N3_DIGIT_SIG 101
#define N3_DIGIT_SPC 100
#define N3_DIGIT_FF  128

class DisplayDigit {
private:
    bool mDot1;
    bool mDot2;

    uint8_t  mMemLen;
    uint8_t *mMem;

    uint8_t  mDigsLen;
    uint8_t *mDigs;
    uint8_t *mDigsMap;

    uint8_t digitMask(uint8_t x);
    void digitsToMem();

public:
    DisplayDigit() :
            mDot1(false), mDot2(false),
            mMemLen(16), mMem(NULL),
            mDigsLen(18), mDigs(NULL), mDigsMap(NULL) {}

    virtual ~DisplayDigit() {
        if (mMem) delete mMem;
        if (mDigs) delete mDigs;
        if (mDigsMap) delete mDigsMap;
    }

    uint8_t size() const { return mDigsLen; }

    bool dot1() const { return mDot1; }
    DisplayDigit& dot1(bool aDot1) { mDot1 = aDot1; return *this; }
    bool dot2() const { return mDot2; }
    DisplayDigit& dot2(bool aDot2) { mDot2 = aDot2; return *this; }

    uint8_t digit(uint8_t aPos) const { return (aPos < mDigsLen) ? mDigs[aPos] : 10; }
    DisplayDigit& digit(uint8_t aPos, uint8_t aDig) { if (aPos < mDigsLen) mDigs[aPos] = aDig; return *this; }

    DisplayDigit& showNum(uint8_t aPos, float aNum, uint8_t aSize=6, uint8_t aAcc=2, bool aFill=false);

    virtual void init();
    virtual DisplayDigit& draw();
};

#endif //N3_DISPLAY_DIGIT_H
