#include <iostream>
/* Presentación
NOMBRE: Ernesto Gutiérrez García
FECHA: 2 de febrero de 2024
PROGRAMA: Actividad-programacion-2.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
*/

//Aquí inicia el programa, con el main
int main(int argc, char** argv) {
int i=1,edadprom=68;
	float edad;
	//nombre de un tamaño de diez caracteres como máximo
	char nom[10];
	//Este for es para que el vector nom se vacíe totalmente
	for(i=0;i<10;i++){
		nom[i]=' ';
	}
	
	printf("Cual es tu primer nombre, sin apellidos\?\\\n");
	//variable tipo string para almacenar una cadena de caracteres (el nombre)
	scanf("%s",&nom);
	printf("Escribe cuantos anios tienes (con decimales)\\\n");
	//variable tipo string para almacenar una cadena de caracteres (el nombre)
	scanf("%f",&edad);
	printf("\aTu nombre es:\t");
	//Este for es para que el vector escriba el nombre, letra por letra
	for(i=0;i<10;i++){
		printf("%c",nom[i]);
	}
	printf("\nTu edad es \t %.2lf anios en formato decimal, lo que representa el %.4e% de le edad de la Tierra", edad,edad/4500000000);
	printf("\nComo dato curioso, los hombres viven en promedio %d anios, y las mujeres %d, en Jalisco", edadprom,edadprom+7);
	printf("\nTu inicial es \t \"%c\"",nom[0]);
	
	

	return 0;
}
//Aquí termina el programa porque se cierra el main
