#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;


void mostrarMenu()
{
    system("cls");
    cout << endl;
    cout << "------- TREY --------" << endl;
    cout << "---------------------" << endl << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl  << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------" << endl;
}

void mostrarEstadisticas(string nombreUltimoGanador, int ultimoPuntaje, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[])
{
    system("cls");
    cout << "-------------- ESTADISTICAS --------------" << endl;
    cout << "Ultimo ganador/a: " << nombreUltimoGanador << " ----- " << ultimoPuntaje << " PTS" << endl;
    cout << "-------------- ---------- --------------" << endl;
    cout << endl;
    for (int x = 0; x < 5; x++)
    {
        cout << "-------------- ---------- --------------" << endl;
        cout << "Puesto: " << x + 1 << ": " << rankingMejores5Jugadores[x] << " " << rankingMejores5Puntajes[x] << " PTS" << endl;
    }
    cout << "-------------- ---------- --------------" << endl;
    cout << endl;
    system("pause");
}

void mostrarCreditos()
{

    system("cls");
    cout << "------------ Trabajo practico integrador ------------" << endl;
    cout << endl;
    cout << "--------------------- Equipo 4 ---------------------" << endl;
    cout << endl;
    cout << "Integrantes: " << endl;
    cout << endl;
    cout << "Cardozo, Luca Julian ---------------- Legajo: 32366" << endl;
    cout << "Rodriguez Maradey, Camilo Agustin --- Legajo: 32430" << endl;
    cout << "Rosales Miquelarena, Ezequiel ------- Legajo: 33253" << endl;
    cout << endl;
    system("pause");
}

int salirJuego()
{
    system("cls");
    char opcionSalir;
    cout << "¿Esta seguro que desea salir del juego? (S/N): " << endl;
    cin >> opcionSalir;
    cout << endl;
    while (opcionSalir != 'S' && opcionSalir != 's' && opcionSalir != 'N' && opcionSalir != 'n')
    {
        cout << "Por favor, ingrese S para salir o N para cancelar su eleccion: " << endl;
        cin >> opcionSalir;
        cout << endl;
    }
    if (opcionSalir == 'S' || opcionSalir == 's')
    {
        return 0;
    }
    return 1;
}
