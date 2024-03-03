/*
NOMBRE: Ernesto Guti�rrez Garc�a
FECHA: 01 de marzo de 2024
PROGRAMA: vectores y conjuntosv2 (con librer�as).cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIER�A EN COMPUTACI�N / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCI�N: El programa guarda valores, muestra cu�ntos valores hay registrados, elimina valores concretos,
elimina todos los valores del vector, muestra los valores de un vector, y le pregunta al usuario si quiere
terminar el programa.
*/



#include <iostream>

#include "vector y conjunto (libreria propia).cpp"


	using namespace std;
	/*Tenemos, respectivamente, una variable que determina lo que el usuario quiere hacer,
	tres contadores,el tama�o real de cada arreglo, un valor que el vector debe adquirir,
	una posici�n que se debe eliminar, una variable que indica la posici�n a modificar,
	una variable que suma valores, una variable que elige un vector, y, por �ltimo, otra variable que
	determina si se ejecuta una operaci�n*/
	
	int cas,i,j,k,k1=0,k2=0,h,val,elim,sum,eleg,nos=0;
	/*Estos son arreglos que almacenan los valores que el usuario solicita o que almacenan los resultados */
	char caso, arr1[20],arr2[20],resul[40],val2,val3;
	
	//variable que mantiene a los ciclos funcionando
	bool ciclo=true;
	//para iniciar, un vector de una posici�n cuyo �nico valor es igual a "0"
	
	/*De manera resumida, la intersecci�n compara todos los caracteres de cada posici�n.
	Si alg�n valor coincide, se almacena un "1" dentro de una variable y se detiene la
	comparaci�n de ese car�cter  para almacenarlo y luego comparar todos los caracteres del arreglo 2,
	pero con otro car�cter del arreglo 1*/
	
		
		
			
int main(int argc, char** argv) {
								                     
	//Ciclo que limpia las variables dentro de los arreglos
	for(i=0;i<20;i++){
			arr1[i]='\0';
			arr2[i]='\0';
	}
	//Se ofrecen varias opciones
		while(ciclo){
			cout<<"Elija una opcion\n";
			cout<<"1-Insertar un valor\n";
			cout<<"2-Modificar un valor\n";
			cout<<"3-Eliminar todos los valores\n";
			cout<<"4-Mostrar lista de valores\n";
			cout<<"5-Operaciones de conjuntos\n";
			cout<<"6-Terminar programa\n";
			cin>>cas;
			
	//Aqu� se decide qu� hace el programa
	
			switch(cas){
				
			//Aqu� se introduce un nuevo valor al vector	
			case 1:{
				
			//valida que se ingrese un arreglo existente
				eleg=elegarr();
			//almacena un valor dentro del arreglo
				cout<<"Introduzca un valor numerico o un caracter. \nNota: el arreglo puede almacenar solo 20 valores"<<endl;
				cin>>val3;
				valtodo(val3);
				
			break;
			}//fin caso 1
			/*Aqu� se le informa sobre los valores del vector para que vea qu� valor puede
			modificar*/
			case 2: {
			
			//muestra los valores del arreglo y luego da oportunidad de modificarlos

			
			
			
			cout<<endl;
				
				
				mod();
			
			break;
			}//fin caso 2
			
			
			case 3:{//Aqu� se borran todos los elementos del vector
				
			//pregunta en qu� arreglo se borrar�n todos su valores
				eleg=elegarr();
				
				if(eleg==1){
					for(i=0;i<k1;i++){
							arr1[i]='\0';
					}
					k1=0;
					cout<<"Los elementos del arreglo uno fueron eliminados exitosamente\n\n";
				}
				else{
					for(i=0;i<k2;i++){	
							arr2[i]='\0';	
					}
					k2=0;
					cout<<"Los elementos del arreglo dos fueron eliminados exitosamente\n\n";
				}
				break;
			}//fin caso 3
			case 4:{
				//Aqu� despliega una lista con los valores del arreglo
				
				imprimir();
				break;
				
			}//fin caso 4
			case 5:{
				//realiza las operaciones de conjuntos
				cout<<"Que operacion desea hacer? Union (u), Interseccion(i), Diferencia(d) o Complemento(c)"<<endl;
				cin>>caso;
				//Aqu� inician m�s opciones para preguntarle al usuario qu� operaci�n desea hacer
				switch(caso){
					/*Almacena los valores de los dos arreglos en uno solo y luego lo muestra*/
					case 'u':{
						unin();
						break;
					}
					
					case 'i':{
						//V�ase la funci�n de la l�nea 37 para entender qu� hace
						cout<<"La interseccion de los dos vectores es igual a:"<<endl;
						
						interseccion();
						break;
					}
					case 'd':{
						eleg=elegarr();
						
						if(eleg==1){
							cout<<"La diferencia entre el primer arreglo y el segundo es:"<<endl;
						dif1();
						}
						else{
							cout<<"La diferencia entre el segundo arreglo y el primer es:"<<endl;
						dif2();
						}
						cout<<endl;
						break;
					}
						
					
					case 'c':{
					/*Si se quiere sacar el complemento de la matriz 1, se imprime la matriz 2 menos
					la diferencia con la matriz1, es decir, todos los elementos que no est�n en la
					matriz 1 ya que la matriz 2 es todo lo que queda del conjunto universo*/
						eleg=elegarr();
						
						if(eleg==1){
							cout<<"El complemento del primer arreglo es:"<<endl;
							dif2();
						}
						else{
							cout<<"El complemento del segundo arreglo es:"<<endl;
							dif1();
						}
					
						break;
					}
					default:{
						cout<<"Operacion invalida"<<endl;
						
						break;
					}
					
				}
				break;
			}
			case 6:{
				ciclo=false;
				cout<<"Programa terminado";
				break;
			} 
			
			/*en caso de que el usuario ponga una opci�n inexistente, le pedir� que la 
			a escribir*/
			default: {
			cout<<"Comando desconocido. Por favor, intente de nuevo\n";
			break;
			}
		}
	}
		return 0;
}
		
