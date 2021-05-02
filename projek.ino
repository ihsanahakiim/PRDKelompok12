int a,b,c,d;
int atas,bawah;
int posisi;

#include <Servo.h>
Servo myServo;   //
void setup() { //fungsi setup servo
  myServo.attach(9);
 Serial.begin(9600);
 posisi = 90;
 myServo.write(posisi);
 delay(1000);
}

void loop() { //inisiasi photosensor
  a = analogRead(0);
  b = analogRead(1);
  c = analogRead(2);
  d = analogRead(4);
Serial.println(" "); //menampilkan serial monitor besar cahaya serap photosensor
  Serial.print("a : ");
  Serial.println(a);
 Serial.print("b : ");
  Serial.println(b);
  Serial.print("c : ");
  Serial.println(c);
  Serial.print("d : ");
  Serial.println(d);
int atas = a+d;
int bawah = b+c;
if ((atas - bawah)> 1000) {
  posisi =- 3;
  if (posisi < 90 ) { //sudut minimum servo
    posisi = 90;
    }
  myServo.write(posisi);
  
  }
 else if ((atas - bawah)> 1000) {
  posisi += 3;
  if (posisi > 170 ) {
    posisi = 170;
    }
  myServo.write(posisi); //sudut maksimumm servo
  } 
  delay(30);
}
