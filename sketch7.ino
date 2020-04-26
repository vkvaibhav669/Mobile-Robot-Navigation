#define lmp 10
#define lmn 11
#define rmp 8
#define rmn 9
#define a 40

#define rT 7//right
#define rE 6
#define lT 5//left
#define lE 4
#define fT 3//front
#define fE 2
int duration=0,cm=0;
int f;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT); 
  
  
  pinMode(lT,OUTPUT);
  pinMode(lE,INPUT);
  
  pinMode(rT,OUTPUT);
  pinMode(rE,INPUT);
  
  pinMode(fT,OUTPUT);
  pinMode(fE,INPUT);
  


}

void loop() {
  // put your main code here, to run repeatedly:
  
 digitalWrite(fT,LOW);
 delayMicroseconds(2);
 digitalWrite(fT,HIGH);
 delayMicroseconds(5);
 digitalWrite(fT,LOW);
 
 duration=pulseIn(fE,HIGH);
 cm=duration/29/2;
 Serial.println(cm);
 if(cm<30)
 {
  stops();
  delay(60);
  backward();
  delay(60);
  
  f= scanRight();
  if(f<20)
  {
    right();
    delay(60);
  }
  else
  {
    f=scanLeft();
    if(f<20)
    {
      left();
      delay(60);
    }
    else
    {
      //f=scanFront();
      backward();
    }
    
  }
  
  
  
  
  //right();




  
  delay(50);
 }
 else
 {
 forward();
 delay(10);
 }
}


 void backward()
  {
  analogWrite(lmp,0);
  analogWrite(lmn,4*a);
  analogWrite(rmn,0);
  analogWrite(rmp,4*a);
  Serial.println("Backward");
  }    
  void stops()
  {
  analogWrite(lmp,0);
  analogWrite(lmn,0);
  analogWrite(rmn,0);
  analogWrite(rmp,0);

  Serial.println("Stopped");
  }
void forward()
{
  analogWrite(lmp,a);
  analogWrite(lmn,0);
  analogWrite(rmn,a);
  analogWrite(rmp,0);

  Serial.println("Forward");
}

void left()
{
  analogWrite(lmp,15*a);
  analogWrite(lmn,0);
  analogWrite(rmn,0);
  analogWrite(rmp,15*a);
  Serial.println("left");
  
}

void right()
{
  analogWrite(lmp,0);
  analogWrite(lmn,15*a);
  analogWrite(rmn,15*a);
  analogWrite(rmp,0);
  Serial.println("right");
}
 
//Function definitions are in next tab

int scanRight()
{
digitalWrite(rT,LOW);
 delayMicroseconds(2);
 digitalWrite(rT,HIGH);
 delayMicroseconds(5);
 digitalWrite(rT,LOW);
 
 duration=pulseIn(rE,HIGH);
 cm=duration/29/2;
 return cm;

}
int scanLeft()
{
  digitalWrite(lT,LOW);
 delayMicroseconds(2);
 digitalWrite(lT,HIGH);
 delayMicroseconds(5);
 digitalWrite(lT,LOW);
 
 duration=pulseIn(lE,HIGH);
 cm=duration/29/2;
 return cm;
}
