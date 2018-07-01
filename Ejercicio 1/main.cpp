#include <iostream>
#include <conio.h>
#include<locale.h>

struct cancion 
{
	char titulo[20];
	char artista[20];
	int duracion;
	int tamano;
}cancion1;
 
using namespace std;
int main() {
	setlocale(LC_CTYPE,"Spanish");

	cout<<"\n------- Ingrese Datos de la Canción -------\n"<<endl;
	cout<<"Titulo: ";
	cin.getline(cancion1.titulo,20,'\n');
	cout<<"Artista: ";
	cin.getline(cancion1.artista,20,'\n');
	cout<<"Duración (en Segundos): ";
	cin>>cancion1.duracion;
	cout<<"Tamaño (en Kb): ";
	cin>>cancion1.tamano;
	
	cout<<"\n       Datos de la Cancion \n"<<endl;
	cout<<cancion1.artista<<" - "<<cancion1.titulo<<".mp3\n"<<endl;
	cout<<"Nombre 		:  "<<cancion1.titulo<<endl;
	cout<<"Artista		:  "<<cancion1.artista<<endl;
	cout<<"Duracion	:  "<<cancion1.duracion<<" segundos"<<endl;
	cout<<"Tamaño 		:  "<<cancion1.tamano<<" Kb\n";
	
	getch();	
	return 0;
}
