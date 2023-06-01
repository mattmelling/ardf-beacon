#include <Arduino.h>
#include "morse.h"

const char message[] = " M1CYT D ";

// Pin we will key on
#define PIN_CW 3
#define PIN_PTT 4
#define PTT_DELAY 500

const long BEACON_DELAY = 3L * 60L * 1000L;

#define keyOn()  analogWrite(PIN_CW, 127);
#define keyOff() analogWrite(PIN_CW, 0);

#define pttOn()  digitalWrite(PIN_PTT, 1); delay(PTT_DELAY);
#define pttOff() delay(PTT_DELAY); digitalWrite(PIN_PTT, 0);

#define DEBUG

unsigned long ts = 0;

void dit() {
  keyOn();
  delayDit();
  keyOff();
  delayGap();
}

void dah() {
  keyOn();
  delayDah();
  keyOff();
  delayGap();
}

void send(char c) {
  if(c >= '0' && c <= '9') {
    c -= 48;
  } else {
    c = c - 65 + 10;
  }
  for(int i = 0; i < MORSE_CHARSZ; i++) {
    switch (morse[(c * MORSE_CHARSZ) + i]) {
    case DIT:
      dit();
      break;
    case DAH:
      dah();
      break;
    case ' ':
      delaySpc();
      return;
    default:
      return;
    }
  }
}

void beacon() {
  #ifdef DEBUG
  Serial.print("Sending \"");
  Serial.print(message);
  Serial.println("\"");
  #endif
  pttOn();

  int len = strlen(message);
  for(int i = 0; i < len; i++) {
    char c = message[i];
    send(c);
    delayChr();
  }

  pttOff();
}

void setup() {
  pinMode(PIN_CW, OUTPUT);
  pinMode(PIN_PTT, OUTPUT);

  pttOff();
  keyOff();

  // Set PWM speed
  TCCR2B = 0b00000100;
  TCCR2A = 0b00000011;

  Serial.begin(115200);
  beacon();
}

void loop() {

  if((millis() - ts) < BEACON_DELAY) {
    #ifdef DEBUG
    delay(1000);
    Serial.print(millis());
    Serial.print(" - ");
    Serial.print(ts);
    Serial.print(" = ");
    Serial.print(millis() - ts);
    Serial.print(" (");
    Serial.print(BEACON_DELAY);
    Serial.println(")");
    #endif
    return;
  }

  beacon();
  ts = millis();
}
