#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


//arreglo usado para imprimir carretera
char calle[20][20];
char carro[20][20];
bool verificar[12];
//funciones usadas para el progragama
void asignar_carretera();
void imprimir_carretera();
void eventos_teclas();
void posicion_carrito(string);
void generar_carritos(int);
void limpiar_carrito(int);
void definir_puntaje();
void clearscreen();
void arreglo_nivel();
void manejar_velocidad();
//variables locales
string posicion = "derecha";
bool comenzar = false;
bool manejar = true;
int contador= 0;
int numero = 0;
int velocidad = 100;
int vidas = 0;
int puntos = 0;
int carritos_esquivados = 0;
int nivel = 0;
int puntuacion_actual = 0;
int contador_puntuacion = 0;
//arreglo de puntaciones
int puntuaciones[10];

void main(){
	int opcion = 0;
	asignar_carretera();
	posicion_carrito(posicion);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	
	clearscreen();
	do{
		//menu de opciones
		cout << "****Menu de opciones****" << endl;
		cout << "1. Jugar. " << endl;
		cout << "2. Tabla de puntuacion. " << endl;
		cout << "3. Salir. " << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			void arreglo_nivel();
			while (true){
				if (!comenzar){
					clearscreen();
					cout << "****Reglas del juego****" << endl;
					cout << "1. No chocar con los carros." << endl;
					cout << "2. Tiene incialmente 3 vidas, al agotarse las vidas se acaba el juego." << endl;
					cout << "3. La velocidad de los carros ira aumentando conforme pasa el tiempo!" << endl;
					cout << endl;
					cout << "PRESIONE SPACE PARA COMENZAR" << endl;
					//system("cls");
					
					if (GetAsyncKeyState(VK_SPACE)){
						comenzar = true;
						vidas = 3;
						puntos = 0;
						carritos_esquivados = 0;
						nivel = 0;
						puntuacion_actual = 0;
						system("cls");
					}
				}
				else{
						
						definir_puntaje();
						if (manejar==false){
							manejar_velocidad();
							manejar = true;
						}
						eventos_teclas();
						limpiar_carrito(numero);
						imprimir_carretera();
						generar_carritos(numero);
						cout << "Vidas: " << vidas << endl;
						cout << "Velocidad: " << velocidad << endl;
						cout << "Puntuacion : " << puntuacion_actual << endl;
						cout << "Nivel: " << nivel << endl;
						cout << endl;
						cout << "PRESIONE ESCAPE PARA PAUSAR EL JUEGO" << endl;
						cout << "PRESIONE TAB PARA DEJAR DE JUGAR" << endl;
						puntuaciones[contador_puntuacion] = puntuacion_actual;
						clearscreen();

						if (GetAsyncKeyState(VK_ESCAPE)){
							system("pause");
							system("cls");
						}
						if (GetAsyncKeyState(VK_TAB)){
							system("cls");
							contador_puntuacion++;
							comenzar = false;
							break;
						}
						Sleep(velocidad);
						
					
				}
			}
			break;
		case 2:
			cout << "Ultimas 10 puntuaciones: " << endl;
			for (int i = 0; i < 10; i++)
			{
					cout << "Puntuacion #" << (i + 1) << ": " << puntuaciones[i] << endl;
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 3:

			break;
		default:
			break;
		}
	} while (opcion!=3);
	//system("pause");
	
}

void asignar_carretera(){
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j>3 && j<16)
				calle[i][j] = ' ';
			else
				calle[i][j] = '|';
		}
	}
}

void posicion_carrito(string direccion){

	if (direccion == "derecha"){
		if (posicion == "derecha"){

		}
		else if (posicion == "centro"){
			calle[16][8] = ' ';
			calle[16][11] = ' ';
			calle[17][9] = ' ';
			calle[17][10] = ' ';
			calle[18][9] = ' ';
			calle[18][10] = ' ';
			calle[19][8] = ' ';
			calle[19][11] = ' ';

			calle[16][15] = '@';
			calle[16][12] = '@';
			calle[17][13] = '@';
			calle[17][14] = '@';
			calle[18][13] = '@';
			calle[18][14] = '@';
			calle[19][12] = '@';
			calle[19][15] = '@';
			posicion = "derecha";
		}
		else if (posicion == "izquierda"){
			calle[16][4] = ' ';
			calle[16][7] = ' ';
			calle[17][5] = ' ';
			calle[17][6] = ' ';
			calle[18][5] = ' ';
			calle[18][6] = ' ';
			calle[19][4] = ' ';
			calle[19][7] = ' ';


			calle[16][8] = '@';
			calle[16][11] = '@';
			calle[17][9] = '@';
			calle[17][10] = '@';
			calle[18][9] = '@';
			calle[18][10] = '@';
			calle[19][8] = '@';
			calle[19][11] = '@';
			posicion = "centro";
		}

	}
	else if (direccion == "izquierda"){
		if (posicion == "derecha"){
			calle[16][15] = ' ';
			calle[16][12] = ' ';
			calle[16][12] = ' ';
			calle[17][13] = ' ';
			calle[17][14] = ' ';
			calle[18][13] = ' ';
			calle[18][14] = ' ';
			calle[19][12] = ' ';
			calle[19][15] = ' ';

			calle[16][8] = '@';
			calle[16][11] = '@';
			calle[17][9] = '@';
			calle[17][10] = '@';
			calle[18][9] = '@';
			calle[18][10] = '@';
			calle[19][8] = '@';
			calle[19][11] = '@';
			posicion = "centro";
		}
		else if (posicion == "centro"){
			calle[16][8] = ' ';
			calle[16][11] = ' ';
			calle[17][9] = ' ';
			calle[17][10] = ' ';
			calle[18][9] = ' ';
			calle[18][10] = ' ';
			calle[19][8] = ' ';
			calle[19][11] = ' ';


			calle[16][4] = '@';
			calle[16][7] = '@';
			calle[17][5] = '@';
			calle[17][6] = '@';
			calle[18][5] = '@';
			calle[18][6] = '@';
			calle[19][4] = '@';
			calle[19][7] = '@';
			posicion = "izquierda";
		}
		else if (posicion == "izquierda"){

		}
	}
}

