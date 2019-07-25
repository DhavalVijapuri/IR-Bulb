#include <IRremote.h>
#include <IRremoteInt.h>


int RECV_PIN=11;

IRrecv irrecv(RECV_PIN);
decode_results results ;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);
irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
if(irrecv.decode(&results))
{
  Serial.println(results.value, HEX);
 translateIR();
  irrecv.resume();
}
}
void translateIR()
{
  switch(results.value)
  {
    case 0x9716BE3F:
      digitalWrite(3,LOW);
    break;
     case 0x3D9AE3F7:
      digitalWrite(3,HIGH);
    break;
    case 0x77D7A320:
      digitalWrite(4,LOW);
    break;
    case 0x1FF256EE:
      digitalWrite(4,HIGH);
  }
}
