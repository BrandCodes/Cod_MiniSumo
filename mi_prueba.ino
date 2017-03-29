// Sensores de línea
const int linea_izq = A0;   //  Sensor de línea izquierdo
const int linea_der = A1;   //  Sensor de línea derecho
const int linea_atr = A2;   //  Sensor de línea trasero

//Salidas al Motor Izquierda, Derecha
int Ai1 = 5;    //  Salida 1 motor izquierdo (cable gris)
int Ai2 = 6;    //  Salida 2 motor izquierdo (cable azul)
int Bi1 = 9;    //  Salida 1 motor derecho (cable azul)
int Bi2 = 10;   //  Salida 2 motor derecho (cable gris)

int velocidad = 64;
int umbral1 = 350;
int umbral2 = 450;

//Contenedores - Línea
int pinStateIzq = 0;
int pinStateDer = 0;
int pinStateAtr = 0;

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

// Rutina
void loop() {

  adelante();

  pinStateIzq = analogRead(linea_izq);
  pinStateDer = analogRead(linea_der);
  pinStateAtr = analogRead(linea_atr);

  if (pinStateIzq < umbral1) {
    detener();
    delay(1000);
    derecha();
    delay(800);
    adelante();
  }
  else  {
    if (pinStateDer < umbral1)  {
      detener();
      delay(1000);
      izquierda();
      delay(800);
      adelante();
    }
    else  {
      if (pinStateAtr < umbral2) {
        detener();
        delay(1000);
        adelante();
        delay(800);
      }
    }
  }
  Serial.print("sensor izquierdo: ");
  Serial.print(pinStateIzq);
  Serial.print(' ');
  Serial.print("sensor derecho: ");
  Serial.print(pinStateDer);
  Serial.print(' ');
  Serial.print("sensor atrás: ");
  Serial.print(pinStateAtr);
  Serial.println(' ');
  delay(100);

}//Fin Loop
