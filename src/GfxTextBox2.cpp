#include <MutilaDebug.h>
#include "GfxTextBox2.h"
#include "CbOledDisplay.h"

GfxTextBox2::GfxTextBox2(String initialText, GfxFont& font, char justify, uint16_t width, uint16_t height, bool border) :
    _text(initialText),
    _font(font),
    _justify(justify),
    _width(width),
    _height(height),
    _border(border)
{
    if (_justify != 'L' && _justify != 'C' && _justify != 'R') {
        _justify = 'C';
    }

    if (height == 0) {
        _height = _font.height() + 4;
    }

    if (width == 0) {
        _font.use();
        _width = CbOledDisplay.getStrWidth(_text.c_str()) + 4;
    }
}

void GfxTextBox2::draw(uint16_t xOffset, uint16_t yOffset) {
    _DBF("GfxText draw@%d,%d : text=%s\n", xOffset, yOffset, _text.c_str());
    _font.use();

    uint16_t useLen = _text.length();
    // If the text does not fit in the box, trucate it until it does
    while (true) {
        if (CbOledDisplay.getStrWidth(_text.substring(0, useLen).c_str()) <= _width-4 || useLen == 0) {
            break;
        } else {
            useLen--;
        }
    }

    CbOledDisplay.drawStr(xOffset + 2, 
                          yOffset + _height - 2,
                          _text.substring(0, useLen+1).c_str());

    if (_border) {
        CbOledDisplay.drawFrame(xOffset, yOffset, _width, _height); 
    }
}

uint16_t GfxTextBox2::width()
{
    return _width;
}

uint16_t GfxTextBox2::height() {
    return _height;
}

const String& GfxTextBox2::text()
{
    return _text;
}

void GfxTextBox2::setText(const String& newText)
{
    _text = newText;
}

