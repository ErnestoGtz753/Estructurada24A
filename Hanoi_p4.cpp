/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 24 de marzo de 2024
PROGRAMA: Hanoi_p4.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Simulación del juego de la "Torre de Hanoi", pero en c++
*/


#include <iostream>
#include <windows.h>//Librería para poder usar system("cls") que sirve para limpiar pantalla
#include <cmath>//lo usaremos para utilizar las potencias y calcular la menor cantidad de movimientos
#include "Libreria_de_hanoi.cpp"
using namespace std;
	int dis,i,j,pos[3][8],torr[3],mov,ori,des;
	short int sta=100;
	char op;
	bool ciclo=true;

void limpiar_inicial();/*Esta función indica las posiciones que tiene cada disco respecto a su torre
y altura iniciales.
*/
void mover();//Hace un movimiento
void imprimir();//Imprime las torres de Hanoi actualizadas
void status();
/*
dis: indica los discos que tendrá la torre
i y j: contadores
torr[8]: indica la altura inicial usada de cada torre
mov: indica los movimientos hechos
ori y des: indican el oriden y destino al que hay que mover el disco, respectivamente


*/

int main(){
	
	while(ciclo){
		
		
		cout<<"Desea jugar (j), ver las instrucciones (v) o terminar el programa (t)?"<<endl;
		cin>>op;
		
		switch(op){
			case 'j':{
				mov=0;
				dis=validar();
				limpiar_inicial();
					
					for(i=0;i<=80;i++){
						cout<<"=";
							
					}
					cout<<endl;
					cout<<"+---------+"<<endl<<"|    0    |"<<endl<<"+---------+"<<endl<<endl<<endl;
					for(i=1;i<=(10-dis);i++){
						for(j=1;j<=3;j++){
						impr_dis(0);	
							
							
						}
						cout<<endl;
					}
					config_inicial(dis);
					
					cout<<endl;
					for(i=0;i<=80;i++){
						cout<<"=";
							
					}
					cout<<endl;
					mover();
					while(torr[2]<(dis-1)){//Aquí ya puede jugar y mover discos. Se detiene cuando ya están todos los discos en la última torre
					system("cls");
					
						for(i=0;i<=80;i++){//Imprime el borde superior
						cout<<"=";	
						}
						
						cout<<endl;
						//Imprime el cuadro donde está la cant. de movimientos
						cout<<"+---------+"<<endl<<"|    "<<mov<<"    |"<<endl<<"+---------+"<<endl<<endl<<endl;
						for(i=1;i<=2;i++){//Imprime dos filas sin discos
							for(j=1;j<=3;j++){
							impr_dis(0);	
									
							}
							cout<<endl;
						}
						//Aquí falta imprimir las torres de hanoi actualizadas
						imprimir();
						cout<<endl;
						
						for(i=0;i<=80;i++){//Imprime el borde inferior
							cout<<"=";
								
						}
						cout<<endl;
						
						status();
						cout<<endl;
						mover();
					}
					system("cls");
					sta=20;
					for(i=0;i<=80;i++){//Imprime el borde superior
						cout<<"=";	
						}
						
						cout<<endl;
						//Imprime el cuadro donde está la cant. de movimientos
						cout<<"+---------+"<<endl<<"|    "<<mov<<"    |"<<endl<<"+---------+"<<endl<<endl<<endl;
						for(i=1;i<=2;i++){//Imprime dos filas sin discos
							for(j=1;j<=3;j++){
							impr_dis(0);	
									
							}
							cout<<endl;
						}
						//Aquí falta imprimir las torres de hanoi actualizadas
						imprimir();
						cout<<endl;
						
						for(i=0;i<=80;i++){//Imprime el borde inferior
							cout<<"=";
								
						}
						cout<<endl;
						status();
				
				
				
				
				break;
			}
			case 'v':{
				cout<<"Para mover un disco, escriba un numero (del 1 al 3) que indica la torre en la que esta el disco que desea mover"<<endl;
				cout<<"Despues introduzca un numero (del 1 al 3) para indicar la torre a la que quiere mover el disco"<<endl;
				cout<<"Recuerde que no puede poner discos sobre otros mas pequenos"<<endl;
				cout<<"Tampoco puede mover discos que no existen o discos que estan bajo otros, por lo que solo se movera el de la parte superior de la torre"<<endl<<endl;
				cout<<"En caso de haber algun error, habra una seccion de 'estatus' que le dira que ocurrio"<<endl;
				cout<<"La meta es acomodar los discos, en la menor cantidad de movimientos posibles, de forma ascendente en la tercera torre,\nsiendo el mas pequeno el que mas alto esta en la torre, y el mas grande hasta el fondo"<<endl<<endl;
				cout<<"Si mientras la ejecucion del juego, desea ya no jugar, solo cierre el programa"<<endl<<endl;
				
				
				
				break;
			}
			case 't':{
				cout<<"Programa terminado correctamente. Gracias por jugar.";
				ciclo=false;
				
				
				break;
			}
			default:{
				cout<<"Comando desconocido."<<endl;
				
				
				break;
			}
				
		}
	
		
	}
	
	
	
	
	
	return 0;
}

