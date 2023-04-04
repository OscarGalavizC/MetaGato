//
// Created by Usuario on 22/05/2021.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include "Utileria.h"
#include "Constantes y estructuras.h"
#include "Diseno.h"
#include "Jugabilidad.h"
#include "Pantallas.h"

//****************************************************************************************
void Menu(Colores &Tema, int dec)
{
    CambiarCursor(APAGADO,NORMAL);

    ImprimirPlantilla();

    ImprimirMenu();
    MoverCursor(2, ALTO_PANTALLA-3);
    std::cout << std::left;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2) << "[ARRIBA]/[ABAJO] para navegar por las opciones";
    std::cout << std::right;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2-2) << "[ENTER] para confirmar selecci\242n" << std::endl;
    int tecla;
    SeleccionMenu(dec);
    do{
        tecla = getch();
        switch (tecla){
            case FLECHA_ABAJO:
            {
                Beep(440, 100);
                if (dec == 5) dec = 1;
                else ++dec;
                break;
            }
            case FLECHA_ARRIBA:
            {
                Beep(440, 100);
                if (dec == 1) dec = 5;
                else --dec;
                break;
            }
        }
        SeleccionMenu(dec);
        Sleep(100);
    }while(tecla != ENTER);
    Beep(880, 70);
    Nombres jugador;
    switch(dec)
    {
        case 1:
        {
            PedirNombre1(Tema, jugador);
            PedirNombre2(Tema, jugador);
            ImprimirPlantilla();
            Juego(Tema, jugador);
            break;
        }
        case 2:
        {
            ImprimirPlantilla();
            Configuracion(Tema, tecla);
            Menu(Tema, dec);
            break;
        }
        case 3:
            Instrucciones(tecla);
            Menu(Tema, dec);
            break;
        case 4:
            ImprimirPlantilla();
            Creditos(tecla);
            Menu(Tema, dec);
            break;
        case 5:
            break;
    }
}
//****************************************************************************************
void Configuracion(Colores &Tema, int tecla)
{
    EstablecerColor(NEGRO, BLANCO);
    MoverCursor((ANCHO_PANTALLA-13)/2-3, ALTO_PANTALLA-26);
    std::cout << "Paleta de colores: " << Tema.par_de_colores;
    MoverCursor((ANCHO_PANTALLA-13)/2+6, ALTO_PANTALLA-23);
    std::cout << '1';
    MoverCursor((ANCHO_PANTALLA-13)/2+6, ALTO_PANTALLA-20);
    std::cout << '2';
    MoverCursor((ANCHO_PANTALLA-13)/2+6, ALTO_PANTALLA-17);
    std::cout << '3';
    MoverCursor((ANCHO_PANTALLA-13)/2+6, ALTO_PANTALLA-14);
    std::cout << '4';
    MoverCursor(2, ALTO_PANTALLA-3);
    std::cout << std::left;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2) << "[ARRIBA]/[ABAJO] para navegar por las opciones";
    std::cout << std::right;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2-3) << "[ENTER] para confirmar selecci\242n" << std::endl;
    Jugadores(Tema);
    do{
        MoverCursor((ANCHO_PANTALLA-13)/2-3, ALTO_PANTALLA-26);
        EstablecerColor(NEGRO, BLANCO);
        std::cout << "Paleta de colores: " << Tema.par_de_colores;
        tecla = getch();
        switch(tecla){
            case FLECHA_ABAJO:
            {
                Beep(440, 100);
                if (Tema.par_de_colores == 4) Tema.par_de_colores = 1;
                else ++Tema.par_de_colores;
                break;
            }
            case FLECHA_ARRIBA:
            {
                Beep(440, 100);
                if (Tema.par_de_colores == 1) Tema.par_de_colores = 4;
                else --Tema.par_de_colores;
                break;
            }
        }
        Jugadores(Tema);
        Sleep(100);
    }while(tecla != ENTER);
    Beep(880, 100);
    EstablecerColor(NEGRO, BLANCO);
}

