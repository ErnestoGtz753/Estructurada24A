/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 24 de marzo de 2024
PROGRAMA: Libreria_de_hanoi.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Una librería que complementa las funciones del programa de Hanoi_p4.cpp
La recursividad de encuentra en la función "void config_inicial()", hasta el final de archivo.
*/
#include <iostream>

using namespace std;

int validar(){
	int dis;
	cout<<"Dime cuantos discos deseas que la torre de Hanoi tenga? (de 3 a 8)"<<endl;
	cin>>dis;
	while(true){
		if(dis>8 || dis<3){
			cout<<"Valor invalido, introduzca un valor entre 3 y 8"<<endl;
			cin>>dis;
		}
		else break;
		
	}
	
	return dis;
}



void impr_dis(int num){//Imprime cada uno de los discos (dibujados como signos de igual)
	cout<<"\t";
	switch(num){
		case 0:{
			cout<<"       |       \t";
			
			
			
			
			break;
		}
		case 1:{
			cout<<"       =       \t";
			
			
			break;
		}
		case 2:{
			cout<<"      ===      \t";
			
			break;
		}
		case 3:{
			
			cout<<"     =====     \t";
			
			
			break;
		}
		case 4:{
			cout<<"    =======    \t";
			
			
			
			break;
		}
		case 5:{
			cout<<"   =========   \t";
			
			
			
			break;
		}
		case 6:{
			cout<<"  ===========  \t";
			
			
			
			break;
		}
		case 7:{
			cout<<" ============= \t";
			
			
			
			break;
		}
		case 8:{
			cout<<"===============\t";
			
			
			
			break;
		}	
	}
}

void config_inicial(int dis){//Imprime la configuración inicial de los discos con recursividad
	if(dis>=1){
		config_inicial(dis-1);	
		impr_dis(dis);
		
		impr_dis(0);
		impr_dis(0);
		cout<<endl;
		
	}
	
}

