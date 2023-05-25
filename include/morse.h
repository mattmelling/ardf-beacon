#ifndef MORSE_H
#define MORSE_H

#include <Arduino.h>

#define MORSE_CHARSZ 6     // Size of morse chars

// Timing constants
// https://morsecode.world/international/timing.html
/* #define TDIT ((int)((60 / (50 * WPM)) * 1000)) // Time for a dit */
#define TDIT 60
#define TDAH (3 * TDIT)                        // Time for a dah
#define TGAP TDIT                              // Time for a gap between dits and dahs
#define TCHR 3 * TDIT                          // Time for space between characters
#define TSPC 7 * TDIT                          // Time for gap between words

#define DIT '.'
#define DAH '-'
#define NIL (char)0

// Morse code table
extern const char morse[];

void delayDit();
void delayDah();
void delayGap();
void delayChr();
void delaySpc();

#endif
