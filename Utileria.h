#ifndef UNTITLED5_UTILERIA_H
#define UNTITLED5_UTILERIA_H

//****************************************************************************************

/**
 * \brief Mueve el cursor en la ventana de despliegue a la posición indicada
 *
 * \details Las posiciones de la ventana de despliegue inician con (0,0) en la
 * esquina superior izquierda. Podría decirse que la posición \b x indica la
 * columna de la ventana y la posición \b y indica el renglón, ambas iniciando
 * en cero.
 *
 * \param x Posición horizontal a donde se moverá el cursor. El cursor se
 *          mueve \b x unidades a la derecha a partir del inicio de la ventana.
 * \param y Posición vertical a donde se moverá el cursor. El cursor se mueve
 *          \b y unidades hacia abajo a partir del inicio de la ventana.
 *
 * \return Nada
 *
 * \warning Si alguna posición se sale de los límites de la ventana de
 *          despliegue, el cursor no se moverá.
 */
void ImprimirMarcoSimple(int x, int y, int anchura, int altura);

//****************************************************************************************
/** \brief Caracteres simples de esquinas, barras y cruces.
 */
enum{
     BV = 179,      /**< Barra vertical */
     CD,            /**< Cruce derecho */
     ESD = 191,     /**< Esquina Superior Derecha */
     EII,           /**< Esquina Inferior Izquierda */
     CIF,           /**< Cruce Inferior */
     CSP,           /**< Cruce Superior */
     CI,            /**< Cruce Inferior */
     BH = 196,      /**< Barra Horizontal */
     C,             /**< Cruce central */
     EID = 217,     /**< Esquina Inferior Derecha */
     ESI            /**< Esquina Superior  Izquierda */
};

/**
 * \brief Imprime una rejilla simple
 *
 * \details Imprime una cuadrícula sin borde indicando el ancho y alto de cada cuadro que lo conforma,
 *          la posición x e y de la esquina superior izquierda y los cuadros que conforman el ancho y
 *          alto de la rejilla.
 *
 * \param x short Posición horizontal con respecto al borde izquierdo de la pantalla de la esquina
 *                superior derecha de la rejilla.
 * \param y short Posición vertical con respecto al borde superior de la pantalla de la esquina
 *                superior derecha de la rejilla.
 * \param ancho_cuadro int Ancho en espacos de caracteres de los cuadros de la rejilla.
 * \param alto_cuadrol int Alto en espacos de caracteres de los cuadros de la rejilla.
 * \param cant_columnas int Cantidad de cuadros que conforman el ancho de la rejilla.
 * \param cant_filas int Cantidad de cuadros que conforman el alto de la rejilla.
 *
 * \return void
 *
 */
void ImprimirRejillaSimple(short x, short y, int ancho_cuadro, int alto_cuadro, int cant_columnas, int cant_filas);

//****************************************************************************************
/** \brief Caracteres dobles de esquinas, barras y cruces.
 */
enum{
    CD_D = 185,     /**< Cruce Derecho Doble */
    BV_D,           /**< Barra Verical Doble */
    ESD_D,          /**< Esquina Superior Derecha Doble */
    EID_D,          /**< Esquina Inferior Derecha Doble */
    EII_D = 200,    /**< Esquina Inferior Izquierda Doble */
    ESI_D,          /**< Esquina Superior Izquierda Doble */
    CIF_D,          /**< Cruce Inferior Doble */
    CSP_D,          /**< Cruce Suoerior Doble */
    CI_D,           /**< Cruce Izquierdo Doble */
    BH_D,           /**< Barra Horizontal Doble */
    C_D             /**< Cruce Derecho Doble */
};

/**
 * \brief Imprimir cuadricula con linea doble
 *
 * \details Imprime una cuadricula doble indicando la posición x e y de la esquina superios izquierda,
 *          el ancho y alto de cada cuadro y la cantidad de cuadros que conforman el ancho y alto de
 *          cuadrícula.
 *
 * \param x short Posición horizontal con respecto al borde izquierdo de la pantalla de la esquina
 *                superior derecha de la cuadrícula.
 * \param y short Posición vertical con respecto al borde superior de la pantalla de la esquina
 *                superior derecha de la cuadricula.
 * \param ancho_cuadro int Ancho en espacos de caracteres de los cuadros de la cuadrícula.
 * \param alto_cuadrol int Alto en espacos de caracteres de los cuadros de la cuadrícula.
 * \param cant_columnas int Cantidad de cuadros que conforman el ancho de la cuadrícula.
 * \param cant_filas int Cantidad de cuadros que conforman el alto de la cuadrícula.
 *
 * \return void
 *
 */
