#include "morse.h"

const char morse[] = {
  DAH, DAH, DAH, DAH, DAH, NIL, // 0
  DIT, DAH, DAH, DAH, DAH, NIL, // 1
  DIT, DIT, DAH, DAH, DAH, NIL, // 2
  DIT, DIT, DIT, DAH, DAH, NIL, // 3
  DIT, DIT, DIT, DIT, DAH, NIL, // 4
  DIT, DIT, DIT, DIT, DIT, NIL, // 5
  DAH, DIT, DIT, DIT, DIT, NIL, // 6
  DAH, DAH, DIT, DIT, DIT, NIL, // 7
  DAH, DAH, DAH, DIT, DIT, NIL, // 8
  DAH, DAH, DAH, DAH, DIT, NIL, // 9
  DIT, DAH, NIL, NIL, NIL, NIL, // A
  DAH, DIT, DIT, DIT, NIL, NIL, // B
  DAH, DIT, DAH, DIT, NIL, NIL, // C
  DAH, DIT, DIT, NIL, NIL, NIL, // D
  DIT, NIL, NIL, NIL, NIL, NIL, // E
  DIT, DIT, DAH, DIT, NIL, NIL, // F
  DAH, DAH, DIT, NIL, NIL, NIL, // G
  DIT, DIT, DIT, DIT, NIL, NIL, // H
  DIT, DIT, NIL, NIL, NIL, NIL, // I
  DIT, DAH, DAH, DAH, NIL, NIL, // J
  DAH, DIT, DAH, NIL, NIL, NIL, // K
  DIT, DAH, DIT, DIT, NIL, NIL, // L
  DAH, DAH, NIL, NIL, NIL, NIL, // M
  DAH, DIT, NIL, NIL, NIL, NIL, // N
  DAH, DAH, DAH, NIL, NIL, NIL, // O
  DIT, DAH, DAH, DIT, NIL, NIL, // P
  DAH, DAH, DIT, DAH, NIL, NIL, // Q
  DIT, DAH, DIT, NIL, NIL, NIL, // R
  DIT, DIT, DIT, NIL, NIL, NIL, // S
  DAH, NIL, NIL, NIL, NIL, NIL, // T
  DIT, DIT, DAH, NIL, NIL, NIL, // U
  DIT, DIT, DIT, DAH, NIL, NIL, // V
  DIT, DAH, DAH, NIL, NIL, NIL, // W
  DAH, DIT, DIT, DAH, NIL, NIL, // X
  DAH, DIT, DAH, DAH, NIL, NIL, // Y
  DAH, DAH, DIT, DIT, NIL, NIL, // Z
};

void delayDit() {
  delay(TDIT);
}

void delayDah() {
  delay(3 * DIT);
}

void delayGap() {
  delay(TDIT);
}

void delayChr() {
  delay(3 * TDIT);
}

void delaySpc() {
  delay(7 * TDIT);
}

