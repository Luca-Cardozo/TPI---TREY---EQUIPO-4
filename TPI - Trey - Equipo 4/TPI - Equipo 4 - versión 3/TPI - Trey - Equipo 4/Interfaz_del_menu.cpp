#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;


void mostrarMenu()
{
    system("cls");
    cout << endl;
    cout << "\033[40;32m ------- TREY --------" << endl;
    cout << "---------------------" << endl << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl  << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "------------------- \033[0m\n" << endl;
}

void mostrarEstadisticas(string nombreUltimoGanador, int ultimoPuntaje, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[])
{
    system("cls");
    cout << "\033[40;35m-------------- ESTADISTICAS --------------" << endl;
    cout << "Ultimo ganador/a: " << nombreUltimoGanador << " ----- " << ultimoPuntaje << " PTS" << endl;
    cout << "-------------- ---------- --------------\033[0m\n" << endl;
    cout << endl;
    for (int x = 0; x < 5; x++)
    {
        cout << "\033[40;36m-------------- ---------- --------------" << endl;
        cout << "Puesto: " << x + 1 << ": " << rankingMejores5Jugadores[x] << " " << rankingMejores5Puntajes[x] << " PTS" << endl;
    }
    cout << "-------------- ---------- --------------\033[0m\n" << endl;
    cout << endl;
    system("pause");
}

void mostrarCreditos()
{

    system("cls");
    cout << "\033[40;33m------------ Trabajo práctico integrador ------------" << endl;
    cout << endl;
    cout << "--------------------- Equipo 4 ---------------------" << endl;
    cout << endl;
    cout << "Integrantes: " << endl;
    cout << endl;
    cout << "Cardozo, Luca Julian ---------------- Legajo: 32366" << endl;
    cout << "Rodriguez Maradey, Camilo Agustin --- Legajo: 32430" << endl;
    cout << "Rosales Miquelarena, Ezequiel ------- Legajo: 33253\033[0m\n" << endl;
    cout << endl;
    system("pause");
}

int salirJuego()
{
    system("cls");
    char opcionSalir;
    cout << "\033[40;31m¿Está seguro que desea salir del juego? (S/N): \033[0m\n" << endl;
    cin >> opcionSalir;
    cout << endl;
    while (opcionSalir != 'S' && opcionSalir != 's' && opcionSalir != 'N' && opcionSalir != 'n')
    {
        cout << "\033[40;31mPor favor, ingrese S para salir o N para cancelar su elección: \033[0m\n" << endl;
        cin >> opcionSalir;
        cout << endl;
    }
    if (opcionSalir == 'S' || opcionSalir == 's')
    {
        return 0;
    }
    return 1;
}
