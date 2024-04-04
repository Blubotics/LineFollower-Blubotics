public:
  void fnc(){}


};

void setup() {

  // DECLARANDO LEDs RECEPTORES (ANALÓGICOS)
  // DDRx = DDRx &~ (1<<DDxn); --> x: letra do port e n: nº do port
  DDRF = DDRF &~ (1<<DDF2); //pinMode(pino, INPUT) - analog pin 2
  DDRF = DDRF &~ (1<<DDF3); // analog pin 3
  DDRF = DDRF &~ (1<<DDF4); // analog pin 4

  // DECLARANDO LEDs EMISSORES (DIGITAIS)
  PORTx = PORTx | (1 << Pxn); //digitalWrite(pnio, HIGH)
  PORTx = PORTx | (1 << Pxn); // 
  PORTx = PORTx | (1 << Pxn); // 

  // DECLARANDO V(IN)s do MOTOR
  // DDRx = DDRx | (1<<DDxn);
  DDRE = DDRE | (1<<DDE4); //pinMode(pino, OUTPUT) - D2
  DDRE = DDRE | (1<<DDE5); // D3
  DDRG = DDRG | (1<<DDG5); // D4
  DDRE = DDRE | (1<<DDE3); // D5

  PORTE = PORTE | (1 << PE4); //digitalWrite(pino, HIGH) - D2
  PORTG = PORTG | (1 << PG5); // D4

  PORTE = PORTE &~ (1 << PE5); //digitalWrite(pino, LOW) - D3
  PORTE = PORTE &~ (1 << PE3); // D5

  // Limiares dos LEDs
  L1 = 0;
  L2 = 0;
  L3 = 0;

}

void loop() {
  
  if(DDF2 < L1 && DDF3 > L2){dutycyle --> roda esquerda}

  else if(DDF2 < L1 && DDF3 < L2){duty cycle alto --> roda esquerda}

  else if(DDF4 < L3 && DDF3 > L2){dutycyle --> rod direita}

  else if(DDF4 <L3 && DDF3 < L2){dutycycle alto --> roda esquerda}

}
