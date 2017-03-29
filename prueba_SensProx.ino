
//Salidas al Motor Izquierda, Derecha
int Ai1 = 5;    //  Salida 1 motor izquierdo (cable gris)
int Ai2 = 6;    //  Salida 2 motor izquierdo (cable azul)
int Bi1 = 9;    //  Salida 1 motor derecho (cable azul)
int Bi2 = 10;   //  Salida 2 motor derecho (cable gris)

int velocidad = 64;

//Sensores de proximidad
//const int detector_cen = 7;   //  Detector de oponente central
const int detector_der = 8;   //  Detector de oponente derecho

//Contenedores - Proximidad
//int pinProxFront = 0;
int pinProxDer = 0;

// Inicialización
void setup()
{
  Serial.begin(9600);

  pinMode(Ai1, OUTPUT);
  pinMode(Ai2, OUTPUT);
  pinMode(Bi1, OUTPUT);
  pinMode(Bi2, OUTPUT);
}

void detener(){
  digitalWrite(Ai1, LOW);
  digitalWrite(Ai2, LOW);
  digitalWrite(Bi1, LOW);
  digitalWrite(Bi2, LOW);
}

void adelante(){
  analogWrite(Ai1, velocidad);
  digitalWrite(Ai2, LOW);
  analogWrite(Bi1, velocidad);
  digitalWrite(Bi2, LOW);
}

void reversa(){
  digitalWrite(Ai1, LOW);
  analogWrite(Ai2, velocidad);
  digitalWrite(Bi1, LOW);
  analogWrite(Bi2, velocidad);
}

void izquierda(){
  digitalWrite(Ai1, LOW);
  analogWrite(Ai2, velocidad);
  analogWrite(Bi1, velocidad);
  digitalWrite(Bi2, LOW);
}
 
void derecha(){
  analogWrite(Ai1, velocidad);
  digitalWrite(Ai2, LOW);
  digitalWrite(Bi1, LOW);
  analogWrite(Bi2, velocidad);
}



void loop() {
 pinProxDer = digitalRead(detector_der);
  // ¡Detección de objeto por el lado derecho! 
   /* pinProxFront = digitalRead(detector_cen);  
  // ¡Detección de objeto por el frente!
    if (pinProxFront != HIGH)  {
      adelante();
    }
    else{
      detener();
    }*/
    
  if (pinProxDer != HIGH)  {
    derecha();
    delay(1000);
    adelante();
  }
  else{
    detener();
  }
    /*Serial.print("sensorProxi central: ");
    Serial.print(pinProxFront);
    Serial.println(' ');*/
    Serial.print("sensorProxi derecho: ");
    Serial.print(pinProxDer);
    Serial.print(' ');
}//Fin LOOP
