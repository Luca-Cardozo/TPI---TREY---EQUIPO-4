#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;

void turno(string nombre, int carta, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, bool &ceroBugs, bool &acum20, int ronda)
{
    int puntosAcumuladosTurno = 0;
    bool seguir = 1;
    int contadorLanzamientos = 0;
    bool bugsTurno = false;
    while (seguir)
    {
        int dado1 = 0, dado2 = 0, dado3 = 0;
        contadorLanzamientos++;
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Turno de: " << nombre << endl;
        cout << "-------------------------------------------" << endl;
        cout << endl;
        lanzamientoDados(PTJugador, dado1, dado2, dado3, contadorBugs);
        //lanzamientoArreglado (dado1, dado2, dado3);
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Ronda #" << ronda << endl;
        cout << "Puntos acumulados de la ronda: " << puntosAcumuladosTurno << endl;
        cout << "Lanzamientos realizados: " << contadorLanzamientos - 1 << endl;
        cout << "-------------------------------------------" << endl;
        cout << endl;
        cout << "Lanzamiento #" << contadorLanzamientos << ":" << endl;
        cout << endl;
        cout << "Resultado del lanzamiento: " << endl;
        cout << endl;
        mostrarResultadoLanzamiento(dado1, dado2, dado3);
        cout << endl;
        cout << "-------------------------------------------" << endl;
        if (dado1 == 1 && dado2 == 1 && dado3 == 1)
        {
            if (contadorBugs >= 6)
            {
                puntosAcumuladosTotales -= 15;
                if (puntosAcumuladosTotales < 0)
                {
                    puntosAcumuladosTotales = 0;
                }
            }
            contadorBugs += 3;
            PTJugador -= 2;
            puntosAcumuladosTurno = 0;
            bugsTurno = true;
            cout << endl;
            cout << "¡Salieron 3 Bugs!" << endl;
            cout << "¡Perdiste todos tus puntos acumulados y perdiste 2 PTs!" << endl;
            cout << "¡Se termina tu turno!" << endl;
            cout << endl;
            seguir = 0;
        }
        else if (dado1 == 1 && dado2 == 1 || dado1 == 1 && dado3 == 1 || dado2 == 1 && dado3 == 1)
        {
            if (contadorBugs >= 6)
            {
                puntosAcumuladosTotales -= 10;
                if (puntosAcumuladosTotales < 0)
                {
                    puntosAcumuladosTotales = 0;
                }
            }
            contadorBugs += 2;
            PTJugador--;
            puntosAcumuladosTurno = 0;
            bugsTurno = true;
            cout << endl;
            cout << "¡Salieron 2 Bugs!" << endl;
            cout << "¡Perdiste todos tus puntos acumulados y perdiste 1 PT!" << endl;
            cout << "¡Se termina tu turno!" << endl;
            cout << endl;
            seguir = 0;
        }
        else if (dado1 == 1 || dado2 == 1 || dado3 == 1)
        {
            if (contadorBugs >= 6)
            {
                puntosAcumuladosTotales -= 5;
                if (puntosAcumuladosTotales < 0)
                {
                    puntosAcumuladosTotales = 0;
                }
            }
            contadorBugs++;
            puntosAcumuladosTurno = 0;
            bugsTurno = true;
            cout << endl;
            cout << "¡Salio 1 Bug!" << endl;
            cout << "¡Perdiste todos tus puntos acumulados!" << endl;
            cout << "¡Se termina tu turno!" << endl;
            cout << endl;
            seguir = 0;
        }
        if (dado1 == 3 && dado2 == 3 && dado3 == 3)
        {
            contadorBugs -= 3;
            PTJugador += 2;
            cout << endl;
            cout << "¡Salieron 3 Fixs!" << endl;
            cout << "¡Se restan 3 Bugs y sumas 2 PTs!" << endl;
            cout << endl;
        }
        else if (dado1 == 3 && dado2 == 3 || dado1 == 3 && dado3 == 3 || dado2 == 3 && dado3 == 3)
        {
            contadorBugs -= 2;
            PTJugador++;
            cout << endl;
            cout << "¡Salieron 2 Fixs!" << endl;
            cout << "¡Se restan 2 Bugs y sumas 1 PT!" << endl;
            cout << endl;
        }
        else if (dado1 == 3 || dado2 == 3 || dado3 == 3)
        {
            contadorBugs--;
            cout << endl;
            cout << "¡Salio 1 Fix!" << endl;
            cout << "¡Se resta 1 Bug!" << endl;
            cout << endl;
        }
        if (contadorBugs < 0)
        {
            contadorBugs = 0;
        }
        system("pause");
        if (seguir)
        {
            puntosAcumuladosTurno = puntosAcumuladosTurno + dado1 + dado2 + dado3;
            mostrarPuntosAcumuladosTurno (nombre, PTJugador, puntosAcumuladosTurno);
            system("pause");
            if (PTJugador > 0)
            {
                cout << endl;
                cout << "----------------------------------------------------------------------" << endl;
                cout << "¿Desea seguir lanzado dados? Ingrese 1 para seguir o 0 para plantarse: " << endl;
                cin >> seguir;
                while(seguir != 1 && seguir != 0)
                {
                    cout << endl;
                    cout << "Ingreso incorrecto. Ingrese 1 para seguir o 0 para plantarse: " << endl;
                    cin >> seguir;
                    cout << endl;
                }
            }
            else
            {
                cout << "-----------------------------------------------------" << endl;
                cout << "Su turno y su partida finalizan debido a tiene 0 PTs" << endl;
                cout << endl;
                PTJugador = 0;
                seguir = 0;
                system("pause");
            }
        }
    }
    puntosAcumuladosTotales += puntosAcumuladosTurno;
    estadoTurno(nombre, ronda, puntosAcumuladosTurno, contadorLanzamientos, carta, PTJugador, contadorBugs, puntosAcumuladosTotales);
    if (!bugsTurno)
    {
        cout << endl;
        cout << "¡En el turno no salieron Bugs! ¡Hito conseguido!" << endl;
        cout << endl;
        ceroBugs = true;
    }
    if (puntosAcumuladosTurno >= 20)
    {
        cout << endl;
        cout << "¡En el turno se acumularon mas de 20 puntos! ¡Hito conseguido!" << endl;
        cout << endl;
        acum20 = true;
    }
    system("pause");
}


