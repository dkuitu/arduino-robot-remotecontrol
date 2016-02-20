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
int speed = 80;

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

xmove = map(x, 994, 1980, -100, 100);
ymove = map(y, 994, 1980, -100, 100);

if (ymove>=10) { //move forward
  analogWrite(leftreverse,0);
  analogWrite(rightreverse,0);
  analogWrite(leftforward, speed);
  analogWrite(rightforward, speed);
  }
else if (ymove>=-10&&xmove>=-10&&xmove<10) { //stop
  analogWrite(leftforward,0);
  analogWrite(rightforward,0);
  analogWrite(leftreverse,0);
  analogWrite(rightreverse,0);
  }
else if (ymove>=-10&&xmove<-10) { //move left
  analogWrite(leftforward,0);
  analogWrite(rightforward,speed);
  analogWrite(leftreverse,speed);
  analogWrite(rightreverse,0);
  }
else if (ymove>=-10&&xmove>=10) { //move right
  analogWrite(leftforward,speed);
  analogWrite(rightforward,0);
  analogWrite(leftreverse,0);
  analogWrite(rightreverse,speed);
  }
else { // reverse
  analogWrite(leftforward,0);
  analogWrite(rightforward,0);
  analogWrite(leftreverse,speed);
  analogWrite(rightreverse,speed);
  }

}
