#include <iostream>
#include <cmath>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int tam=5, tamdeter,h=0,k=0,i,j,l,col,fil;
	float deter1[5][5],deter2[5][5],resul[5][5],prod[5][5],pos,determinante,hacer=1;
	
void nueva_matriz(){
	if(tamdeter>2){
		
			for(i=0;i<=tamdeter;i++){
				prod[tamdeter][i]=deter1[0][i]*pow(-1,((i+2)%2));
				cout<<"Prod: "<<prod[tamdeter][i]<<" "<<endl;
			
			}
			hacer++;
		
		
		
		for(l=0;l<=tamdeter;l++){
			h=0;
			k=0;
			cout<<"Resul\n";
			for(i=0;i<=tamdeter;i++){
				if(i!=0){
						
					for(j=0;j<=tamdeter;j++){
						if(j!=col){
							deter2[h][k]=deter1[i][j];
							//cout<<"Valor de deter2: "<<deter2[h][k]<<endl;
							resul[h][k]=resul[h][k]+deter2[h][k]*prod[tamdeter][l];
							
							cout<<resul[h][k]<<" ";//<<"\nProd: "<<prod[tamdeter][l]<<" ";//opcional
							//cout<<"Prod: "<<prod[tamdeter][l]<<endl;
							if(k==(tamdeter-1)){
								h++;
								k=0;	
									
							}
							else{
								k++;
							}
							
							
						}		
					}
					cout<<endl;//opcional
				}	
			}
		col++;	
		cout<<endl;
		}
		
		for(i=0;i<=tamdeter;i++){
			for(j=0;j<=tamdeter;j++){
				deter1[i][j]=resul[i][j];
				resul[i][j]=0;
				
			}
		}
		tamdeter--;
		col=0;
		nueva_matriz();
	}
	else{
			determinante=(resul[0][0]*resul[1][1]*resul[2][2])+(resul[1][0]*resul[2][1]*resul[0][2]) + (resul[2][0]*resul[0][1]*resul[1][2]) - ((resul[0][2]*resul[1][1]*deter2[2][0]) + (resul[1][2]*resul[2][1]*resul[0][0]) + (resul[2][2]*resul[0][1]*resul[1][0]));
			cout<<"Determintante: "<<determinante;
		
	}
	
		
	
}
void guardar(){
	for(i=0;i<=tamdeter;i++){
		for(j=0;j<=tamdeter;j++){
						//deter1[i][j]=rand()%10;	
			deter2[i][j]=deter1[i][j];
						
		}	
	}
	nueva_matriz();
}

void almacenar(){
	for(i=0;i<=tamdeter;i++){
		for(j=0;j<=tamdeter;j++){
			cin>>deter1[i][j];
		}
		
		
	}
	fil=0;
	col=0;
	guardar();	
}


	






int main(int argc, char** argv) {
	
	tamdeter=tam-1;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			resul[i][j]=0;
			
		}
	}
	almacenar();
	
	
	
	
	return 0;
}
