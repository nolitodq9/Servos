



#include <Servo.h>

//Pin de control do Servo
#define CTRL 3

// Pin de lectura do potenciómetro
#define POT A5


//Declaramos o obxecto motor da clase servo
Servo motor;
int angulo = 0;
int veloc = 3000;

String orde = "";


void setup() {
   motor.attach(CTRL);
   Serial.begin(9600);
}

void loop(){
	//Comprobamos se hai orde no teclado
  if(Serial.available())  {
    orde = Serial.readStringUntil('\n');
    orde.toLowerCase();
    if(orde.equals("esquerda")) angulo = 180;
    else if(orde.equals("centro esquerda")) angulo = 135;
    else if(orde.equals("centro")) angulo = 90;
    else if(orde.equals("centro dereita")) angulo = 45;  
    else if(orde.equals("dereita")) angulo = 0;
            else{
              int tmp = orde.toInt();
              if(tmp>= 0 && tmp <=180) angulo = tmp;
              else angulo = 0;
            }
                 
}
            else{
              
              // Lectura do potenciometro
             angulo = analogRead(POT);
             angulo = map(angulo , 0, 1023, 0, 180); 
            }
            
            //Actualiza servo
            motor.write(angulo);
            delay(veloc);
            Serial.println(angulo);
            
}            