void limpiar_inicial(){
	for(i=0;i<dis;i++){/*Indica las posiciones de cada disco en relación a la torre.
				Todos inician en la primera torre, pero a diferentes alturas*/
				
		pos[0][i]=(dis-i);//En la torre 1 se almacena la posición respectiva de cada disco
		//cout<<"i"<<i<<" "<<pos[0][i]<<" "; //Prueba para comprobar el correcto almacenamiento de posiciones		
	}
	for(i;i<=7;i++){
		pos[0][i]=0;//El resto de la primera torre se llena de 0, indicando que no hay nada
					
	}
				
	for(i=1;i<=2;i++){//Esto limpia el resto de posiciones de las otras dos torres
		for(j=0;j<7;j++){
			pos[i][j]=0;	
						
		}			
	}
	torr[0]=dis-1;
	torr[1]=-1;
	torr[2]=-1;
	
}
void mover(){//Indica la torre a la que hay que mover un disco
	
	cout<<"Origen: "<<endl;
	cin>>ori;
	ori--;
	if((ori>=0 && ori<=2) && (torr[ori]>=0)){
		cout<<"Destino: "<<endl;
		cin>>des;
		des--;
		if((des<0 || des>2)||(pos[des][torr[des]]<pos[ori][torr[ori]]&&pos[des][torr[des]]>0)||ori==des){
			/*Si el destino no está dentro de ninguna de las tres torres o
			si el disco de destino tiene un tamaño menor al del origen, entonces no hace nada.
			*/
			
			if(des<0 || des>2)sta=0;
			else if(pos[des][torr[des]]<pos[ori][torr[ori]]&&pos[des][torr[des]]>0)sta=1;
			else sta=2;
				
		}
		else{//Aquí mueve un disco de torre
			
			torr[des]++;//la altura de la torre de destino aumenta en una posición
			//cout<<"torr des ++ = "<<torr[des]<<endl;
			/*cout<<"Valores de pos\n";
			for(i=0;i<dis;i++)cout<<pos[0][i]<<" ";*/
			pos[des][torr[des]]=pos[ori][torr[ori]];//la torre de destino almacena el nuevo disco
			//cout<<"pos destino = "<<pos[des][torr[des]]<<endl;
			pos[ori][torr[ori]]=0;//la torre de origen pierde un disco
			//cout<<"pos origen = "<<pos[ori][torr[ori]]<<endl;
			torr[ori]--;//la altura de la torre de origen disminuye en una posición
			//cout<<"torr ori -- = "<<torr[ori]<<endl;
			mov++;//Se hizo un movimiento.
			
		}
		
	}
	else{
		if(ori<0 || ori>2)sta=10;
		else sta=11;	
		
	}
	
}	

void imprimir(){
	for(i=7;i>=0;i--){
		for(j=0;j<=2;j++){
			if(i>torr[j]){
				impr_dis(0);
			}
			else{	
				impr_dis(pos[j][i]);
			}
			
		}
		cout<<endl;
			
	}	
	
}
void status(){//Imprime el estatus del programa para que el usuario lo vea
	cout<<"Estatus:"<<endl;
	switch(sta){
		case 100:{
			cout<<"Disco correctamente cambiado de posicicion"<<endl;
			
			
			break;
		}
		case 20:{
			cout<<"\aGanaste!";
					if(mov>(pow(2,dis)-1))cout<<" pero lo pudiste haber hecho en "<<pow(2,dis)-1<<" movimientos."<<endl;
					else cout<<" y lo hiciste en la menor cantidad de movimientos posible."<<endl;
					cout<<endl;
			break;
		}
		case 0:{
		
		cout<<"Destino invalido porque esa torre de destino no existe"<<endl;
			
			
			break;
		}
		case 1:{
			cout<<"Destino invalido porque no puede poner un disco sobre otro que sea mas pequeno"<<endl;
			
			
			break;
		}
		case 2:{
			cout<<"Destino invalido porque no puede poner el disco en la misma torre\n";
			break;
		}
		case 10:{
			cout<<"Origen invalido porque no existe esa torre"<<endl;
			
			
			break;
		}
		case 11:{
			cout<<"Origen invalido porque no hay disco en esa torre"<<endl;
			
			
			break;
		}
		
		
		
		
	}
	sta=100;
	
	
}


