#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;

void estadoPartida(string &nombre1, int &puntosAcumuladosJ1, int &carta1, int &PTJugador1, int &contadorBugsJ1, string &nombre2, int &puntosAcumuladosJ2, int &carta2, int &PTJugador2, int &contadorBugsJ2)
{
    cout << "\033[40;31m--------------------------------------------------------" << endl;
    cout << nombre1 << ": " << puntosAcumuladosJ1 << " de " << carta1 << " puntos\t";
    cout << nombre2 << ": " << puntosAcumuladosJ2 << " de " << carta2 << " puntos" << endl;
    cout << "PT: " << PTJugador1 << " / BUGS: " << contadorBugsJ1 << "\t\t";
    cout << "PT: " << PTJugador1 << " / BUGS: \033[0m\n" << contadorBugsJ2 << endl;
}

void mostrarPuntosAcumuladosTurno (string nombre, int PTJugador, int puntosAcumuladosTurno)
{
    system("cls");
    cout << "\033[40;32m----------------- TREY ------------------" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    cout << "Resultados actuales del turno de " << nombre << endl;
    cout << "Puntos acumulados en el turno: " << puntosAcumuladosTurno << endl;
    cout << "PT disponibles: " << PTJugador << endl;
    cout << "-----------------------------------------\033[0m\n" << endl;
    cout << endl;
}

void estadoTurno(string nombre, int &ronda, int &puntosRonda, int &lanzamientos, int &carta, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales)
{
    system("cls");
    cout << "\033[40;36m----------------- TREY ------------------" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    cout << endl << "RESULTADOS DEL TURNO DE " << nombre << endl;
    cout << "+---------------------------------+" << endl;
    cout << "    RONDA: " << ronda << endl;
    cout << "    PUNTOS DE LA RONDA: " << puntosRonda << endl;
    cout << "    LANZAMIENTOS: " << lanzamientos << endl;
    cout << "-----------------------------------------" << endl;
    cout << "PROGRESO ACTUAL: " << puntosAcumuladosTotales << " DE " << carta << " PUNTOS" << endl;
    cout << "PT: " << PTJugador << "----/----" << "BUGS: " << contadorBugs << endl;
    cout << "+---------------------------------+\033[0m\n" << endl;
    cout << endl;
}


void calculoEstadisticas(string nombre, int puntaje, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[])
{
    for (int x = 0; x < 5; x++)
    {
        if (puntaje > rankingMejores5Puntajes[x])
        {
            string aux1;
            int aux2;
            aux1 = rankingMejores5Jugadores[x];
            rankingMejores5Jugadores[x] = nombre;
            aux2 = rankingMejores5Puntajes[x];
            rankingMejores5Puntajes[x] = puntaje;
            for (int y = x + 1; y < 5; y++)
            {
                string auxJugador;
                auxJugador = rankingMejores5Jugadores[y];
                rankingMejores5Jugadores[y] = aux1;
                aux1 = auxJugador;
                int auxPuntaje;
                auxPuntaje = rankingMejores5Puntajes[y];
                rankingMejores5Puntajes[y] = aux2;
                aux2 = auxPuntaje;
            }
            break;
        }
    }
}

void mostrarHitos(int contadorBugs1, int contadorBugs2, bool ceroBugsJ1, bool ceroBugsJ2, bool acum20J1, bool acum20J2, int &totalAcumJ1, int &totalAcumJ2)
{
    if (contadorBugs1 < contadorBugs2)
    {
        cout << "Menor Bugs: " << 7 << " pts " << " --//-- " << 0 << " pts" << endl;
        totalAcumJ1 += 7;
    }
    else if (contadorBugs2 < contadorBugs1)
    {
        cout << "Menor Bugs: " << 0 << " pts " << " --//-- " << 7 << " pts" << endl;
        totalAcumJ2 += 7;
    }
    else
    {
        cout << "Menor Bugs: " << 7 << " pts " << " --//-- " << 7 << " pts" << endl;
        totalAcumJ1 += 7;
        totalAcumJ2 += 7;
    }
    if (ceroBugsJ1 && ceroBugsJ2)
    {
        cout << "Llegar a 0 Bugs: " << 15 << " pts " << " --//-- " << 15 << " pts" << endl;
        totalAcumJ1 += 15;
        totalAcumJ2 += 15;
    }
    else if (ceroBugsJ1 && !ceroBugsJ2)
    {
        cout << "Llegar a 0 Bugs: " << 15 << " pts " << " --//-- " << 0 << " pts" << endl;
        totalAcumJ1 += 15;
    }
    else if (!ceroBugsJ1 && ceroBugsJ2)
    {
        cout << "Llegar a 0 Bugs: " << 0 << " pts " << " --//-- " << 15 << " pts" << endl;
        totalAcumJ2 += 15;
    }
    else
    {
        cout << "Llegar a 0 Bugs: " << 0 << " pts " << " --//-- " << 0 << " pts" << endl;
    }
    if (acum20J1 && acum20J2)
    {
        cout << "Acumular 20 puntos: " << 10 << " pts " << " --//-- " << 10 << " pts" << endl;
        totalAcumJ1 += 10;
        totalAcumJ2 += 10;
    }
    else if (acum20J1 && !acum20J2)
    {
        cout << "Acumular 20 puntos: " << 10 << " pts " << " --//-- " << 0 << " pts" << endl;
        totalAcumJ1 += 10;
    }
    else if (!acum20J1 && acum20J2)
    {
        cout << "Acumular 20 puntos: " << 0 << " pts " << " --//-- " << 10 << " pts" << endl;
        totalAcumJ2 += 10;
    }
    else
    {
        cout << "Acumular 20 puntos: " << 0 << " pts " << " --//-- " << 0 << " pts" << endl;
    }
}