//****************************************************************************************
void PedirNombre1(Colores tema, Nombres &jugador)
{
    do{
        system("cls");
        ImprimirPlantilla();
        MoverCursor((ANCHO_PANTALLA - 46) / 2, ALTO_PANTALLA - 24);
        std::cout << "Nombre de los jugadores (m\240ximo 10 caracteres):";
        MoverCursor((ANCHO_PANTALLA - 21) / 2, ALTO_PANTALLA - 20);

        EstablecerColor(NEGRO, tema.COLOR1);
        std::cout << "Jugador 1: ";
        std::cout << "                                            ";
        EstablecerColor(NEGRO, BLANCO);

        MoverCursor((ANCHO_PANTALLA - 21) / 2+11, ALTO_PANTALLA - 20);

        CambiarCursor(ENCENDIDO, NORMAL);
        getline(std::cin, jugador.jugador1);
        CambiarCursor(APAGADO, NORMAL);
    }while(jugador.jugador1.length() < 1 || jugador.jugador1.length() > 10);
}
//****************************************************************************************
void PedirNombre2(Colores tema, Nombres &jugador)
{
    do{
        system("cls");
        ImprimirPlantilla();
        MoverCursor((ANCHO_PANTALLA - 46) / 2, ALTO_PANTALLA - 24);
        std::cout << "Nombre de los jugadores (m\240ximo 10 caracteres):";
        MoverCursor((ANCHO_PANTALLA - 21) / 2, ALTO_PANTALLA - 20);

        EstablecerColor(NEGRO, tema.COLOR2);
        std::cout << "Jugador 2: ";
        std::cout << "                                            ";
        EstablecerColor(NEGRO, BLANCO);

        MoverCursor((ANCHO_PANTALLA - 21) / 2+11, ALTO_PANTALLA - 20);

        CambiarCursor(ENCENDIDO, NORMAL);
        getline(std::cin, jugador.jugador2);
        CambiarCursor(APAGADO, NORMAL);
    }while(jugador.jugador2.length() < 1 || jugador.jugador2.length() > 10);
}
//****************************************************************************************
//****************************************************************************************
void Juego(Colores tema, Nombres nombre)
{
    Tablero tablero;
    for(int k = 0; k < 9; ++k){
        tablero.cuadrante[k].lim_izq = POSX_ORIGEN + 6*(k%3);
        tablero.cuadrante[k].lim_der = tablero.cuadrante[k].lim_izq + 4;
        tablero.cuadrante[k].lim_sup = POSY_ORIGEN + 6*(k/3);
        tablero.cuadrante[k].lim_inf = tablero.cuadrante[k].lim_sup + 4;
    }

    ImprimirTablero((ANCHO_PANTALLA-19)/2,16);
    MoverCursor(2, ALTO_PANTALLA-17);
    std::cout << "    [ARRIBA]/[ABAJO]/[IZQUIERDA]/" << std::endl;
    std::cout << ' ' << char(BV) << "    [DERECHA] para moverse por" << std::endl;
    std::cout << ' ' << char(BV) << "    el tablero" << std::endl;
    MoverCursor(ANCHO_PANTALLA-36, ALTO_PANTALLA-17);
    std::cout << "[ENTER] para seleccionar casilla" << std::endl;
    int turno = JUGADOR1;
    tablero.indice_proximo = 9;

    while(true){
        ImprimirTurno(turno, tema, nombre);

        Beep(440,300);

        //Dependiendo de dónde puso el jugador anterior, dependerá
        //si la seleccion se limitará al cuadrante o a todo el tablero.
        CambiarCursor(ENCENDIDO, SOLIDO);
        tablero.indice_actual = tablero.indice_proximo;
        if(tablero.ganador_cuadrante[tablero.indice_proximo] == VACIO) SeleccionRestringida(turno, tablero);
        else SeleccionLibre(turno, tablero);
        CambiarCursor(APAGADO, SOLIDO);

        //Una vez el jugador escoja, se imprime el símbolo en pantalla.
        ImprimirSimbolo(tema, tablero); //El índice de la casilla equivale al indice del proximo cuadrante.

        //Se comprueba si con este último movimiento un jugador ganó algún cuadrante.
        tablero.ganador_cuadrante[tablero.indice_actual] = ComprobarGanador(tablero.cuadrante[tablero.indice_actual].casilla);
        if(tablero.ganador_cuadrante[tablero.indice_actual] != VACIO){
            PintarCuadrante(tablero.ganador_cuadrante[tablero.indice_actual], tema, tablero.indice_actual);
            RellenarCuadrante(turno, tablero.cuadrante[tablero.indice_actual].casilla);
            //En caso de que un cuadrante sea ganado, se comprueba si esto determina al ganador.
            tablero.ganador = ComprobarGanador(tablero.ganador_cuadrante);
            if(tablero.ganador != VACIO) break;
        }

        //Terminado el proceso de selección y comprobación del
        //ganador se hace un cambio al turno y se reinicia el ciclo.
        if(turno == JUGADOR1) turno = JUGADOR2;
        else turno = JUGADOR1;
    }

    //En caso de haber ganador, se imprime un mensaje felicitando al ganador
    //o se indica empate en caso de haberlo.
    ImprimirCuadroMensaje(tablero.ganador,tema,nombre);
    MoverCursor(2, ALTO_PANTALLA-3);
    SeleccionFin(tema, nombre);
}
// *****************************************************************************************************

