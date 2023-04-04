//
// Created by Usuario on 22/05/2021.
//

#ifndef UNTITLED7_PANTALLAS_H
#define UNTITLED7_PANTALLAS_H

// ****************************************************************************************

/**
 * \brief Imprime la pantilla b�sica para todas las pantallas
 *
 * \details Imprime el t�tulo del juego, el marco simple que delimita el borde de la pantalla
 *          y posiciona el cursor hasta arriba para posicionar correctamente la plantilla.
 *
 * \return void
 *
 */
void ImprimirPlantilla();

// ****************************************************************************************

/**
 * \brief Inicia la plantilla men�.
 *
 * \details Inicia la plantilla b�sica de la pantalla men� donde se pueden acceder a las
 *          otras pantallas.
 *
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param dec int Entero que representa la decisi�n de opciones en el men�.
 *
 * \return void
 *
 */
void Menu(Colores &Tema, int dec);

// ****************************************************************************************

/**
 * \brief Captura segura de los nombres de los jugadores.
 *
 * \details Funci�n que imprime una plantilla donde se pide el nombre de los jugadores tal
 *          que la cantidad de caracteres sea mayor que 1 y menor que 11.
 *
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param nombre Nombres Estructura que contiene a los nombres de los jugadores.
 *
 * \return void
 *
 */
void PedirNombre1(Colores tema, Nombres &jugador);

void PedirNombre2(Colores tema, Nombres &jugador);

// ****************************************************************************************

/**
 * \brief Inicio de una partida del juego Metagato.
 *
 * \details Dentro de aqu� se encuentra el c�digo principal del juego donde se desarrolla
 *          una partida del Metagato en la que por turnos cada jugador va poniendo sus simbolos
 *          en el tablero seg�n las reglas del juego hasta que un jugador gane.
 *
 * \param tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param nombre Nombres Estructura que contiene a los nombres de los jugadores.
 *
 * \return void
 *
 */
void Juego(Colores tema, Nombres nombre);

// ****************************************************************************************

/**
 * \brief Inicia la pantalla de configuraci�n.
 *
 * \details Dentro de esta funci�n se inicia la selecci�n de los temas de los jugadores.
 *
 * \param &Tema Colores Estructura que contiene los conjuntos de colores para los jugadores.
 * \param tecla int Variable que representa la tecla presionada por el usuario.
 *
 * \return void
 *
 */
void Configuracion(Colores &Tema, int tecla);

// ****************************************************************************************

/**
 * \brief Imprime una pantalla con los cr�ditos del programa
 *
 * \details Muestra el prop�sito del programa, los nombres de los desarrolladores
 *
 * \param tecla int Variable que si se eval�a como 13 (ENTER) cierra la pantalla.
 *
 * \return void
 *
 */
void Creditos(int tecla);

// ****************************************************************************************

/**
 * \brief Funci�n que imprime las pantallas que muestran las instrucciones del juego.
 *
 * \details Permite desplazarse a traves de las pantallas utilizando las teclas left y right.
 *
 * \param tecla int Variable que representa la tecla presionada por el usuario.
 *
 * \return void
 *
 */
void Instrucciones(int tecla);

// ****************************************************************************************

/**
 * \brief Imprime las instrucciones que pertenecen a la primera pantalla.
 *
 * \details Describe el juego y las metas del juego.
 *
 * \param x La coordenada en el eje x para imprimir las instrucciones.
 * \param y La coordenada en el eje y para imprimir las instrucciones.
 *
 * \return void
 *
 */
void RulesPg1(int x, int y);

// ****************************************************************************************

/**
 * \brief Imprime las instrucciones que pertenecen a la segunda pantalla.
 *
 * \details Explica el comienzo del juego, c�mo se juegan las celdas, y la
 *          din�mica de los turnos.
 *
 * \param x La coordenada en el eje x para imprimir las instrucciones.
 * \param y La coordenada en el eje y para imprimir las instrucciones.
 *
 * \return void
 *
 */
void RulesPg2(int x, int y);

// ****************************************************************************************

/**
 * \brief Imprime las instrucciones que pertenecen a la tercera pantalla.
 *
 * \details Muestra gr�ficamente un ejemplo de las reglas para escoger una celda,
 *          despues del primer turno.
 *
 * \param x La coordenada en el eje x para imprimir las instrucciones.
 * \param y La coordenada en el eje y para imprimir las instrucciones.
 *
 * \return void
 *
 */
void RulesPg3(int x, int y);

// ****************************************************************************************

/**
 * \brief Imprime las instrucciones que pertenecen a la cuarta y �ltima pantalla
 *
 * \details Explica la condici�n para que el juego acabe.
 *
 * \param x La coordenada en el eje x para imprimir las intrucciones.
 * \param y La coordeada en el eje y para imprimir las instrucciones.
 *
 * \return void
 *
 */
void RulesPg4(int x, int y);

// ****************************************************************************************

#endif //UNTITLED7_PANTALLAS_H
