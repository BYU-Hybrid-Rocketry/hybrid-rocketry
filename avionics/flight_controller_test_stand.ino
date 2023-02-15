enum State {
  STATE_1,
  STATE_2,
  STATE_3
};

State currentState = STATE_1;

const int pin1 = 2;
const int pin2 = 3;
const int pin3 = 4;
const int masterPin = 5;

void setup() {
    pinMode(masterPin, INPUT);
    pinMode(pin1, INPUT);
    pinMode(pin2, INPUT);
    pinMode(pin3, INPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    Serial.println("Starting up...");
    // Wait for master to be HIGH before program can execute
    while (digitalRead(masterPin) == LOW) {
        delay(1000);
    }
}



void loop() {
    int state1 = digitalRead(pin1);
    int state2 = digitalRead(pin2);
    int state3 = digitalRead(pin3);

    if (state1 == HIGH && state2 == LOW && state3 == LOW) {
    currentState = STATE_1;
    } else if (state1 == LOW && state2 == HIGH && state3 == LOW) {
    currentState = STATE_2;
    } else if (state1 == LOW && state2 == LOW && state3 == HIGH) {
    currentState = STATE_3;
    }

    switch (currentState) {
    case STATE_1:
        digitalWrite(13, HIGH);
        Serial.println("Current state: STATE_1");
        break;
    case STATE_2:
        digitalWrite(13, LOW);
        Serial.println("Current state: STATE_2");
        break;
    case STATE_3:
        digitalWrite(13, HIGH);
        Serial.println("Current state: STATE_3");
        break;
    }
}
