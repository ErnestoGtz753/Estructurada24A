/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 13 de febrero de 2024
PROGRAMA: arregloscinco.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Se registran valores numéricos decimales en un arreglo de 10 espacios cuando el usuario
lo desee. Después se muestran los valores del arreglo en una lista, junto a una sumatoria. Por último, si
el usuario quiere hacer una modificación, se le pregunta dónde y se registra el valor para luego
mostrar la lista de valores actualizada.
*/

#include <iostream>
#include <stdlib.h>

/*para no tener errores con el búfer a la hora de registrar valores, usaremos fflush que usa la
	biblioteca stlib.h*/


int main(){
	/*declaro el arreglo en diez espacios, una sumatoria con cero y otras variables que usé a lo largo
	del programa*/
	float f[10],sum=0;
	
	//El i es un contador y el esc de "escoger" la posición del arreglo donde se hará un cambio
	int i,esc;
	//estas variables preguntan si se quiere registrar un valor o hacer un cambio de valor en una variable.
	char reg,cam;
	//Este ciclo borra todo el contenido del arreglo, dejándolo en "0".
	for(i=0;i<=9;i++){
	f[i]=0;
	}
	
	//Este arreglo pregunta el valor de diez valores, contando desde la posición cero del arreglo.
	for(i=0;i<=9;){
		
		printf("Desea introducir un dato? Si(s), No(n)\n");
		scanf("%c",&reg);
		/*Si el usuario quiere registrar valores, se registra en una nueva posición y 
		se prepara el siguiente espacio en memoria*/
		if(reg=='s'){
			printf("Introduzca el un valor numero %d\n",i+1);
			scanf("%f",&f[i]);
			sum+=f[i];
			i++;	
	}
	//Si ya no quiere introducir más valores, el ciclo termina directamente.
	else {
		printf("Como ya no quiere introducir mas valores, se imprimiran los que ya registro.\n Los espacios en blanco se imprimiran como un '0'");
		
	break;
	}
	/*Para no tener problemas con el flujo y registrar valores tipo caracter, 
	borramos el búfer para empezar "desde cero".*/
	fflush(stdin);
	
	}
	//Aquí se imprime la lista de los valores registrados. En caso de no registrar nada, se escribe un "0".
	printf("Los valores que introdujiste son:\n");
	for(i=0;i<=9;i++){
		printf("%i - %.2f\n",i+1,f[i]);
		
	}
	//Aquí se escribe la sumatoria
	printf("La sumatoria es %.2f\n",sum);
	//Borramos el búfer por la misma razón anteriormente mencionada.
	fflush(stdin);
	//ciclo infinito hasta que el usuario ya no quiera modificar valores de la lista.
	for(;;){
		/*si quiere registrar valores, luego se pregunta la posición y se registra. Si ya no quiere
		modificar valores, se imprime otra lista y luego se pregunta otra vez si quiere hacer
		una nueva modificación */
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
	//Cuando el usuario ya no quiere hacer ninguna mofificación, el ciclo se cierra y el programa termina.
				if(cam=='n')break;
				
			}	
			
		fflush(stdin);
	}
	
	return 0;
}