void Creditos(int tecla)
{
    do {
        MoverCursor((ANCHO_PANTALLA-9)/2, ALTO_PANTALLA-24);
        std::cout << "CR" << char(144) << "DITOS:" << std::endl << std::endl;
        std::cout << ' ' << (char)BV << "  Programa presentado como proyecto final de Programaci\242n de Computadoras de la" << std::endl;
        std::cout << ' ' << (char)BV << "  Licenciatura en Ciencias de la Computaci\242n en la Universidad de Sonora." << std::endl << std::endl;
        std::cout << ' ' << (char)BV << "  Maestra: Irene Rodriguez Castillo." << std::endl;
        std::cout << ' ' << (char)BV << "  Equipo 2." << std::endl << std::endl << std::endl;
        MoverCursor((ANCHO_PANTALLA-26)/2, ALTO_PANTALLA-16);
        std::cout << "EQUIPO DE DESARROLLADORES:" << std::endl  << std::endl;
        std::cout << ' ' << (char)BV << "  Galaviz Cuen Oscar Eduardo" << std::endl;
        std::cout << ' ' << (char)BV << "  Navarro Mel\202ndrez Erick Joel" << std::endl;
        std::cout << ' ' << (char)BV << "  Ochoa Galv\240n Daniel Rub\202n" << std::endl;
        std::cout << ' ' << (char)BV << "  Ruiz Gonz\240lez Kevin David" << std::endl << std::endl;
        MoverCursor(0, ALTO_PANTALLA-3);
        std::cout << ' ' << (char)BV << "Pulsa [ENTER] para regresar al men\243" << std::endl;
        tecla = getch();
    }while(tecla != ENTER);
}

// *****************************************************************************************************
void Instrucciones(int tecla)
{
    int pagina = 1;
    do{
        ImprimirPlantilla();
        switch (pagina) {
            case 1: {
                RulesPg1(ANCHO_PANTALLA, ALTO_PANTALLA);
                break;
            }
            case 2: {
                RulesPg2(ANCHO_PANTALLA, ALTO_PANTALLA);
                break;
            }
            case 3: {
                RulesPg3(ANCHO_PANTALLA, ALTO_PANTALLA);
                break;
            }
            case 4: {
                RulesPg4(ANCHO_PANTALLA, ALTO_PANTALLA);
                break;
            }
        }
//        // Definir los valores y ponerles nombre a las teclas especiales.
        tecla = getch();
        switch (tecla){
            case FLECHA_IZQ: {
                if (pagina == 1) pagina = 1;
                else --pagina;
                break;
            }
            case FLECHA_DER:{
                if (pagina == 4) pagina = 4;
                else ++pagina;
                break;
            }
        }
    }while(tecla != ENTER);
}

