#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int i,j,k,l,tam=5,tamdeter=tam-1,iter=0,col=0,x=0,y=0;
float deter1[5][5][5][5],resul[5][5][5][5];

void nueva_matriz(){
	if(iter<(tam-3)){
	//	for(n=0;n<=tamdeter;n++){
			//for(m=0;m<=tamdeter;m++){//almacena todos los cofactores de todas las matrices
				
				for(l=0;l<=tamdeter;l++){
					for(k=0;k<tamdeter;k++){//almacena todos los cofactores de una sola matriz
						x=0;
						y=0;
						cout<<"Resul: "<<endl;
						for(i=1;i<=tamdeter;i++){ //estos dos for almacenan un cofactor de una matriz
							for(j=0;j<=tamdeter;j++){
								if(j!=k){//si j es distinto a la columna del cofactor, entonces se almacena la nueva matriz
									resul[l+1][k][x][y]=deter1[l][k][i][j];
									cout<<resul[l+1][k][x][y]<<" ";
									if(y==(tamdeter-1)){
										y=0;
										x++;
										
									}
									else{
										y++;
										
									}
									
									
								}
							}
						}
						
					}
				
					for(k=0;k<tamdeter;k++){
						for(i=0;i<tamdeter;i++){
							for(j=0;j<tamdeter;j++){
								deter1[l][k][i][j]=resul[l+1][k][i][j];	
								
								
							}
							
							
						}
						
					}	
							
					
					
				}
				
				
		//	}
			
		//}
			
		
		
		
		
		
		iter++;
		
	}
	
	
	
	
	
	
	
}








void alm(){
	
	for(i=0;i<=tamdeter;i++){
		for(j=0;j<=tamdeter;j++){

			cin>>deter1[0][0][i][j];
		
		}
	}
	
	
	
	
}





int main(int argc, char** argv) {
	alm();
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
