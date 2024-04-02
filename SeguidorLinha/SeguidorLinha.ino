int MP[4] = {4,5,6,7};

#define Sl A1
#define Sc A2
#define Sr A3

int x = 0;
int y = 0;
int z = 0;

void setup() {
  
  for(int i = 0; i <= 4; i++){
    pinMode(MP[i], OUTPUT);
    digitalWrite(MP[i], LOW);
  }

  Serial.begin(9600);

  pinMode(Sl, INPUT);
  pinMode(Sc, INPUT);
  pinMode(Sr, INPUT);


}

void loop() {
  
  x = analogRead(Sl);
  y = analogRead(Sc);
  z = analogRead(Sr);

  // Serial.print("Left: ");
  // Serial.println(x);

  // Serial.print("Center: ");
  // Serial.println(y);

  // Serial.print("Right: ");
  // Serial.println(z);

  Serial.println("---------------");

  // delay(300);

  if(y < 500 && x > 500 && z > 500){forward();}
  else if(x < 500 && z > 500){left();}
  else if(z < 500 && x > 500){right();}
  else if(y > 500 && x > 500 && y > 500){forward();}
  //else if(x > 500 && y > 500 && z > 500){stop();}


}

void forward(){
  Serial.println("forward");
  digitalWrite(MP[0], LOW);
  digitalWrite(MP[1], HIGH); // Roda da direita para frente
  digitalWrite(MP[3], HIGH);
  digitalWrite(MP[2], LOW);

}

void left(){

  Serial.println("right");
  //for(int i=0;i<10000;i++){
    digitalWrite(MP[0], LOW);
    digitalWrite(MP[1], HIGH); // Roda da direita para frente apenas
    digitalWrite(MP[3], LOW);
    digitalWrite(MP[2], LOW);
  //}
}

void right(){

  Serial.println("left");
  digitalWrite(MP[0], LOW);
  digitalWrite(MP[1], LOW); // Roda da direita parada
  digitalWrite(MP[3], HIGH);
  digitalWrite(MP[2], LOW);
}


void stop(){
  digitalWrite(MP[1], LOW);
  digitalWrite(MP[0], LOW);
  digitalWrite(MP[2], LOW);
  digitalWrite(MP[3], LOW);
}


//move forward
  // digitalWrite(IN[1], HIGH);
  // digitalWrite(IN[0], LOW);
  // digitalWrite(IN[2], HIGH);
  // digitalWrite(IN[3], LOW);
