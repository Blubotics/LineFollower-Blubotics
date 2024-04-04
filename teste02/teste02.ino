int i = 1;
float m = 0;
float m1, m2, m3, m4, m5 = 0;
float l1, l2, l3, l4, l5 = 0;

void setup()
{
  Serial.begin(9600);
  // LEDs RECEPTORES
  // DDRx = DDRx &~ (1<<DDxn); --> x: letra do port e n: nº do port
  DDRF = DDRF &~ (1 << DDF0); // pinMode(pino, INPUT) - analog pin 0
  DDRF = DDRF &~ (1 << DDF1); // analog pin 1

  DDRF = DDRF &~ (1 << DDF2); // analog pin 2
  DDRF = DDRF &~ (1 << DDF3); // analog pin 3
  DDRF = DDRF &~ (1 << DDF4); // analog pin 4

  //DDRF = DDRF &~ (1 << DDF5); // analog pin 5
  //DDRF = DDRF &~ (1 << DDF6);// analog pin 6
  //DDRF = DDRF &~ (1 << DDF7);// analog pin 7

  DDRH = DDRH | (1 << DDH4);
  // ACION.
  PORTH = PORTH | (1 << PH4); // digitalWrite(pino, HIGH) - D7
  //PORTD = PORTD | (1 << PD6); // D6 
  
  // V(in)s DO MOTOR
  PORTE = PORTE | (1 << PE4); //digitalWrite(pino, HIGH) - D2
  PORTE = PORTE &~ (1 << PE5); //digitalWrite(pino, LOW) - D3
  
  PORTG = PORTG | (1 << PG5); // D4
  PORTE = PORTE &~ (1 << PE3); // D5
}

void loop()
{
  float lft, ctr ,rgt, pl, pr; //receptor 'left', 'center', 'right'
  pl = analogRead(DDF0);
  lft = analogRead(DDF1);
  ctr = analogRead(DDF2);
  rgt = analogRead(DDF3);
  pr = analogRead(DDF4);
  
  if(i<=15){
    m1 += pl;
    m2 += lft;
    m3 += ctr;
    m4 += rgt;
    m5 += pr;
    if(i==15){
      m1 = m1/i;
      m2 = m2/i;
      m3 = m3/i;
      m4 = m4/i;
      m5 = m5/i;
    }
    i++;
  }

  l1 = 1.1*m1;
  l2 = 1.1*m2;
  l3 = 1.1*m3;
  l4 = 1.1*m4;
  l5 = 1.1*m5;

  if(pl < l1){
    PORTH = PORTH | (1 << PH4);
  }
  else{
    PORTH = PORTH &~ (1 << PH4);
  } 
  
  if(lft < l2){
    PORTF = PORTF | (1 << PF2);
  }
  else{
    PORTF = PORTF &~ (1 << PF3);
  } 

  if(ctr < l3){
    PORTF = PORTF | (1 << PF4);
  }
  else{
    PORTH = PORTH &~ (1 << PH4);
  } 

  if(rgt < l4){
    PORTH = PORTH | (1 << PH4);
  }
  else{
    PORTH = PORTH &~ (1 << PH4);
  } 

  if(pr < l5){
    PORTH = PORTH | (1 << PH4);
  }
  else{
    PORTH = PORTH &~ (1 << PH4);
  } 

  Serial.println(pl);

  // -*-*-*-*-*-*-*-*
  //if(lft < 680 && ctr > 680){dutycycle --> motor right}
  //else if(lft < 680 && ctr < 680){dutycycle++ --> motor right}
  //else if(rgt < 680 && ctr > 680){dutycycle --> motor left}
  //else if(rgt < 680 && ctr < 680){dutycycle++ --> motor left}
  // -*-*-*-*-*-*-*-*

  
  
  // falta condição dentro de cada if que desliga
  // ou ajusta a correção pelo duty cycle
}
