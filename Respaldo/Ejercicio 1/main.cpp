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
	int minutos=0,segundos=0;
	setlocale(LC_CTYPE,"Spanish");

	cout<<"\n------- Ingrese Datos de la Canción -------\n"<<endl;
	cout<<"Título: ";
	cin.getline(cancion1.titulo,20,'\n');
	cout<<"Artista: ";
	cin.getline(cancion1.artista,20,'\n');
	cout<<"Duración (en Segundos): ";
	cin>>cancion1.duracion;
	cout<<"Tamaño (en Kb): ";
	cin>>cancion1.tamano;
	
	cout<<"\n       Datos de la Canción \n"<<endl;
	cout<<cancion1.artista<<" - "<<cancion1.titulo<<".mp3\n"<<endl;
	cout<<"Nombre 		:  "<<cancion1.titulo<<endl;
	cout<<"Artista		:  "<<cancion1.artista<<endl;
		segundos=segundos+cancion1.duracion;
		for(int i=0;i<10;i++){
			if(segundos>=60){
				segundos-=60;
				minutos++;
			}
		}
	cout<<"Duración	:  "<<minutos<<" Minutos "<<segundos<<" segundos"<<endl;
	cout<<"Tamaño 		:  "<<cancion1.tamano<<" Kb\n";
	
	getch();	
	return 0;
}
