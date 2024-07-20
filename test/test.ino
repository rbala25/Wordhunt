#include <Servo.h>

Servo front;
Servo pen;
Servo rear;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5000); 
  pinMode(13, OUTPUT);

  rear.write(60);
  front.write(140);
  pen.write(0);
  //100 for extended pen

  front.attach(9); 
  rear.attach(10);
  pen.attach(11);

  delay(1000);
  fifteen();
  delay(200);
  pen.write(100);

  
}

void loop() {
  // put your main code here, to run repeatedly:

}


void one() {
  rear.write(48); 
  front.write(47); 
}

void two() {
  rear.write(39); //47
  front.write(41); //50
}

void three() {
  rear.write(29);
  front.write(35);
}

void four() {
  rear.write(20);
  front.write(31);
}

void five() {
  rear.write(45);
  front.write(37);
}

void six() {
  rear.write(36);
  front.write(31);
}

void seven() {
  rear.write(26);
  front.write(26);
}

void eight() {
  rear.write(17);
  front.write(23);
}

void nine() {
  rear.write(44);
  front.write(29);
}

void ten() {
  rear.write(34);
  front.write(24);
}

void eleven() {
  rear.write(23);
  front.write(16);
}

void twelve() {
  rear.write(12);
  front.write(12);
}

void thirteen() {
  rear.write(44);
  front.write(21);
}

void fourteen() {
  rear.write(34);
  front.write(16);
}

void fifteen() {
  rear.write(21);
  front.write(9);
}

void sixteen() {
  rear.write(9);
  front.write(2);
}

