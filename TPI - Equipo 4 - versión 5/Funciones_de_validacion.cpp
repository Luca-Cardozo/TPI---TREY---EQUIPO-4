#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;


// Funciones de validacion
int PTArreglado()
{
    int PTJugador;
    cout << "Valor de PT arreglado: " << endl;
    cin >> PTJugador;
    return PTJugador;
}

int contBugsArreglado()
{
    int contBugsArreglado;
    cout << "Valor de bugs arreglado: " << endl;
    cin >> contBugsArreglado;
    return contBugsArreglado;
}

int puntosAcumuladosArreglado()
{
    int puntosAcumuladosArreglado;
    cout << "Valor de puntos acumulados arreglado: " << endl;
    cin >> puntosAcumuladosArreglado;
    return puntosAcumuladosArreglado;
}

void lanzamientoArreglado(int &dado1, int &dado2, int &dado3)
{
    cout << "Valor arreglado para el primer dado: " << endl;
    cin >> dado1;
    cout << "Valor arreglado para el segundo dado: " << endl;
    cin >> dado2;
    cout << "Valor arreglado para el tercer dado: " << endl;
    cin >> dado3;
}
