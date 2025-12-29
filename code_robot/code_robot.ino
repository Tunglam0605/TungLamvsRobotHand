/*
  code_robot - Bo thu dieu khien ban tay robot
  Tac gia: Tung Lam Automatic

  Mo ta:
  - Nhan du lieu 5 kenh qua nRF24L01.
  - Dieu khien 5 servo tuong ung 5 ngon tay.

  So do chan (Arduino):
  - nRF24L01: CE = D9, CSN = D10 (SPI mac dinh)
  - Servo: D4, D5, D6, D7, D8
*/

#include <Servo.h> // Thu vien dieu khien servo
#include <SPI.h>   // Giao tiep SPI
#include "RF24.h"  // Thu vien nRF24L01

// Khai bao servo
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

RF24 radio(9, 10); // CE, CSN
const uint64_t pipe = 0xE8E8F0F0E1LL; // Dia chi kenh truyen

int msg[5]; // Goi du lieu 5 gia tri

void setup() {
  Serial.begin(9600);

  // Gan chan servo
  myServo1.attach(4); // A1
  myServo2.attach(5); // A2
  myServo3.attach(6); // A3
  myServo4.attach(7); // A4
  myServo5.attach(8); // A5

  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&msg, sizeof(msg)); // Doc du lieu RF
    delay(20);

    // Debug gia tri nhan
    Serial.print(msg[0]); Serial.print("    ");
    Serial.print(msg[1]); Serial.print("    ");
    Serial.print(msg[2]); Serial.print("    ");
    Serial.print(msg[3]); Serial.print("    ");
    Serial.println(msg[4]);

    // Dieu khien servo (dao thu tu theo mapping cam bien)
    myServo1.write(msg[4]); // A1
    myServo2.write(msg[3]); // A2
    myServo3.write(msg[2]); // A3
    myServo4.write(msg[1]); // A4
    myServo5.write(msg[0]); // A5
  } else {
    Serial.println("Khong nhan duoc du lieu");
    myServo1.write(0);
    myServo2.write(0);
    myServo3.write(0);
    myServo4.write(0);
    myServo5.write(0);
  }
}
