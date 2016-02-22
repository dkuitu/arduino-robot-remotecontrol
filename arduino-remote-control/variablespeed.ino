int leftforward = 10;
int leftreverse = 11;
int rightforward = 6;
int rightreverse = 5;
int xpin = 3;
int ypin = 9;
unsigned long x;
unsigned long y;
int xmove;
int ymove;
int speed = 100;


void setup() {
Serial.begin(9600);
pinMode(leftforward,OUTPUT);
pinMode(leftreverse,OUTPUT);
pinMode(rightforward,OUTPUT);
pinMode(rightforward,OUTPUT);
pinMode(xpin,INPUT);
pinMode(ypin,INPUT);
}

void loop() {
x = pulseIn(xpin,HIGH);
y = pulseIn(ypin,HIGH);
Serial.print(xmove);
Serial.print(" | ");
Serial.println(ymove);
delay(100);

xmove = map(x, 994, 1980, -125, 125);
ymove = map(y, 994, 1980, -125, 125);


stoppedorreverse();
moveforward();
moveleft();
moveright();

}

int moveforward(void){
if (ymove>=10) { //move forward
  analogWrite(leftreverse,0);
  analogWrite(rightreverse,0);
  analogWrite(leftforward, ymove );
  analogWrite(rightforward, ymove);
  }
}
int stoppedorreverse(void){
if (ymove>=-10&&xmove>=-10&&xmove<10) { //stop
  analogWrite(leftforward,0);
  analogWrite(rightforward,0);
  analogWrite(leftreverse,0);
  analogWrite(rightreverse,0);
  }
  else
  { // reverse
  analogWrite(leftforward,0);
  analogWrite(rightforward,0);
  analogWrite(leftreverse,-ymove);
  analogWrite(rightreverse,-ymove);
  }
}
int moveleft(void) {
if (ymove>=-10&&xmove<-10) { //move left
  analogWrite(leftforward,ymove*.5);
  analogWrite(rightforward,ymove*2);
  analogWrite(leftreverse,0);
  analogWrite(rightreverse,0);
  }
}
int moveright(void){
if (ymove>=-10&&xmove>=10) { //move right
  analogWrite(leftforward,ymove*2);
  analogWrite(rightforward,ymove*.5);
  analogWrite(leftreverse,0);
  analogWrite(rightreverse,0);
  }
}
