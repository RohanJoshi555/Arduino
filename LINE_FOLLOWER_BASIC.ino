//Author: Rohan Joshi
//Project: Black Line Follower Robot using two Infrared Sensors

int IN1=8,IN2=9,IN3=10,IN4=11; //Supplies input to L298N Driver Module IN1,IN2,IN3,IN4 pins
int IR1=6,IR2=7;               //Receives output from the 2 IR Sensors  
int IR1STATE,IR2STATE;
void setup() {
  pinMode(IR1,INPUT);pinMode(IR2,INPUT);
  pinMode(IN1,OUTPUT);pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);pinMode(IN4,OUTPUT);
}

void loop() {
  
  IR1STATE=digitalRead(IR1);IR2STATE=digitalRead(IR2);//When sensor recieves transmitted(sensor is not above black)ir light
  if(IR1STATE==HIGH && IR2STATE==HIGH)                //output of the sensor is low otherwise high
  {
    digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);
    //Serial.print("GO STRAIGHT\n");
  }
  else if(IR1STATE==LOW && IR2STATE==HIGH)
  {
    digitalWrite(IN1,HIGH);digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);
    //Serial.print("TURN LEFT\n");
  }
  else if(IR1STATE==HIGH && IR2STATE==LOW)
  {
    digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);digitalWrite(IN4,HIGH);
    //Serial.print("TURN RIGHT\n");
  }
  else if(IR1STATE==LOW && IR2STATE==LOW)
  {
    digitalWrite(IN1,HIGH);digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);digitalWrite(IN4,HIGH);
    //Serial.print("STOP\n");
  }

}
