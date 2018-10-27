#define pwm_a 9
#define pwm_b 10
#define control_a_1 2
#define control_a_2 3
#define control_b_1 4
#define control_b_2 5
#define d1 A0
#define d2 A1
#define d3 A2
#define d4 A3
#define d5 A4
#define d6 A5
#define d7 A6
#define d8 A7
int ds[8] = {d1, d2, d3, d4, d5, d6, d7, d8};
byte w = 0;
byte b = 0;
bool rl;
int val;

void setup() {
  

}

void loop() {
  if (b == 8){
    forwardAll(255);
   }
  else{
    if (rl){
      forward(0, 255);
      forward(1, 255-32*w);
    }
    else{
      forward(1, 255);
      forward(0, 255-32*w);
    }
  }
}


void getVal(int arr[8]){
  for (int i = 0; i < 8; i++){
    val = analogRead(arr[i]);
    if (val < 400){
      w++;
    }
    else if (val > 400){
      b++;
    if (i == 0){
      if (val < 400){
        rl = 1;
      }
      else{
        rl = 0;
      }
    }
    }
  }
}

void hold(bool motor) {
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

void forward(bool motor, byte sp) {
  if (!motor) {
    digitalWrite(control_a_1, HIGH);
    digitalWrite(control_a_2, LOW);
  }
  else {
    digitalWrite(control_b_1, HIGH);
    digitalWrite(control_b_2, LOW);
  }
}

void backward(bool motor, byte sp) {
  if (!motor) {
    digitalWrite(control_a_1, LOW);
    digitalWrite(control_a_2, HIGH);
  }
  else {
    digitalWrite(control_b_1, LOW);
    digitalWrite(control_b_2, HIGH);
  }
}

void backwardAll(byte sp) {
  backward(0, sp);
  backward(1, sp);
}

void forwardAll(byte sp) {
  forward(0, sp);
  forward(1, sp);
}

void turnLeft(byte sp) {
  forward(0, sp);
  forward(1, 255);
}

void turnRight(byte sp) {
  forward(0, 255);
  forward(1, sp);
}

void brakeAll() {
  brake(0);
  brake(1);
}

void holdAll() {
  hold(0);
  hold(1);
}
