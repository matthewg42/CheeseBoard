#pragma once

#include <U8g2lib.h>
#include "Config.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// Our CbOledDisplay object will have some extra functions, like multi-line wrapped text
class CbOledDisplayClass : public CBOLED_CLASS {
public:
    CbOledDisplayClass(const u8g2_cb_t *rotation, uint8_t clock, uint8_t data, uint8_t reset=U8X8_PIN_NONE);

    // Get the width of a single character
    u8g2_uint_t getCharWidth(char c);

    // Like drawStr, but right justified
    // \param x the x position of the right-most pixel of the text
    // \param y the bottom most pixel of the text
    // \param s the string to draw
    u8g2_uint_t drawStrR(u8g2_uint_t x, u8g2_uint_t y, const char *s);

    // Display text, wrapped, centred
    // \param text the text to display
    // \param hAlign horizontal alignment: L C R
    // \param vAlign vertical aignment: T M B
    void drawText(const char* text, char hAlign='L', char vAlign='M');

};

extern CbOledDisplayClass CbOledDisplay;
