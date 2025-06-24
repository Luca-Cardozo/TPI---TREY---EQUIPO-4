#ifndef FUNCIONESTREY_H_INCLUDED
#define FUNCIONESTREY_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Funciones de validacion
int PTArreglado();
int contBugsArreglado();
int puntosAcumuladosArreglado();
void lanzamientoArreglado(int &dado1, int &dado2, int &dado3);


// Interfaz del menu
void mostrarMenu();
void mostrarEstadisticas(string nombreUltimoGanador, int ultimoPuntaje, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[]);
void mostrarCreditos();
void mostrarReglas();
int salirJuego();


// Entrada de datos
int elegirOpcion();
void cargarJugadores(string &nombre1, string &nombre2);

// Logica del juego
void generarMazoAleatorio(int vMazo[]);
void robarCarta(string nombre1, string nombre2, int &carta1, int &carta2);
int otorgarPTIniciales (int carta);
void lanzamientoDados(int &PTJugador, int &dado1, int &dado2, int &dado3, int contadorBugs);
void convertirDado(int dado);
void mostrarResultadoLanzamiento(int dado1, int dado2, int dado3);
void combinacionesDados(int dado1, int dado2, int dado3, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, int &puntosAcumuladosTurno, bool &bugsTurno, int &seguir);
void dosDados(int dado1, int dado2, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, int &puntosAcumuladosTurno, bool &bugsTurno, int &seguir);
void tresDados(int dado1, int dado2, int dado3, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, int &puntosAcumuladosTurno, bool &bugsTurno, int &seguir);

// Ejecucion del juego
void turno(string nombre, int carta, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, bool &ceroBugs, bool &acum20, int ronda);
void juego(string nombre1, string nombre2, int carta1, int carta2, int &PTJugador1, int &PTJugador2, int &contadorBugs1, int &contadorBugs2, int &puntosAcumuladosTotalesJ1, int &puntosAcumuladosTotalesJ2, bool &ceroBugsJ1, bool &ceroBugsJ2, bool &acum20J1, bool &acum20J2, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[], string &nombreUltimoGanador, int &ultimoPuntaje);


// Puntaje y estadisticas
void estadoPartida(string nombre1, int puntosAcumuladosJ1, int carta1, int PTJugador1, int contadorBugsJ1, string nombre2, int puntosAcumuladosJ2, int carta2, int PTJugador2, int contadorBugsJ2);
void mostrarPuntosAcumuladosTurno (string nombre, int PTJugador, int puntosAcumuladosTurno);
void estadoTurno(string nombre, int ronda, int puntosRonda, int lanzamientos, int carta, int PTJugador, int contadorBugs, int puntosAcumuladosTotales);
void calculoEstadisticas(string nombre, int puntaje, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[]);
void mostrarPuntajeFinal(string nombre1, string nombre2, int PTJugador1, int PTJugador2, int contadorBugs1, int contadorBugs2, int puntosAcumuladosTotalesJ1, int puntosAcumuladosTotalesJ2, bool ceroBugsJ1, bool ceroBugsJ2, bool acum20J1, bool acum20J2, string rankingMejores5Jugadores[], int rankingMejores5Puntajes[], string &nombreUltimoGanador, int &ultimoPuntaje);
void mostrarHitos(int contadorBugs1, int contadorBugs2, bool ceroBugsJ1, bool ceroBugsJ2, bool acum20J1, bool acum20J2, int &totalAcumJ1, int &totalAcumJ2);

#endif // FUNCIONESTREY_H_INCLUDED
