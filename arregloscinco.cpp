/*
NOMBRE: Ernesto Guti�rrez Garc�a
FECHA: 13 de febrero de 2024
PROGRAMA: arregloscinco.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIER�A EN COMPUTACI�N / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCI�N: Se registran valores num�ricos decimales en un arreglo de 10 espacios cuando el usuario
lo desee. Despu�s se muestran los valores del arreglo en una lista, junto a una sumatoria. Por �ltimo, si
el usuario quiere hacer una modificaci�n, se le pregunta d�nde y se registra el valor para luego
mostrar la lista de valores actualizada.
*/

#include <iostream>
#include <stdlib.h>

/*para no tener errores con el b�fer a la hora de registrar valores, usaremos fflush que usa la
	biblioteca stlib.h*/


int main(){
	/*declaro el arreglo en diez espacios, una sumatoria con cero y otras variables que us� a lo largo
	del programa*/
	float f[10],sum=0;
	
	//El i es un contador y el esc de "escoger" la posici�n del arreglo donde se har� un cambio
	int i,esc;
	//estas variables preguntan si se quiere registrar un valor o hacer un cambio de valor en una variable.
	char reg,cam;
	//Este ciclo borra todo el contenido del arreglo, dej�ndolo en "0".
	for(i=0;i<=9;i++){
	f[i]=0;
	}
	
	//Este arreglo pregunta el valor de diez valores, contando desde la posici�n cero del arreglo.
	for(i=0;i<=9;){
		
		printf("Desea introducir un dato? Si(s), No(n)\n");
		scanf("%c",&reg);
		/*Si el usuario quiere registrar valores, se registra en una nueva posici�n y 
		se prepara el siguiente espacio en memoria*/
		if(reg=='s'){
			printf("Introduzca el un valor numero %d\n",i+1);
			scanf("%f",&f[i]);
			sum+=f[i];
			i++;	
	}
	//Si ya no quiere introducir m�s valores, el ciclo termina directamente.
	else {
		printf("Como ya no quiere introducir mas valores, se imprimiran los que ya registro.\n Los espacios en blanco se imprimiran como un '0'");
		
	break;
	}
	/*Para no tener problemas con el flujo y registrar valores tipo caracter, 
	borramos el b�fer para empezar "desde cero".*/
	fflush(stdin);
	
	}
	//Aqu� se imprime la lista de los valores registrados. En caso de no registrar nada, se escribe un "0".
	printf("Los valores que introdujiste son:\n");
	for(i=0;i<=9;i++){
		printf("%i - %.2f\n",i+1,f[i]);
		
	}
	//Aqu� se escribe la sumatoria
	printf("La sumatoria es %.2f\n",sum);
	//Borramos el b�fer por la misma raz�n anteriormente mencionada.
	fflush(stdin);
	//ciclo infinito hasta que el usuario ya no quiera modificar valores de la lista.
	for(;;){
		/*si quiere registrar valores, luego se pregunta la posici�n y se registra. Si ya no quiere
		modificar valores, se imprime otra lista y luego se pregunta otra vez si quiere hacer
		una nueva modificaci�n */
		printf("Quiere borrar el valor de alguna variable? Si(s), No(n)\n");
		scanf("%c",&cam);
		if(cam=='s'){
		
			printf("Cual de las diez variables quiere modificar? (escoja un numero del 1 - 10)\n");
			scanf("%d",&esc);
			printf("Escriba un valor\n");
			scanf("%f",&f[esc-1]);
			}
			else {
				printf("Los valores actuales son:\n");
					for(i=0;i<=9;i++){
					printf("%i - %.2f\n",i+1,f[i]);
					}
					fflush(stdin);
				printf("Quiere hacer un nuevo cambio? Si(s), no(n)\n");
				scanf("%c",&cam);
	//Cuando el usuario ya no quiere hacer ninguna mofificaci�n, el ciclo se cierra y el programa termina.
				if(cam=='n')break;
				
			}	
			
		fflush(stdin);
	}
	
	return 0;
}
