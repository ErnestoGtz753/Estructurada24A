/*
NOMBRE: Ernesto Gutiérrez García
FECHA: 9 de abril de 2024
PROGRAMA: Cadenas_y_modificaciones.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: El programa pide una cadena de caracteres para informar al usuario si la frase es un palíndromo, 
cuántas vocales, consonantes y espacios tiene; además, imprime la frase en letras mayúsculas, minúsculas y 
concatena una frase nueva que se le vuelve a solicitar al usuario.
*/



#include <iostream>

using namespace std;
    /*
    Las variables tipo string están para guardar cadenas de caracteres y trabajar con ellas
    La variable tipo char es para imprimir ciertos caracteres de la cadena, pero en forma de carácter y no de número (luego especifico más)
    las variables tipo entero son para contar y para indicar cuántos caracteres son vocales, consonantes y espacios.
    La última cuenta cuántos caracteres de una cadena coinciden en posición con los caracteres de la misma cadena, pero leída al revés (para ver si es un palíndromo
    La última variable indica si la cadena es un palíndromo)
    */
    string tex,texmod;
    char car;
    int i,j=0,voc=0,cons=0,esp=0,pal=0;
    bool palindromo;
    //funciones que usaremos y que están escritas al final del documento
void palin();
void mayus();
void minusc();

int main(){
    
    cout<<"Escriba una cadena de caracteres"<<endl;
    //getlinea almacena todos los caracteres de una línea, incluyendo los espacios (algo cin por sí solo no hace)
    getline(cin,tex);
    //cuenta las vocales, consonantes y espacios
    for(i=0;i<tex.size();i++){
        if(tex[i]=='a'||tex[i]=='e'||tex[i]=='i'||tex[i]=='o'||tex[i]=='u')voc++;
        else
            if(tex[i]==' '){
                esp++;
            }
            else 
                if((tex[i]>=97&&tex[i]<=122)||(tex[i]>=65&&tex[i]<=90)||(tex[i]>=164&&tex[i]<=165)){
                    cons++;
                }
                
    }
    
    cout<<"Cantidad de vocales: "<<voc<<endl;
    cout<<"Cantidad de espacios: "<<esp<<endl;
    cout<<"Cantidad de consonantes: "<<cons<<endl;
    
    palin();//entra a la función palíndromo que cuenta la cantidad de caracteres que coinciden sin se lee la cadena de izquierda a derecha y viceversa
    if(palindromo==true){//si es palíndromo, se indica que lo es
        cout<<endl<<"Es palindromo"<<endl;
        
    }
    else cout<<endl<<"NO es palindromo"<<endl;
    mayus();
    minusc();
    cout<<"Escriba una frase para concatenarla con la anterior"<<endl;
    getline(cin,texmod);
    cout<<tex<<" "<<texmod;

    return 0;
}

void palin(){//función palíndromo
    
    for(i=0;i<tex.size();i++){
        if(tex[i]!=' '){
            texmod[j]=tex[i];
            j++;
        }
    }
    for(i=0;i<j;i++){
        if(texmod[i]==texmod[texmod.size()-i-1]){
            pal++;
            
        }
        
        
    }
    if(pal==texmod.size()) palindromo=true;
    else palindromo = false;
}
void mayus(){//función mayúscula
/*Si algún caracter es una letra minúscula, la imprime como mayúscula, sino, solo la imprime
*/
    cout<<"Frase en mayusculas: ";
    for(i=0;i<tex.size();i++){
        if(tex[i]>=97 && tex[i]<=122){
            car=tex[i]-32;
            cout<<car;
            
        }
        else if(tex[i]==164)cout<<"Ñ";
        else cout<<tex[i];
        
    }
    cout<<endl;
    
}

void minusc(){//función minúscula
//el razonamiento de su funcionamiento es igual que el de la función anterior
    cout<<"Frase en minusculas: ";
    for(i=0;i<tex.size();i++){
        if(tex[i]>=65 && tex[i]<=90){
            car=tex[i]+32;
            cout<<car;
            
        }
        else if(tex[i]==165)cout<<"ñ";
        else cout<<tex[i];
        
        
        
    }
    cout<<endl;
    
}