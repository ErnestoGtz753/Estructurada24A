/*
NOMBRE: Ernesto Guti�rrez Garc�a
FECHA: 6 de febrero de 2024
PROGRAMA: Fibonacci_y_ciclos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIER�A EN COMPUTACI�N / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCI�N: Imprime la cantidad n de n�meeros de la serie de Fibonacci con la 
			estructura de control iterativa que el usuario desee.
*/
#include <stdio.h>

int main(){
	/*Variables para preguntar al usuario qu� ciclo quiere usar, un contador para usar los
	ciclos, una variable que indica el �ltimo n�mero de la serie de Fibonacci que se
	procesar�, y un arreglo para hacer la suma de los dos t�rminos anteriores.
	*/
	char cic;
	int i=2,fin,f[46];
	/*estos son los dos primeros n�meros que sumar� el programa para hacer el 2do
	n�mero de Fibonacci
	*/
	f[0]=0;
	f[1]=1;
	//Aqu� se escoge qu� ciclo se desea usar
	printf("�Que ciclo desea usar? While(w), For(f) o DoWhile(d)\n");
	scanf("%c",&cic);
	//un Switch para escoger el ciclo a usar
	switch (cic){
		case 'w':
		printf("�Cuantos numeros de la serie de Fibonacci quiere procesar?\n");
		scanf("%d",&fin);
		if(fin>=1)printf("1 ");
		
		while(i<=fin){
			/* se usa un arreglo que suma los dos n�meros anteriores y, al mismo tiempo
			almacena un nuevo valor que ser� usado en la siguiente iteraci�n. Lo mismo con
			los otros dos ciclos
			*/
		f[i]=f[i-1]+f[i-2];
		printf("%d ",f[i]);
		i++;
		}
			break;
			
		case 'f':printf("�Cuantos numeros de la serie de Fibonacci quiere procesar?\n");
		scanf("%d",&fin);
		if(fin>=1)printf("1 ");
		
		for(i=2;i<=fin;i++){
		f[i]=f[i-1]+f[i-2];
		printf("%d ",f[i]);
		
		}
			break;
		case 'd':printf("�Cuantos numeros de la serie de Fibonacci quiere procesar?\n");
		scanf("%d",&fin);
		if(fin>=1)printf("1 ");
		
		do{
		f[i]=f[i-1]+f[i-2];
		printf("%d ",f[i]);
		i++;
		}while(i<=fin);
		//como se usa un dowhile, si se escribe 0, se ejecutar� una vez al menos
			if(fin<1)printf("\nDebido a que escogio el do while, se ejecuto una vez demas");
			break;
			//en caso de escoger un ciclo que no est� en el programa, mandar� este mensaje
		default:printf("Ese no es un ciclo valido, reinicie el programa para reintentarlo");
			break;
	}
	return 0;
}
