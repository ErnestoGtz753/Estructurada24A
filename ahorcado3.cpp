/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 19 de abril de 2024
PROGRAMA: ahorcado3.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Recrea el juego del ahorcado en donde puedes escribir una letra, para adivinar
poco a poco la palabra; o escribir la palabra completa. Tienes seis oportunidades y
la palabra la escoge aleatoriamente la computadora de un banco de 20 palabras.
*/



#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

/*
tam: determina el tamaño máximo de letras con el que el programa trabaja bien

dib: fase del ahorcado que hay que dibujar
pal:determina el número de la palabra que se usará del banco de palabras
vid: vidas disponibles
i, j y h: contadores
estatus: indica cuál número de estado que la función "status" debe de mostrar
coin: cantidad de letras que coinciden con la palabra original. Usado en funciones
inten: intentos


palabra: palabra concreta del banco de palabras
letra: contiene la letra o palabra que el usuario ingresa para adivinar

op: opcion a escoger
usd: letras usadas
letra: letra que el usuario introduce
usarlet: letras usadas

ciclo: mantiene todo el programa repitiéndose
jugar: mantiene el juego del ahorcado funcionando
usada: la letra ya fue usada
coin: la letra sí coincide con alguna de la palabra escogida del banco de palabras

op: opción escogida (jugar, instrucciones o terminar)
usd: letras usadas en el programa. Para evitar errores con las vidas
usarlet: letras, de forma ordenada, que el usuario ya adivinó

ciclo: mantiene al programa funcionando.
jugar: mantiene al juego corriendo
usada: indica si una letra ya se usó. Funciona dentro de las funciones
*/

const int tam=20;
short int dib,pal=0,vid=6,i,j,h=0,estatus,coin=0,inten;
string palabra,letra;

char op,usd[20],usarlet[tam];
bool ciclo=1,jugar=1,usada;

void limpiar(){/*esta función limpia las variables que contienen las letras.
Necesario cuando el usuario quiere jugar varias veces dentro de la misma ejecución del programa.*/
	for(i=0;i<20;i++){
    	usd[i]=' ';
                    
    }
    
    for(i=0;i<tam;i++){
        usarlet[i]=' ';
                    
    }
	
	
	
}
void validar(){
	coin=0;	
	usada=0;
	
	
		if(vid>0){
			if(letra.size()==1){
				for(j=0;j<20;j++){
					if(letra[0]==usd[j]){
						usada=1;
						estatus=1;
						break;
					}	
				}
				if(usada==0){
					for(j=0;j<palabra.size();j++){
					
						if(palabra[j]==letra[0]){
							if(letra[0]=='a' || letra[0]=='e' || letra[0]=='i' || letra[0]=='o' || letra[0]=='u'){
								vid--;
							}
							usd[h]=letra[0];
							h++;
							estatus=7;
							break;
						}	
						
					}
					for(j=0;j<palabra.size();j++){
						if(palabra[j]==letra[0]){
							usarlet[j]=letra[0];
							
							coin=1;
						}
						
					}
					if(coin==0){
						vid--;
						usd[h]=letra[0];
							h++;
						estatus=2;
						
					}
				}
			
			}
			else{
				if(letra.size()==palabra.size()){
					for(i=0;i<letra.size();i++){
						if(letra[i]==palabra[i])
						coin++;
						
					}
					if(coin==letra.size()){
						estatus=6;
					}
					else {
						vid--;
						estatus=5;
					}
					
				}
				else{
					vid--;
					estatus=5;
					
				}
					
			}	
			coin=0;
			for(i=0;i<palabra.size();i++){
				if(usarlet[i]==palabra[i]){
					coin++;
					
				}			
			}
			if(coin==palabra.size()){
				jugar=0;
				estatus=4;
			}	
		}
		else{
			jugar=0;
			estatus=3;
		}		
}

void status(){
	cout<<"Estatus:"<<endl;
	switch(estatus){//informa sobre la realizacion de la accion
        case 1:{
            cout<<"No se realizo ninguna accion ya que esa letra ya fue usada";
            break;
        }
        case 2:{
            cout<<"Letra incorrecta";
            break;
        }
        case 3:{
            cout<<"Se acabaron las vidas. La palabra que debias adivinar es "<<palabra;
            break;
        }
        case 4:{
            cout<<"Ganaste! Felicidades! Adivinaste que la palabra es "<<palabra<<"!";
                		
            break;
        }
        case 5:{
            cout<<"La palabra que escribiste no es correcta";
            break;
        }
        case 6:{
            cout<<"La palabra que escribiste es correcta! Adivinaste que la palabra es "<<palabra<<"!";
            jugar=0;
            break;
        }
        case 7:{
            cout<<"La letra que escribio es correcta";
            break;
        }                  	
    }
    cout<<endl<<endl; 
	
	
}

