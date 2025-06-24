#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FuncionesTrey.h"

using namespace std;

void generarMazoAleatorio(int vMazo[])
{
    for (int x = 0; x < 20; x++)
    {
        vMazo[x] = rand() % (65 - 50 + 1) + 50;
    }
}

void robarCarta(string nombre1, string nombre2, int &carta1, int &carta2)
{
    int vMazo[20];
    generarMazoAleatorio(vMazo);
    int opcion1, opcion2;
    system("cls");
    cout << "\033[40;32m----------------- TREY ------------------" << endl;
    cout << "-----------------------------------------\033[0m\n" << endl;
    cout << nombre1 << ", elige un numero del 1 al 20 para elegir una carta del mazo: " << endl;
    cin >> opcion1;
    cout << endl;
    while(opcion1 < 1 || opcion1 > 20)
    {
        cout << "\033[40;31mEl numero ingresado debe ser mayor o igual a 1 y menor o igual a 20. Inténtelo nuevamente: \033[0m\n";
        cin >> opcion1;
        cout << endl;
    }
    carta1 = vMazo[opcion1 - 1];
    cout << nombre2 << ", elige un numero del 1 al 20 para elegir una carta del mazo: " << endl;
    cin >> opcion2;
    cout << endl;
    while(opcion2 < 1 || opcion2 > 20 || opcion1 == opcion2)
    {
        cout << "\033[40;31mEl numero ingresado debe ser mayor o igual a 1 y menor o igual a 20, y no puede ser " << opcion1 << " porque ya fue elegido. Inténtelo nuevamente: \033[0m\n";
        cin >> opcion2;
        cout << endl;
    }
    carta2 = vMazo[opcion2 - 1];
}

int otorgarPTIniciales (int carta)
{
    if (carta <= 55)
    {
        return 7;
    }
    else if (carta <= 60)
    {
        return 8;
    }
    return 9;
}

void lanzamientoDados(int &PTJugador, int &dado1, int &dado2, int &dado3, int contadorBugs)
{
    int eleccion;
    cout << "\033[40;32m-----------------------------------------" << endl;
    cout << "Puntos de tiempo actuales: \033[0m\n" << PTJugador << endl;
    cout << endl;
    if (PTJugador >= 2 && contadorBugs < 3)
    {
        cout << "\033[40;33mPuede lanzar 2 dados gastando 1 PT o 3 dados gastando 2 PT\033[0m\n" << endl;
        cout << endl;
        cout << "\033[40;33mIngrese la cantidad de dados a lanzar (2/3)\033[0m\n" << endl;
        cin >> eleccion;
        cout << endl;
        while (eleccion != 2 && eleccion != 3)
        {
            cout << "\033[40;31mPor favor ingrese 2 o 3 para indicar la cantidad de dados a lanzar: \033[0m\n" << endl;
            cin >> eleccion;
            cout << endl;
        }
        if (eleccion == 2)
        {
            PTJugador -= 1;
            dado1 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
        }
        else if (eleccion == 3)
        {
            PTJugador -= 2;
            dado1 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
            dado3 = rand() % 6 + 1;
        }
    }
    else if (PTJugador == 1)
    {
        cout << "\033[40;31mSolo se pueden lanzar 2 dados debido a que solo se cuenta con 1 PT\033[0m\n" << endl;
        cout << endl;
        system("pause");
        PTJugador -= 1;
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
    }
    else if (contadorBugs >= 3)
    {
        cout << "\033[40;31mSolo se pueden lanzar 2 dados debido a que se poseen 3 o mas Bugs\033[0m\n" << endl;
        cout << endl;
        system("pause");
        PTJugador -= 1;
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
    }
}

