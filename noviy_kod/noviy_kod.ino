#definew pwm_a 9
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
const int w[8] = { -4, -3, -2, -1, 1, 2, 3, 4};
int val[8] = {d1, d2, d3, d4, d5, d6, d7, d8};
static unsigned long t_prev;
static float e_prev = 0.0;
int v_avg = 128;
float reg;
float e;
unsigned long t;
// коэфы на подбор
float kp;
float kd;
float sum;
int cnt;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  evaluate();
  go(v_avg + reg, v_avg - reg);
}
void evaluate(){
  for (byte i = 0; i < 8; i++) {
    if (val[i] > 300) {
      sum += w[i];
      cnt++;
     }
  if (cnt > 0) {
    e = sum/(4 + cnt);
    reg = kp * e + kd * (e - e_prev) / (millis() - t_prev);
    e_prev = e;
  }
}

}

void go(byte v1, byte v2){
  digitalWrite(control_a_1, HIGH);
  digitalWrite(control_a_2, LOW);
  analogWrite(pwm_a, v1);
  digitalWrite(control_b_1, HIGH);
  digitalWrite(control_b_2, LOW);
  analogWrite(pwm_b, v2);
} 


