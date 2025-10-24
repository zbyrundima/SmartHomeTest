const int buttonPin = 7;
const int pinRed = 8;
const int pinYellow = 12;
const int pinGreen = 13;

int buttonState = 0;  // Variable to store the button state

void setup() {
  // Initialize LED pins as output
  pinMode(pinRed, OUTPUT);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinGreen, OUTPUT);

  // Initialize button pin as input
  pinMode(buttonPin, INPUT);

  // Ensure all LEDs are off at start
  digitalWrite(pinRed, LOW);
  digitalWrite(pinYellow, LOW);
  digitalWrite(pinGreen, LOW);
}

void loop() {
  // Read button state
  buttonState = digitalRead(buttonPin);

  // Enter while loop: run LED sequence until button is pressed
  while (digitalRead(buttonPin) == LOW) {
    // Turn on red LED
    digitalWrite(pinRed, HIGH);
    delay(300);
    digitalWrite(pinRed, LOW);
    delay(300);

    // Turn on yellow LED
    digitalWrite(pinYellow, HIGH);
    delay(300);
    digitalWrite(pinYellow, LOW);
    delay(300);

    // Turn on green LED
    digitalWrite(pinGreen, HIGH);
    delay(300);
    digitalWrite(pinGreen, LOW);
    delay(300);
  }

  // When button is pressed, turn off all LEDs and wait until released
  digitalWrite(pinRed, LOW);
  digitalWrite(pinYellow, LOW);
  digitalWrite(pinGreen, LOW);

  // Wait for button to be released before resuming
  while (digitalRead(buttonPin) == HIGH) {
    delay(10);  // small delay to avoid busy waiting
  }
}