void convertirDado(int dado)
{
    switch(dado)
    {
    case 1:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "|       |" << endl;
        cout << "|   x   |" << endl;
        cout << "|       |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 2:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x     |" << endl;
        cout << "|       |" << endl;
        cout << "|     x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 3:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x     |" << endl;
        cout << "|   x   |" << endl;
        cout << "|     x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 4:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "|       |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 5:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "|   x   |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    case 6:
        cout << endl;
        cout << "+-------+" << endl;
        cout << "| x   x |" << endl;
        cout << "| x   x |" << endl;
        cout << "| x   x |" << endl;
        cout << "+-------+" << endl;
        cout << endl;
        break;
    }
}

void mostrarResultadoLanzamiento(int dado1, int dado2, int dado3)
{
    cout << endl;
    cout << "\033[40;34mDado 1: \033[0m\n" << endl;
    convertirDado(dado1);
    cout << endl;
    cout << "\033[40;34mDado 2: \033[0m\n" << endl;
    convertirDado(dado2);
    cout << endl;
    if (dado3 != 0)
    {
        cout << endl;
        cout << "\033[40;34mDado 3: \033[0m\n" << endl;
        convertirDado(dado3);
        cout << endl;
    }
}

void combinacionesDados (int dado1, int dado2, int dado3, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, int &puntosAcumuladosTurno, bool &bugsTurno, bool &seguir)
{
    if (dado3 == 0)
    {
        dosDados(dado1, dado2, PTJugador, contadorBugs, puntosAcumuladosTotales, puntosAcumuladosTurno, bugsTurno, seguir);
    }
    else
    {
        tresDados(dado1, dado2, dado3, PTJugador, contadorBugs, puntosAcumuladosTotales, puntosAcumuladosTurno, bugsTurno, seguir);
    }
}


void dosDados(int dado1, int dado2, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, int &puntosAcumuladosTurno, bool &bugsTurno, bool &seguir)
{
    int vDados[2] = {dado1, dado2};
    int bugCount = 0, fixCount = 0;

    for (int x = 0; x < 2; x++)
    {
        if (vDados[x] == 1)
        {
            bugCount++;
        }
        else if (vDados[x] == 3)
        {
            fixCount++;
        }
    }

    if (bugCount == 2)
    {
        if (contadorBugs >= 6)
        {
            cout << endl;
            cout << "\033[40;31m¡Como tienes 6 o más bugs y salieron 2 más, pierdes 10 puntos!\033[0m\n";
            cout << endl;
            puntosAcumuladosTotales -= 10;
            if (puntosAcumuladosTotales < 0)
            {
                puntosAcumuladosTotales = 0;
            }
        }
        PTJugador--;
        contadorBugs += 2;
        puntosAcumuladosTurno = 0;
        bugsTurno = true;
        seguir = false;
        cout << endl;
        cout << "\033[40;33m¡Salieron 2 Bugs! Perdés los puntos acumulados y 1 PT. Se termina el turno.\033[0m\n";
        cout << endl;
    }
    else if (bugCount == 1)
    {
        if (contadorBugs >= 6)
        {
            cout << endl;
            cout << "\033[40;31m¡Como tienes 6 o más bugs y salió 1 más, pierdes 5 puntos!\033[0m\n";
            cout << endl;
            puntosAcumuladosTotales -= 5;
            if (puntosAcumuladosTotales < 0)
            {
                puntosAcumuladosTotales = 0;
            }
        }
        if (fixCount == 1)
        {
            cout << endl;
            cout << "\033[40;33m¡Obtuviste 1 bug y 1 fix (se anulan entre ellos)!¡No sumás puntos en esta ronda y se termina el turno!\033[0m\n" << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "\033[40;33m¡Salió 1 Bug! Perdés los puntos acumulados y se termina el turno.\033[0m\n";
            cout << endl;
            contadorBugs++;
        }
        puntosAcumuladosTurno = 0;
        bugsTurno = true;
        seguir = false;
    }
    else if (fixCount == 1)
    {
        contadorBugs--;
        cout << endl;
        cout << "\033[40;36m¡Salió 1 Fix! Se resta 1 Bug.\033[0m\n";
        cout << endl;
    }
    else if (fixCount == 2)
    {
        contadorBugs -= 2;
        PTJugador += 1;
        cout << endl;
        cout << "\033[40;36m¡Salieron 2 Fixes! Se restan 2 Bugs y sumás 1 PT.\033[0m\n";
        cout << endl;
    }
    if (contadorBugs < 0)
    {
        contadorBugs = 0;
    }
    if (PTJugador < 0)
    {
        PTJugador = 0;
    }
}


