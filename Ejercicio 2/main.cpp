#include <iostream>
#include <conio.h>
#include<locale.h>
#include<string.h>


struct imagen{
	char nombre[20];
	int ancho;
	int alto;
	double tamano;
}imagenes[100];

 
void PedirDatos();
void menu();
void buscar();
void MostrarDatos(imagen);

int incremento(int x){
	return x++;
	
}

using namespace std;
int main() {
	setlocale(LC_CTYPE,"Spanish");
	cout<<"Guardar Datos de Imagenes por Estrucura";
	cout<<"\n------- Guardar Datos-------\n"<<endl;
	menu();
	
	getch();	
	return 0;
}


void PedirDatos(int y){
	cout<<"\n**************************************************\n";
	for(int i=0;i<100;i++){
		fflush(stdin);//vaciar el buffer xq se llenaria de basura en la primera iteracion
		cout<<" Datos de la Imagen "<<y+1<<endl;
		cout<<"	Nombre : ";
		cin.getline(imagenes[y].nombre,20,'\n');
		cout<<"	Ancho (en píxeles) : ";
		cin>>imagenes[y].ancho;
		cout<<"	Alto (en píxeles) : ";
		cin>>imagenes[y].alto;
		cout<<"	Tamaño : ";
		cin>>imagenes[y].tamano;
		cout<<endl;
		break;
		if(i==99){
			cout<<"Se Termino el Espacio";
		}
	}
}

void MostrarTodo(int y){
	cout<<"\n**************************************************\n";
	for(int j=0;j<=y;j++){
		cout<<"\n_________________________________\n";
		cout<<"Imagen "<<j+1<<endl;
		cout<<"Nombre	: "<<imagenes[j].nombre<<".JPG"<<endl;
		cout<<"Alto	: "<<imagenes[j].alto<<" píxeles"<<endl;
		cout<<"Ancho	: "<<imagenes[j].ancho<<" píxeles"<<endl;
		cout<<"Tamaño	: "<<imagenes[j].tamano<<" Kb"<<endl;
	}
}
void Buscar(){
	char img[20]="";
	
	int encontrado;
	cout<<"\nIngresa Imagen a Buscar: ";
	cin>>img;
	
	for(int k=0;k<100;k++){
		if(strcmp(imagenes[k].nombre,img)==0){
			encontrado=1;
			cout<<"_______________________________________"<<endl;
			cout<<"\nImagen Encontrada\n"<<"Imagen Nro. "<<k+1<<endl;
			cout<<"Nombre : "<<imagenes[k].nombre<<".jpg"<<endl;
			cout<<"Alto : "<<imagenes[k].alto<<" píxeles"<<endl;
			cout<<"Ancho : "<<imagenes[k].ancho<<" píxeles"<<endl;
			cout<<"Tamaño : "<<imagenes[k].tamano<<" Kb"<<endl;
		}
	}if(encontrado==0){
		cout<<"No hay coincidencias"<<endl;
	}
	
}
void salir(){
	cout<<"******** Programa Finalizado *********"<<endl;
}
void menu(){
	int opcion,in=0;
	do{
	cout<<"\n**************************************************\n";
	cout<< "	MENU DE OPCIONES\n";
	cout<<"1.- Añadir Nueva Imagen\n";
	cout<<"2.- Ver Todas las Imagenes\n";
	cout<<"3.- Buscar Imagen\n";
	cout<<"4.- Salir\n";
	cout<<"Selecciona Una Opcion: "; 
	cin>>opcion; int y;
	switch(opcion){
		case 1: y=in;
		PedirDatos(y);
		in++;
		break;
		
		case 2: MostrarTodo(y);
		break;
		
		case 3: Buscar();
		break;
		
		case 4: salir();
		break;
		default:
		cout<<"Opcion Incorrecta\n";	
		}
	}while(opcion!=4);	
}
