//
// Created by Usuario on 22/05/2021.
//

#ifndef UNTITLED7_DISENO_H
#define UNTITLED7_DISENO_H
#include "Constantes y estructuras.h"

// ****************************************************************************************

/**
 * \brief Función que imprime los símbolos del jugador en el tablero
 *
 * \details Dependiendo del turno del jugador, y del color que escogió para representarlo,
 *          la función imprime el símbolo correspondiente al jugador en la celda indicada
 *          por el jugador.
 *
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param tablero Tablero Estructura que contiene la información de los cuadrantes como
 *                 los ganadores de cada uno, sus límites, etcétera.
 *
 * \return void
 */
void ImprimirSimbolo(Colores tema, Tablero tablero);

// ****************************************************************************************

/**
 * \brief Pinta el cuadrante
 *
 * \details Rellena los lugares donde se imprimían simbolos con espacios con el fondo de
 *          color dependiendo del resultado del juego en ese cuadrante.
 *
 * \param jugador int Valor que indica el jugador ganador del cuadrante.
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param indice_cuadrante int Número que representa a un cuadrante del tablero en un
 *                             arreglo unidimensional.
 *
 * \return void
 *
 */
void PintarCuadrante(int jugador, Colores tema, int indice_cuadrante);

// ****************************************************************************************

/**
 * \brief Rellena el arreglo.
 *
 * \details Rellena los lugares donde se imprimían simbolos con el valor de los simbolos
 *          del resultado del juego en ese cuadrante.
 *
 * \param jugador int Valor que indica el jugador ganador del cuadrante.
 * \param T[] int Arreglo que contiene las casillas de un cuadrante.
 *
 * \return void
 *
 */
void RellenarCuadrante(int jugador, int T[]);

// ****************************************************************************************

/**
 * \brief Imprime el indicador de turno
 *
 * \details Abajo del tablero de juego imprime un indicador con los nombres de los
 *          jugadores, marcando con color al jugador del turno actual y en gris al otro.
 *
 * \param jugador int Valor que indica el jugador actual.
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param nombre Nombres Estructura que contiene a los nombres de los jugadores.
 *
 * \return void
 *
 */
void ImprimirTurno(int jugador, Colores tema, Nombres nombre);

// ****************************************************************************************

/**
 * \brief Imprime el resultado del juego.
 *
 * \details Imprime el cuadro que anuncia el fin de la partida en el cual se imprimirá el
 *          mensaje del color del jugador ganador y el nombre de este.
 *
 * \param jugador int Dependiendo del valor, indica al jugador ganador.
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param nombre Nombres Estructura que contiene a los nombres de los jugadores.
 *
 * \return void
 *
 */
void ImprimirCuadroMensaje(int jugador, Colores tema, Nombres nombre);

// ****************************************************************************************

/**
 * \brief Imprime el tablero del juego
 *
 * \details Esta función construye la plantilla base del tablero del juego sobre la cual
 *          se imprimen los símbolos que representan a los jugadores.
 *
 * \param x Posición horizontal a donde se moverá el cursor. El cursor se
 *          mueve \b x unidades a la derecha a partir del inicio de la ventana.
 * \param y Posición vertical a donde se moverá el cursor. El cursor se mueve
 *          \b y unidades hacia abajo a partir del inicio de la ventana.
 *
 * \return void
 *
 */
void ImprimirTablero(int x, int y);

// ****************************************************************************************

/**
 * \brief Imprime el titulo del juego, con un formato especial.
 *
 * \details Imprime cada linea del texto del titulo con un color especifico, en una posición
 *          determinada por las coordenadas indicadas en los parámetros.
 *
 * \param x La coordenada en el eje x de la consola
 * \param y La coordenada en el eje y de la consola
 *
 * \return void
 *
 */
void ImprimirTitulo(int x, int y);

// ****************************************************************************************

/**
 * \brief Imprime las opciones para la navegación del juego, en la pantalla principal.
 *
 * \details Incluye las secciones de "Jugar", "Configuración", "Instrucciones",
 *          "Créditos" y "Salir".
 *
 * \return void
 *
 */
void ImprimirMenu();

// ****************************************************************************************

/**
 * \brief Seleccion en el cuadro del fin de la partida
 *
 * \details Permite seleccionar entre las dos opciones mediante las teclas [ARRIBA] y
 *          [ABAJO] utilizando [ENTER] para confirmar la selección.
 *
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param nombre Nombres Estructura que contiene a los nombres de los jugadores.
 *
 * \return void
 *
 */
void SeleccionFin(Colores tema, Nombres nombre);

// ****************************************************************************************

/**
 * \brief Menú de la pantalla principal
 *
 * \details Es la función que indica en que opción del menú se encuentra actualmente el
 *          usuario.
 *
 * \param dec int Entero que representa la decisión de opciones en el menú.
 *
 * \return void
 *
 */
void SeleccionMenu(int dec);

// ****************************************************************************************

/**
 * \brief Establece el tema actual de colores de los jugadores
 *
 * \details Es la función que indica en que opción de los temas se encuentra actualmente
 *          el usuario.
 *
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 *
 * \return void
 *
 */
void Jugadores(Colores &Tema);

// ****************************************************************************************

/**
 * \brief Función que genera una serie corta de tonos, al comienzo del programa
 *
 * \return void
 */
void MelodiaIntro();


/**
 * \brief Función que genera una serie corta de tonos festivos
 *
 * \return void
 */
void MelodiaGanadora();



#endif //UNTITLED7_DISENO_H
