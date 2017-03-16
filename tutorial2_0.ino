/*
 Codigo para un robot Minisumo con 2 sensores sharp y 2 sensores QTR
 By Jason Salazar
  
 */

//Declaracion de pines para sensores
//int SharpDer = A0; 
//int SharpIzq = A1; 
int QtrDer   = A1;    //A1
int QtrIzq   = A0;    //A0
int QtrAtr   = A2;    //A3
//int SharpladoDer = A4; 
//int SharpladoIzq = A5; 


//Declaracion de variables para leer los valores de los sensores
int Sizq = 0;
int Sder = 0;
int SLadoizq = 0;
int SLadoder = 0;
int Qder = 0;
int Qizq = 0;
int Qatr =0;

//Declaracion de pines para los motores
int Mder1 = 9;  //4
int Mder2 = 10;  //5
int Mizq1 = 5;  //6
int Mizq2 = 6;  //7


int Led = 8;

void setup() {                  
   pinMode(Mder1, OUTPUT);     
   pinMode(Mder2, OUTPUT); 
   pinMode(Mizq1, OUTPUT);
   pinMode(Mizq2, OUTPUT); 
   pinMode(Led, OUTPUT); 
   digitalWrite(Led, HIGH);   // set the LED on
   delay(5000);  // Tiempo de Seguriadad
}

void loop() {
  sensores();
  // Estos valores de 300 pueden cambiar dependiendo de cada sensor, cuando es menor a 300 se refiere a que no detecta nada, y mayor a 300 es que el sensor esta detectando algo
  // sin embargo eso lo debes comprobar tu mismo con tus sensores.
  //if((SLadoizq<=300)&&(Sizq<=300)&&(Sder<=300)&&(SLadoder<=300)){derechasuave();}   // 0 0 0 0=> elegir entre ir adelante o dar vueltas
  //adoizq<=300)&&(Sizq<=300)&&(Sder<=300)&&(SLadoder>=300)){derechafuerte();}  // 0 0 0 1
  //if((SLadoizq<=300)&&(Sizq<=300)&&(Sder>=300)&&(SLadoder<=300)){derechasuave();}   // 0 0 1 0
  //if((SLadoizq<=300)&&(Sizq>=300)&&(Sder<=300)&&(SLadoder<=300)){izquierdasuave();} // 0 1 0 0
  //if((SLadoizq<=300)&&(Sizq>=300)&&(Sder>=300)&&(SLadoder<=300)){adelante();}       // 0 1 1 0
  //if((SLadoizq>=300)&&(Sizq<=300)&&(Sder<=300)&&(SLadoder<=300)){izquierdafuerte();}// 1 0 0 0 
  
  //Para los sensores QTR los valores menores a 500 indican que detecto la liena blanca, por lo que si cualquiera de los 2 sensores detecta la linea blanca el robot debe regresar
  // Tu decides si quieres que solo regrese o tambien quieres que gire a la derecha o izquierda
  
  if((Qder<=500)||(Qizq<=500)){
    parar();
    delay(200);
    atras();
    delay(200);
  }   //el tiempo del delay depende de que tan rapido sea tu robot
  else if ((Qatr<=500)){
    parar();
    delay(200);
    adelante();
    delay(200);
  }
       
}//FIN LOOP


// Lectura de Sensores
void sensores (){
/* Sder = digitalRead(SharpDer); 
 delay(1);   
 Sizq = digitalRead(SharpIzq); 
 delay(1);   
 SLadoder = digitalRead(SharpladoDer); 
 delay(1);   
 SLadoizq = digitalRead(SharpladoIzq); 
 delay(1); */
 
 Qder = analogRead(QtrDer); 
 delay(1);   
 Qizq = analogRead(QtrIzq); 
 delay(1);   
 Qatr = analogRead(QtrAtr);
 delay(1);
}

void adelante(){
analogWrite(Mder1, HIGH);
analogWrite(Mder2, LOW);
analogWrite(Mizq1, HIGH);
analogWrite(Mizq2, LOW);
}
void atras(){
analogWrite(Mder1, LOW);
analogWrite(Mder2, HIGH);
analogWrite(Mizq1, LOW);
analogWrite(Mizq2, HIGH);
}
void parar(){
analogWrite(Mder1, LOW);
analogWrite(Mder2, LOW);
analogWrite(Mizq1, LOW);
analogWrite(Mizq2, LOW);
}

void derechasuave(){
analogWrite(Mder1, LOW);
analogWrite(Mder2, LOW);
analogWrite(Mizq1, HIGH);
analogWrite(Mizq2, LOW);
}
void derechafuerte(){
analogWrite(Mder1, LOW);
analogWrite(Mder2, HIGH);
analogWrite(Mizq1, HIGH);
analogWrite(Mizq2, LOW);
}

void izquierdasuave(){
analogWrite(Mder1, HIGH);
analogWrite(Mder2, LOW);
analogWrite(Mizq1, LOW);
analogWrite(Mizq2, LOW);
}
void izquierdafuerte(){
analogWrite(Mder1, HIGH);
analogWrite(Mder2, LOW);
analogWrite(Mizq1, LOW);
analogWrite(Mizq2, HIGH);
}

