#include <iostream>
using namespace std;
/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 03 de marzo de 2024
PROGRAMA: vector y conjunto (libreria propia).cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Este programa es una librería que es llamada por el usuario desde el programa principal
y que realiza todas las operaciones entre conjuntos, imprime valores y los modifica
*/

	int casa,ia,ja,ka,k1a=0,k2a=0,ha,vala,elima,suma,elega,nosa=0;
	/*Estos son arreglos que almacenan los valores que el usuario solicita o que almacenan los resultados */
	char casoa, arr1a[20],arr2a[20],resula[40],val2a,val3a;
	
		char imprimir(){//Imprime los valores de los dos arreglos
		//
			cout<<"Arreglo n1:"<<endl;
			/*int k1, i, k2;
			char arr1[20],arr2[20];*/
			
			if(k1a==0){
				cout<<"Sin elementos\n\n";
			}
			else{
				for(ia=0;ia<k1a;ia++){
				cout<<ia+1<<"-. "<<arr1a[ia]<<"\n";
				}	
			}
			
			cout<<"Arreglo n2:"<<endl;
			if(k2a==0){
				cout<<"Sin elementos\n\n";
			}
			else{
				for(ia=0;ia<k2a;ia++){
				cout<<ia+1<<"-. "<<arr2a[ia]<<"\n";
				}	
			}
			cout<<endl;
		}
		
		/*Al igual que la intersección, compara todas las palabras, pero en caso de no coincidir
		ninguna, entonces se almacena la palabra en la matriz resul, indicando que no hay valor qué
		eliminar. Lo mismo para dif2, pero esta vez es la matriz2 menos la matriz1*/
		char dif1(){//Calcula: arreglo1 - arreglo2	
			int ha=0;
			
						for(ia=0;ia<k1a;ia++){
							nosa=0;
							for(ja=0;ja<k2a;ja++){
									if(arr1a[ia]==arr2a[ja]){
										nosa++;
										break;
									}		
							}
							if(nosa==0){
								resula[ha]=arr1a[ia];
								ha++;
							}
						}
			if(ha!=0){
				for(ia=0;ia<ha;ia++){
				cout<<ia+1<<"-."<<resula[ia]<<endl;
				}
			}
			else cout<<"Conjunto vacio";
			
			cout<<endl;
		}//fin dif1
		
		char dif2(){//Calcula: arreglo2 - arreglo1

			 int ha=0;
			 //char arr1a[20], arr2a[20], resul[40];
						for(ia=0;ia<k2a;ia++){
							nosa=0;
							for(ja=0;ja<k1a;ja++){
									if(arr2a[ia]==arr1a[ja]){
										nosa++;
										break;
									}		
							}
							if(nosa==0){
								resula[ha]=arr2a[ia];
								ha++;
							}
						}
			if(ha!=0){			
				for(ia=0;ia<ha;ia++){
					cout<<ia+1<<"-."<<resula[ia]<<"\n";
				}
			}
			else cout<<"Conjunto vacio";
			cout<<endl;
		}//fin dif2

		int elegarr(){//valida que se escoja un arreglo válido (1 o 2)
			//int elega;		
			while(true){
					cout<<"En cual de los dos arreglos desea hacer el cambio? (1 o 2)"<<endl;
					cin>>elega;
					if(elega==1 || elega==2){
						return elega;
					//break;	
					}
					else cout<<"Arreglo invalido, vuelva a intentarlo"<<endl;
			}
		}//fin elegarr
		
		char validar(char vala){
			if((vala>=65 && vala<=90) || (vala>=97 && vala<=122) || (vala>=48 && vala<=57)){
				return vala;
			}
			else return '@';
		}
		
		char valtodo(char val3a){
				if(elega==1){
					//cin>>val3;
					val2a=validar(val3a);
				
					if(k1a==0 && val2a!='@'){arr1a[k1a]=val2a;
					k1a++;}
						else{
								for(ia=0;ia<k1a;ia++){
									if(val2a==arr1a[ia] || val2a=='@'){
										cout<<"El valor no se almacenara porque ya esta repetido o porque es un caracter especial\n\n";
										break;
									}
									else {
										arr1a[k1a]=val2a;
										k1a++;
										break;
									}
								}
							
						}
				}
				else{
				//	cin>>val3;
					val2a=validar(val3a);
					if(k2a==0 && val2a!='@'){arr2a[k2a]=val2a;
					k2a++;}
					else{
							for(ia=0;ia<k2a;ia++){
								if(val2a==arr2a[ia]||val2a=='@'){
									cout<<"El valor no se almacenara porque ya esta repetido o porque es un caracter especial\n\n";
									break;
								}
								else {
									arr2a[k2a]=val2a;
									k2a++;
									break;
								}
							}
						
					}
				}
			
		}
		
		void unin(){
			cout<<"El valor de la union es:"<<endl;
						
						ha=0;
						for(ia=0;ia<k1a;ia++){
							resula[ha]=arr1a[ia];
							ha++;	
						}
						
						for(ia=0;ia<k2a;ia++){
							nosa=0;
							for(ja=0;ja<k1a;ja++){
								if(arr2a[ia]==arr1a[ja]){
									nosa++;
									break;
								}	
							}
							if(nosa==0){
								resula[ha]=arr2a[ia];
								ha++;
							}		
						}
						
						if(ha!=0){
							for(ia=0;ia<ha;ia++){
							cout<<ia+1<<"-."<<resula[ia]<<endl;
							}
						}
						else cout<<"Conjunto vacio";
						
						
						ha=0;
						cout<<endl;
		}
		
		void interseccion(){
			for(ia=0;ia<k1a;ia++){
							for(ja=0;ja<k2a;ja++){
								if(arr1a[ia]==arr2a[ja]){
									resula[ha]=arr1a[ia];
									ha++;			
									break;
								}	
							}
						}
						if(ha==0)cout<<"Conjunto vacio\n\n";
						else{
							for(ia=0;ia<ha;ia++){
								cout<<ia+1<<"-."<<resula[ia]<<endl;
							}
						}
						ha=0;
					cout<<endl;									
		}
		
		void mod(){
			imprimir();
			elega=elegarr();
			cout << "Que posicion de valor quieres modificar?\n";
				cin>>elima;
				
				if(elega==1){
					if(elima>=1 && elima<=k1a){
					cout<<"Introduzca el nuevo valor\n";
					cin>>arr1a[elima-1];
					}
					else cout<<"Posicion no valida\n";
				}
				else {if(elima>=1 && elima<=k2a){
					cout<<"Introduzca el nuevo valor\n";
					cin>>arr2a[elima-1];
				
				}
				else cout<<"Posicion no valida\n";
				}
			
		}
