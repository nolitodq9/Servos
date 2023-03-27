
 * Proba de funcionamento dun servomotor
 * empregando a librería <Servo.h> e 
 * ligado a un potenciómetro.
   
   Entradas: pin analóxico A5
   Saídas: pin pwm 3
     
   Autor: Manuel Dominguez Queiruga
   Data: 25/03/2021
 */

#include <Servo.h>  // introducimos a biblioteca servo 

//Pin de control do servo
#define CTRL 3    	// asignamos control ao pin 3 que é a salida que vai darlle a orde o servo


//Pin de lectura do potenc
#define POT A5 		// asignamos control pin pin que lle da orde de funcionamento ao servo

//Declaramos o obxecto motor
//da clase Servo
Servo motor;      		// definimos servo motor, indicamos que ao servo lle chamamos motor
int angulo = 0;			// introducimos un valor enteiro a ángulo, para definir un valor do potenciómetro
int veloc = 100;		// introducimos unha variable creada para delay, é decir así se temos varios delay con cambiar o valor donde definimos xa cambiamos todas a vez

void setup() {
  motor.attach(CTRL);   //	variable do id de arduino "atach", estás escribindo que hai un motor

void loop() {
  //Lectura do potenciometro
  angulo = analogRead(POT);							// dicimos que ángulo é a lectura do potenciómetro
  angulo = map(angulo, 0, 1023, 0, 180);			// 
  //Actualiza servo									
  motor.write(angulo);								//	para que se mova no valor do ángulo o motor
  delay(veloc);										//	que espere o tempo valor
}



