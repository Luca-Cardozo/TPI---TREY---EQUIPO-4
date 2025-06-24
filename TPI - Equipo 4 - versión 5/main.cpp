#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");
    // Inicializacion de la semilla para generar numeros pseudoaleatorios
    srand(time(NULL));

    // Variable que almacena la eleccion del menu
    int opcion;
    // Variables que almacenan los nombres de los jugadores, las cartas elegidas y sus puntos de tiempo
    string nombre1, nombre2;
    int carta1, carta2;
    int PTJugador1, PTJugador2;
    // Vectores para almacenar los 5 mejores puntajes y los nombres de los jugadores correspondientes
    // Se mostraran eligiendo la opcion ESTADISTICAS
    string rankingMejores5Jugadores[5] = {"Vacío", "Vacío", "Vacío", "Vacío", "Vacío"};
    //string rankingMejores5Jugadores[5] = {"Nombre1", "Nombre2", "Nombre3", "Nombre4", "Nombre5"};
    int rankingMejores5Puntajes[5] = {};
    //int rankingMejores5Puntajes[5] = {84, 73, 62, 60, 45};
    // Variables que almacenan el nombre y puntaje del ultimo ganador. Se muestran en ESTADISTICAS
    string nombreUltimoGanador;
    int ultimoPuntaje;
    // Desarrollo del programa
    while (true)
    {
        // Funcion que visualiza el menu del juego
        mostrarMenu();
        // Funcion que pide la eleccion numerica al usuario y retorna la misma
        opcion = elegirOpcion();
        int opcionSalir;
        // Variables que almacenan los puntos y bugs acumulados por cada jugador en cada partida
        int puntosAcumuladosJ1 = 0, puntosAcumuladosJ2 = 0;
        int contadorBugsJ1 = 0, contadorBugsJ2 = 0;
        // Variables que almacenan los hitos alcanzados por cada jugador en cada partida
        bool ceroBugsJ1 = false, ceroBugsJ2 = false;
        bool acum20J1 = false, acum20J2 = false;
        // Menu de opciones
        switch (opcion)
        {
        case 1:
            // Funcion que solicita los nombres de los jugadores y los carga antes de iniciar la partida
            cargarJugadores(nombre1, nombre2);
            // Funcion que solicita a los jugadores robar una carta para asignarles el objetivo a conseguir para ganar el juego
            // El mazo de cartas esta generado en un vector de 20 elementos pseudoaleatorios con valores del 50 al 65
            robarCarta(nombre1, nombre2, carta1, carta2);
            // Funcion que asigna los puntos de tiempo iniciales a cada jugador en relacion al numero de la carta robada
            PTJugador1 = otorgarPTIniciales(carta1);
            PTJugador2 = otorgarPTIniciales(carta2);

            // Funciones de validacion
            //PTJugador1 = PTArreglado();
            //PTJugador2 = PTArreglado();
            //puntosAcumuladosJ1 = puntosAcumuladosArreglado();
            //puntosAcumuladosJ2 = puntosAcumuladosArreglado();
            //contadorBugsJ1 = contBugsArreglado();
            //contadorBugsJ2 = contBugsArreglado();

            // Funcion que desarrolla el juego completo
            // Esta compuesta por llamados a varias funciones encargadas de desarrollar los turnos, lanzamientos de dados, calculos y mostrar resultados
            juego(nombre1, nombre2, carta1, carta2, PTJugador1, PTJugador2, contadorBugsJ1, contadorBugsJ2, puntosAcumuladosJ1, puntosAcumuladosJ2, ceroBugsJ1, ceroBugsJ2, acum20J1, acum20J2, rankingMejores5Jugadores, rankingMejores5Puntajes, nombreUltimoGanador, ultimoPuntaje);
            break;
        case 2:
            // Funcion que muestra las ESTADISTICAS (ranking de 5 mejores puntajes y nombres, ademas del nombre y puntaje del ultimo ganador)
            mostrarEstadisticas(nombreUltimoGanador, ultimoPuntaje, rankingMejores5Jugadores, rankingMejores5Puntajes);
            break;
        case 3:
            // Funcion que muestra los CREDITOS (nombres, apellidos y legajos de cada integrante del equipo)
            mostrarCreditos();
            break;
        case 4:
            // Funcion que muestra las reglas del juego
            mostrarReglas();
            break;
        case 0:
            // Funcion que solicita al usuario confirmar su eleccion de salida del juego y retorna dicha eleccion
            opcionSalir = salirJuego();
            if (opcionSalir == 0)
            {
                return 0;
            }
            break;
        default:
            cout << endl;
            cout << "\033[40;31mElegiste una opción incorrecta. Vuelve a intentarlo.\033[0m\n" << endl;
            system("pause");
            cout << endl;
            break;
        }
    }
}
