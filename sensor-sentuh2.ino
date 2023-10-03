#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);




#define sensorSentuh 2
const int Relay = 3;
const int buzzer = 4;
int statusLampu = 0;


void setup() {
Serial.begin(9600);
pinMode(sensorSentuh, INPUT);
pinMode(Relay, OUTPUT);
pinMode(buzzer, OUTPUT);
digitalWrite(Relay,HIGH);
}

void loop() {
int kondisi = digitalRead(sensorSentuh);

if(kondisi==1) //saat disentuh
{
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  if(statusLampu==0) 
  { Serial.println("Lampu Hidup"); 
    lcd.setCursor(2, 0);
    lcd.print("di sentuh");
    statusLampu=1;
    digitalWrite(Relay,LOW); // hidupkan lampu
  }
  
  else
  {
    Serial.println("mati");
    lcd.setCursor(1, 1);
    lcd.print("tidak disentuh"); 
    statusLampu=0;
    digitalWrite(Relay,HIGH);
  }
}

Serial.println(statusLampu);
delay(500);
}
