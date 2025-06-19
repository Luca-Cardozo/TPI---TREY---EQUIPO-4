#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;


int elegirOpcion()
{
    int opcion;
    cout << endl;
    cout << "\033[40;36mElija una opción: \033[0m\n";
    cin >> opcion;
    cout << endl;
    return opcion;
}

void cargarJugadores(string &nombre1, string &nombre2)
{
    char confirmar;
    do
    {
        cout << "\033[40;32m----------------- TREY ------------------" << endl;
        cout << "----------------------------------------- \033[0m\n" << endl;
        cout << endl;
        cout << "\033[40;36mAntes de comenzar deben registrar sus nombres: \033[0m\n" << endl;
        cout << endl;
        cout << "\033[40;36m¿Nombre Jugador 1? \033[0m\n";
        cin >> nombre1;
        cout << "\033[40;36m¿Nombre Jugador 2? \033[0m\n";
        cin >> nombre2;
        cout << endl << "\033[40;36m¿Confirmar nombres? (S/N) \033[0m\n";
        cin >> confirmar;
        cout << endl;
        if (confirmar == 'N' || confirmar == 'n')
        {
            cout << "\033[40;36mPor favor volver a ingresar los nombres:\033[0m\n" << endl;
            cout << endl;
        }
        else if (confirmar != 'S' && confirmar != 's')
        {
            cout << "\033[40;36mIngreso incorrecto. Por favor volver a ingresar los nombres:\033[0m\n" << endl;
            cout << endl;
        }
    }
    while (confirmar != 'S' && confirmar != 's');
}
