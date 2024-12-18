// C++ code
//

int x = 0;
int p= 0; 
int d = 0;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9,  OUTPUT);
  randomSeed(analogRead(0));

}

void loop()
{
  for ( x = 0; x<=100; x = x+1)
   {p = random(9,14);}
 for ( x = 0; x<=100; x = x+1)
   { d = random(200,1000);}  
  
  
  
  digitalWrite(p, HIGH);
     delay(d);
     digitalWrite(p, LOW);
     delay(d);

  
}
