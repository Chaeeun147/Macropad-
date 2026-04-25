#include <Keyboard.h>

const int NUM_KEYS = 9;

const int buttonPins[NUM_KEYS] = {D0, D1, D2, D3, D4, D5, D6, D7, D8}; 

// 225=1, 226=2, 227=3, 228=4, 229=5, 230=6, 231=7, 232=8, 233=9
const uint8_t keyCodes[NUM_KEYS] = {225, 228, 231, 226, 229, 232, 227, 230, 233};

bool previousState[NUM_KEYS] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {
  for (int i = 0; i < NUM_KEYS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < NUM_KEYS; i++) {
    bool currentState = digitalRead(buttonPins[i]);

    if (currentState == LOW && previousState[i] == HIGH) {
      Keyboard.press(keyCodes[i]);
      delay(50);
    } 
    else if (currentState == HIGH && previousState[i] == LOW) {
      Keyboard.release(keyCodes[i]);
      delay(50); 
    }

    previousState[i] = currentState;
  }
}