/* Práctica na que se vai controlar a posición dun servomotor de dúas maneiras. A primeira a través do monitor
serie e a segunda a través do potenciómetro.

Entradas: pin analóxico A5 e Monitor serie
Saídas: pin pwm 3

Autor: Manuel Dominguez Queiruga
Data: 25/03/2023 */


#include <Servo.h>		// introducimos a biblioteca servo para poder manexar o servomotor

//Pin de control do Servo
#define CTRL 3

// Pin de lectura do potenciómetro
#define POT A5


//Declaramos o obxecto motor da clase servo
Servo motor;		// Chamámolle servo ao motor para que sepa o que está manexando
int angulo = 0;		// dámolle un valor de 0º ao ángulo
int veloc = 3000;	// e a velocidade queremos que sexa 3000

String orde = "";	// Aqui o que se fai é dicir que imos comunicarnos de forma escrita	


void setup() {
   motor.attach(CTRL);		//Está conectando a variable do servo ao pin asignado (3)
   Serial.begin(9600);		// a velocidade de comunicación será de 9600 baudios
}

void loop(){
							//comprobamos se hai orde no teclado
  if(Serial.available())  {				// Si o monitor serie está dispoñible, neste caso se estamos escribindo 
    orde = Serial.readStringUntil('\n');		//  Orde significa leer o que escribo no monitor serie
    orde.toLowerCase();					// Isto é para que lea o que escribimos no monitor serie
    if(orde.equals("esquerda")) angulo = 180;		// si escribimos "esquerda" o servo posiciónase no angulo de 180º"
    else if(orde.equals("centro esquerda")) angulo = 135;// si escribimos "centro esquerda" o servo posiciónase no angulo de 135º"
    else if(orde.equals("centro")) angulo = 90;		// si escribimos "centro" o servo posiciónase no angulo de 90º"
    else if(orde.equals("centro dereita")) angulo = 45;  // si escribimos "centro dereita" o servo posiciónase no angulo de 45º"
    else if(orde.equals("dereita")) angulo = 0;		// si escribimos "dereita" o servo posiciónase no angulo de 180º"
            else{					// senon fai o seguinte.. 
              int tmp = orde.toInt();			// o valor tmp é igual ao escrito na entrada, esto é para poñer o servo na posición exacta que escriba
              if(tmp>= 0 && tmp <=180) angulo = tmp;	// función que lle fai que o servo se sitúe na posicion que lle indicamos
              else angulo = 0;				// se non escribimos o angulo ten que ser cero
            }
                 
}
            else{					// senon fai isto
              
              // Lectura do potenciometro
             angulo = analogRead(POT);			// Se non se escribe no monitor serie, enton que ángulo sexa o valor do potenciómetro
             angulo = map(angulo , 0, 1023, 0, 180); 	// aqui mapeamos os valores do potenciómetro
            }
            
            //Actualiza servo
            motor.write(angulo);	// Aquí decimos que o motor se posicione no valor de ángulo 
            delay(veloc);		// que espere o tempo veloc, definido ao principio o valor
            Serial.println(angulo);	// que imprima o valor do angulo no monitor serie
            
}            
