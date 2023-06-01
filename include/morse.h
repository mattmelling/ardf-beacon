#ifndef MORSE_H
#define MORSE_H

#include <Arduino.h>

#define MORSE_CHARSZ 6     // Size of morse chars

// Timing constants
// https://morsecode.world/international/timing.html
/* #define TDIT ((int)((60 / (50 * WPM)) * 1000)) // Time for a dit */
#define TDIT 100

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
