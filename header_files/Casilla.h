/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Casilla.h
 * Author: Dani
 *
 * Created on October 6, 2021, 1:18 AM
 */

#ifndef CASILLA_H
#define CASILLA_H

typedef struct Casilla{
    char letra;
    char letra_fila;
    int numero_col;
    
    /*
     * 1 para sin seleccionar;
     * 2 para seleccionado;
     * 3 para encontrado;
     */
    int estado;
} Casilla;

#endif /* CASILLA_H */
