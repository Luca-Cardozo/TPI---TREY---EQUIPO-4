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
    cout << "3 - CREDITOS" << endl;
    cout << "4 - REGLAS" << endl  << endl;
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

void mostrarReglas()
{
    system("cls");
    cout << "------------ INSTRUCTIVO ------------" << endl << endl;
    cout << "\033[40;33m¿Qué es Trey?\033[0m\n" << endl;
    cout << "Es un juego en el cada jugador asume el rol de un programador que debe completar un proyecto para un cliente" << endl;
    cout << "enfrentando los desafíos típicos del desarrollo de software: cumplir con los tiempos, minimizar errores y" << endl;
    cout << "entregar resultados funcionales. Cada proyecto tiene una dificultad determinada, expresada en puntos. A lo" << endl;
    cout << "largo de varias rondas, los jugadores lanzan dados para avanzar en su tarea, pero los resultados pueden generar" << endl;
    cout << "tanto errores (BUGS), como arreglos (FIXES). Después de cada tirada de dados, deberán decidir si continúan" << endl;
    cout << "arriesgando para acumular más puntos o si prefieren detenerse y conservar lo logrado hasta el momento." << endl << endl;

    cout << "\033[40;33m- INICIO DE JUEGO:\033[0m\n" << endl;
    cout << "El juego comienza con cada jugador robando una carta de un mazo compuesto por 20 cartas numeradas del 50 al 65." << endl;
    cout << "Cada carta representa un proyecto de programación con una dificultad específica, expresada en puntos. Según el" << endl;
    cout << "valor de la carta obtenida, el jugador recibe una cantidad determinada de Puntos de Tiempo (PT), necesarios" << endl;
    cout << "para realizar acciones durante la partida: " << endl << endl;
    cout << "\033[32mCartas\033[0m" << "--------------------" << "\033[32mPuntos\033[0m" << endl;
    cout << " 50-55 ------------------- 7 PTs" << endl;
    cout << " 56-60 ------------------- 8 PTs" << endl;
    cout << " 61-65 ------------------- 9 PTs" << endl << endl;

    cout << "\033[40;33m- LANZAMIENTO DE DADOS:\033[0m\n" << endl;
    cout << "En su turno, el jugador elige lanzar dos o tres dados de seis caras. Según la cantidad de dados que decida usar," << endl;
    cout << "deberá pagar el siguiente costo en Puntos de Tiempo (PT):" << endl << endl;
    cout << "2 dados: cuesta 1 PT" << endl;
    cout << "3 dados: cuesta 2 PT" << endl << endl;
    cout << "Tras lanzar los dados, se aplican las siguientes reglas:" << endl;
    cout << "- Si no aparece ningún BUG (1): Se suman los valores obtenidos y el jugador puede decidir si quiere seguir" << endl;
    cout << "lanzando o plantarse y conservar los puntos acumulados en esa ronda." << endl;
    cout << "- Si aparece al menos un BUG (1): La ronda termina inmediatamente. El jugador pierde todos los puntos" << endl;
    cout << "acumulados en esa ronda y suma 1 BUG a su contador de BUGS." << endl;
    cout << "- Si aparece un FIX o Buena Práctica (3): Se elimina 1 BUG acumulado. Por ejemplo, si un jugador tenía 4 BUGS" << endl;
    cout << "y en su tirada obtiene un 3, pasa a tener 3 BUGS." << endl << endl;

    cout << "\033[40;33m- DESARROLLO DE JUEGO:\033[0m\n" << endl;
    cout << "Cada jugador deberá completar el trabajo asignado sumando puntos a lo largo de varias rondas, utilizando tiradas" << endl;
    cout << "de dados. El objetivo es alcanzar el valor indicado en la carta inicial, pero deberán tener cuidado: el azar" << endl;
    cout << "puede introducir bugs (errores) que complicarán el avance." << endl;

    cout << endl << "\033[40;33m------A TENER EN CUENTA-----\033[0m\n" << endl;

    cout << "\033[32mBUGS (número 1 en los dados)\033[0m" << endl;
    cout << "- 1 dado con 1: El jugador pierde todos los puntos acumulados en esa ronda, el turno finaliza inmediatamente y" << endl;
    cout << "suma 1 BUG a su contador personal." << endl;
    cout << "- 2 dados con 1: Además de perder todos los puntos de la ronda, el jugador pierde 1 Punto de Tiempo (PT)" << endl;
    cout << "adicional y suma 2 BUGS a su contador." << endl;
    cout << "- 3 dados con 1: Además de perder todos los puntos de la ronda, el jugador pierde 2 Punto de Tiempo (PT)"  << endl;
    cout << "adicional y suma 3 BUGS a su contador." << endl;

    cout << endl << "\033[32mFIXES (número 3 en los dados)\033[0m" << endl;
    cout << "- 1 dado con 3: El jugador elimina 1 BUG acumulado." << endl;
    cout << "- 2 dads con 3: El jugador elimina 2 BUGS  y gana 1 Punto de Tiempo (PT)." << endl;
    cout << "- 3 dados con 3: El jugador elimina 3 BUGS y gana 2 Punto de Tiempo (PT). " << endl;
    cout << "* Si el contador de BUGS está en 0, los FIXES (3) no se acumulan. Solo sirven para reducir la cantidad de BUGS (1)." << endl;

    cout << endl << "Acciones al acumular BUGS:" << endl;
    cout << "3 o más: El jugador solo puede lanzar 2 dados por turno." << endl;
    cout << "6 o más: Además de la restricción anterior, se suma una pérdida de 5 puntos del total acumulado cada vez que" << endl;
    cout << "aparezca un nuevo BUG. " << endl;

    cout << endl << "Consecución de HITOS que permiten sumar puntos adicionales:" << endl;
    cout << "Menor cantidad de BUGS: +7 puntos" << endl;
    cout << "Llegar a 0 BUGS por lo menos 1 vez: +15 puntos" << endl;
    cout << "Acumular 20 puntos en una ronda sin BUGS: +10 puntos" << endl;
    cout << "ACLARACION: en caso de empate en un HITO, ambos jugadores suman los puntos" << endl;

    cout << endl << "\033[40;33m------FINALIZACIÓN DE JUEGO-----\033[0m\n" << endl;
    cout << "El juego puede terminar de 2 formas:" << endl;
    cout << "- Cuando un jugador alcanza o supera el puntaje de su carta objetivo." << endl;
    cout << "- Cuando un jugador pierde todos sus Puntos de Tiempo." << endl;
    cout << "- Cuando se completan las 10 rondas." << endl;
    cout << "ACLARACIÓN: en todos los casos mencionados la ronda debe completarse (cada jugador debe completar su turno)." << endl;
    cout << endl;
    system("pause");
}
