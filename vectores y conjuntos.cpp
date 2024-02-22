/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 22 de febrero de 2024
PROGRAMA: vectores y conjuntos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: El programa guarda valores, muestra cuántos valores hay registrados, elimina valores concretos,
elimina todos los valores del vector, muestra los valores de un vector, y le pregunta al usuario si quiere
terminar el programa.
*/



#include <iostream>
#include <vector>
#include <cstring>


	using namespace std;
	/*Tenemos, respectivamente, una variable que determina lo que el usuario quiere hacer,
	tres contadores,el tamaño real de cada arreglo, un valor que el vector debe adquirir,
	una posición que se debe eliminar, una variable que indica la posición a modificar,
	una variable que suma valores, una variable que elige un vector, y, por último, otra variable que
	determina si se ejecuta una operación*/
	
	int cas,i,j,k,k1=0,k2=0,h,val,elim,sum,eleg,nos=0;
	/*Estos son matrices que almacenan los valores que el usuario solicita (deben de ser matrices
	para almacenar varios caracteres dentro de una misma fila), o que almacenan los resultados */
	char caso,arr1[20][20],arr2[20][20],resul[40][20];
	
	//variable que mantiene a los ciclos funcionando
	bool ciclo=true;
	//para iniciar, un vector de una posición cuyo único valor es igual a "0"
	
	/*De manera resumida, la intersección compara todos los caracteres de cada palabra de cada
	matriz. Si un caracter no coincide con una palabra, se aumenta un valor que indica cuántas
	palabras de una matriz no coinciden con ninguna palabra de la primera matriz. En caso de que
	ninguna palabra coincida, el contador valdrá lo mismo que la cantidad de valores de la
	segunda matriz y no se almacenará la palabra en la matriz resul ya que ninguna palabra de la
	primera matriz coincide con la segunda. */
		void interseccion(){
			h=0;
			for(i=0;i<k1;i++){
							nos=0;
							for(j=0;j<k2;j++){
								for(k=0;k<20;k++){
									if(arr1[i][k]!=arr2[j][k]){
									nos++;
									
									break;
									}	
								}	
							}
							if(nos<k2){
									for(k=0;k<20;k++){
										resul[h][k]=arr1[i][k];
									}
									h++;
								}
						}
		}
		//Imprime los valores de ambas matrices a través de dos for anidados
		void imprimir(){
		cout<<"Arreglo n1:"<<endl;
				for(i=0;i<k1;i++){
					j=0;
					if(arr1[i][j]=='\0')break;
				
					printf("%d-. ",i+1);
					for(j=0;j<20;j++){
						if(arr1[i][j]!='\0')printf("%c",arr1[i][j]);
						else break;	
					}
					
					cout<<endl;
		
				}
					
				cout<<endl<<"Arreglo n2:"<<endl;
				for(i=0;i<k2;i++){
					j=0;
					if(arr2[i][j]=='\0')break;
				
					printf("%d-. ",i+1);
					for(j=0;j<20;j++){
						if(arr2[i][j]!='\0')printf("%c",arr2[i][j]);
						else break;	
					}
					
					cout<<endl;
		
				}
				cout<<endl;
			
		}
		/*Al igual que la intersección, compara todas las palabras, pero en caso de no coincidir
		ninguna, entonces se almacena la palabra en la matriz resul, indicando que no hay valor qué
		eliminar. Lo mismo para dif2, pero esta vez es la matriz2 menos la matriz1*/
		void dif1(){
			h=0;
						for(i=0;i<k1;i++){
							nos=0;
							for(j=0;j<k2;j++){
								for(k=0;k<20;k++){
									if(arr1[i][k]!=arr2[j][k]){
									nos++;
									break;
									}	
								}	
							}
							if(nos==k2){
									for(k=0;k<20;k++){
										resul[h][k]=arr1[i][k];
									}
									h++;
								}
						}
						for(i=0;i<h;i++){
								cout<<i+1<<"-."<<resul[i]<<endl;
						}
		}
		void dif2(){
			h=0;
						for(i=0;i<k2;i++){
							nos=0;
							for(j=0;j<k1;j++){
								for(k=0;k<20;k++){
									if(arr2[i][k]!=arr1[j][k]){
									nos++;
									break;
									}	
								}	
							}
							if(nos==k1){
									for(k=0;k<20;k++){
										resul[h][k]=arr2[i][k];
									}
									h++;
								}
						}
						for(i=0;i<h;i++){
								cout<<i+1<<"-."<<resul[i]<<endl;
						}
		}
	
			
			
