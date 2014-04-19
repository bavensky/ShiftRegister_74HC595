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
int latchPin = 12;  // Pin connected to ST_CP 
int clockPin = 13;  // Pin connected to SH_CP 
int dataPin = 11;   // Pin connected to DS 

int A = 0;  int B = 0;

void setup() {
pinMode(latchPin, OUTPUT);  // Set pin output
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}

void loop() 
{
  // ฐาน 2  = 0B11111111
  // ฐาน 10 = 255
  // ฐาน 16 = 0xFF
  
  A = 0; B = 0B00000000; 
  
  Send(B,A);
  
  // A คือส่งข้อมูลเข้าไอซีตัวแรก
  // B คือส่งข้อมูลเข้าไอซีตัวที่สอง 
  
}

/*******************************************************************************
* MSB = Most significant bit  / LSB = Less significant bit                     *
* เช่น MSB---> 11000101 <--- LSB                                                *
* 1 ตัวซ้ายสุดคือ MSB และ 1 ตัวขวาสุดคือ LSB                                         *
* ถ้ากำหนดว่าส่งข้อมูลแบบ serial โดยส่ง LSB ก่อน                                     *
* เราก็ต้องจะส่งข้อมูล 1-0-1-0-0-0-1-1 ตามลำดับ                                      *
*******************************************************************************/
void Send(int ic2,int ic1)
{
  digitalWrite(latchPin, LOW);                
  shiftOut(dataPin, clockPin, LSBFIRST,ic2);  
  shiftOut(dataPin, clockPin, MSBFIRST,ic1);  
  digitalWrite(latchPin, HIGH);     
  delay(1000);
}

