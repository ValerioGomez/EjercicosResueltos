#include <iostream>
#include <string.h>
#include<locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int n,r;
	setlocale(LC_CTYPE,"Spanish");
	cout<<"�Cu�ntos Cuadrados Diferentes hay en una Cuadr�cula de NxN?\nIngrese N: ";
	do{
	cin>>n;
	
	r=n*(n+1)*(2*n+1)/6;
	if(n!=0){
	cout<<"Para una Cuadr�cula de "<<n<<"x"<<n<<" existen "<<r<<" Cuadrados."<<endl;
	}
	}while(n!=0);
	return 0;
}
