Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@Kobchok1141 
Learn Git and GitHub without any code!
Using the Hello World guide, you’ll start a branch, write comments, and open a pull request.


Chawapon1108
/
Microprocessor-class-RAI1
1
01
 Code Issues 0 Pull requests 0 Actions Projects 0 Wiki Security Insights
Microprocessor-class-RAI1/LAB_4_Exercise_2.ino
@Chawapon1108 Chawapon1108 Create LAB_4_Exercise_2.ino
5e38758 5 minutes ago
83 lines (73 sloc)  1.5 KB
  
#include<SPI.h>

#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9
#define BUTTON_UP A0
#define BUTTON_DOWN A1
#define BUTTON_CD A2
#define PIEZO_PIN 3

int i;

int map7seg[10] = {
  0x3f, //0
  0x06, //1
  0x5b, //2
  0x4f, //3
  0x66, //4
  0x6d, //5
  0x7d, //6
  0x07, //7
  0x7f, //8
  0x6f, //9
};

void spi_write_1(unsigned char cData){
  shiftOut(DATA_PIN,CLOCK_PIN,MSBFIRST, cData);
  digitalWrite(SS_PIN_1,HIGH);
  digitalWrite(SS_PIN_1,LOW);

}
void spi_write_2(unsigned char cData){
  shiftOut(DATA_PIN,CLOCK_PIN,MSBFIRST, cData);
  digitalWrite(SS_PIN_2,HIGH);
  digitalWrite(SS_PIN_2,LOW);
}
void setup()
{
  Serial.begin(9600);
  pinMode(SS_PIN_1, OUTPUT);
  pinMode(SS_PIN_2, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_CD, INPUT_PULLUP);
  
  spi_write_2(map7seg[0]);
  spi_write_1(map7seg[0]);
}

void loop()
{ 
  /*for(int i = 0 ; i < 100 ; i++){
    int num1 = i/10;
    int num2 = i%10;
    spi_write_1(map7seg[num1]);
    spi_write_2(map7seg[num2]);
    delay(300);
  }*/
  
  if(digitalRead(BUTTON_UP)==0){
    delay(100);
    i++;
  }
  else if(digitalRead(BUTTON_DOWN)==0){
    delay(100);
    i--;
  }
  else if(digitalRead(BUTTON_CD) ==0){
    for(;i>0;i--){
      spi_write_1(map7seg[i/10]);
      spi_write_2(map7seg[i%10]);
      delay(1000);
    }
     tone(PIEZO_PIN, 500, 2000);
  }
    
    spi_write_1(map7seg[i/10]);
    spi_write_2(map7seg[i%10]);
  
}
© 2020 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