void mostrarPuntajeFinal(string nombre1, string nombre2, int PTJugador1, int PTJugador2, int contadorBugs1, int contadorBugs2, int puntosAcumuladosTotalesJ1, int puntosAcumuladosTotalesJ2, bool ceroBugsJ1, bool ceroBugsJ2, bool acum20J1, bool acum20J2, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[], string &nombreUltimoGanador, int &ultimoPuntaje)
{
    int puntosDescontadosBugsJ1 = contadorBugs1 * (-5);
    int puntosDescontadosBugsJ2 = contadorBugs2 * (-5);
    int puntosSumadosPTSobrantesJ1 = PTJugador1 * 7;
    int puntosSumadosPTSobrantesJ2 = PTJugador2 * 7;
    int totalAcumJ1 = puntosAcumuladosTotalesJ1 + puntosDescontadosBugsJ1 + puntosSumadosPTSobrantesJ1;
    int totalAcumJ2 = puntosAcumuladosTotalesJ2 + puntosDescontadosBugsJ2 + puntosSumadosPTSobrantesJ2;
    system("cls");
    cout << "\033[40;32m----------------- TREY ------------------" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    cout << "---------- RESULTADOS FINALES ----------" << endl;
    cout << "---------- ------------------ ----------\033[0m\n" << endl;
    cout << "\033[40;34mJugador: " << nombre1 << " --//-- " << nombre2 << endl;
    cout << "Puntos: " << puntosAcumuladosTotalesJ1 << " pts " << " --//-- " << puntosAcumuladosTotalesJ2 << " pts" << endl;
    cout << "Bugs: " << puntosDescontadosBugsJ1 << " pts (" << contadorBugs1 << ") " << " --//-- " << puntosDescontadosBugsJ2 << " pts (" << contadorBugs2 << ")" << endl;
    cout << "Tiempo: " << puntosSumadosPTSobrantesJ1 << " pts (" << PTJugador1 << ") " << " --//-- " << puntosSumadosPTSobrantesJ2 << " pts (" << PTJugador2 << ")" << endl;
    mostrarHitos(contadorBugs1, contadorBugs2, ceroBugsJ1, ceroBugsJ2, acum20J1, acum20J2, totalAcumJ1, totalAcumJ2);
    cout << "---------- ------------------ ----------" << endl;
    cout << "TOTAL: " << totalAcumJ1 << " pts " << " --//-- " << totalAcumJ2 << " pts\033[0m\n" << endl;
    cout << endl;
    if (totalAcumJ1 > totalAcumJ2)
    {
        nombreUltimoGanador = nombre1;
        ultimoPuntaje = totalAcumJ1;
        calculoEstadisticas(nombre1, totalAcumJ1, rankingMejores5Jugadores, rankingMejores5Puntajes);
        cout << endl;
        cout << "\033[40;35m¡Felicitaciones " << nombre1 << "! ¡Eres el/la ganador/a con " << totalAcumJ1 << " puntos!\033[0m\n" << endl;
        cout << endl;
    }
    else if (totalAcumJ1 < totalAcumJ2)
    {
        nombreUltimoGanador = nombre2;
        ultimoPuntaje = totalAcumJ2;
        calculoEstadisticas(nombre2, totalAcumJ2, rankingMejores5Jugadores, rankingMejores5Puntajes);
        cout << endl;
        cout << "\033[40;35m¡Felicitaciones " << nombre2 << "! ¡Eres el/la ganador/a con " << totalAcumJ2 << " puntos!\033[0m\n" << endl;
        cout << endl;
    }
    else
    {
        nombreUltimoGanador = nombre1 + "/" + nombre2;
        ultimoPuntaje = totalAcumJ1;
        calculoEstadisticas(nombre1 + "/" + nombre2, totalAcumJ1, rankingMejores5Jugadores, rankingMejores5Puntajes);
        cout << endl;
        cout << "\033[40;35m¡El juego ha resultado en un empate!\033[0m\n" << endl;
        cout << endl;
    }
    system("pause");
}
