#define pwm_a 9
#define pwm_b 10
#define control_a_1 2
#define control_a_2 3
#define control_b_1 4
#define control_b_2 5

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void release(bool motor) {
  if (!motor) {
    digitalWrite(control_a_1, LOW);
    digitalWrite(control_a_2, LOW);
  }
  else {
    digitalWrite(control_b_1, LOW);
    digitalWrite(control_b_2, LOW);
  }
}

void brake(bool motor) {
  if (!motor) {
    digitalWrite(control_a_1, HIGH);
    digitalWrite(control_a_2, HIGH);
  }
  else {
    digitalWrite(control_b_1, HIGH);
    digitalWrite(control_b_2, HIGH);
  }
}

void forward(bool motor) {
  if (!motor) {
    digitalWrite(control_a_1, HIGH);
    digitalWrite(control_a_2, LOW);
  }
  else {
    digitalWrite(control_b_1, HIGH);
    digitalWrite(control_b_2, LOW);
  }
}

void backrward(bool motor) {
  if (!motor) {
    digitalWrite(control_a_1, LOW);
    digitalWrite(control_a_2, HIGH);
  }
  else {
    digitalWrite(control_b_1, LOW);
    digitalWrite(control_b_2, HIGH);
  }
}
