#include <iostream>
#include <conio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	
	char palabra[]="";
	char palabra2[]="hola";
	cin>>palabra;
	if(strcmp(palabra2,palabra)==0){
		cout<<"si son";
	}
	
	
	getch();
	return 0;
}
