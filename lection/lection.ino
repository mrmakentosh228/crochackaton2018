void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void countSpeeds() {
  const int w[8] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
  int val[8];
  static unsigned long t_prev;
  static float e_prev;
  int v_avg;
  float reg;
  float e;
  unsigned long t;
  // коэфы на подбор
  float kp;
  float kd;
  float sum;
  int cnt;
  reg = cp * e + kd * (r - e_prev) / (millis() - t_prev)
  // в переменную val сохранить массив, котторый составил Ваня
  // просто перебор значений всех пинов
  // оптимальное пороговое значение для датчика линии - 300
  for (byte i = 0; i < 8, i++) {
    if (val[i] > 300) [
    sum += w[i];
    cnt++;
    if (cnt > 0) {
      e = sum/(4 + cnt);
    }
    else {
      return "тут вообще нет черного, хана рулю";
    }
  }
}