void base(int pal){//determina la palabra a usar
	switch(pal){
		case 1:{
			palabra="mariposa";
			break;
		}
		case 2:{
			palabra="espejo";
			break;
		}
		case 3:{
			palabra="camino";
			break;
		}
		case 4:{
			palabra="ventana";
			break;
		}
		case 5:{
			palabra="ardilla";
			break;
		}
		case 6:{
			palabra="reloj";
			break;
		}
		case 7:{
			palabra="monte";
			break;
		}
		case 8:{
			palabra="caracol";
			break;
		}
		case 9:{
			palabra="manzana";
			break;
		}
		case 10:{
			palabra="estambre";
			break;
		}
		case 11:{
			palabra="electricidad";
			break;
		}
		case 12:{
			palabra="macaco";
			break;
		}
		case 13:{
			palabra="cine";
			break;
		}
		case 14:{
			palabra="dormir";
			break;
		}
		case 15:{
			palabra="entablar";
			break;
		}
		case 16:{
			palabra="presidente";
			break;
		}
		case 17:{
			palabra="quisquilloso";
			break;
		}
		case 18:{
			palabra="computadora";
			break;
		}
		case 19:{
			palabra="robocop";
			break;
		}
		case 20:{
			palabra="rostizar";
			break;
		}
	
	}
      
}
    
void dibujar (int dib){
        
        for(i=0;i<=20;i++){
            cout<<"=";
        }
        cout<<endl<<endl;
        cout<<"Vidas: "<<vid<<endl;
        cout<<"Intentos: "<<inten<<endl<<endl;
       
        
        
        cout<<"+---+"<<endl;
            
        switch(dib){//Dibuja la fase del monito del ahorcado
           case 0:{
               cout<<"|"<<endl<<"|"<<endl<<"|"<<endl;
               break;
           } 
           case 1:{
               cout<<"|    O"<<endl<<"|"<<endl<<"|"<<endl;
               break;
           }
           case 2:{
               cout<<"|    O"<<endl<<"|    |"<<endl<<"|"<<endl;
               break;
           }
           case 3:{
               cout<<"|    O"<<endl<<"|   -|"<<endl<<"|"<<endl;
               break;
           }
           case 4:{
               cout<<"|    O"<<endl<<"|   -|-"<<endl<<"|"<<endl;
               break;
           }
           case 5:{
               cout<<"|    O"<<endl<<"|   -|-"<<endl<<"|   -"<<endl;
               break;
           }
           case 6:{
               cout<<"|    O"<<endl<<"|   -|-"<<endl<<"|   - -"<<endl;
               break;
           }
        }
        
        cout<<"==="<<endl;
        cout<<endl;
        cout<<"Letras usadas"<<endl;
        for(i=0;i<6;i++){
            cout<<usd[i]<<" ";
            
            
        }
        cout<<endl<<endl<<endl<<"Progreso"<<endl;;
        
        for(int i=0;i<palabra.size();i++){
            cout<<usarlet[i]<<" ";
            
        }
        cout<<endl;
        
        for(int i=0;i<palabra.size();i++){
            cout<<(char)238<<" ";
        }
        cout<<endl<<endl;
        
        for(int i=0;i<=20;i++){
            cout<<"=";
        }
        cout<<endl<<endl;
    }
    
    
    
int main(){
    do{
        cout<<"Que desea hacer:"<<endl;
        cout<<"1.-Jugar"<<endl;
        cout<<"2.-Ver las instrucciones"<<endl;
        cout<<"3.-Terminar programa"<<endl<<endl;
        
        cin>>op;
        system("cls");//borra pantalla para que se vea bien
        switch(op){
            case '1':{//caso para jugar
            	inten=0;
            	jugar=1;
            	vid=6;
            	h=0;
            	//escoge la palabra de forma aleatoria
                base(1+rand()%20);
                
                coin=0;
                
                letra=" ";
               
                limpiar();
                dibujar(0);
                
               	cout<<"Escribe una letra"<<endl;
               	cin>>letra;
               	validar();
               	status();
               	inten++;
                do{
                	
                	coin=0;
                	system("cls");
                	dibujar(6-vid);//esta función dibuja la interfaz gráfica
                	status();//informa al usuario sobre el estado de la acción
                	if(jugar==0)break;
    
                	
                	cout<<"Escribe una letra o palabra"<<endl;
	               	cin>>letra;//pide una letra o palabra
					cout<<endl<<endl;
	               	validar();//esta función determinar cuándo ganas o pierdes y tu progreso
	               	inten++;
                }while(jugar);
                
               		system("cls");
                	dibujar(6-vid);
                	status();
                
                cout<<"\a";
                
                
                
                
                
                
                break;
            }
            case '2':{//Indicaciones de cómo jugar
                cout<<"El juego consiste en adivinar una palabra. Para ello, debes intentar adivinando sus letras por medio del teclado.\nSi adivinas una letra, se pondra en la seccion de progreso, si no, te quitara una vida.\n\nAunque la vocal forme parte de la palabra, se te restara una vida.\nSi ya conoces la palabra, escribela completa, si es correcta, ganas, si no, pierdes una vida.\nSolo tienes seis vidas en total.\n\nNota: no hay mayusculas ni acentos, y todas son palabras unicas (no hay frases ni espacios).\n\nDisfruta!\n\n";
                
                
                break;
            }
            case '3':{//Termina la ejecución del programa
                cout<<"Programa terminado correctamente. Gracias por jugar.";
                ciclo=false;
                
                
                break;
            }
            default:{
                cout<<"Instruccion desconocida. Vuelva a intentarlo"<<endl<<endl;
                
                
                break;
            }
            
            
            
            
            
            
        }
        
       
    }while(ciclo);
    
    
    
    
    
    return 0;
}



