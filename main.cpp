#include "Utileria.h"
#include "Diseno.h"
#include "Pantallas.h"
#include "Constantes y estructuras.h"

int main()
{

    EstablecerColor(NEGRO, BLANCO);
    CambiarCursor(APAGADO, NORMAL);
    EstablecerTitulo("Metagato");
    EstablecerVentana(ANCHO_PANTALLA, ALTO_PANTALLA);
    int dec = 1;
    Colores Tema;
    ImprimirMarcoSimple (1, 1, ANCHO_PANTALLA-2, ALTO_PANTALLA-2);
    ImprimirTitulo((ANCHO_PANTALLA-75)/2, 4);
    MelodiaIntro();
    Menu(Tema, dec);
}
