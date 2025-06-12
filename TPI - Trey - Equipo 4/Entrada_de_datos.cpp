#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;


int elegirOpcion()
{
    int opcion;
    cout << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    cout << endl;
    return opcion;
}

void cargarJugadores(string &nombre1, string &nombre2)
{
    char confirmar;
    do
    {
        cout << "----------------- TREY ------------------" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
        cout << "Antes de comenzar deben registrar sus nombres: " << endl;
        cout << endl;
        cout << "¿Nombre Jugador 1? ";
        cin >> nombre1;
        cout << "¿Nombre Jugador 2? ";
        cin >> nombre2;
        cout << endl << "¿Confirmar nombres? (S/N) ";
        cin >> confirmar;
        cout << endl;
        if (confirmar == 'N' || confirmar == 'n')
        {
            cout << "Por favor volver a ingresar los nombres:" << endl;
            cout << endl;
        }
        else if (confirmar != 'S' && confirmar != 's')
        {
            cout << "Ingreso incorrecto. Por favor volver a ingresar los nombres:" << endl;
            cout << endl;
        }
    }
    while (confirmar != 'S' && confirmar != 's');
}
