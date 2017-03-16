
// Sensores de línea
int linea_izq = A0;   //  Sensor de línea izquierdo
int linea_der = A1;   //  Sensor de línea derecho
int linea_atr = A2;   //  Sensor de línea trasero
  
int Ai1 = 5;    //  Salida 1 motor izquierdo (cable gris)
int Ai2 = 6;    //  Salida 2 motor izquierdo (cable azul)
int Bi1 = 9;    //  Salida 1 motor derecho (cable azul)
int Bi2 = 10;   //  Salida 2 motor derecho (cable gris)

//int LED = 13;   //  Led indicador ready
 
int velocidad = 64;
int umbral = 250;

// Inicialización
void setup()
{
  Serial.begin(9600);
//  pinMode(LED, OUTPUT);
  pinMode(Ai1, OUTPUT);
  pinMode(Ai2, OUTPUT);
  pinMode(Bi1, OUTPUT);
  pinMode(Bi2, OUTPUT);
}

void adelante(){
  analogWrite(Ai1, velocidad);
  analogWrite(Ai2, 0);
  analogWrite(Bi1, velocidad);
  analogWrite(Bi2, 0);
}

void detener(){
  analogWrite(Ai1, 0);
  analogWrite(Ai2, 0);
  analogWrite(Bi1, 0);
  analogWrite(Bi2, 0);
}

void reversa(){
  analogWrite(Ai1, 0);
  analogWrite(Ai2, velocidad);
  analogWrite(Bi1, 0);
  analogWrite(Bi2, velocidad);
}

void derecha(){
  analogWrite(Ai1, 0);
  analogWrite(Ai2, velocidad);
  analogWrite(Bi1, velocidad);
  analogWrite(Bi2, 0);
}
 
void izquierda(){
  analogWrite(Ai1, velocidad);
  analogWrite(Ai2, 0);
  analogWrite(Bi1, 0);
  analogWrite(Bi2, velocidad);
}

// Rutina
void loop() {
  adelante();
  //detener():
// ¡Detección de línea por el lado izquierdo!
  linea_izq = analogRead(A0);   // Lectura del sensor de línea izquierdo
  if (linea_izq < 300) {
    detener();
    delay(1000);
    derecha();
    delay(800);
    adelante();
  }
  else  {
  // ¡Detección de línea por el lado derecho!
      linea_der = analogRead(A1);   // Lectura del sensor de línea derecho
      if (linea_der < umbral)  {
        detener();
        delay(1000);
        izquierda();
        delay(800);
        adelante();
      }
  else  {
  // ¡Detección de línea por atrás!
      linea_atr = analogRead(A2);   // Lectura del sensor de línea atras  
      if (linea_atr < 500) {
        detener();
        delay(1000);
      }
    }    
  }
    Serial.print("sensor izquierdo: ");
    Serial.print(linea_izq);
    Serial.print(' ');
    Serial.print("sensor derecho: ");
    Serial.print(linea_der);
    Serial.print(' ');
    Serial.print("sensor atrás: ");
    Serial.print(linea_atr);
    Serial.println(' ');   
    
  // ¡Detección de objeto por el lado derecho! 
  /*if (detector_der == digitalRead(HIGH))  {
    derecha();
    delay(1000);
    adelante();
  }
  // ¡Detección de objeto por el frente!
  if (detector_cen == digitalRead(HIGH))  {
    adelante();
  }*/

  //int detector_cen, detector_der, detector_izq;
  //int lectura = digitalRead(LOW);         //En vez de LOW se pondría el sensor deseado.
  if (detector_cen == digitalRead(LOW))  {    
    adelante();
    delay(500);
    detener();
    Serial.print("sensor centro: ");
    Serial.print(detector_cen);
    //Serial.print(lectura);
    Serial.println(' ');
  }  
  //lectura = 0;
  if (detector_der == digitalRead(LOW))  {
    derecha();
    delay(500);
    detener();
    Serial.print("sensor derecho: ");
    Serial.print(detector_der);
    //Serial.print(lectura);
    Serial.println(' ');
  }
  //lectura = 0;
}//Fin Loop
