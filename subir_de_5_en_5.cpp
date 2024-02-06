/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 6 de febrero de 2024
PROGRAMA: subir_de_5_en_5.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Si el número está entre el 0 y 500, se escribirá de 5 en 5, 100 veces; si está entre el 500 y
1000, se escribirá de 1000 en 1000, sino, se escribirá "No se puede calcular", por último, pregunta
si se quiere ejecutar el programa otra vez. Al finalizar, dice todas las sumas realizadas por el programa.
*/

#include <stdio.h>
#include <iostream>

int main(){
	/*variables que registran el número del usuario, contador de sumas, contador de operaciones 
	(para usar los ciclos) y preguntar si se quiere realizar el programa otra vez, respectivamente*/
	
	int num,contador=0,i,siono;
	
	//ciclo que mantiene todo el programa funcionando hasta que el usuario diga que no (justo al final)
	while(1){
	//pide un numero para realizarle las sumas o, en su defecto, al salirse del rango, no hacer nada
	printf("Escribe un numero\n");
	scanf("%d",&num);
	//si el numero esta entre el 0 y 500, imprimirlo 100 veces, sumándole 5 a cada iteración
	if(num>0 && num<=500){
		printf("\n");
		
	for(i=1;i<=100;i++){
		printf("%d\n",num+i*5);
		//este contador registra la cantidad de sumas que hizo
		contador++;
	}}
	//si el número esta entre el 500 y 1000, imprimirlo 50 veces, sumándole 10 a cada iteración
	else if(num>500 && num<=1000){
		printf("\n");
	for(i=1;i<=50;i++){
		printf("%d\n",num+i*10);
		//este contador registra la nueva cantidad de sumas
		contador++;
	}}
	//en caso de que el numero se salga del rango del 1 y 1000, se escribirá "no se puede calcular"
	else printf("No se puede calcular\n");
	
	
	//aquí pregunta al usuario si quiere continuar, en caso de no escribir "1", entonces detiene el ciclo
	printf("¿Quieres continuar? Si (1) o No (0)\n");
	scanf("%d",&siono);
	if(siono==0)break;

}
	//Una vez que el programa termine, dirá la cantidad de sumas que tuvo que hacer.
	printf("El programa realizo un total de %d sumas",contador);
	
	return 0;
}
