/*
  Mach Phat - Bo phat gang tay (RF24)
  Tac gia: Tung Lam Automatic

  Mo ta:
  - Doc 5 cam bien flex tu A1..A5.
  - Map gia tri analog sang goc 0..180.
  - Gui du lieu qua nRF24L01.

  So do chan:
  - nRF24L01: CE = D9, CSN = D10 (SPI mac dinh)
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Tao doi tuong RF24
RF24 radio(9, 10); // CE, CSN

// Dia chi giao tiep giua 2 module
const byte address[6] = "00001";

byte msg[5]; // Goi du lieu 5 kenh

// Chan ket noi flex A1..A5
int flex_5 = A5;
int flex_4 = A4;
int flex_3 = A3;
int flex_2 = A2;
int flex_1 = A1;

int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;

void setup()
{
  Serial.begin(9600);
  radio.begin();

  // Mo kenh phat
  radio.openWritingPipe(address);
  radio.stopListening();
}

void loop()
{
  // Doc va map gia tri flex
  flex_5_val = analogRead(flex_5);
  flex_5_val = map(flex_5_val, 400, 600, 0, 180);

  flex_4_val = analogRead(flex_4);
  flex_4_val = map(flex_4_val, 400, 670, 0, 180);

  flex_3_val = analogRead(flex_3);
  flex_3_val = map(flex_3_val, 470, 770, 0, 180);

  flex_2_val = analogRead(flex_2);
  flex_2_val = map(flex_2_val, 460, 670, 0, 180);

  flex_1_val = analogRead(flex_1);
  flex_1_val = map(flex_1_val, 400, 620, 0, 180);

  // Dong goi du lieu
  msg[0] = flex_5_val;
  msg[1] = flex_4_val;
  msg[2] = flex_3_val;
  msg[3] = flex_2_val;
  msg[4] = flex_1_val;

  // Gui du lieu qua RF
  radio.write(msg, sizeof(msg));

  delay(100);
}
