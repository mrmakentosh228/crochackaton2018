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

void setup() {
  

}

void loop() {
  if (b == 8){
    forwardAll(255);
   }
  else{
    if rl{
      forward(0, 255);
      forward(1, 255-32*w);
    }
    else{
      forward(1, 255);
      forward(0, 255-32*w);
    }
  }
}


void getVal(arr){
  for (byte i, i < 8, i++){
    val = analogRead(arr[i]);
    if (val < 400){
      w++;
    }
    else if (val > 400){
      b++;
    if (i == 0){
      if (val < 400){
        rl = True
      }
      else{
        rl = False
      }
    }
    }
  }
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
