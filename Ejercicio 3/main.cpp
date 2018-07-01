#include <iostream>
#include <conio.h>
#include <string.h>
#include<locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	struct persona{
	char nombre[20];
	int dia;
	int mes;
	int anio;
	double tamano;
	}personas[8];
	
	void PedirDatos();
	void buscar();
	
using namespace std;
int main() {
		setlocale(LC_CTYPE,"Spanish");
		cout<<"Ingrese datos de 8 personas\n";
		PedirDatos();
		cout<<" *********** Fin de Datos *********** \n";
		buscar();
	getch();
	return 0;
}

void PedirDatos(){
		for(int i=0;i<8;i++){
		fflush(stdin);
		cout<<" Datos de la Persona "<<i+1<<endl;
		cout<<"	Nombre : ";
		cin.getline(personas[i].nombre,20,'\n');
		cout<<"	Día : ";
		cin>>personas[i].dia;
		cout<<"	Mes : ";
		cin>>personas[i].mes;
		cout<<"	Año : ";
		cin>>personas[i].anio;
		cout<<endl;
	}
}

void buscar(){
	int buscarmes,encontrado;
	do{
	cout<<"Ingrese un número de mes: ";
	cin>>buscarmes;
	
	for(int j=0;j<8;j++){
		if(personas[j].mes==buscarmes){
			encontrado=1;
			cout<<"_______________________________________"<<endl;
			cout<<"\nPersona Nro "<<j+1<<endl;
			cout<<"Nombre : "<<personas[j].nombre<<endl;
			cout<<"Fecha de Cumpleaños: "<<personas[j].dia<<"/"<<personas[j].mes<<"/"<<personas[j].anio<<endl;
		}
	}if(encontrado==0){
		cout<<"No hay Cumpleañeros"<<endl;
	}
	}while(buscarmes!=0);
	
}
