/*
  Mach Thu - Bo thu dieu khien ban tay robot (RF24)
  Tac gia: Tung Lam Automatic

  Mo ta:
  - Nhan 5 kenh goc servo qua nRF24L01.
  - Dieu khien 5 servo tuong ung ngon tay.

  So do chan:
  - nRF24L01: CE = D9, CSN = D10 (SPI mac dinh)
  - Servo: D8, D7, D6, D5, D4
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

// Tao doi tuong RF24
RF24 radio(9, 10); // CE, CSN

// Dia chi giao tiep giua 2 module
const byte address[6] = "00001";

// Khai bao servo
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

byte msg[5];

void setup()
{
  while (!Serial);
  Serial.begin(9600);

  // Gan chan servo
  myServo1.attach(8);
  myServo2.attach(7);
  myServo3.attach(6);
  myServo4.attach(5);
  myServo5.attach(4);

  // Khoi tao RF
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
  Serial.println("START");
}

void loop()
{
  if (radio.available())
  {
    radio.read(msg, sizeof(msg));

    // In gia tri nhan
    Serial.print("CH4: "); Serial.println(msg[4]);
    Serial.print("CH3: "); Serial.println(msg[3]);
    Serial.print("CH2: "); Serial.println(msg[2]);
    Serial.print("CH1: "); Serial.println(msg[1]);
    Serial.print("CH0: "); Serial.println(msg[0]);

    // Dieu khien servo theo goc nhan
    myServo1.write(msg[4]); // A1
    myServo2.write(msg[3]); // A2
    myServo3.write(msg[2]); // A3
    myServo4.write(msg[1]); // A4
    myServo5.write(msg[0]); // A5

    delay(100);
  }
}
