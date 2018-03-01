int AeroIn=53;
int TTLout=50;
int Aero=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(AeroIn,INPUT);
  pinMode(TTLout,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Aero=digitalRead(AeroIn);
  Serial.println(Aero);
  if (Aero==HIGH)
  {
    digitalWrite(TTLout,HIGH);
  }
  if (Aero==LOW)
  {
    digitalWrite(TTLout,LOW);
  }

}
