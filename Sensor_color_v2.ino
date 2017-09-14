#define led 7
#define s0 2  
#define s1 3  
#define s2 4  
#define s3 5 
#define out 6
#define push 8
#define muestras 512
 
int RGB = 0;
long frecuencia = 0;  
float factor_RGB[3];  
void setup()   
{  
   
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);
  pinMode(push, INPUT);
  //Escala de frecuencia de salida al 2%
  digitalWrite(s0, LOW);  
  digitalWrite(s1, HIGH);  
  //Comunicación Serial
  Serial.begin(9600);
}  
    
void loop() 
{  
  // Para calibrar el sensor se debe presionar el pulsador
  if(digitalRead(push)== HIGH)
  {
    TCS_init();  
  }
  else
  // El sensor comienza la lectura de color
  {
    // Se encienden los leds del sensor para tener mejor lectura
    digitalWrite(led, HIGH);
    leer_R();
    RGB = frecuencia * factor_RGB[0];
    Serial.print("Rojo = ");
    Serial.print(RGB);
    Serial.print(" ");
    leer_G();
    RGB = frecuencia * factor_RGB[1];
    Serial.print("Verde = ");
    Serial.print(RGB);
    Serial.print(" ");
    leer_B();
    RGB = frecuencia * factor_RGB[2];
    Serial.print("Azul = ");
    Serial.println(RGB);
    
  }
  
}
long calcular_frecuencia(int pin) {
  
  long freq = 0;
  for(unsigned int j=0; j<muestras; j++) freq+= 500000/pulseIn(pin, HIGH, 150000);
  return freq / muestras;
}
void TCS_init()
{
  // Iniciamos corrección de balance de blancos
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  Serial.println("Calibrando Balance de blancos..");
  // Se encienden los leds del sensor para tener mejor lectura
  digitalWrite(led, HIGH);
  delay(1000);
  leer_R();
  factor_RGB[0] = 255.0/frecuencia;
  leer_G();
  factor_RGB[1] = 255.0/frecuencia;
  leer_B();
  factor_RGB[2] = 255.0/frecuencia;
  Serial.println("Sensor calibrado correctamente!!");
  digitalWrite(led, LOW);
  delay(1000); 
}
void leer_R()
{
  // Activar lectura de color Rojo
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  frecuencia = calcular_frecuencia(out);
}  
void leer_G()
{
  // Activar lectura de color Verde
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  frecuencia = calcular_frecuencia(out);
}
void leer_B()
{
  // Activar lectura de color Azul
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  frecuencia = calcular_frecuencia(out);
}
