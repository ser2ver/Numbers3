#include "DisplayDigit.h"

#define N3_MAP_0 0x5F
#define N3_MAP_1 0x50
#define N3_MAP_2 0x3B
#define N3_MAP_3 0x79
#define N3_MAP_4 0x74
#define N3_MAP_5 0x6D
#define N3_MAP_6 0x6F
#define N3_MAP_7 0x58
#define N3_MAP_8 0x7F
#define N3_MAP_9 0x7D

#define N3_MAP_A 0x7E
#define N3_MAP_B 0x67
#define N3_MAP_C 0x0F
#define N3_MAP_D 0x73
#define N3_MAP_E 0x2F
#define N3_MAP_F 0x2E
#define N3_MAP_G 0x4F
#define N3_MAP_H 0x76
#define N3_MAP_I 0x06
#define N3_MAP_J 0x51
#define N3_MAP_K 0x01
#define N3_MAP_L 0x07
#define N3_MAP_M 0x01
#define N3_MAP_N 0x62
#define N3_MAP_O 0x63
#define N3_MAP_P 0x3E
#define N3_MAP_Q 0x01
#define N3_MAP_R 0x01
#define N3_MAP_S 0x6D
#define N3_MAP_T 0x27
#define N3_MAP_U 0x43
#define N3_MAP_V 0x01
#define N3_MAP_W 0x01
#define N3_MAP_X 0x01
#define N3_MAP_Y 0x01
#define N3_MAP_Z 0x3B

#define N3_MAP_SIG 0x20
#define N3_MAP_SPC 0x00
#define N3_MAP_FF 0x7F

uint8_t DisplayDigit::digitMask(uint8_t x) {
    switch (x) {
        case 0:
            return N3_MAP_0;
        case 1:
            return N3_MAP_1;
        case 2:
            return N3_MAP_2;
        case 3:
            return N3_MAP_3;
        case 4:
            return N3_MAP_4;
        case 5:
            return N3_MAP_5;
        case 6:
            return N3_MAP_6;
        case 7:
            return N3_MAP_7;
        case 8:
            return N3_MAP_8;
        case 9:
            return N3_MAP_9;
        case N3_DIGIT_A:
            return N3_MAP_A;
        case N3_DIGIT_B:
            return N3_MAP_B;
        case N3_DIGIT_C:
            return N3_MAP_C;
        case N3_DIGIT_D:
            return N3_MAP_D;
        case N3_DIGIT_E:
            return N3_MAP_E;
        case N3_DIGIT_F:
            return N3_MAP_F;
        case N3_DIGIT_G:
            return N3_MAP_G;
        case N3_DIGIT_H:
            return N3_MAP_H;
        case N3_DIGIT_I:
            return N3_MAP_I;
        case N3_DIGIT_J:
            return N3_MAP_J;
        case N3_DIGIT_K:
            return N3_MAP_K;
        case N3_DIGIT_L:
            return N3_MAP_L;
        case N3_DIGIT_M:
            return N3_MAP_M;
        case N3_DIGIT_N:
            return N3_MAP_N;
        case N3_DIGIT_O:
            return N3_MAP_O;
        case N3_DIGIT_P:
            return N3_MAP_P;
        case N3_DIGIT_Q:
            return N3_MAP_Q;
        case N3_DIGIT_R:
            return N3_MAP_R;
        case N3_DIGIT_S:
            return N3_MAP_S;
        case N3_DIGIT_T:
            return N3_MAP_T;
        case N3_DIGIT_U:
            return N3_MAP_U;
        case N3_DIGIT_V:
            return N3_MAP_V;
        case N3_DIGIT_W:
            return N3_MAP_W;
        case N3_DIGIT_X:
            return N3_MAP_X;
        case N3_DIGIT_Y:
            return N3_MAP_Y;
        case N3_DIGIT_Z:
            return N3_MAP_Z;
        case N3_DIGIT_SIG:
            return N3_MAP_SIG;
        case N3_DIGIT_FF:
            return N3_MAP_FF;
        case N3_DIGIT_SPC:
        default:
            return N3_MAP_SPC;
    }
}

