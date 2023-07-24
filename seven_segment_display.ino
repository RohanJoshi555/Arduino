//Author: Rohan Joshi
//Project: Using ESP 32 and a single seven segment display to display hexadecimal numbers 0-9 and A-F 
int displaypin[7]={15,2,4,5,18,19,21};
byte numarray[16][7]={  {0,0,0,0,0,0,1},   //0
                       {1,1,0,0,1,1,1},   //1
                       {0,0,1,0,0,1,0},   //2
                       {1,0,0,0,0,1,0},   //3
                       {1,1,0,0,1,0,0},   //4
                       {1,0,0,1,0,0,0},   //5
                       {0,0,0,1,0,0,0},   //6
                       {1,1,0,0,0,1,1},   //7
                       {0,0,0,0,0,0,0},   //8
                       {1,0,0,0,0,0,0},   //9
                       {0,1,0,0,0,0,0},   //A
                       {0,0,0,0,0,0,0},   //B Same as 8
                       {0,0,1,1,0,0,1},   //C
                       {0,0,0,0,0,0,1},   //D Same as 0
                       {0,0,1,1,0,0,0},   //E
                       {0,1,1,1,0,0,0}    //F
                      };

void setup() {
  for(int i=0;i<7;i++)
  {
    pinMode(displaypin[i],OUTPUT);
    digitalWrite(displaypin[i],LOW);
    delay(500);
  }
}

void loop() {
  for(int i=0;i<16;i++)
  {
    delay(1000);
    Display(i);
  }
}

void Display(int number){
  for(int i=0;i<7;i++)
  {
    digitalWrite(displaypin[i],numarray[number][i]);
  }
}
