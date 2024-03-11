#include <iostream>
#include <cmath>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int tam=5, tamdeter,iter=0,h=0,k=0,i,j,l,col,fil,z=0,m;
	float deter1[5][5][5][5],deter2[5][5],resul[5][5][5][5],prod[5][5][5],pos,determinante;
	
void nueva_matriz(){
	if(iter<(tam-3)){
		
		for(m=0;m<=tamdeter;m++){
			
			for(l=0;l<=tamdeter;l++){
				for(i=0;i<=tamdeter;i++){
					prod[z][tamdeter][i]=resul[z][0][0][i]*pow(-1,((i+2)%2));
					cout<<"Prod: "<<prod[z][tamdeter][i]<<" "<<endl;
			
				}
				h=0;
				k=0;
				//z=0;
				
				cout<<"Resul\n";
				for(i=1;i<=tamdeter;i++){	
						for(j=0;j<=tamdeter;j++){
							if(j!=col){
							//	deter2[h][k]=deter1[i][j];
								//cout<<"Valor de deter2: "<<deter2[h][k]<<endl;
								resul[z][h][k]=deter1[m][i][j]*prod[z][tamdeter][l];
								cout<<"Prod: "<<prod[z][tamdeter][l]<<endl;
								//cout<<resul[z][h][k]<<" ";//<<"\nProd: "<<prod[tamdeter][l]<<" ";//opcional
								
								if(k==(tamdeter-1)){
									k=0;
									h++;		
								}
								else{
									k++;
								}
								
								
							}		
						}
						cout<<endl;//opcional
						
				}
				col++;	
				cout<<endl;
				z++;
			}
				
			col=0;	
			for(i=0;i<=tamdeter;i++){
				for(j=0;j<=tamdeter;j++){
					deter1[z][i][j]=resul[z-1][i][j];
					//resul[i][j]=0;
					
				}
			}
		}
		
		
		
		tamdeter--;
		iter++;
		
		nueva_matriz();
	}
	/*else{
			determinante=(resul[0][0]*resul[1][1]*resul[2][2])+(resul[1][0]*resul[2][1]*resul[0][2]) + (resul[2][0]*resul[0][1]*resul[1][2]) - ((resul[0][2]*resul[1][1]*deter2[2][0]) + (resul[1][2]*resul[2][1]*resul[0][0]) + (resul[2][2]*resul[0][1]*resul[1][0]));
			cout<<"Determintante: "<<determinante;
		
	}*/
	
		
	//z++;	
}
void guardar(){
	for(i=0;i<=tamdeter;i++){
		for(j=0;j<=tamdeter;j++){
						//deter1[i][j]=rand()%10;	
			resul[i][j]=deter1[i][j];
						
		}	
	}
	nueva_matriz();
}

void almacenar(){
	for(i=0;i<=tamdeter;i++){
		for(j=0;j<=tamdeter;j++){
			cin>>deter1[0][i][j];
		}
		
		
	}
	fil=0;
	col=0;
	//guardar();	
	nueva_matriz();
}


	






int main(int argc, char** argv) {
	
	tamdeter=tam-1;
	for(i=0;i<(tamdeter*tamdeter);i++){
		for(j=0;j<tamdeter;j++){
			for(k=0;k<=tamdeter;k++){
				resul[i][j][k]=0;	
				
			}
			
			
		}
	}
	almacenar();
	
	
	
	
	return 0;
}
