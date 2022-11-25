#include <Stepper.h>
// Define number of steps per rotation:
const int stepsPerRevolution = 174; //2084 is about 72 deg

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

const int buttonPin = 12;
const int buzzer = 7;
int buttonState = 0;

int OptoPin = 13;

void setup() {
  // Set the speed to 5 rpm:
  myStepper.setSpeed(10);

  pinMode(OptoPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzer, OUTPUT);

  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println("button pressed");

    for (int i = 0; i < 62; i++) {
      myStepper.step(stepsPerRevolution);
      delay(1000);
      digitalWrite(OptoPin, LOW);
      delay(1000);
      digitalWrite(OptoPin, HIGH);
      delay(1000);
    }

    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
  }

  else {
    Serial.println("button not pressed");
  }

}
