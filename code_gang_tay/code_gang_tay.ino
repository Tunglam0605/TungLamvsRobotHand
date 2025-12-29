/*
  code_gang_tay - Bo phat gang tay (flex sensor)
  Tac gia: Tung Lam Automatic

  Mo ta:
  - Doc 5 cam bien flex (A1..A5).
  - Map gia tri analog thanh goc servo 0..180.
  - Gui du lieu qua nRF24L01.

  So do chan (Arduino):
  - nRF24L01: CE = D9, CSN = D10 (SPI mac dinh)
  - Flex sensor: A1..A5 (ung voi ngon tay)
*/

#include <SPI.h>   // Giao tiep SPI cho nRF24L01
#include "RF24.h" // Thu vien dieu khien nRF24L01

int msg[5]; // Goi du lieu gom 5 gia tri (5 ngon tay)

// Chan doc cam bien flex
int flex_5 = A5; // ngon cai
int flex_4 = A4;
int flex_3 = A3;
int flex_2 = A2;
int flex_1 = A1;

// Bien luu gia tri flex
int flex_5_val;
int flex_4_val;
int flex_3_val;
int flex_2_val;
int flex_1_val;
int flex_5_val1;
int flex_4_val1;
int flex_3_val1;
int flex_2_val1;
int flex_1_val1;

RF24 radio(9, 10); // CE, CSN
const uint64_t pipe = 0xE8E8F0F0E1LL; // Dia chi kenh truyen

void setup(void) {
  Serial.begin(57600);
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.setPALevel(RF24_PA_MIN); // Cong suat phat thap de on dinh
  radio.stopListening();         // Chuyen sang che do phat
}

void loop(void) {
  // Doc gia tri flex (ADC)
  flex_5_val = analogRead(flex_5);
  flex_5_val1 = map(flex_5_val, 640, 710, 0, 180);

  flex_4_val = analogRead(flex_4);
  flex_4_val1 = map(flex_4_val, 645, 750, 0, 180);

  flex_3_val = analogRead(flex_3);
  flex_3_val1 = map(flex_3_val, 848, 910, 0, 180);

  flex_2_val = analogRead(flex_2);
  flex_2_val1 = map(flex_2_val, 735, 815, 0, 180);

  flex_1_val = abs(analogRead(flex_1));
  flex_1_val1 = map(flex_1_val, 730, 815, 0, 180);

  // Dong goi du lieu
  msg[0] = flex_5_val1;
  msg[1] = flex_4_val1;
  msg[2] = flex_3_val1;
  msg[3] = flex_2_val1;
  msg[4] = flex_1_val1;

  // Gioi han goc an toan
  msg[0] = constrain(msg[0], 0, 180);
  msg[1] = constrain(msg[1], 0, 180);
  msg[2] = constrain(msg[2], 0, 180);
  msg[3] = constrain(msg[3], 0, 180);
  msg[4] = constrain(msg[4], 0, 180);

  // Gui du lieu qua RF
  radio.write(msg, sizeof(msg));

  // Debug neu can
  // Serial.print(msg[0]); Serial.print("  ");
  // Serial.print(msg[1]); Serial.print("  ");
  // Serial.print(msg[2]); Serial.print("  ");
  // Serial.print(msg[3]); Serial.print("  ");
  // Serial.println(msg[4]);
}

// Ghi chu: Co the dung bo loc Kalman de on dinh tin hieu flex.
// #include <SimpleKalmanFilter.h>
// SimpleKalmanFilter bo_loc(1, 1, 0.01);
// u_kalman = bo_loc.updateEstimate(val);
// u_kalman = map(u_kalman, 550, 750, 0, 180);
