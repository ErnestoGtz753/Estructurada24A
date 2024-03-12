/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 11 de marzo de 2024
PROGRAMA: Matricesv4.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Almacena valores manual o aleatoriamente dentro de dos matrices cuadradas de
tamaño 2*2 hasta 15*15, que permite hacer una suma, resta o multiplicación entre ellas (la división no se pudo).
*/
//librerías de entrada y salida, y para usar números aleatorios
#include <iostream>
#include <cstdlib>

/* Inicializamos dos matrices de 10 * 10 ya que es la cantidad de espacios máxima que
	usará (según los requerimientos); una matriz que almacene los resultados de las
	operaciones; un tamaño de matriz; una variable que indica en cuál de las dos matrices
	se insertarán datos; tres contadores para los ciclos; una variable que nos servirá para
	almacenar los resultados en la matriz de resultado (abajo lo explico mejor);
	una variable para almacenar cada uno de los resultados de la multiplicación de matrices;
	una variable para almacenar valores en las matrices; una variable para almacenar valores
	aleatorios; otra variable (det) para saber cuántas matrices hemos llenado; 
	variable (inte) para que cerrar el switch y no continuar el programa (luego lo explico mejor);
	una variable para sumar los valores cuando la matriz se multiplica; y, por último, dos variables
	para indicar qué columna y fila se modificarán, respectivamente (abajo lo explico mejor).
	*/
	int mat1[15][15], mat2[15][15],resul[15][15],tam,eleg,i,j,k,h=0,val,ran,det=0,inte=1,sum=0,c,f;
	//Estas variables mantienen activos a los ciclos que validan datos hasta que sea un valor válido
	bool ciclo=true,todo=true;
	//variables para elegir las opciones en los swtich e if.
	char tipo,op,deci,term,mos;
	using namespace std;
	//una función de tipo void para simplificar el codigo de imprimir los valores de las matrices
	void imp1(){
		cout<<"Matriz n1:"<<endl<<"    ";
		for(i=0;i<tam;i++){
			cout<<"C"<<i+1<<" ";
		}
	
		cout<<endl;
		
		for(i=0;i<tam;i++){
			cout<<"F"<<i+1<<": ";
			for(j=0;j<tam;j++){
				cout<<mat1[i][j]<<" ";
			
			}
			cout<<endl;
		}
	}
	//Esta función es igual que la de la línea 34, pero con la matriz número dos
	void imp2(){
		cout<<"Matriz n2:"<<endl<<"    ";
		for(i=0;i<tam;i++){
			cout<<"C"<<i+1<<" ";
		}
	
		cout<<endl;
		
		for(i=0;i<tam;i++){
			cout<<"F"<<i+1<<": ";
			for(j=0;j<tam;j++){
				cout<<mat2[i][j]<<" ";
			
			}
			cout<<endl;
		}
	}
