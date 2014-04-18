/*******************************************************************************
 * Project  : IC Shift Register 74HC595                                        *
 * Compiler : Arduino 1.5.2                                                    *
 * Board    : Arduino DUE                                                      *
 * Device   : 74HC595 LED                                                      *
 * Link     : http://myfunnyelectronics.blogspot.in/2014/04/blog-post.html     * 
 * Author   : Bavensky :3                                                      *
 * E-Mail   : Aphirak_Sang-ngenchai@hotmail.com                                *
 * Date     : 18/04/2014 [dd/mm/yyyy]                                          *
 *******************************************************************************/
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
  // ฐาน 2  = 0B11111111
  // ฐาน 10 = 255
  // ฐาน 16 = 0xFF
  
  A = 0xFF; B = 255; Send(B,A); 
  
}

void Send(int ic2,int ic1)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST,ic2);
  shiftOut(dataPin, clockPin, MSBFIRST,ic1); 
  digitalWrite(latchPin, HIGH);
  delay(1000);
}
