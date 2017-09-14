
//Estos son los pines que vienen desde la tablilla
const int s0=1;
const int s1=2;
const int s2=3;
const int s3=4;
const int out=5;
const int btn=6;
//los valores que regresará de cada color según la refracción
int rojo=0;
int verde=0;
int azul =0;
int rojoa=0;
int verdea=0;
int azula =0;
bool pushed=true;
int diferenciar=0;
int diferenciaa=0;
int diferenciav=0;

void setup() {
 Serial.begin(9600);
  //Son las salidas que encienden los leds
 pinMode (s0,OUTPUT);
 pinMode (s1,OUTPUT);
 pinMode (s2,OUTPUT);
 pinMode (s3,OUTPUT);

 //la entrada que recibe el pulso y lo cuantifica
 pinMode (btn,INPUT);
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
  Serial.print(pushed);

/*  if (rojo<15 && verde <rojo && verde>azul)
  {
    Serial.println(" Rojo");
  }else if (azul>5 && verde<rojo && verde >azul){
    Serial.println(" Verde");
  }else if (verde> azul && azul <6 && azul<rojo){
    Serial.println(" Azul");
    
  }else {Serial.println(" ");}
 */
while (pushed){
  rojoa=rojo;
  azula=azul;
  verdea=verde;
  color();
  diferenciar=rojoa-rojo;
  if (diferenciar>=-1 && diferenciar>=1) {}else {Serial.println("Discontinuidad Rojo ");}
  diferenciaa=azula-azul;
/*  if (diferenciaa!=0 || diferenciaa!=1 || diferenciaa!=-1) {Serial.println("Discontunuidad azul");}
  diferenciar=verdea-verde;
  if (diferenciav!=0 || diferenciav!=1 || diferenciav!=-1) {Serial.println("Discontunuidad verde");}
  */
  delay(100);
  if (btn==HIGH){ pushed=not pushed; delay(100);}
  }
 if (btn==HIGH){ pushed=not pushed; delay(100);}
 
 if (rojo<verde && rojo<azul){
  Serial.println(" Rojo");
 }else if (azul< rojo && azul<verde && azul<15){Serial.println(" Azul");}
 else if (verde<rojo && verde<azul){Serial.println(" Verde");}
  else if (rojo<7 && verde<7 && azul<7){Serial.println(" Blanco");}
  else if (rojo>17 && verde>17 && azul>14){Serial.println(" Negra");}else {Serial.println(" ");}
  
   

  delay(900);

}

void color(){
  //para las salidas s2 y s3 low low=enciende el color rojo
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
