#include <iostream>
#include <windows.h>
#include "utileria.h"


//****************************************************************************************
void ImprimirMarcoSimple(int x, int y, int anchura, int altura){
    MoverCursor(x, y);
    std::cout << (char)ESI;
    for(int i = 2; i < anchura; ++i) std::cout << (char)BH;
    std::cout << (char)ESD << std::endl;

    for(int i = 2; i < altura; ++i){
        MoverCursor(x, y + i - 1);
        std::cout << (char)BV;
        for(int i = 2; i < anchura; ++i) std::cout << ' ';
        std::cout << (char)BV << std::endl;
    }

    MoverCursor(x, y + altura - 1);
    std::cout << (char)EII;
    for(int i = 2; i < anchura; ++i) std::cout << (char)BH;
    std::cout << (char)EID << std::endl;
}
//****************************************************************************************
void ImprimirRejillaSimple(short x, short y, int ancho_cuadro, int alto_cuadro, int cant_columnas, int cant_filas)
{
    for(int k = 1; k < alto_cuadro*cant_filas; ++k){
        MoverCursor(x, y + k - 1);
        for(int i = 1; i < ancho_cuadro; ++i) std::cout << ' ';
        std::cout << (char)BV;
        for(int j = 2; j < cant_columnas; ++j){
            for(int i = 1; i < ancho_cuadro; ++i) std::cout << ' ';
            std::cout << (char)BV;
        }
        for(int i = 1; i < ancho_cuadro; ++i) std::cout << ' ';
    }

    for(int k = 1; k < cant_filas; ++k){
        MoverCursor(x, y + k*alto_cuadro - 1);
        for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH;
        std::cout << (char)C;
        for(int j = 2; j < cant_columnas; ++j){
            for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH;
            std::cout << (char)C;
        }
        for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH;
    }
}
//****************************************************************************************
void ImprimirCuadriculaDoble(int x, int y, int ancho_cuadro, int alto_cuadro, int cant_columnas, int cant_filas)
{
    MoverCursor(x, y);
    std::cout << (char)ESI_D;
    for(int i = 1; i < cant_columnas; ++i){
        for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH_D;
        std::cout << (char)CSP_D;
    }
    for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH_D;
    std::cout << (char)ESD_D;

    for(int k = 1; k <= alto_cuadro*cant_filas; ++k){
        MoverCursor(x, y + k);
        std::cout << (char)BV_D;
        for(int j = 0; j < cant_columnas; ++j){
            for(int i = 1; i < ancho_cuadro; ++i) std::cout << ' ';
            std::cout << (char)BV_D;
        }
        for(int i = 0; i < ancho_cuadro; ++i) std::cout << ' ';
    }

    for(int k = 1; k < cant_filas; ++k){
        MoverCursor(x, y + k*alto_cuadro);
        std::cout << (char)CI_D;
        for(int j = 1; j < cant_columnas; ++j){
            for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH_D;
            std::cout << (char)C_D;
        }
        for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH_D;
        std::cout << (char)CD_D;
    }

    MoverCursor(x, y + alto_cuadro*cant_filas);
    std::cout << (char)EII_D;
    for(int i = 1; i < cant_columnas; ++i){
        for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH_D;
        std::cout << (char)CIF_D;
    }
    for(int i = 1; i < ancho_cuadro; ++i) std::cout << (char)BH_D;
    std::cout << (char)EID_D;
}
//*************************************************************************************************************************
void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}
//****************************************************************************************
void EstablecerVentana(int ancho, int alto)
{
    _COORD coord;
    coord.X = ancho;
    coord.Y = alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = alto - 1;
    Rect.Right = ancho - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
//****************************************************************************************
void MoverCursor(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x,y};
    SetConsoleCursorPosition(handle,coord);
}
//****************************************************************************************
void CambiarCursor(EstadoCursor estado, ModoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf = {modo, estado};
    SetConsoleCursorInfo(hOut, &ConCurInf);
}
//****************************************************************************************
void EstablecerTitulo(const char * titulo)
{
    SetConsoleTitle(titulo);
}
//*****************************************