int main(int argc, char** argv) {
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			arr1[i][j]='\0';
			arr2[i][j]='\0';
		
		}
		
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
			
	//Aquí se decide qué hace el programa
	
			switch(cas){
				
			//Aquí se introduce un nuevo valor al vector	
			case 1:{
				
			//valida que se ingrese un arreglo existente
				for(;;){
				
					cout<<"En cual de los dos arreglos desea insertar los valores? (1 o 2)"<<endl;
					cin>>eleg;
					if(eleg==1 || eleg==2)break;
					else cout<<"Arreglo invalido, vuelva a intentarlo"<<endl;
				}
			//almacena un valor dentro del arreglo
				cout<<"Introduzca un valor o cadena de caracteres (menor a 20)"<<endl;
				if(eleg==1){
					scanf("%s",arr1[k1]);
					k1++;
				}
				else{
					scanf("%s",arr2[k2]);
					k2++;
				}
				
			break;
			}
			/*Aquí se le informa sobre los valores del vector para que vea qué valor puede
			modificar*/
			case 2: {
			
			//muestra los valores del arreglo y luego da oportunidad de modificarlos
				cout<<"Los valores de los dos arreglos son:\n";
					imprimir();
				
				for(;;){
				
					cout<<"En cual de los dos arreglos desea modificar los valores? (1 o 2)"<<endl;
					cin>>eleg;
					if(eleg==1 || eleg==2)break;
					else cout<<"Arreglo invalido, vuelva a intentarlo"<<endl;
				}
				cout << "Que posicion de valor quieres modificar?\n";
				cin>>elim;
				if(eleg==1){
					if(elim>0 && elim<=k1){
					cout<<"Introduzca el nuevo valor\n";
					scanf("%s",&arr1[elim-1]);
					}
					else cout<<"Posicion no valida\n";
				}
				else {if(elim>0 && elim<=k2){
					cout<<"Introduzca el nuevo valor\n";
					scanf("%s",&arr2[elim-1]);
				
				}
				else cout<<"Posicion no valida\n";
				}
			
			break;
			}
			//Aquí se borran todos los elementos del vector
			case 3:{
				
			//pregunta en qué arreglo se borrarán todos su valores
				for(;;){
				
					cout<<"En cual de los dos arreglos desea borrar todos sus valores? (1 o 2)"<<endl;
					cin>>eleg;
					if(eleg==1 || eleg==2)break;
					else cout<<"Arreglo invalido, vuelva a intentarlo"<<endl;
				}
				if(eleg==1){
					for(i=0;i<20;i++){
						for(j=0;j<20;j++){
							arr1[i][j]='\0';
						}
					}
					k1=0;
				}else{
					for(i=0;i<20;i++){
						for(j=0;j<20;j++){
							arr2[i][j]='\0';
						}
					}
					k2=0;
				}
				break;
			}
			case 4:{
				
			
				//Aquí despliega una lista con los valores de la matriz
				imprimir();
				break;
				
			}
			case 5:{
				//realiza las operaciones de conjuntos
				cout<<"Que operacion desea hacer? Union (u), Interseccion(i), Diferencia(d) o Complemento(c)"<<endl;
				cin>>caso;
				
				switch(caso){
					/*Almacena los valores de las dos matrices en una sola y luego la muestra*/
					case 'u':{
						cout<<"El valor de la union es:"<<endl;
						h=0;
						for(i=0;i<k1;i++){
							for(j=0;j<20;j++){
								resul[h][j]=arr1[i][j];
							}
							h++;
							
						}
						for(i=0;i<k2;i++){
							for(j=0;j<20;j++){
								resul[h][j]=arr2[i][j];
							}
							h++;	
						}
						
						
							for(i=0;i<k1+k2;i++){
								cout<<i+1<<".-"<<resul[i]<<endl;
							}
						cout<<endl;
						break;
					}
					
					case 'i':{
						//Véase la función de la línea 37 para entender qué hace
						cout<<"La interseccion de los dos vectores es igual a:"<<endl;
						
						interseccion();
						
						for(i=0;i<h;i++){
								cout<<i+1<<"-."<<resul[i]<<endl;
						}
					cout<<endl;
						break;
					}
					case 'd':{
						for(;;){
				
							cout<<"A cual de los dos arreglos quiere sacarle diferencia? (1 o 2)"<<endl;
							cin>>eleg;
							if(eleg==1 || eleg==2)break;
							else cout<<"Arreglo invalido, vuelva a intentarlo"<<endl;
						}
						if(eleg==1){
							cout<<"La diferencia entre el primer vector y el segundo es:"<<endl;
						dif1();
						}
						else{
							cout<<"La diferencia entre el segundo vector y el primer es:"<<endl;
						dif2();
						}
						cout<<endl;
						break;
					}
						
					
					case 'c':{
					/*Si se quiere sacar el complemento de la matriz 1, se imprime la matriz 2 menos
					la diferencia con la matriz1, es decir, todos los elementos que no están en la
					matriz 1 ya que la matriz 2 es todo lo que queda del conjunto universo*/
						for(;;){
				
						cout<<"A cual de los dos vectores le quiere sacar su complemento? (1 o 2)"<<endl;
						cin>>eleg;
						if(eleg==1 || eleg==2)break;
						else cout<<"Arreglo invalido, vuelva a intentarlo"<<endl;
						}
						
						if(eleg==1){
							h=0;
							for(i=0;i<k2;i++){
								nos=0;
								for(j=0;j<k1;j++){
									for(k=0;k<20;k++){
										if(arr2[i][k]!=arr1[j][k]){
										nos++;
										break;
										}	
									}	
								}
								if(nos==k1){
										for(k=0;k<20;k++){
											resul[h][k]=arr2[i][k];
										}
										h++;
									}
							}
							cout<<"El complemento del primer arreglo es:"<<endl;
							for(i=0;i<h;i++){
									cout<<i+1<<"-."<<resul[i]<<endl;
							}
						}
						else{h=0;
							for(i=0;i<k1;i++){
								nos=0;
								for(j=0;j<k2;j++){
									for(k=0;k<20;k++){
										if(arr1[i][k]!=arr2[j][k]){
										nos++;
										break;
										}	
									}	
								}
								if(nos==k2){
										for(k=0;k<20;k++){
											resul[h][k]=arr1[i][k];
										}
										h++;
									}
							}
							cout<<"El complemento del segundo arreglo es:"<<endl;
							for(i=0;i<h;i++){
									cout<<i+1<<"-."<<resul[i]<<endl;
							}
						}
						cout<<endl;
						break;
					}
					default:{
						
						break;
					}
					
				}
				break;
			}
			case 6:{
				ciclo=false;
				break;
			} 
			
			/*en caso de que el usuario ponga una opción inexistente, le pedirá que la 
			a escribir*/
			default: {
			cout<<"Comando desconocido. Por favor, intente de nuevo\n";
			break;
			}
		}
	}
		return 0;
}
		
