/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: Dani
 *
 * Created on October 5, 2021, 1:06 PM
 */

#ifndef TABLERO_H
#define TABLERO_H
#include <stdlib.h>
#include <time.h>
#include "Casilla.h"

typedef struct Table
{
    Casilla **tablero;
    int row_count; //n
    int col_count; //m

} Table;

extern Table table;

extern void inicializarTablero(int n, int m);

extern void randomizarTablero();

/*
 * Retorna 1 si esta dos veces;
 * Retorna -1 si no lo está. 
 */
extern int checkIfTwice(char letra);

/*
 * Retorna 1 si es válido;
 * Retorna -1 si no lo es. 
 */
extern int checkIfValidRow(char row);

/*
 * Retorna 1 si es válido;
 * Retorna -1 si no lo es. 
 */
extern int checkIfValidCol(int col);

/*
 * Retorna 1 se hizo con exito;
 * Retorna -1 si ya esta revelado o si ya esta seleccionado. 
 */
extern int revealIfPossible(char row, int col);

extern void hideRevealed();

/*
 * Retorna 1 si son iguales y cambia el estado a 3;
 * Retorna -1 si no lo son. 
 */
extern int checkIfRevealedAreEquals();

extern void liberarMemoriaTablero();

#endif /* TABLERO_H */
