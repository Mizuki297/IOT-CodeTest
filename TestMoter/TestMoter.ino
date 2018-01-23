int motorA;
int motorB;
void setup(){
  Serial.begin(11500);
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
}

void loop(){/.
 analogWrite(5,motorA);
 digitalWrite(1,HIGH);
}
