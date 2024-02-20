/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 20 de febrero de 2024
PROGRAMA: vectorfinal(menu).cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: El programa guarda valores, muestra cuántos valores hay registrados, elimina valores concretos,
elimina todos los valores del vector, muestra los valores de un vector, y le pregunta al usuario si quiere
terminar el programa.
*/



#include <iostream>
#include <vector>


	using namespace std;	
int main(int argc, char** argv) {
	/*Tenemos, respectivamente, una variable que determina lo que el usuario quiere hacer,
	un contador, un valor que el vector debe adquirir, una posición que se debe eliminar,
	y, por último, una variable que mantiene el proceso funcionando hasta que el usuario
	lo desee*/
	
	int cas,i=0,val,elim;
	bool ciclo=true;
	vector<int>vec(1);
	//se ejecuta todo hasta que el usuario lo desee
		while(ciclo){
		
			cout<<"Elija una opcion\n";
			cout<<"1-Insertar un valor\n2-Conocer el tamano del vector\n3-Eliminar un valor\n4-Eliminar todos los valores\n5-Mostrar lista de valores\n6-Terminar programa\n";
			cin>>cas;
			
	
	
	//Aquí se decide qué hace el programa
			switch(cas){
			//Aquí se introduce un nuevo valor al vector	
			case 1:
			
				cout<<"Introduzca un valor\n";
				cin>>val;
	
				vec.push_back(val);
				i++;
			break;
			//Aquí se informa al usuario sobre el tamaño del vector
			case 2: cout<<"El tamano del vector es de "<< vec.size()-1 << " espacio(s)\n";
			break;
			
			/*Aquí se le informa sobre los valores del vector para que vea qué valor puede
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
			
			//Aquí se borran todos los elementos del vector
			case 4:for(i=0;i<=vec.size();i++){
					vec.pop_back();	
	
				}
				
				cout<<"Listo, ahora todos los valores del vector estan vacios\n";
				break;
				
			case 5:
				//Aquí despliega una lista con los valores del vector
					cout<<"Los valores del vector son:\n";
				for(i=1;i<vec.size();i++){
					cout<<i<< " -. "<< vec[i] << endl;	
					
				}
					
					cout<<endl;
				
				break;
				
				//Aquí termina el ciclo y el programa finaliza
			case 6:ciclo=false;
				break;
			
			/*en caso de que el usuario ponga una opción inexistente, le pedirá que la 
			a escribir*/
			default: cout<<"Comando desconocido. Por favor, intente de nuevo\n";
			break;
	}
	}
	return 0;
}
