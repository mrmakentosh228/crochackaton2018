void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void release() {
  digitalWrite(control_1, LOW);
  digitalWrite(control_2, LOW);
}

void brake() {
  digitalWrite(control_1, HIGH);
  digitalWrite(control_2, HIGH);
}

void forward() {
  digitalWrite(control_1, HIGH);
  digitalWrite(control_2, LOW);
}

void backrward() {
  digitalWrite(control_1, LOW);
  digitalWrite(control_2, HIGH);
}