void DisplayDigit::digitsToMem() {
    uint8_t a1, a2, m, m1, m2, s1, s2;
    for (uint8_t i=0; i < mDigsLen; ++i) {
        m = digitMask(mDigs[i]);
        if (i == 4) {
            a1 = 15;
            a2 = 8;
            m1 = m << 4;
            m2 = (m & 0x70) >> 4;
            s1 = 0x0F;
            s2 = 0xF8;
            mMem[a1] &= s1;
            mMem[a1] |= m1;
            mMem[a2] &= s2;
            mMem[a2] |= m2;
        } else if (i == 9) {
            a1 = 11;
            a2 = 4;
            m1 = (m & 0x01) << 7;
            m2 = m >> 1;
            s1 = 0x7F;
            s2 = 0xC0;
            mMem[a1] &= s1;
            mMem[a1] |= m1;
            mMem[a2] &= s2;
            mMem[a2] |= m2;
        } else if (i == 12) {
            a1 = 6;
            a2 = 7;
            m1 = m << 4;
            m2 = m >> 4;
            s1 = 0x0F;
            s2 = 0xF8;
            mMem[a1] &= s1;
            mMem[a1] |= m1;
            mMem[a2] &= s2;
            mMem[a2] |= m2;
        } else if (i == 13) {
            a1 = 7;
            a2 = 0;
            m1 = m << 3;
            m2 = m >> 5;
            s1 = 0x07;
            s2 = 0xFC;
            mMem[a1] &= s1;
            mMem[a1] |= m1;
            mMem[a2] &= s2;
            mMem[a2] |= m2;
        } else {
            a2 = mDigsMap[i];
            a1 = a2 / 8;
            a2 = a2 % 8;
            m1 = m << a2;
            m2 = m >> (8 - a2);
            s1 = 0xFF >> (8 - a2);
            s2 = 0xFF << a2;
            mMem[a1] &= s1;
            mMem[a1] |= m1;
            if (a2) {
                mMem[a1+1] &= s2;
                mMem[a1+1] |= m2;
            }
        }
    }
    a1 = 3;
    m1 = 0x80;
    if (mDot1) {
        mMem[a1] |= m1;
    } else {
        mMem[a1] &= ~m1;
    }
    m1 = 0x40;
    if (mDot2) {
        mMem[a1] |= m1;
    } else {
        mMem[a1] &= ~m1;
    }
}

/**
 * Show number on display
 * @param aPos Position on display
 * @param aNum Value of the number
 * @param aSize Size of the number on display
 * @param aAcc Accuracy - count digits after point
 * @param aFill Fill by zero
 * @return this
 */
DisplayDigit& DisplayDigit::showNum(uint8_t aPos, float aNum, uint8_t aSize, uint8_t aAcc, bool aFill) {
    for (uint8_t i=0; i < aAcc; ++i)
        aNum *= 10;

    int32_t x = round(fabs(aNum));
    int8_t p = aSize - 1;
    int8_t b = (aNum < 0) ? 1 : 0;

    for ( ; p >= b; --p) {
        digit(aPos + p, x % 10);
        x /= 10;
        if (!aFill && !x && (p < aSize - aAcc)) {
            --p;
            break;
        }
    }

    if (aNum < 0) {
        digit(aPos + p--, N3_DIGIT_SIG);
    }

    for ( ; p >= 0; --p) {
        digit(aPos + p, N3_DIGIT_SPC);
    }

    return *this;
}

void DisplayDigit::init() {
    pinMode(N3_PIN_CLOCK, OUTPUT);
    pinMode(N3_PIN_LOAD, OUTPUT);
    pinMode(N3_PIN_DATA, OUTPUT);

    digitalWrite(N3_PIN_CLOCK, LOW);
    digitalWrite(N3_PIN_LOAD, LOW);
    digitalWrite(N3_PIN_DATA, LOW);

    if (mMem)
        delete mMem;
    mMem = new uint8_t[mMemLen];
    for (uint8_t i=0; i < mMemLen; ++i) {
        mMem[i] = 0;
    }

    if (mDigs)
        delete mDigs;
    mDigs = new uint8_t[mDigsLen];
    for (uint8_t i=0; i < mDigsLen; ++i) {
        mDigs[i] = N3_DIGIT_SPC;
    }

    if (mDigsMap)
        delete mDigsMap;
    mDigsMap = new uint8_t[mDigsLen];

    mDigsMap[0] = 96;
    mDigsMap[1] = 103;
    mDigsMap[2] = 110;
    mDigsMap[3] = 117;
    mDigsMap[4] = 0;//?
    mDigsMap[5] = 67;
    mDigsMap[6] = 74;
    mDigsMap[7] = 81;
    mDigsMap[8] = 88;
    mDigsMap[9] = 0;//?
    mDigsMap[10] = 38;
    mDigsMap[11] = 45;
    mDigsMap[12] = 0;//?
    mDigsMap[13] = 0;//?
    mDigsMap[14] = 2;
    mDigsMap[15] = 9;
    mDigsMap[16] = 16;
    mDigsMap[17] = 23;
}

DisplayDigit& DisplayDigit::draw() {
    digitsToMem();

    for (uint8_t i=0; i < mMemLen; ++i) {
        for (uint16_t j=1; j < 256; j <<= 1) {
            digitalWrite(N3_PIN_CLOCK, LOW);
            digitalWrite(N3_PIN_DATA, ((mMem[i] & j) ? HIGH : LOW));
            digitalWrite(N3_PIN_CLOCK, HIGH);
        }
    }
    digitalWrite(N3_PIN_CLOCK, LOW);

    digitalWrite(N3_PIN_LOAD, HIGH);
    delayMicroseconds(10);
    digitalWrite(N3_PIN_LOAD, LOW);

    return *this;
}
