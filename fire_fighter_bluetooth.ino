char t;
char state=n;
int speed=0;

//h-bridge pins
int R_PWM =5 ; int L_PWM = 6; int R_PWM1 =9; int L_PWM1 = 10;



void setup() {
  pinMode(R_PWM, OUTPUT); pinMode(L_PWM, OUTPUT); pinMode(R_PWM1, OUTPUT); pinMode(L_PWM1, OUTPUT);
  analogWrite(R_PWM, 0); analogWrite(L_PWM, 0); analogWrite(R_PWM1, 0); analogWrite(L_PWM1, 0);
  delay(2000);
Serial.begin(9600);
 
}



void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
while(t == 'F'){            //move forward(all motors rotate in forward direction)
  F();
}
 
while(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  B();
}
 
while(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  L();
}
 
while(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  R();
}

delay(100);
}



 void F(){
  park(state);
  state='f';
  if(speed<230){
  for(speed=0;speed<230;speed++){
    analogWrite(R_PWM, speed);
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM1, speed);
    analogWrite(L_PWM1, 0);
    delay(5);}}
    analogWrite(R_PWM, 230);
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM1, 230);
    analogWrite(L_PWM1, 0);
    
 }
 void B(){
   park(state);
  state='b';
  if(speed<230){
  for(speed=0;speed<230;speed++){
    analogWrite(R_PWM, 0);
    analogWrite(L_PWM, speed);
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, speed);
    delay(5);}}
    analogWrite(R_PWM, 0);
    analogWrite(L_PWM, 230);
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, 230);
 }
 void R(){
  park(state);
  state='r';
  if(speed<180){
  for(speed=0;speed<180;speed++){
    analogWrite(R_PWM, speed);
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, speed);
    delay(5);}}
    analogWrite(R_PWM, 180);
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, 180);
 }
 void L(){
  park(state);
  state='l';
  if(speed<180){
  for(speed=0;speed<180;speed++){
    analogWrite(R_PWM, 0);
    analogWrite(L_PWM, speed);
    analogWrite(R_PWM1, speed);
    analogWrite(L_PWM1, 0);
    delay(5);}}
    analogWrite(R_PWM, 0);
    analogWrite(L_PWM, 180);
    analogWrite(R_PWM1, 180);
    analogWrite(L_PWM1, 0);
 }
 void park(char s){
  switch(s){
    case 'f':
     for(speed;speed>0;speed--){
    analogWrite(R_PWM, speed);
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM1, speed);
    analogWrite(L_PWM1, 0);
    delay(5);}
    break;

    case 'b':
    for(speed;speed>0;speed--){
    analogWrite(R_PWM, 0);
    analogWrite(L_PWM, speed);
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, speed);
    delay(5);}

    break;
    case 'r':
    for(speed;speed>0;speed--){
    analogWrite(R_PWM, speed);
    analogWrite(L_PWM, 0);
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM1, speed);
    delay(5);}
    break;
    case'l':
     for(speed;speed>0;speed--){
    analogWrite(R_PWM, 0);
    analogWrite(L_PWM, speed);
    analogWrite(R_PWM1, speed);
    analogWrite(L_PWM1, 0);
    delay(5);}
    break;
    }
  }
 
