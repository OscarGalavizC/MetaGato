//
// Created by Usuario on 22/05/2021.
//
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "Diseno.h"
#include "Pantallas.h"
#include "Constantes y estructuras.h"

//****************************************************************************************
void ImprimirPlantilla()
{
    ImprimirMarcoSimple(1,1, ANCHO_PANTALLA-2, ALTO_PANTALLA-2);
    MoverCursor(0, 0);
    ImprimirTitulo((ANCHO_PANTALLA-75)/2, 4);
}
//****************************************************************************************
void SeleccionMenu(int dec)
{
    // Borrar flechas en "Jugar"
    MoverCursor((ANCHO_PANTALLA-13)/2+2, ALTO_PANTALLA-24);
    std::cout << ' ';
    MoverCursor((ANCHO_PANTALLA-13)/2+10, ALTO_PANTALLA-24);
    std::cout << ' ';

    // Borrar flechas en "Configuracion"
    MoverCursor((ANCHO_PANTALLA-13)/2-2, ALTO_PANTALLA-20);
    std::cout << ' ';
    MoverCursor((ANCHO_PANTALLA-13)/2+14, ALTO_PANTALLA-20);
    std::cout << ' ';

    // Borrar flechas en "Instrucciones"
    MoverCursor((ANCHO_PANTALLA-13)/2-2, ALTO_PANTALLA-16);
    std::cout << ' ';
    MoverCursor((ANCHO_PANTALLA-13)/2+14, ALTO_PANTALLA-16);
    std::cout << ' ';

    // Borrar flechas en "Creditos"
    MoverCursor((ANCHO_PANTALLA-13)/2+1, ALTO_PANTALLA-12);
    std::cout << ' ';
    MoverCursor((ANCHO_PANTALLA-13)/2+12, ALTO_PANTALLA-12);
    std::cout << ' ';

    // Borrar flechas en "Salir"
    MoverCursor((ANCHO_PANTALLA-13)/2+2, ALTO_PANTALLA-8);
    std::cout << ' ';
    MoverCursor((ANCHO_PANTALLA-13)/2+10, ALTO_PANTALLA-8);
    std::cout << ' ';

    switch (dec) {
        case 1: {       // Impresión en "Jugar"
            MoverCursor((ANCHO_PANTALLA-13)/2+2, ALTO_PANTALLA-24);
            std::cout << '\257';
            MoverCursor((ANCHO_PANTALLA-13)/2+10, ALTO_PANTALLA-24);
            std::cout << '\256';
            break;
        }

        case 2: {       // Impresión en "Opciones"
            MoverCursor((ANCHO_PANTALLA-13)/2-2, ALTO_PANTALLA-20);
            std::cout << '\257';
            MoverCursor((ANCHO_PANTALLA-13)/2+14, ALTO_PANTALLA-20);
            std::cout << '\256';
            break;
        }

        case 3: {       // Impresión en "Instrucciones"
            MoverCursor((ANCHO_PANTALLA-13)/2-2, ALTO_PANTALLA-16);
            std::cout << '\257';
            MoverCursor((ANCHO_PANTALLA-13)/2+14, ALTO_PANTALLA-16);
            std::cout << '\256';
            break;
        }

        case 4: {       // Impresión en "Creditos"
            MoverCursor((ANCHO_PANTALLA-13)/2+1, ALTO_PANTALLA-12);
            std::cout << '\257';
            MoverCursor((ANCHO_PANTALLA-13)/2+12, ALTO_PANTALLA-12);
            std::cout << '\256';
            break;
        }
        case 5: {       // Impresión en "Salir"
            MoverCursor((ANCHO_PANTALLA-13)/2+2, ALTO_PANTALLA-8);
            std::cout << '\257';
            MoverCursor((ANCHO_PANTALLA-13)/2+10, ALTO_PANTALLA-8);
            std::cout << '\256';
            break;
        }
    }
}
//****************************************************************************************

