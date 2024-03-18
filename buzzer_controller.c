#define BUTTON_PIN 2
#define BUZZER_PIN 8

int SOUND_DURATION = 500;
int SILENCE_DURATION = 600;
int MELODY[] = {1, 1, 5, 5, 6, 6, 5, 0, 4, 4, 3, 3, 2, 2, 1};
int melodyLength = sizeof(MELODY);

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    playMelody();
    // Wait for the button to be released
    while (digitalRead(BUTTON_PIN) == LOW) {
      delay(10); // Debouncing delay
    }
  }
}

void playMelody() {
  for (int i = 0; i < melodyLength; i++) {
    int note = MELODY[i];
    if (note == 0) {
      // No sound
      delay(SOUND_DURATION);
    } else {
      // Play the note
      tone(BUZZER_PIN, getNoteFrequency(note), SOUND_DURATION);
    }
    // Delay between notes
    delay(SILENCE_DURATION);
  }
}

int getNoteFrequency(int note) {
  switch (note) {
    case 1: return 262; // Do (Low)
    case 2: return 294; // Re
    case 3: return 330; // Mi
    case 4: return 349; // Fa
    case 5: return 392; // Sol
    case 6: return 440; // La
    case 7: return 494; // Si
    case 8: return 523; // Do (High)
    default: return 0; // No sound
    }
}