#ifndef N3_LIGHT_H
#define N3_LIGHT_H

#include "Settings.h"

class Light {
private:
    uint16_t mVal;

public:
    Light() : mVal(1000) {}
    virtual ~Light() {}

    void init();
    void reload();

    uint16_t value() const { return mVal; }
};

#endif //N3_LIGHT_H
