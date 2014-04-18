// IC Shift Register 74HC595
int latchPin = 12;
int clockPin = 13;
int dataPin = 11;

int A = 0;
int B = 0;

void setup() {
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}

void loop() 
{
  A = 0xFF; B = 255; Send(B,A); 
  // ฐาน 2  = 0B11111111
  // ฐาน 10 = 255
  // ฐาน 16 = 0xFF
}

void Send(int X2,int X1)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST,X2);
  shiftOut(dataPin, clockPin, MSBFIRST,X1); 
  digitalWrite(latchPin, HIGH);
  delay(1000);
}
