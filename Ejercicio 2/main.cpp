#include <iostream>
#include <conio.h>
#include<locale.h>

struct imagen 
{
	char nombre[20];
	int ancho;
	int alto;
	double tamano;
}imagenes[2];
 
using namespace std;
int main() {
	setlocale(LC_CTYPE,"Spanish");

	cout<<"\n------- Guardar Datos de Imágenes -------\n"<<endl;
	for(int i=0;i<2;i++){
		cout<<" Datos de la Imagen ";
		cout<<"	Nombre : ";
		cin.getline(imagenes[i].nombre,20,'\n');
		cout<<"	Ancho (en píxeles) : ";
		cin>>imagenes[i].ancho;
		cout<<"	Alto (en píxeles) : ";
		cin>>imagenes[i].alto;
		cout<<"	Tamaño : ";
		cin>>imagenes[i].tamano;
		
	}
	
	getch();	
	return 0;
}