void SeleccionFin(Colores tema, Nombres nombre)
{
    int dec2 = 1, tecla;
    // Imprime los símbolos que delimitan la selección,
    // a la izquierda y a la derecha de la opción
    MoverCursor((ANCHO_PANTALLA - 14) / 2 - 3, ALTO_PANTALLA / 2 + 5);
    std::cout << '\257';
    MoverCursor((ANCHO_PANTALLA + 14) / 2 + 2, ALTO_PANTALLA / 2 + 5);
    std::cout << '\256';
    do {
        tecla=getch();
        if (tecla == FLECHA_ARRIBA || tecla == FLECHA_ABAJO) {
            Beep(440, 100);
            if (dec2 == 1) dec2 = 2;
            else dec2 = 1;
        }
        // Borrar flechas en "Jugar otra vez"
        MoverCursor((ANCHO_PANTALLA - 14) / 2 - 3, ALTO_PANTALLA / 2 + 5);
        std::cout << ' ';
        MoverCursor((ANCHO_PANTALLA + 14) / 2 + 2, ALTO_PANTALLA / 2 + 5);
        std::cout << ' ';


        // Borrar flechas en "Regresar al menú"
        MoverCursor((ANCHO_PANTALLA - 16) / 2 - 3, ALTO_PANTALLA / 2 + 8);
        std::cout << ' ';
        MoverCursor((ANCHO_PANTALLA + 16) / 2 + 2, ALTO_PANTALLA / 2 + 8);
        std::cout << ' ';

        switch (dec2) {
            case 1: {       // Impresión en "Jugar otra vez"
                MoverCursor((ANCHO_PANTALLA - 14) / 2 - 3, ALTO_PANTALLA / 2 + 5);
                std::cout << '\257';
                MoverCursor((ANCHO_PANTALLA + 14) / 2 + 2, ALTO_PANTALLA / 2 + 5);
                std::cout << '\256';
                break;
            }

            case 2: {       // Impresión en "Regresar al menú"
                MoverCursor((ANCHO_PANTALLA - 16) / 2 - 3, ALTO_PANTALLA / 2 + 8);
                std::cout << '\257';
                MoverCursor((ANCHO_PANTALLA + 16) / 2 + 2, ALTO_PANTALLA / 2 + 8);
                std::cout << '\256';
                break;
            }
        }
    }while(tecla != ENTER);
    Beep(880, 70);
    if (dec2 == 1){
        ImprimirPlantilla();
        Juego(tema, nombre);
    }
    else{
        dec2 = 1;
        Menu(tema, dec2);
    }
}
//****************************************************************************************


void Jugadores(Colores &Tema)
{
    // Borrar  en "Jugar otra vez"
    MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-23);
    std::cout << "         ";
    MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-23);
    std::cout << "         ";

    // Borrar flechas en "Opciones"
    MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-20);
    std::cout << "         ";
    MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-20);
    std::cout << "         ";

    // Borrar flechas en "Instrucciones"
    MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-17);
    std::cout << "         ";
    MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-17);
    std::cout << "         ";

    // Borrar flechas en "Creditos"
    MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-14);
    std::cout << "         ";
    MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-14);
    std::cout << "         ";
    switch (Tema.par_de_colores) {
        case 1: {       // Impresión en "Jugar"
            Tema.COLOR1 = ROJOCLARO;
            Tema.COLOR2 = AZULCLARO;
            MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-23);
            EstablecerColor(NEGRO, Tema.COLOR1);
            std::cout << "Jugador 1";
            MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-23);
            EstablecerColor(NEGRO, Tema.COLOR2);
            std::cout << "Jugador 2";
            break;
        }

        case 2: {       // Impresión en "Opciones"
            Tema.COLOR1 = AMARILLOCLARO;
            Tema.COLOR2 = AGUAMARINACLARO;
            MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-20);
            EstablecerColor(NEGRO, Tema.COLOR1);
            std::cout << "Jugador 1";
            MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-20);
            EstablecerColor(NEGRO, Tema.COLOR2);
            std::cout << "Jugador 2";
            break;
        }

        case 3: {       // Impresión en "Instrucciones"
            Tema.COLOR1 = MAGENTA;
            Tema.COLOR2 = VERDECLARO;
            MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-17);
            EstablecerColor(NEGRO, Tema.COLOR1);
            std::cout << "Jugador 1";
            MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-17);
            EstablecerColor(NEGRO, Tema.COLOR2);
            std::cout << "Jugador 2";
            break;
        }

        case 4: {       // Impresión en "Creditos"
            Tema.COLOR1 = GRISCLARO;
            Tema.COLOR2 = GRISCLARO;
            MoverCursor(ANCHO_PANTALLA/2-14, ALTO_PANTALLA-14);
            EstablecerColor(NEGRO, Tema.COLOR1);
            std::cout << "Jugador 1";
            MoverCursor(ANCHO_PANTALLA/2+5, ALTO_PANTALLA-14);
            EstablecerColor(NEGRO, Tema.COLOR2);
            std::cout << "Jugador 2";
            break;
        }
    }
}

