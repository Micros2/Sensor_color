const int s0=1;
const int s1=2;
const int s2=3;
const int s3=4;
const int out=5;
int rojo=0;
int verde=0;
int azul =0;


void setup() {
 Serial.begin(9600);
 pinMode (s0,OUTPUT);
 pinMode (s1,OUTPUT);
 pinMode (s2,OUTPUT);
 pinMode (s3,OUTPUT);
 pinMode (out,INPUT);
 digitalWrite(s0,HIGH);
 digitalWrite(s1,HIGH);
 

}

void loop() {
  color();
  Serial.print(" ");
  Serial.print(rojo,DEC);
  Serial.print(" ");
  Serial.print(verde,DEC);
  Serial.print(" ");
  Serial.print(azul,DEC);

  if (rojo<15 && verde <rojo && verde>azul)
  {
    Serial.println(" Rojo");
  }else if (azul>5 && verde<rojo && verde >azul){
    Serial.println(" Verde");
  }else if (verde> azul && azul <6 && azul<rojo){
    Serial.println(" Azul");
    
  }else {Serial.println(" ");}
  delay(900);

}

void color(){
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  rojo=pulseIn(out, digitalRead(out)==HIGH ? LOW : HIGH);
  digitalWrite(s3,HIGH);
  azul=pulseIn(out, digitalRead(out)==HIGH ? LOW : HIGH);
  digitalWrite(s2,HIGH);
  verde=pulseIn(out, digitalRead(out)==HIGH ? LOW : HIGH);
  
  
  }
