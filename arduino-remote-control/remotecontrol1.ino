int leftforward = 10;
int leftreverse = 11;
int rightforward = 6;
int rightreverse = 5;
int x = 3;
int y = 9;
int speed;

void setup() {
Serial.begin(9600);
pinMode(leftforward,OUTPUT);
pinMode(leftreverse,OUTPUT);
pinMode(rightforward,OUTPUT);
pinMode(rightforward,OUTPUT);
pinMode(x,INPUT);
pinMode(y,INPUT);
speed = 0;
}

void loop() {
x = digitalRead(x);
Serial.println('x');


    }
}
