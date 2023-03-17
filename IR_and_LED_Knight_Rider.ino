void setup() {
  // 52 is for IR
  // 30, 32, 34, 36 is for yellow LED
  // 43, 45, 47, 49 is for red LED
  pinMode(52, INPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(49, OUTPUT);
}


void loop() {
  int time = 250;
  
  if(digitalRead(52) == LOW) {
    // if rays gets it's reflection (white surface) the red light is going to turn on and yellow will offed
    for(int j=43; j<50; j=j+2) {
      digitalWrite(j, HIGH);
      delay(time);
      digitalWrite(j, LOW);
      if(digitalRead(52) == HIGH){
        break;
      }
    }

    for(int i=30; i<37; i=i+2) {
      digitalWrite(i, LOW);
      if(digitalRead(52) == HIGH){
        break;
      }
    }

  }
  else{
    // if rays doesn't get it's reflection (black surface or no obstacle) the yellow light is going to turn on and red will offed
    for(int k=30; k<37; k=k+2) {
      digitalWrite(k, HIGH);
      delay(time);
      digitalWrite(k, LOW);
      if(digitalRead(52) == LOW){
        break;
      }
    }

    for(int l=43; l<50; l=l+2) {
      digitalWrite(l, LOW);
      if(digitalRead(52) == HIGH){
        break;
  
      }
    }
  }
}