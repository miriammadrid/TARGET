#include <stdio.h>
/*Escribir un programa que dado un número n determine si es o no un 
  número perfecto.*/
/* esta es una prueba*/
int main() {
	int i, num, sum=0, cont=0;
	
	printf("Ingrese el numero para ver si es perfecto: ");
	scanf("%d", &num);
      	
	for(i=1; i<num; i++) {
		cont=num%i;
		if(cont==0) {
			sum+=i;
		}
	}
       	if(sum==num){
		printf("El numero %d es perfecto.\n", num);
	}
	else
	printf("El numero %d NO es perfecto.\n", num);
	return 0;
}
