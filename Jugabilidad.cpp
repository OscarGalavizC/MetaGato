//
// Created by Usuario on 22/05/2021.
//
#include "conio.h"
#include "Jugabilidad.h"
#include "Constantes y estructuras.h"

////*************************************************************************************************************************
int ComprobarGanador(int T[])
{
    int ganador = VACIO;

    for(int i = 0; i < 9; i += 3)
        if(T[i] == T[i+1] && T[i+1] == T[i+2] && T[i] != VACIO && T[i] != EMPATE){
            ganador = T[i]; //0,1,2;  3,4,5;  6,7,8
            break;
        }
    for(int i = 0; i < 3; ++i)
        if(T[i] == T[i+3] && T[i+3] == T[i+6] && T[i] != VACIO && T[i] != EMPATE){
            ganador = T[i]; //0,3,6;  1,4,7;  2,5,8
            break;
        }
    if(T[0] == T[4] && T[4] == T[8] && T[0] != EMPATE) ganador = T[0];
    if(T[2] == T[4] && T[4] == T[6] && T[2] != EMPATE) ganador = T[2];

    if(ganador == VACIO){
        ganador = EMPATE;
        for(int i = 0; i < 9; ++i){
            if(T[i] == VACIO){
                ganador = VACIO;
                break;
            }
        }
    }

    return ganador;
}
////*************************************************************************************************************************
void SeleccionRestringida(int turno, Tablero &tablero)
{
    int x = tablero.cuadrante[tablero.indice_actual].lim_izq + 2;
    int y = tablero.cuadrante[tablero.indice_actual].lim_sup + 2;
    int i, j, tecla;

    MoverCursor(x, y);

    while(true){
        tecla = getch();
        if(y > tablero.cuadrante[tablero.indice_actual].lim_sup && tecla == FLECHA_ARRIBA) MoverCursor(x, ----y);
        if(x > tablero.cuadrante[tablero.indice_actual].lim_izq && tecla == FLECHA_IZQ) MoverCursor(----x, y);
        if(x < tablero.cuadrante[tablero.indice_actual].lim_der && tecla == FLECHA_DER) MoverCursor(++++x, y);
        if(y < tablero.cuadrante[tablero.indice_actual].lim_inf && tecla == FLECHA_ABAJO) MoverCursor(x, ++++y);
        if(tecla == ENTER){
            i = ((x - POSX_ORIGEN)/2)/3 + 3*(((y - POSY_ORIGEN)/2)/3);
            j = ((x - POSX_ORIGEN)/2)%3 + 3*(((y - POSY_ORIGEN)/2)%3);
            if(tablero.cuadrante[i].casilla[j] == VACIO){
                tablero.cuadrante[i].casilla[j] = turno;
                break;
            }
        }
    }
    tablero.indice_actual = i;
    tablero.indice_proximo = j;
}
////*************************************************************************************************************************
void SeleccionLibre(int turno, Tablero &tablero)
{
    int x = POSX_ORIGEN + 8;
    int y = POSY_ORIGEN + 8;
    int i, j, tecla;

    MoverCursor(x, y);

    while(true){
        tecla = getch();
        if(y > MINREN && tecla == FLECHA_ARRIBA) MoverCursor(x, ----y);
        if(x > MINCOL && tecla == FLECHA_IZQ) MoverCursor(----x, y);
        if(x < MAXCOL && tecla == FLECHA_DER) MoverCursor(++++x, y);
        if(y < MAXREN && tecla == FLECHA_ABAJO) MoverCursor(x, ++++y);
        if(tecla == ENTER){
            i = ((x - POSX_ORIGEN)/2)/3 + 3*(((y - POSY_ORIGEN)/2)/3);
            j = ((x - POSX_ORIGEN)/2)%3 + 3*(((y - POSY_ORIGEN)/2)%3);
            if(tablero.cuadrante[i].casilla[j] == VACIO){
                tablero.cuadrante[i].casilla[j] = turno;
                break;
            }
        }
    }
    tablero.indice_actual = i;
    tablero.indice_proximo = j;
}
//*************************************************************************************************************************
