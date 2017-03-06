

// Sensores
int linea_izq = A0;   //  Sensor de línea izquierdo
int linea_der = A1;   //  Sensor de línea derecho
int linea_atr = A2;   //  Sensor de línea trasero

int detector_izq = 4;   //  Detector de oponente izquierdo
int detector_cen = 7;   //  Detector de oponente central
int detector_der = 8;   //  Detector de oponente derecho

int Ai1 = 5;    //  Salida 1 motor izquierdo (cable gris)
int Ai2 = 6;    //  Salida 2 motor izquierdo (cable azul)
int Bi1 = 9;    //  Salida 1 motor derecho (cable azul)
int Bi2 = 10;   //  Salida 2 motor derecho (cable gris)

//int LED = 13;   //  Led indicador ready
 
// Variables
int SA0 = 0;    //  Almacenamos los niveles de los detectores de línea
int SA1 = 0;
int SA2 = 0;

int velocidad = 64;
int umbral = 100;

// Inicialización
void setup()
{
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
 
void reversa(){
  analogWrite(Ai1, 0);
  analogWrite(Ai2, velocidad);
  analogWrite(Bi1, 0);
  analogWrite(Bi2, velocidad);
}
 
void detener(){
  analogWrite(Ai1, 0);
  analogWrite(Ai2, 0);
  analogWrite(Bi1, 0);
  analogWrite(Bi2, 0);
}

// Rutina
void loop() {

  reversa();
  linea_izq = analogRead(A0);   // Lectura de los sensores de línea
  linea_der = analogRead(A1);
  linea_atr = analogRead(A2);

//  detector_izq = digitalRead(4);   //  Leemos los Detector de oponente
//  detector_cen = digitalRead(7);
//  detector_der = digitalRead(8);
/*
// ¡Detección de línea por el lado izquierdo!
  if (linea_izq < umbral) {
    reversa();
//    delay(500);
//    derecha();
//    delay(100);
//    adelante();
  }
 
// ¡Detección de línea por el lado derecho! 
  if (linea_der < umbral)  {
    reversa();
//    delay(500);
//    izquierda();
//    delay(100);
//    adelante();
    }*/

// ¡Detección de línea por atrás!
  if (linea_atr < umbral) {
//    derecha();
//    delay(100);
    adelante();
    delay(1000);
    detener();
    delay(500);
  }

  //Detectando línea, frontal:
  if(linea_izq && linea_der < umbral){
    reversa();
    delay(1000);
    detener();
    delay(500);
  }

  //DEtectando por izquierda:
  if(linea_izq < umbral){
    reversa();
    delay(1000);
    derecha();
    adelante();
  }

  //DEtectando por derecha:
  if(linea_der < umbral){
    reversa();
    delay(1000);
    izquierda();
    adelante();
  }
/*
// ¡Detección de objeto por el lado izquierdo!
  if (detector_izq = digitalRead(HIGH))  {
    izquierda();
    delay(1000);
    adelante();
  }
 
  // ¡Detección de objeto por el lado derecho! 
  if (detector_der = digitalRead(HIGH))  {
    derecha();
    delay(1000);
    adelante();
  }

  // ¡Detección de objeto por el frente!
  if (detector_cen = digitalRead(HIGH))  {
    adelante();
  }*/
}