void generar_carritos(int carril){
	if (carril == 3 && contador <= 22){
		calle[contador][12] = '@';
		calle[contador][15] = '@';
		calle[contador + 1][13] = '@';
		calle[contador + 1][14] = '@';
		calle[contador + 2][13] = '@';
		calle[contador + 2][14] = '@';
		calle[contador + 3][12] = '@';
		calle[contador + 3][15] = '@';
		contador++;
	}
	else if (carril == 2 && contador <= 22){
		calle[contador][8] = '@';
		calle[contador][11] = '@';
		calle[contador + 1][9] = '@';
		calle[contador + 1][10] = '@';
		calle[contador + 2][9] = '@';
		calle[contador + 2][10] = '@';
		calle[contador + 3][8] = '@';
		calle[contador + 3][11] = '@';
		contador++;
	}
	else if (carril == 1 && contador <= 22){
		calle[contador][4] = '@';
		calle[contador][7] = '@';
		calle[contador + 1][5] = '@';
		calle[contador + 1][6] = '@';
		calle[contador + 2][5] = '@';
		calle[contador + 2][6] = '@';
		calle[contador + 3][4] = '@';
		calle[contador + 3][7] = '@';
		contador++;
	}
	else{
		if (numero < 3){
			numero++;
		}
		else{
			numero = 0;
		}
		nivel++;
		carritos_esquivados++;
		puntuacion_actual = puntuacion_actual + puntos;
		contador = 0;
	}

}

void definir_puntaje(){
	if (carritos_esquivados <= 10){
		puntos = 20;
		if (nivel == 10 && contador==0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 10 && carritos_esquivados <= 20){
		puntos = 40;
		if (nivel == 20 && contador == 0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 20 && carritos_esquivados <= 30){
		puntos = 60;
		if (nivel == 30 && contador == 0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 30 && carritos_esquivados <= 40){
		puntos = 80;
		if (nivel == 40 && contador == 0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 50 && carritos_esquivados <= 60){
		puntos = 100;
		if (nivel == 50 && contador == 0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 80 && carritos_esquivados <= 90){
		puntos = 130;
		if (nivel == 60 && contador == 0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 90 && carritos_esquivados <= 100){
		puntos = 170;
		if (nivel == 70 && contador == 0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 100 && carritos_esquivados <= 110){
		puntos = 220;
		if (nivel == 80 && contador == 0){
			manejar = false;
		}
	}
	else if (carritos_esquivados > 110 && nivel <= 120){
		puntos = 280;
		if (nivel == 90 && contador == 0){
			manejar = false;
		}
	}
}

void manejar_velocidad(){
	if (nivel == 10){
		velocidad = velocidad - 10;
	}
	else if (nivel == 20){
		velocidad = velocidad - 10;
	}
	else if (nivel == 30){
		velocidad = velocidad - 10;
	}
	else if (nivel == 40){
		velocidad = velocidad - 10;
	}
	else if (nivel == 50){
		velocidad = velocidad - 10;
	}
	else if (nivel == 60){
		velocidad = velocidad - 10;
	}
	else if (nivel == 80){
		velocidad = velocidad - 10;
	}
	else if (nivel == 90){
		velocidad = velocidad - 10;
	}
}


void limpiar_carrito(int carril){
	if (carril == 3){
		calle[contador][12] = ' ';
		calle[contador][15] = ' ';
		calle[contador - 1][13] = ' ';
		calle[contador - 1][14] = ' ';
		calle[contador - 2][13] = ' ';
		calle[contador - 2][14] = ' ';
		calle[contador - 3][12] = ' ';
		calle[contador - 3][15] = ' ';
	}
	else if (carril == 2){
		calle[contador][8] = ' ';
		calle[contador][11] = ' ';
		calle[contador - 1][9] = ' ';
		calle[contador - 1][10] = ' ';
		calle[contador - 2][9] = ' ';
		calle[contador - 2][10] = ' ';
		calle[contador - 3][8] = ' ';
		calle[contador - 3][11] = ' ';
	}
	else if (carril = 1){
		calle[contador][4] = ' ';
		calle[contador][7] = ' ';
		calle[contador - 1][5] = ' ';
		calle[contador - 1][6] = ' ';
		calle[contador - 2][5] = ' ';
		calle[contador - 2][6] = ' ';
		calle[contador - 3][4] = ' ';
		calle[contador - 3][7] = ' ';
	}
}

void imprimir_carretera(){
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			cout << calle[i][j];
		}
		cout << endl;
	}
}

void eventos_teclas(){
	if (GetAsyncKeyState(VK_UP)){
		velocidad = 0;
		//system("cls");
	}
	else if (GetAsyncKeyState(VK_DOWN)){
		velocidad = 100;
		//system("cls");
	}
	else if (GetAsyncKeyState(VK_RIGHT)){
		posicion_carrito("derecha");
		//system("cls");
	}
	else if (GetAsyncKeyState(VK_LEFT)){
		//cout << "izquierda";
		posicion_carrito("izquierda");
		//system("pause");
	}
}

void verificar_choque(){

}

void arreglo_nivel(){
	for (int i = 0; i < 10; i++)
	{
		verificar[i] = true;
	}
}

void clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
