<div align="center">
  <h1>Robot Ban Tay</h1>
  <p><strong>Dieu khien ban tay robot bang gang tay flex sensor</strong></p>
  <p>nRF24L01 + 5 Servo + Flex Sensor</p>
  <p>Tac gia: Tung Lam Automatic</p>
  <p>
    <img src="https://img.shields.io/badge/Board-Arduino-0B7C3E" />
    <img src="https://img.shields.io/badge/Radio-nRF24L01-1D4ED8" />
    <img src="https://img.shields.io/badge/Sensor-Flex-DC2626" />
    <img src="https://img.shields.io/badge/Actuator-Servo-F97316" />
  </p>
</div>

---

## Gioi thieu
Thu muc nay gom cac chuong trinh dieu khien ban tay robot bang gang tay co cam bien flex. Du lieu tu gang tay duoc gui qua nRF24L01 va robot nhan de dieu khien 5 servo tuong ung 5 ngon tay.

## Cau truc thu muc
- `code_gang_tay/code_gang_tay.ino` - Bo phat gang tay (doc flex, gui RF).
- `code_robot/code_robot.ino` - Bo thu dieu khien servo (nhan RF).
- `Mach Phat/MainCode/MainCode.ino` - Phien ban bo phat don gian.
- `Mach Thu/MainCode/MainCode.ino` - Phien ban bo thu don gian.

## Phan cung can thiet
- 2 Arduino (1 bo phat, 1 bo thu).
- 2 module nRF24L01.
- 5 cam bien flex (A1..A5).
- 5 servo.

## So do chan dau noi

### Bo phat
- nRF24L01: CE = D9, CSN = D10, SPI mac dinh.
- Flex: A1..A5.

### Bo thu
- nRF24L01: CE = D9, CSN = D10, SPI mac dinh.
- Servo: D4..D8 (tuy file se map khac mot chut).

> Luu y: Can cap nguon on dinh cho servo va noi chung GND voi Arduino.

## Cach nap
1. Nap bo phat: `code_gang_tay.ino` hoac `Mach Phat/MainCode.ino`.
2. Nap bo thu: `code_robot.ino` hoac `Mach Thu/MainCode.ino`.
3. Dieu chinh ham `map()` theo cam bien flex thuc te.

## Hieu chinh
- Thay doi gia tri `map()` de phu hop do cong/tang tay.
- Neu servo bi nguoc, hoan doi thu tu kenh hoac doi goc gui.

## Tac gia
Tung Lam Automatic

