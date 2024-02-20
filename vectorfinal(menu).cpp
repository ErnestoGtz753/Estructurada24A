/*
NOMBRE: Ernesto Guti�rrez Garc�a
FECHA: 20 de febrero de 2024
PROGRAMA: vectorfinal(menu).cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIER�A EN COMPUTACI�N / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCI�N: El programa guarda valores, muestra cu�ntos valores hay registrados, elimina valores concretos,
elimina todos los valores del vector, muestra los valores de un vector, y le pregunta al usuario si quiere
terminar el programa.
*/



#include <iostream>
#include <vector>


	using namespace std;	
int main(int argc, char** argv) {
	/*Tenemos, respectivamente, una variable que determina lo que el usuario quiere hacer,
	un contador, un valor que el vector debe adquirir, una posici�n que se debe eliminar,
	y, por �ltimo, una variable que mantiene el proceso funcionando hasta que el usuario
	lo desee*/
	
	int cas,i=0,val,elim;
	bool ciclo=true;
	vector<int>vec(1);
	//se ejecuta todo hasta que el usuario lo desee
		while(ciclo){
		
			cout<<"Elija una opcion\n";
			cout<<"1-Insertar un valor\n2-Conocer el tamano del vector\n3-Eliminar un valor\n4-Eliminar todos los valores\n5-Mostrar lista de valores\n6-Terminar programa\n";
			cin>>cas;
			
	
	
	//Aqu� se decide qu� hace el programa
			switch(cas){
			//Aqu� se introduce un nuevo valor al vector	
			case 1:
			
				cout<<"Introduzca un valor\n";
				cin>>val;
	
				vec.push_back(val);
				i++;
			break;
			//Aqu� se informa al usuario sobre el tama�o del vector
			case 2: cout<<"El tamano del vector es de "<< vec.size()-1 << " espacio(s)\n";
			break;
			
			/*Aqu� se le informa sobre los valores del vector para que vea qu� valor puede
			modificar*/
			case 3: 
			cout<<"Los actuales valores del vector son:\n";
				for(i=1;i<vec.size();i++){
					cout<<i<< " -. "<< vec[i] << endl;	
					
				}
			
			cout << "Que posicion de valor quieres eliminar?\n";
			cin>>elim;
			if(elim>0 && elim<=vec.size()){
				cout<<"Introduzca un nuevo valor entero\n";
				cin>>val;
				vec[elim]=val;
			}
			else cout<<"Posicion no valida\n";
			break;
			
			//Aqu� se borran todos los elementos del vector
			case 4:for(i=0;i<=vec.size();i++){
					vec.pop_back();	
	
				}
				
				cout<<"Listo, ahora todos los valores del vector estan vacios\n";
				break;
				
			case 5:
				//Aqu� despliega una lista con los valores del vector
					cout<<"Los valores del vector son:\n";
				for(i=1;i<vec.size();i++){
					cout<<i<< " -. "<< vec[i] << endl;	
					
				}
					
					cout<<endl;
				
				break;
				
				//Aqu� termina el ciclo y el programa finaliza
			case 6:ciclo=false;
				break;
			
			/*en caso de que el usuario ponga una opci�n inexistente, le pedir� que la 
			a escribir*/
			default: cout<<"Comando desconocido. Por favor, intente de nuevo\n";
			break;
	}
	}
	return 0;
}
