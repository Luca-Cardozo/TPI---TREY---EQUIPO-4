#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;

void generarMazoAleatorio(int vMazo[])
{
    for (int x = 0; x < 20; x++)
    {
        vMazo[x] = rand() % (65 - 50 + 1) + 50;
    }
}

void robarCarta(string nombre1, string nombre2, int &carta1, int &carta2)
{
    int vMazo[20];
    generarMazoAleatorio(vMazo);
    int opcion1, opcion2;
    system("cls");
    cout << "----------------- TREY ------------------" << endl;
    cout << "-----------------------------------------" << endl;
    cout << nombre1 << ", elige un numero del 1 al 20 para elegir una carta del mazo: " << endl;
    cin >> opcion1;
    cout << endl;
    while(opcion1 < 1 || opcion1 > 20)
    {
        cout << "El numero ingresado debe ser mayor o igual a 1 y menor o igual a 20. Intentelo nuevamente: ";
        cin >> opcion1;
        cout << endl;
    }
    carta1 = vMazo[opcion1 - 1];
    cout << nombre2 << ", elige un numero del 1 al 20 para elegir una carta del mazo: " << endl;
    cin >> opcion2;
    cout << endl;
    while(opcion2 < 1 || opcion2 > 20 || opcion1 == opcion2)
    {
        cout << "El numero ingresado debe ser mayor o igual a 1 y menor o igual a 20, y no puede ser " << opcion1 << " porque ya fue elegido. Intentelo nuevamente: ";
        cin >> opcion2;
        cout << endl;
    }
    carta2 = vMazo[opcion2 - 1];
}

int otorgarPTIniciales (int carta)
{
    if (carta <= 55)
    {
        return 7;
    }
    else if (carta <= 60)
    {
        return 8;
    }
    return 9;
}

void lanzamientoDados(int &PTJugador, int &dado1, int &dado2, int &dado3, int contadorBugs)
{
    int eleccion;
    cout << "-----------------------------------------" << endl;
    cout << "Puntos de tiempo actuales: " << PTJugador << endl;
    cout << endl;
    if (PTJugador >= 2 && contadorBugs < 3)
    {
        cout << "Puede lanzar 2 dados gastando 1 PT o 3 dados gastando 2 PT" << endl;
        cout << endl;
        cout << "Ingrese la cantidad de dados a lanzar (2/3)" << endl;
        cin >> eleccion;
        cout << endl;
        while (eleccion != 2 && eleccion != 3)
        {
            cout << "Por favor ingrese 2 o 3 para indicar la cantidad de dados a lanzar: " << endl;
            cin >> eleccion;
            cout << endl;
        }
        if (eleccion == 2)
        {
            PTJugador -= 1;
            dado1 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
        }
        else if (eleccion == 3)
        {
            PTJugador -= 2;
            dado1 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
            dado3 = rand() % 6 + 1;
        }
    }
    else if (PTJugador == 1)
    {
        cout << "Solo se pueden lanzar 2 dados debido a que solo se cuenta con 1 PT" << endl;
        cout << endl;
        system("pause");
        PTJugador -= 1;
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
    }
    else if (contadorBugs >= 3)
    {
        cout << "Solo se pueden lanzar 2 dados debido a que se poseen 3 o mas Bugs" << endl;
        cout << endl;
        system("pause");
        PTJugador -= 1;
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
    }
}

void convertirDado(int dado)
{
    switch(dado)
    {
    case 1:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   x   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 2:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x     |" << endl;
        cout << "|       |" << endl;
        cout << "|     x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 3:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x     |" << endl;
        cout << "|   x   |" << endl;
        cout << "|     x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 4:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "|       |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 5:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "|   x   |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 6:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "| x   x |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    }
}

void mostrarResultadoLanzamiento(int dado1, int dado2, int dado3)
{
    cout << endl;
    cout << "Dado 1: " << endl;
    convertirDado(dado1);
    cout << endl;
    cout << "Dado 2: " << endl;
    convertirDado(dado2);
    cout << endl;
    if (dado3 != 0)
    {
        cout << endl;
        cout << "Dado 3: " << endl;
        convertirDado(dado3);
        cout << endl;
    }
}
