const int ledPin = 13; // Pin number for the built-in LED
const int buzzerPin = 8; // Pin number for the Buzzer

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if(digitalRead(2) == HIGH)  // If the button will be pressed then only the code will run otherwise there will be nothing to observe
  {
  morseCodeGenerator("MEHTA");  // It will blink code for "KANISHQ" --> "-.- .- -. .. ... .... --.-"
  delay(3000); // Delay between repetitions
  }
  else{
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}

void morseCodeGenerator(const char* name) {
  // Morse code for all 26 alphabets
  const char* morseCode[] = {
    ".-",   // A --0
    "-...", // B --1
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
  };

  for (int i = 0; name[i] != '\0'; i++) {
    if (name[i] == ' ') {
      delay(7 * 300); // It it recognizes a space then it will give a longer delay
    } else {
      int index = name[i] - 'A'; // Gives the index after a particular calculation
      if (index >= 0 && index < 26) {
        const char* letterCode = morseCode[index];
        for (int j = 0; letterCode[j] != '\0'; j++) {
          if (letterCode[j] == '.') {
            digitalWrite(ledPin, HIGH);
            tone(buzzerPin, 400); // buzzer tuner
            delay(300); // Duration of a dot
            digitalWrite(ledPin, LOW);
            noTone(buzzerPin); // stops the buzer
          } else if (letterCode[j] == '-') {
            digitalWrite(ledPin, HIGH);
            tone(buzzerPin, 400);
            delay(900); // Duration of a dash
            digitalWrite(ledPin, LOW);
            noTone(buzzerPin);
          }
          delay(300); // Pause between blinks
        }
        delay(900); // Pause between letters
      }
    }
  }
}
