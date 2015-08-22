/*gpioLEDS.c
lógica para manejar la interfaz del GPIO en la raspberry pi
por medio de wiringPi y hacer parpadear un LED
cambiar el retraso a la mitad del tiempo mientras se reciba información de entrada
(un botón está presionado)*/

#include <stdio.h>
#include <wiringPi.h>

int t = 0;				  //variable para especificar el tiempo entre instruccion e instruccion

int main()
{
  printf("gpioLEDS.c\n\n");
  printf("si input gpio 18 == 1 (boton presionado): 500 ms intervalo entre parpadeos\n");
  printf("si input gpio 18 == 0 (boton no presionado): 1000 ms intervalo entre\n");
  printf("usa ctrl-z para terminar el proceso\n\n\n");

  if (wiringPiSetup() == -1)  //termina el programa si no ha sido configurado wiringpi
  	return 1 ;

  pinMode(0, OUTPUT);         //configura el pin BCM_GPIO 17 a modo output
  pinMode(1, INPUT);          //configura el pin BCM_GPIO 18 a modo input (input)
  
  while(1)		      //ciclo continuo para seguir ejecutando las instrucciones necesarias
  {
	if(digitalRead(1) == 1)
	{
		printf("Boton presionado, t = 500...\n\n");
		t = 500;			  //500 ms entre parpadeos

		while(digitalRead(1) == 1){

			digitalWrite(0, 1);       	//HIGH en pin BCM_GPIO 17 (encendido)
	   	 	delay(t);                 	//espera t ms antes de ejecutar la siguiente accion
	    	digitalWrite(0, 0);       	//LOW en pin BCM_GPIO 17 (apagado)
	    	delay(t);
		}
	}
	else{
		printf("Boton no presionado, t = 1000...\n\n");
		t = 1000;			  //1000 ms entre parpadeos

		while(digitalRead(1) == 0){
			
			digitalWrite(0, 1);       	//HIGH en pin BCM_GPIO 17 (encendido)
	   	 	delay(t);                 	//espera t ms antes de ejecutar la siguiente accion
	    	digitalWrite(0, 0);       	//LOW en pin BCM_GPIO 17 (apagado)
	    	delay(t);
		}
	}
  }
  
  return 0;
}