// ****************************************************************************************

void RulesPg1(int x, int y)
{
    MoverCursor(0, 16);
    std::cout << ' ' << (char)BV << "\tINSTRUCCIONES" << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << "\tDESCRIPCI\340N" << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << "\t\t\"Metagato\" es una variaci\242n sobre el tradicional juego del gato, donde "<< std::endl;
    std::cout << ' ' << (char)BV << "\t2 jugadores toman turnos escogiendo una celda de un tablero de 3x3 celdas, " << std::endl;
    std::cout << ' ' << (char)BV << "\tmarcando dicha celda como suya, a traves de un s\241mbolo (una cruz o un c\241rculo)." << std::endl;
    std::cout << ' ' << (char)BV << "\tEn esta variaci\242n, hay un tablero global que consta de 9 tableros locales de " << std::endl;
    std::cout << ' ' << (char)BV << "\t3x3 celdas, acomodadas a su vez en un 3x3 (disponiendo 81 celdas para jugar)." << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << "\t\tLa meta del juego es alinear 3 s\241mbolos de forma vertical, diagonal u " << std::endl;
    std::cout << ' ' << (char)BV << "\thorizontal en un tablero local, para poder reclamarlo como propio. Cuando " << std::endl;
    std::cout << ' ' << (char)BV << "\tun jugador logre alinear, en el tablero global, 3 tableros locales " << std::endl;
    std::cout << ' ' << (char)BV << "\tganados, ese jugador resulta el ganador." << std::endl;

    MoverCursor(x - 6, y - 5);
    std::cout << ">>";

    MoverCursor(2, ALTO_PANTALLA-3);
    std::cout << std::left;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 + 10) << "[IZQUIERA]/[DERECHA] para moverse entre p\240ginas";
    std::cout << std::right;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 - 10) << "[ENTER] para volver al men\243" << std::endl;
}

// ****************************************************************************************

void RulesPg2(int x, int y)
{
    MoverCursor(0, 16);
    std::cout << ' ' << (char)BV << "\tCOMIENZO DEL JUEGO" << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << "\t\tEl Jugador 1 comienza el juego seleccionando cualquiera de las 81 " << std::endl;
    std::cout << ' ' << (char)BV << "\tceldas del tablero global, y marc\240ndolo con su s\241mbolo. Despu\202s, sigue el " << std::endl;
    std::cout << ' ' << (char)BV << "\tturno del jugador 2, cuyas opciones de selecci\242n de celda estar\240n " << std::endl;
    std::cout << ' ' << (char)BV << "\tdelimitadas por la celda que escogi\242 el jugador anterior. El jugador 2 " << std::endl;
    std::cout << ' ' << (char)BV << "\ts\242lo podr\240 jugar en el tablero local correspondiente a la ubicaci\242n " << std::endl;
    std::cout << ' ' << (char)BV << "\tde la celda escogida en el tablero anterior, relativo al tablero global." << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << "\t\tPor ejemplo, si el anterior elige la celda al sureste del " << std::endl;
    std::cout << ' ' << (char)BV << "\tcentro del tablero local, el jugador actual debe jugar en el tablero local " << std::endl;
    std::cout << ' ' << (char)BV << "\tque se encuentra al sureste del centro del tablero global." << std::endl;
    std::cout << ' ' << (char)BV << std::endl;

    MoverCursor(5, y - 5);
    std::cout << "<<";
    MoverCursor(x - 6, y - 5);
    std::cout << ">>";

    MoverCursor(2, ALTO_PANTALLA-3);
    std::cout << std::left;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 + 10) << "[IZQUIERA]/[DERECHA] para moverse entre p\240ginas";
    std::cout << std::right;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 - 10) << "[ENTER] para volver al men\243" << std::endl;
}