// ****************************************************************************************
void ImprimirSimbolo(Colores tema, Tablero tablero)
{
    MoverCursor(POSX_ORIGEN + 2*(tablero.indice_proximo%3 + 3*(tablero.indice_actual%3)), POSY_ORIGEN + 2*(tablero.indice_proximo/3 + 3*(tablero.indice_actual/3)));

    if(tablero.cuadrante[tablero.indice_actual].casilla[tablero.indice_proximo] == JUGADOR1){
        EstablecerColor(COLORFONDO, tema.COLOR1);
        std::cout << 'X';
    }
    if(tablero.cuadrante[tablero.indice_actual].casilla[tablero.indice_proximo] == JUGADOR2){
        EstablecerColor(COLORFONDO, tema.COLOR2);
        std::cout << 'O';
    }

    EstablecerColor(COLORFONDO, COLORLETRA);
}
// ****************************************************************************************
void ImprimirCuadroMensaje(int jugador, Colores tema, Nombres nombre)
{
    ImprimirMarcoSimple((ANCHO_PANTALLA-29)/2,(ALTO_PANTALLA-8)/2,29,17);


    if(jugador == JUGADOR1){
        MoverCursor((ANCHO_PANTALLA-14-nombre.jugador1.length())/2,ALTO_PANTALLA/2 - 2);
        EstablecerColor(NEGRO, tema.COLOR1);
        std::cout << std::right;
        std::cout << "\255Felicidades " << nombre.jugador1 << "!";
        MoverCursor((ANCHO_PANTALLA-7)/2,ALTO_PANTALLA/2 + 1);
        std::cout << "GANASTE";
        MelodiaGanadora();
    }else if(jugador == JUGADOR2){
        MoverCursor((ANCHO_PANTALLA-14-nombre.jugador2.length())/2,ALTO_PANTALLA/2 - 2);
        EstablecerColor(NEGRO, tema.COLOR2);
        std::cout << std::right;
        std::cout << "\255Felicidades " << nombre.jugador2 << "!";
        MoverCursor((ANCHO_PANTALLA-7)/2,ALTO_PANTALLA/2 + 1);
        std::cout << "GANASTE";
        MelodiaGanadora();
    }else{
        MoverCursor((ANCHO_PANTALLA-23)/2,ALTO_PANTALLA/2 - 2);
        EstablecerColor(NEGRO, GRISCLARO);
        std::cout << "La partida ha terminado";
        MoverCursor((ANCHO_PANTALLA-10)/2,ALTO_PANTALLA/2 + 1);
        std::cout << "en empate.";
    }

    EstablecerColor(NEGRO,BLANCO);
    MoverCursor((ANCHO_PANTALLA-14)/2,ALTO_PANTALLA/2 + 5);
    std::cout << "Jugar otra vez";
    MoverCursor((ANCHO_PANTALLA-16)/2,ALTO_PANTALLA/2 + 8);
    std::cout << "Regresar al men\243";
}
//****************************************************************************************
void PintarCuadrante(int jugador, Colores tema, int indice_cuadrante)
{
    if(jugador == JUGADOR1) EstablecerColor(tema.COLOR1, NEGRO);
    else if(jugador == JUGADOR2) EstablecerColor(tema.COLOR2, NEGRO);
    else EstablecerColor(BLANCO, NEGRO);
    ImprimirRejillaSimple(POSX_ORIGEN + 6*(indice_cuadrante%3), POSY_ORIGEN + 6*(indice_cuadrante/3),2,2,3,3);
    EstablecerColor(NEGRO, BLANCO);
}
//****************************************************************************************
void RellenarCuadrante(int jugador, int T[])
{
    for(int k = 0; k < 9; ++k) T[k] = jugador;
}
//****************************************************************************************
void ImprimirTurno(int jugador, Colores tema, Nombres nombre)
{
    EstablecerColor(NEGRO,GRIS);
    if(jugador == JUGADOR1) EstablecerColor(NEGRO,tema.COLOR1);
    MoverCursor(ANCHO_PANTALLA/2 - 15, ALTO_PANTALLA-6);
    std::cout << std::right;
    std::cout << std::setw(10) << nombre.jugador1;

    EstablecerColor(NEGRO,GRIS);
    if(jugador == JUGADOR2) EstablecerColor(NEGRO,tema.COLOR2);
    MoverCursor(ANCHO_PANTALLA/2 + 4, ALTO_PANTALLA-6);
    std::cout << std::left;
    std::cout << std::setw(10) << nombre.jugador2;
    EstablecerColor(NEGRO,COLORLETRA);
}
//****************************************************************************************
void ImprimirTablero(int x, int y)
{
    ImprimirCuadriculaDoble(x,y,6,6,3,3);

    for(int j = 0; j < 3; ++j){
        for(int i = 0; i < 3; ++i){
            ImprimirRejillaSimple(x + 1 + i*6, y + 1 + j*6,2,2,3,3);
        }
    }
}
//****************************************************************************************
void ImprimirTitulo(int x, int y)
{
    EstablecerColor(COLORFONDO,ROJO);
    MoverCursor(x, y);
    std::cout << "                        \334\333\337                                   \334\333\337          " << std::endl;
    EstablecerColor(COLORFONDO,ROJO);
    MoverCursor(x, y+1);
    std::cout << "                     \334\333\333\333\333\333\333\337                              \334\333\333\333\333\333\333\337        " << std::endl;
    EstablecerColor(COLORFONDO,ROJO);
    MoverCursor(x, y+2);
    std::cout << "  \337\333\334\333\333\334 \334\333\333\334  \334\333\333\333\333\334  \333\333     \334\333\333\333\334\333\334   \334\333\333\333\334\333\334   \334\333\333\333\334\333\334    \333\333     \334\333\333\333\333\334 " << std::endl;
    EstablecerColor(COLORFONDO,AMARILLO);
    MoverCursor(x, y+3);
    std::cout << "  \334\333\337  \337\333\337 \337\333 \334\333\334__\334\337  \333\333    \334\333\337  \337\333\333  \334\333\337  \337\333\333  \334\333\337  \337\333\333    \333\333    \334\333\337  \337\333\333" << std::endl;
    EstablecerColor(COLORFONDO,VERDE);
    MoverCursor(x, y+4);
    std::cout << " \334\333\333  \334\333\333  \333\333 \333\333\334      \333\333\334   \333\333\334  _\333\333\334 \333\333\334  _\333\333\334 \333\333\334  _\333\333\334   \333\333\334   \333\333\334  \334\333\333" << std::endl;
    EstablecerColor(COLORFONDO,AZUL);
    MoverCursor(x, y+5);
    std::cout << "\334\333\333  \334\333\333   \333\333\334 \337\333\333\333\337    \337\333\334   \337\333\333\337  \333\333\334 \337\333\333\337  \333\333\334 \337\333\333\337  \333\333\334   \337\333\334   \337\333\333\333\333\337 " << std::endl;
    EstablecerColor(COLORFONDO,AZUL);
    MoverCursor(x, y+6);
    std::cout << "                                               \333\333                          " << std::endl;
    EstablecerColor(COLORFONDO,PURPURA);
    MoverCursor(x, y+7);
    std::cout << "                                              \333\333\337                          " << std::endl;
    EstablecerColor(COLORFONDO,PURPURA);
    MoverCursor(x, y+8);
    std::cout << "                                          \337\333\333\333\333\337                           " << std::endl;

    EstablecerColor(COLORFONDO, COLORLETRA);
}
//****************************************************************************************
void ImprimirMenu()
{
    MoverCursor((ANCHO_PANTALLA-13)/2+4, ALTO_PANTALLA-24);
    std::cout << "JUGAR";
    MoverCursor((ANCHO_PANTALLA-13)/2, ALTO_PANTALLA-20);
    std::cout << "CONFIGURACI" << char(224) << "N";
    MoverCursor((ANCHO_PANTALLA-13)/2, ALTO_PANTALLA-16);
    std::cout << "INSTRUCCIONES";
    MoverCursor((ANCHO_PANTALLA-13)/2+3, ALTO_PANTALLA-12);
    std::cout << "CR" << char(144) << "DITOS";
    MoverCursor((ANCHO_PANTALLA-13)/2+4, ALTO_PANTALLA-8);
    std::cout << "SALIR";
}
//****************************************************************************************

void MelodiaIntro()
{
    Beep(1864, 100);
    Beep(1760, 100);
    Beep(1567, 100);
    Beep(2093, 100);
    Beep(1396, 100);
    Beep(2093, 100);
    Beep(2793, 175);
    Sleep(700);
}

//****************************************************************************************

void MelodiaGanadora()
{
    Beep(1046, 60);
    Beep(1396, 60);
    Beep(1760, 60);
    Beep(2093, 180);
    Beep(2093, 120);
    Beep(1864, 60);
    Beep(2093, 400);
}
