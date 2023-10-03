#define sensorSentuh 2
const int buzzer = 4;
const int relay = 3;
void setup() {
Serial.begin(9600);
pinMode(sensorSentuh, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(relay, OUTPUT);
digitalWrite(relay,HIGH);
}

void loop() {
int kondisi = digitalRead(sensorSentuh);

if(kondisi==1) // saat disentuh
{
  digitalWrite(relay,LOW);
  digitalWrite(buzzer,HIGH);
} 
if(kondisi==0) //tidak disentuh
{ 
  digitalWrite(relay,HIGH);
  digitalWrite(buzzer,LOW);
}
}