// ****************************************************************************************

void RulesPg3(int x, int y)
{
    MoverCursor(9, 15);
    std::cout << "Si el jugador anterior juega esta ";
    MoverCursor(9, 16);
    std::cout << "celda de un tablero local:";

    ImprimirMarcoSimple(20, 24, 7, 7);
    ImprimirRejillaSimple(21, 25, 2, 2, 3, 3);
    MoverCursor(25, 29);
    EstablecerColor(NEGRO, ROJOCLARO);
    std::cout << 'X';

    EstablecerColor(NEGRO, BLANCO);
    MoverCursor((x/2 + 2), 15);
    std::cout << "El siguiente jugador debe jugar en";
    MoverCursor((x/2 + 2), 16);
    std::cout << "cualquier celda disponible de este ";
    MoverCursor((x/2 + 2), 17);
    std::cout << "tablero local (resaltado en amarillo).";
    MoverCursor((x/2 + 2), 18);

    ImprimirTablero((x/2 + 8), 20);
    EstablecerColor(AMARILLOCLARO, NEGRO);
    ImprimirRejillaSimple((x/2 + 21), 33, 2, 2, 3, 3);
    EstablecerColor(NEGRO, BLANCO);

    MoverCursor(5, y - 5);
    std::cout << "<<";
    MoverCursor(x - 6, y - 5);
    std::cout << ">>";

    MoverCursor(2, ALTO_PANTALLA-3);
    std::cout << std::left;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 + 10) << "[IZQUIERA]/[DERECHA] para moverse entre p\240ginas";
    std::cout << std::right;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 - 10) << "[ENTER] para volver al men\243" << std::endl;
}

// ****************************************************************************************

void RulesPg4(int x, int y)
{//Salsa de tomate
    MoverCursor(0, 16);
    std::cout << ' ' << (char)BV << "\t\tEn caso de que el tablero a la cual el jugador fue \"enviado\" " << std::endl;
    std::cout << ' ' << (char)BV << "\tno tenga celdas disponibles para escoger, o ya fue ganado, entonces  " << std::endl;
    std::cout << ' ' << (char)BV << "\tel jugador tiene la libertad de escoger cualquier celda de cualquier " << std::endl;
    std::cout << ' ' << (char)BV << "\ttablero local no ganado." << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << "\t\tEl juego termina una vez que, en el tablero global,  se hayan alineado " << std::endl;
    std::cout << ' ' << (char)BV << "\ttres tableros locales ganados por el mismo jugador, de forma horizontal, " << std::endl;
    std::cout << ' ' << (char)BV << "\tvertical o diagonal. En caso de que no queden m\240s movimientos legales " << std::endl;
    std::cout << ' ' << (char)BV << "\tposibles en el tablero antes de que gane un jugador, entonces el juego " << std::endl;
    std::cout << ' ' << (char)BV << "\ttermina en un empate." << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << std::endl;
    std::cout << ' ' << (char)BV << "\tPulse [ENTER] para regresar al men\243 principal.";

    MoverCursor(5, y - 5);
    std::cout << "<<";

    MoverCursor(2, ALTO_PANTALLA-3);
    std::cout << std::left;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 + 10) << "[IZQUIERA]/[DERECHA] para moverse entre p\240ginas";
    std::cout << std::right;
    std::cout << std::setw((ANCHO_PANTALLA-4)/2 - 10) << "[ENTER] para volver al men\243" << std::endl;
}
////*************************************************************************************************************************
