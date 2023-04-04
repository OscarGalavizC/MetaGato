//
// Created by Usuario on 22/05/2021.
//

#ifndef UNTITLED7_CONSTANTES_Y_ESTRUCTURAS_H
#define UNTITLED7_CONSTANTES_Y_ESTRUCTURAS_H

#include "Utileria.h"
#include <string>

#define COLORFONDO NEGRO
#define COLORLETRA BLANCO

#define ANCHO_PANTALLA 92
#define ALTO_PANTALLA 42

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ENTER 13

#define MINCOL 37
#define MINREN 17
#define MAXCOL MINCOL + 16
#define MAXREN MINREN + 16

#define POSX_ORIGEN 37
#define POSY_ORIGEN 17

#define VACIO 0
#define JUGADOR1 1
#define JUGADOR2 2
#define EMPATE 3

//****************************************************************************************
/** \brief Información de límites y casillas de un cuadrante
 */
struct Cuadrante{
    int casilla[9] = {VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO};
    int lim_sup, lim_izq, lim_inf, lim_der;
};

//****************************************************************************************
/** \brief Información de ganadores de cuadrantes, cuadrantes en sí e indices.
 */
struct Tablero{
    Cuadrante cuadrante[9];
    int indice_actual, indice_proximo;
    int ganador_cuadrante[10] = {VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,JUGADOR1};
    int ganador = VACIO;
};

//****************************************************************************************
/** \brief Colores actuales de los jugadores segun el tema seleccionado
 */
struct Colores
{
    int par_de_colores = 1;
    Color COLOR1 = ROJOCLARO;
    Color COLOR2 = AZULCLARO;

};

//****************************************************************************************
/** \brief Nombre de los jugadores según aquellos capturados
 */
struct Nombres
{
    std::string jugador1 = "Jugador 1";
    std::string jugador2 = "Jugador 2";
};

//****************************************************************************************

#endif //UNTITLED7_CONSTANTES_Y_ESTRUCTURAS_H
