// Sensores de línea
const int linea_izq = A0;   //  Sensor de línea izquierdo
const int linea_der = A1;   //  Sensor de línea derecho
const int linea_atr = A2;   //  Sensor de línea trasero

//Sensores de proximidad
const int detector_izq = 4;   //  Detector de oponente izquierdo
const int detector_cen = 7;   //  Detector de oponente central
const int detector_der = 8;   //  Detector de oponente derecho
  
//Salidas al Motor Izquierda, Derecha
int Ai1 = 5;    //  Salida 1 motor izquierdo (cable gris)
int Ai2 = 6;    //  Salida 2 motor izquierdo (cable azul)
int Bi1 = 9;    //  Salida 1 motor derecho (cable azul)
int Bi2 = 10;   //  Salida 2 motor derecho (cable gris)

//int LED = 13;   //  Led indicador ready
 
int velocidad = 64;
int umbral = 250;

//Contenedores - Línea
int pinStateIzq = 0;
int pinStateDer = 0;
int pinStateAtr = 0;

//Contenedores - Proximidad
int pinProxIzq = 0;
int pinProxDer = 0;
int pinProxFront = 0;

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

void MtdProximidad(){
  pinProxIzq = digitalRead(detector_izq);
  pinProxDer = digitalRead(detector_der);
  pinProxFront = digitalRead(detector_cen);
  //¡Detección de objeto por el lado izquierdo!
  if (pinProxIzq == HIGH)  {
    izquierda();
    delay(1000);
    adelante();
  } 
  // ¡Detección de objeto por el lado derecho! 
  if (pinProxDer == HIGH)  {
    derecha();
    delay(1000);
    adelante();
  }
  // ¡Detección de objeto por el frente!
  if (pinProxFront == HIGH)  {
    adelante();
  }

  //Mandando a imprimir los valores:
    Serial.print("sensorProxi izquierdo: ");
    Serial.print(detector_izq);
    Serial.print(' ');
    Serial.print("sensorProxi derecho: ");
    Serial.print(detector_der);
    Serial.print(' ');
    Serial.print("sensorProxi atrás: ");
    Serial.print(detector_cen);
    Serial.println(' '); 
}//Fin MTDProximididad

// Rutina
void loop() {  
  adelante();
  //MtdProximidad();
// ¡Detección de línea por el lado izquierdo!
  //linea_izq = analogRead(A0);   // Lectura del sensor de línea izquierdo
  pinStateIzq = analogRead(linea_izq);
  pinStateDer = analogRead(linea_der);
  pinStateAtr = analogRead(linea_atr);
  if (pinStateIzq < 400) {
    detener();
    delay(1000);
    derecha();
    delay(800);
    adelante();
  }   
  else  {
  // ¡Detección de línea por el lado derecho!
    //linea_der = analogRead(A1);   // Lectura del sensor de línea derecho
      if (pinStateDer < 400)  {
        detener();
        delay(1000);
        izquierda();
        delay(800);
        adelante();
      }   
  else  {
  // ¡Detección de línea por atrás!
      //linea_atr = analogRead(A2);   // Lectura del sensor de línea atras
      if (pinStateAtr < 500) {
        detener();
        delay(1000);
        adelante();
        delay(800);
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
}//Fin Loop