void tresDados(int dado1, int dado2, int dado3, int &PTJugador, int &contadorBugs, int &puntosAcumuladosTotales, int &puntosAcumuladosTurno, bool &bugsTurno, bool &seguir)
{
    int bugCount = 0, fixCount = 0;
    if (dado1 == 1) bugCount++;
    if (dado2 == 1) bugCount++;
    if (dado3 == 1) bugCount++;

    if (dado1 == 3) fixCount++;
    if (dado2 == 3) fixCount++;
    if (dado3 == 3) fixCount++;

    switch (bugCount)
    {
    case 3:
        if (contadorBugs >= 6)
        {
            cout << endl;
            cout << "\033[40;31m¡Como tienes 6 o más bugs y salieron 3 más, pierdes 15 puntos!\033[0m\n";
            cout << endl;
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
        seguir = false;
        cout << endl;
        cout << "\033[40;33m¡Salieron 3 Bugs! Perdés puntos y 2 PT. Se termina el turno.\033[0m\n";
        cout << endl;
        break;
    case 2:
        if (contadorBugs >= 6)
        {
            cout << endl;
            cout << "\033[40;31m¡Como tienes 6 o más bugs y salieron 2 más, pierdes 10 puntos!\033[0m\n";
            cout << endl;
            puntosAcumuladosTotales -= 10;
            if (puntosAcumuladosTotales < 0)
            {
                puntosAcumuladosTotales = 0;
            }
        }
        contadorBugs += 2;
        PTJugador -= 1;
        puntosAcumuladosTurno = 0;
        bugsTurno = true;
        seguir = false;
        cout << endl;
        cout << "\033[40;33m¡Salieron 2 Bugs! Perdés puntos y 1 PT. Se termina el turno.\033[0m\n";
        cout << endl;
        break;
    case 1:
        if (contadorBugs >= 6)
        {
            cout << endl;
            cout << "\033[40;31m¡Como tienes 6 o más bugs y salió 1 más, pierdes 5 puntos!\033[0m\n";
            cout << endl;
            puntosAcumuladosTotales -= 5;
            if (puntosAcumuladosTotales < 0)
            {
                puntosAcumuladosTotales = 0;
            }
        }
        contadorBugs += 1;
        puntosAcumuladosTurno = 0;
        bugsTurno = true;
        seguir = false;
        cout << endl;
        cout << "\033[40;33m¡Salió 1 Bug! Perdés los puntos de la ronda. Se termina el turno.\033[0m\n";
        cout << endl;
        break;
    default:
        break;
    }

    switch (fixCount)
    {
    case 3:
        contadorBugs -= 3;
        PTJugador += 2;
        cout << endl;
        cout << "\033[40;36m¡Salieron 3 Fixes! Se restan 3 Bugs y sumás 2 PTs.\033[0m\n";
        cout << endl;
        break;
    case 2:
        contadorBugs -= 2;
        PTJugador += 1;
        cout << endl;
        cout << "\033[40;36m¡Salieron 2 Fixes! Se restan 2 Bugs y sumás 1 PT.\033[0m\n";
        cout << endl;
        break;
    case 1:
        contadorBugs -= 1;
        cout << endl;
        cout << "\033[40;36m¡Salió 1 Fix! Se resta 1 Bug.\033[0m\n";
        cout << endl;
        break;
    default:
        break;
    }

    if (contadorBugs < 0) contadorBugs = 0;
    if (PTJugador < 0) PTJugador = 0;
}


