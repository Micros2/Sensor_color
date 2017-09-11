
//Estos son los pines que vienen desde la tablilla
const int s0=1;
const int s1=2;
const int s2=3;
const int s3=4;
const int out=5;
//los valores que regresará de cada color según la refracción
int rojo=0;
int verde=0;
int azul =0;


void setup() {
 Serial.begin(9600);
  //Son las salidas que encienden los leds
 pinMode (s0,OUTPUT);
 pinMode (s1,OUTPUT);
 pinMode (s2,OUTPUT);
 pinMode (s3,OUTPUT);
 //la entrada que recibe el pulso y lo cuantifica
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

/*  if (rojo<15 && verde <rojo && verde>azul)
  {
    Serial.println(" Rojo");
  }else if (azul>5 && verde<rojo && verde >azul){
    Serial.println(" Verde");
  }else if (verde> azul && azul <6 && azul<rojo){
    Serial.println(" Azul");
    
  }else {Serial.println(" ");}
 */

 if (rojo<verde && rojo<azul){
  Serial.println(" Rojo");
 }else if (azul< rojo && azul<verde && azul<15){Serial.println(" Azul");}
 else if (verde<rojo && verde<azul){Serial.println(" Verde");}
  else if (rojo<7 && verde<7 && azul<7){Serial.println(" Blanco");}
  else if (rojo>17 && verde>17 && azul>14){Serial.println(" Negra");}
  
   

  delay(900);

}

void color(){
  //para las salidas s2 y s2 low low=enciende el color rojo
  //Para las salidas s2 y s3 low high= enciende el color azul
  //Para las salidas s2 y s3 high high=enciende el color verde
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
   
  rojo=pulseIn(out, digitalRead(out)==HIGH ? LOW : HIGH);
  delay(100);
 // rojo= map(rojo,150,600,255,0); //Se hace un mapeo para relacionar los valores de la frecuencia con los del RGB convencionales
  digitalWrite(s3,HIGH);
  azul=pulseIn(out, digitalRead(out)==HIGH ? LOW : HIGH);
  delay(100);
//  azul= map(rojo,150,600,255,0);
  digitalWrite(s2,HIGH);
  verde=pulseIn(out, digitalRead(out)==HIGH ? LOW : HIGH);
//  verde= map(rojo,150,600,255,0);
  
  }