void ImprimirCuadriculaDoble(int x, int y, int ancho_cuadro, int alto_cuadro, int cant_columnas, int cant_filas);

//****************************************************************************************

/** \brief Establece las dimensiones de la consola al ejecutar un programa
 *
 * \details La consola se divide en posiciones donde se disponen los caracteres
 * que se imprimen, uno por cada posición. Esta función permite establecer las
 * dimensiones medidas en posiciones en que la consola es desplegada.
 *
 * \param ancho int Dimensión horizontal de la consola medido en posiciones.
 * \param alto int Dimensión vertical de la consola medido en posiciones.
 *
 * \return void
 *
 */
void EstablecerVentana(int ancho, int alto);

//****************************************************************************************
/** \brief Colores de texto y fondo de la ventana de despliegue
 */
enum Color{                 // Color es el nombre del tipo enumerado
    NEGRO,          /**< Color negro */
    AZUL,           /**< Color azul fuerte */
    VERDE,          /**< Color verde oscuro */
    AGUAMARINA,     /**< Color azul verde */
    ROJO,           /**< Color rojo oscuro */
    PURPURA,        /**< Color morado */
    AMARILLO,       /**< Color amarillo */
    GRISCLARO,      /**< Color gris claro */
    GRIS,           /**< Color gris oscuro */
    AZULCLARO,      /**< Color azul cielo */
    VERDECLARO,     /**< Color verde claro */
    AGUAMARINACLARO,/**< Color azul verde claro */
    ROJOCLARO,      /**< Color rojo claro */
    MAGENTA,        /**< Color rosa fuerte */
    AMARILLOCLARO,  /**< Color amarillo claro */
    BLANCO          /**< Color blanco */
};
/** \brief Establece el color de fondo y texto para impresi&oacute;n.
 * \details Después de establecer el color, lo que se imprima aparecerá con
 * esta combinación de colores.
 *
 * \param colorFondo El color de fondo del texto a imprimir
 * \param colorTexto El color del texto a imprimir
 *
 * \pre Tanto el color de fondo como de texto deben ser valores de la
 * enumeración tipo Color: NEGRO, AZUL, VERDE, ..., BLANCO
 */
void EstablecerColor(Color colorFondo, Color colorTexto);
//*************************************************************************************************************************
/**
 * \brief Mueve el cursor en la ventana de despliegue a la posición indicada
 *
 * \details Las posiciones de la ventana de despliegue inician con (0,0) en la
 * esquina superior izquierda. Podría decirse que la posición \b x indica la
 * columna de la ventana y la posición \b y indica el renglón, ambas iniciando
 * en cero.
 *
 * \param x Posición horizontal a donde se moverá el cursor. El cursor se
 *          mueve \b x unidades a la derecha a partir del inicio de la ventana.
 * \param y Posición vertical a donde se moverá el cursor. El cursor se mueve
 *          \b y unidades hacia abajo a partir del inicio de la ventana.
 *
 * \return Nada
 *
 * \warning Si alguna posición se sale de los límites de la ventana de
 *          despliegue, el cursor no se moverá.
 */
void MoverCursor(short x,short y);

//****************************************************************************************

/** \brief Estado del cursor
 */
enum EstadoCursor{
    APAGADO,    /**< Apaga el cursor. Lo hace invisible */
    ENCENDIDO   /**< Enciende el cursor. Lo hace visible */
};

/** \brief Modo o tamaño del cursor
 */
enum ModoCursor{
    NORMAL = 20,    /**< El cursor tiene un tamaño pequeño, tamaño normal */
    MEDIO = 50,     /**< El cursor tiene un tamaño medio, más alto del normal, ocupa la mitad del área de un carácter en la ventana */
    SOLIDO = 100     /**< El cursor tiene el tamaño de todo el área de un carácter en la ventana */
};

/** \brief Cambia el estado y el tamaño del cursor
 *
 * \param estado El estado a establecer. Los posibles valores son ENCENDIDO o APAGADO
 * \param modo El tamaño o modo del cursor a establecer. Los posibles valores son MINI, NORMAL y SOLIDO
 *
 * \return Nada
 */
void CambiarCursor(EstadoCursor estado, ModoCursor modo);
//****************************************************************************************
/**
 * \brief Establece el título de la consola
 *
 * \details El título en la barra de título de la consola es la dirección del ejecutable
 *          por defecto. Esta función establece un nuevo título introduciendo como argumento
 *          una cadena de caracteres.
 *
 * \param titulo const char * Cadena de caracteres que contiene al título que se desea establecer.
 *
 * \return Nada
 *
 */
void EstablecerTitulo(const char * titulo);
//****************************************************************************************


#endif //UNTITLED5_UTILERIA_H