void juego(string nombre1, string nombre2, int carta1, int carta2, int &PTJugador1, int &PTJugador2, int &contadorBugs1, int &contadorBugs2, int &puntosAcumuladosTotalesJ1, int &puntosAcumuladosTotalesJ2, bool &ceroBugsJ1, bool &ceroBugsJ2, bool &acum20J1, bool &acum20J2, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[], string &nombreUltimoGanador, int &ultimoPuntaje)
{
    system("cls");
    int ronda = 0;
    do
    {
        ronda++;
        cout << endl;
        cout << "----------------- TREY ------------------" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "------------ Ronda " << ronda << "------------" << endl;
        cout << endl;
        estadoPartida(nombre1, puntosAcumuladosTotalesJ1, carta1, PTJugador1, contadorBugs1, nombre2, puntosAcumuladosTotalesJ2, carta2, PTJugador2, contadorBugs2);
        cout << endl;
        turno(nombre1, carta1, PTJugador1, contadorBugs1, puntosAcumuladosTotalesJ1, ceroBugsJ1, acum20J1, ronda);
        turno(nombre2, carta2, PTJugador2, contadorBugs2, puntosAcumuladosTotalesJ2, ceroBugsJ2, acum20J2, ronda);
        if (puntosAcumuladosTotalesJ1 >= carta1 && puntosAcumuladosTotalesJ2 >= carta2)
        {
            cout << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "El juego ha finalizado porque ambos jugadores han alcanzado el objetivo de su carta." << endl;
            cout << endl;
            break;
        }
        else if (puntosAcumuladosTotalesJ1 >= carta1)
        {
            cout << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "El juego ha finalizado porque " << nombre1 << " ha alcanzado el objetivo de su carta." << endl;
            cout << endl;
            break;
        }
        else if (puntosAcumuladosTotalesJ2 >= carta2)
        {
            cout << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "El juego ha finalizado porque " << nombre2 << " ha alcanzado el objetivo de su carta." << endl;
            cout << endl;
            break;
        }
        if (PTJugador1 == 0 && PTJugador2 == 0)
        {
            cout << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "El juego ha finalizado porque ambos jugadores se quedaron sin puntos de tiempo." << endl;
            cout << endl;
            break;
        }
        else if (PTJugador1 == 0)
        {
            cout << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "El juego ha finalizado porque " << nombre1 << " se ha quedado sin puntos de tiempo." << endl;
            cout << endl;
            break;
        }
        else if (PTJugador2 == 0)
        {
            cout << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "El juego ha finalizado porque " << nombre2 << " se ha quedado sin puntos de tiempo." << endl;
            cout << endl;
            break;
        }
    }
    while (ronda < 10);
    if (ronda == 10)
    {
        cout << endl;
        cout << "El juego ha finalizado porque se completo la ronda 10" << endl;
        cout << endl;
    }
    system("pause");
    mostrarPuntajeFinal(nombre1, nombre2, PTJugador1, PTJugador2, contadorBugs1, contadorBugs2, puntosAcumuladosTotalesJ1, puntosAcumuladosTotalesJ2, ceroBugsJ1, ceroBugsJ2, acum20J1, acum20J2, rankingMejores5Jugadores, rankingMejores5Puntajes, nombreUltimoGanador, ultimoPuntaje);
}
