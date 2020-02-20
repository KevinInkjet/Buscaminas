/*  Tarea #1 - Buscaminas
	Compilador utilizado: Dev-c++
	Kevin Samuel C?rdenas Mu?oz
	cardenas.kevin@uabc.edu.mx
	Prueba
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int n, tablero[25][25], fila, columna, i, azar1, azar2, x=0, y=0, count=0;
	char vista[25][25], cuadrado = 254;
	bool valid = false, mensaje = false, win = false;
	srand(time(NULL));
	do
	{
		cout << "Dame el orden de la matriz del 2 al 25: " << endl;
		cin >> n;
		if(n >= 2 && n <= 25)
		{
			valid = true;
		}
	}while(valid == false);
	valid = false;
	//PONER CEROS EN TODA LA MATRIZ
	for(fila=0; fila<n; fila++)
	{
		for(columna=0; columna<n; columna++)
		{
			tablero[fila][columna] = 0;	
			vista[fila][columna] = 00;
		}
	}
	//PONER BOMBAS
	
	for(i=0; i<n; i++)
	{
		azar1 = rand()%n;
		azar2 = rand()%n;
		if(tablero[azar1][azar2] != -1)
		{				
			tablero[azar1][azar2] = -1;
			//cout << "Fila: " << azar1 << " Columna: " << azar2 << " es -1" << endl;
		}
		else
		{
			i--;
		}
	}
	
	for(fila=0; fila<n; fila++)
	{
		for(columna=0; columna<n; columna++)
		{
			count = 0;
			if(tablero[fila][columna+1] == -1) //Derecha
			{
				count = count + 1;
			}
			if(tablero[fila][columna-1] == -1) //Izquierda
			{
				count = count + 1;
			}
			if(tablero[fila-1][columna] == -1) //Arriba
			{
				count = count + 1;
			}
			if(tablero[fila+1][columna] == -1) //ABAJO
			{
				count = count + 1;
			}
			if(tablero[fila-1][columna-1] == -1) //SUPERIOR IZQUIERDA
			{
				count = count + 1;
			}
			if(tablero[fila-1][columna+1] == -1) //SUPERIOR DERECHA
			{
				count = count + 1;
			}
			if(tablero[fila+1][columna-1] == -1) //INFERIOR IZQUIERDA
			{
				count = count + 1;
			}
			if(tablero[fila+1][columna+1] == -1) //INFERIOR DERECHA
			{
				count = count + 1;
			}
			
			if(tablero[fila][columna] != -1)
			{
				tablero[fila][columna] = count;
			}
		}
	}
	system("cls");
	do{
		if(mensaje == true)
		{
			cout << "No utilizaste un rango adecuado, intenta otra vez." << endl;
		}
		cout << "Para el juego se utilizara el siguiente esquema de coordenadas donde debes ingresar un valor de x y otro de y " << endl;
		cout << "Recuerda que solo puedes usar numeros del 0 al 24" << endl;
		cout << "     y=0     y=1" << endl;
		cout << "x=0  ___     ___" << endl;
		cout << "x=1  ___     ___" << endl;
		cout << "Como ejemplo, selecciona algun elemento de la matriz anterior..." << endl;
		cout << "x: ";
		cin>>x;
		cout << "y: ";
		cin>>y;
		//cout << "x: " << x << " y: " << y << endl;
		if(x == 0 && y == 0)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else if(x == 0 && y == 1)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else if(x == 1 && y == 0)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else if(x == 1 && y == 1)
		{
			cout << "BIEN HECHO" << endl;
			valid = true;
		}
		else
		{
			mensaje = true;
		}
		system("cls");
	}while(valid == false);
	//EL JUEGO
	do
	{	
		for(fila=0; fila<n; fila++)
		{
			for(columna=0; columna<n; columna++)
			{
				if(vista[fila][columna] == 00) //IMPRIME VALORES QUE NO SE HAYAN DESBLOQUEADO(OCULTOS)
				{
					cout << cuadrado << "\t";
				}
				else //IMPRIME LOS VALORES QUE YA SE DESBLOQUEARON
				{
					cout << tablero[fila][columna] << "\t";
				}
			}
			cout << endl;
		}
		
		do
		{
			cout << "x: ";
			cin>>x;
			cout << "y: ";
			cin>>y;
		}while(x > 24 || y > 24);
		
		vista[x][y] = 1;
		
		if(tablero[x][y] == -1)
		{
			win = true;
		}
		
		system("cls");
	}while(win == false);
}