int main(int argc, char** argv) {
	//ciclo que valida un tamaño válido de matriz
	while(ciclo){
	
		cout<<"Que tamaño quiere que la matriz tenga? (2 - 15)"<<endl;
		cin>>tam;
		if(tam>15 || tam<2)
		cout<<"Tamano invalido, escoja de nuevo"<<endl;
		else ciclo=false;
	}
	/*un ciclo que repite todo el programa, preguntando si el usuario quiere modificar o mostrar los
	valores de la matriz*/
while(todo){
	cout<<"Desea mostrar los datos de la matriz(d) o modificarlos(m)?"<<endl;
	cin>>mos;
	if(mos=='m'){
	
	cout<<"Quiere introducir los valores manualmente dentro de la matriz (m) o que se llene aleatoriamente (a)"<<endl;
	cin>>tipo;
	//switch que pregunta como se almacenarán los valores de la matriz
	switch(tipo){
		case 'm':{
			
			ciclo=true;
			while(ciclo){
				cout<<"En cual de las dos matrices desea introducir datos? (1 o 2)"<<endl;
				cin>>eleg;
				if(eleg > 2 || eleg <1){
					cout<<"Matriz invalida, escoja de nuevo"<<endl;
				
				}
				else ciclo=false;
			}
			
			
			while(det!=2){
			
			//introduce manualmente valores a la matriz
			if(eleg==1){
				eleg=2;
				det++;
				for(i=0;i<tam;i++){
					for(j=0;j<tam;j++){
						cout<<endl<<"C"<<j+1<<": "<<endl;
						cout<<"F"<<i+1<<": ";
						cin>>val;
						
						mat1[i][j]=val;
					
					}
				}
			}
			else{
				//una vez que se llenó una matriz, se requerirá llenar la otra
				det++;
				eleg=1;
				for(i=0;i<tam;i++){
					for(j=0;j<tam;j++){
						cout<<endl<<"C"<<j+1<<": "<<endl;
						cout<<"F"<<i+1<<": ";
						cin>>val;
						
						mat2[i][j]=val;
					
					}
				}
			}
			cout<<"Ahora falta que le de valores a la matriz numero "<<eleg<<endl;
			}
			
			break;
		}
		case 'a':{
			
		//llena la matriz con números aleatorios
			for(i=0;i<tam;i++){
			
				for(j=0;j<tam;j++){
					ran=-200+rand()%(600);
					mat1[i][j]=ran;
				}
			}

			for(i=0;i<tam;i++){
				for(j=0;j<tam;j++){
					ran=-200+rand()%(600);
					mat2[i][j]=ran;
			
				}
		
			}
		
			
		
		
			break;
		}
		//si no escoge una opción válida, se reinicia la opción.
		default:{
			cout<<"Opcion invalida, reinicie el programa para volver a intentarlo";
			inte=0;
			break;
		}
	}
	
	if(inte!=0){
	
		imp1();
		imp2();
		//pregunta al usuario si desea realizar una operación o modificar los valores de las matrices
		cout<<"Que desea hacer? Una operacion (o) o una modificacion (m)"<<endl;
		cin>>deci;
		
		if(deci=='o'){
			cout<<"Que operaciones desea realizar en las dos matrices? Multiplicacion(m), suma(s) o resta(r)"<<endl;
			cin>>op;
			switch(op){
				//operación de multiplicación
				case 'm':{
					
					cout<<endl;
				
					for(i=0;i<tam;i++){
						for(j=0;j<tam;j++){
							for(k=0;k<tam;k++){
						
						sum+=(mat1[i][k])*(mat2[k][j]);
		
							}
						resul[i][h]=sum;
						if(h<tam-1)h++;
						else h=0;
						sum=0;
						}	
					}
						
					for(i=0;i<tam;i++){
						cout<<"C"<<i+1<<" ";
						}
						cout<<endl;
						for(i=0;i<tam;i++){
							cout<<"F"<<i+1<<": ";
							for(j=0;j<tam;j++){
								cout<<resul[i][j]<<" ";
						
							}
							cout<<endl;
						}
						cout<<endl;
					
					break;
					}
					//operación de suma
				case 's':{
					for(i=0;i<tam;i++){
						cout<<"C"<<i+1<<" ";
					}
					cout<<endl;
					for(i=0;i<tam;i++){
						cout<<"F"<<i+1<<": ";
						for(j=0;j<tam;j++){
							resul[i][j]=(mat1[i][j])+(mat2[i][j]);
							cout<<resul[i][j]<<" ";
						
						
						}
						cout<<endl;
					}
					break;
				}	
			//operación de resta
				case 'r':{
					for(i=0;i<tam;i++){
						cout<<"C"<<i+1<<" ";
					}
					cout<<endl;
					for(i=0;i<tam;i++){
						cout<<"F"<<i+1<<": ";
						for(j=0;j<tam;j++){
							resul[i][j]=(mat1[i][j])-(mat2[i][j]);
							cout<<resul[i][j]<<" ";
							
						
						}
						cout<<endl;
					}
					break;
				}	
				default:{
					cout<<"Operacion desconocida. Reinicie el programa para intentarlo otra vez";
					break;
				}		
			}
		}
		//Si se desea modificar un elemento, entoces pregunta en qué posición
		else if(deci=='m'){
			
			cout<<"Que desea hacer? Modificar un elemento (m) o eliminar todos los elementos de una matriz(e)"<<endl;
			cin>>deci;
			
			switch(deci){
				//modificar un elemento en específico, dependiendo de la matriz
				case 'm':{
					cout<<"Cual matriz quiere modificar? (1 o 2)"<<endl;
					cin>>eleg;
					if(eleg==1){
						imp1();
						cout<<endl<<"Cual posicion desea modificar?"<<endl<<"Inserte columna "<<endl<<"C";
						cin>>c;
						cout<<"Inserte fila"<<endl<<"F";
						cin>>f;
						
						if(f>=1 && f<=tam && c>=1 && c<=tam){
						cout<<"Inserte un nuevo valor"<<endl;
						cin>>val;
						mat1[f][c]=val;
						cout<<"Valor modificado correctamente"<<endl;
						}
						else cout<<"Posicion invalida?"<<endl;
					}
					
					else if(eleg==2){
						imp2();
						cout<<endl<<"Cual posicion desea modificar?"<<endl<<"Inserte columna "<<endl<<"C";
						cin>>c;
						cout<<"Inserte fila"<<endl<<"F";
						cin>>f;
						if(f>=1 && f<=tam && c>=1 && c<=tam){
						cout<<"Inserte un nuevo valor"<<endl;
						cin>>val;
						mat2[f][c]=val;
						cout<<"Valor modificado correctamente"<<endl;
						}
						else cout<<"Posicion invalida?"<<endl;
					}
					else cout<<"Matriz invalida"<<endl;
				
					break;
				}
				//elimina todos los valores de una matriz
				case 'e':{
					cout<<"A cual matriz desea borrarle todos sus elementos? (1 o 2)"<<endl;
					cin>>eleg;
					if(eleg==1){
						for(i=0;i<tam;i++){
							for(j=0;j<tam;j++){
								mat1[i][j]=0;
							}
						}
						cout<<"Matriz vaciada correctamente"<<endl;
					}
					else if(eleg==2){
						for(i=0;i<tam;i++){
							for(j=0;j<tam;j++){
								mat2[i][j]=0;
							}
						}
						cout<<"Matriz vaciada correctamente"<<endl;
					}
					else cout<<"Matriz invalida"<<endl;
					
					
					break;
				}
				default:{cout<<"Comando invalido"<<endl;
					break;
				}
				
			
			}
		}
		else cout<<"Comando desconocido"<<endl;
	}
}
else{
	//en caso que desde el inicio (línea 78) el usuario no quiere modificar los datos, se mostrarán
	imp1();
	imp2();
}
	//si el usuario quiere terminar el programa, escribirá una (t), sino, cualquier carácter (como una c)
	cout<<"Quiere terminar el programa aqui (t) o continuar(c)?"<<endl;
	cin>>term;
	if(term=='t')todo=false;
	
}
	return 0;
}
