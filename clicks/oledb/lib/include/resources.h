#include "oledb.h"

/**
 * @brief Memory buffer for 96x39 OLED monochrome module.
 */
oledb_resources_t oledb_img[ 480 ] = {
    0xFF, 0xFF, 0x3F, 0x1F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x83, 0xC3, 0x63, 0x63, 0x63, 0x63, 0x63,
    0x63, 0xE3, 0xE3, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x83,
    0xC3, 0xE3, 0x63, 0x63, 0x63, 0x63, 0x63, 0xE3, 0xE3, 0x03, 0x03, 0x63,
    0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0xE3, 0xE3, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0xE3, 0xE3, 0x03, 0x03, 0x03, 0x83, 0xC3,
    0xE3, 0x63, 0x63, 0x63, 0x63, 0xC3, 0xC3, 0x83, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF3, 0xFF, 0x8C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF,
    0xC1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0xFF, 0xFF, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x3E, 0xFF, 0xC1,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC1, 0xFF, 0x3E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x83, 0x83, 0x03, 0x00, 0x80, 0x83,
    0x03, 0x03, 0xC3, 0xC3, 0xC3, 0x83, 0x03, 0x03, 0x03, 0x00, 0x00, 0x83,
    0xC3, 0xC3, 0xC3, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x31,
    0x31, 0x31, 0x31, 0x31, 0x31, 0xFF, 0xFF, 0x00, 0x00, 0xF0, 0xF8, 0x1C,
    0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0x00, 0x0C, 0x0C, 0x18, 0xFC, 0xFC, 0x00,
    0x00, 0x04, 0x8C, 0xF8, 0x70, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0xFD, 0xFD,
    0x00, 0x00, 0xFF, 0xFF, 0x03, 0x1F, 0xFC, 0xC0, 0x00, 0xC0, 0xFC, 0x1F,
    0x03, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x3C, 0xF0, 0xC0,
    0x00, 0xC0, 0xF0, 0x3C, 0x0C, 0x00, 0xF0, 0xF8, 0x1C, 0x0C, 0x0C, 0x18,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFE, 0xF8, 0xF0, 0xE0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x86, 0x86,
    0x86, 0x86, 0x86, 0x86, 0x86, 0x87, 0x87, 0x80, 0x80, 0x81, 0x83, 0x87,
    0x86, 0x86, 0x87, 0x83, 0x81, 0x80, 0x80, 0x80, 0x80, 0x87, 0x87, 0x80,
    0x80, 0x86, 0x87, 0x81, 0x80, 0x80, 0x87, 0x87, 0x80, 0x80, 0x87, 0x87,
    0x80, 0x80, 0x87, 0x87, 0x80, 0x80, 0x81, 0x87, 0x86, 0x87, 0x81, 0x80,
    0x80, 0x87, 0x87, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x87,
    0x9F, 0xBF, 0xB1, 0xB0, 0x80, 0x80, 0x81, 0x83, 0x87, 0x86, 0x86, 0x83,
    0x87, 0x87, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xF0, 0xF8, 0xFE, 0xFF
};
