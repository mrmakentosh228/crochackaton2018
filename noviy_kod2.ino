#define pwm_a 9
#define pwm_b 10
#define control_a_1 2
#define control_a_2 3
#define control_b_1 5
#define control_b_2 7
#define d1 A0
#define d2 A1
#define d3 A2
#define d4 A3
#define d5 A4
#define d6 A5
#define d7 A6
#define d8 A7
const int w[8] = { -4, -3, -2, -1, 1, 2, 3, 4};
int val[8] = {d1, d2, d3, d4, d5, d6, d7, d8};
static unsigned long t_prev = 0;
static float e_prev = 0.0;
int v_avg = 150;
float reg = 0.0;
float e = 0.0;
unsigned long t;
// коэфы на подбор
float kp = 60;
float kd = 60;
float sum;
int cnt;

void setup() {
  pinMode(control_a_1, OUTPUT);
  pinMode(control_a_2, OUTPUT);
  pinMode(control_b_1, OUTPUT);
  pinMode(control_b_2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  t = millis();
  evaluate();
  byte speed_left = v_avg - reg;
  byte speed_right = v_avg + reg;
  //Serial.print("Left: " + String(speed_left) + " Right: " + String(speed_right));
  // new string in serial port
  //Serial.println();
  go(speed_right, speed_left);
}
void evaluate() {
  for (byte i = 0; i < 8; i++) {
    unsigned int sensor_data = analogRead(val[i]);
    if (sensor_data > 300) {
      sum += w[i];
      cnt++;
    }
  }
  if (cnt > 0) {
    e = sum / (4 * cnt);
    Serial.println(e);  
    if (t - t_prev > 0) {
      reg = kp * e + kd * (e - e_prev) / (t - t_prev);
    }
    else {
      reg = kp * e + kd * (e - e_prev);
    }
    e_prev = e;
    t_prev = t;
    sum = 0.0;
    cnt = 0;
  }
}

void go(byte v1, byte v2) {
  digitalWrite(control_a_1, HIGH);
  digitalWrite(control_a_2, LOW);
  analogWrite(pwm_a, v1);
  digitalWrite(control_b_1, HIGH);
  digitalWrite(control_b_2, LOW);
  analogWrite(pwm_b, v2);
}


