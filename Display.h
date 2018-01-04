#ifndef N3_DISPLAY_H
#define N3_DISPLAY_H

#include "DisplayNumber.h"
#include "Termo.h"
#include "Light.h"

class Display : public DisplayNumber {
private:
    Termo mTermo;
    Light mLight;

public:
    Display() :
            DisplayNumber(),
            mTermo(N3_PIN_TERMO, 12),
            mLight()
    {}
    virtual ~Display() {}

    Termo& termo() { return mTermo; }
    Light& light() { return mLight; }

    virtual void init();
    virtual Display& draw();
};

#endif //N3_DISPLAY_H
