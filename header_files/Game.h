/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Dani
 *
 * Created on October 5, 2021, 1:18 PM
 */

#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>  
#include "Tablero.h"

extern int accionConsecutiva;

extern void empezarJuego();

extern void printTable();

extern void menu();

extern int pedirAccion();

#endif /* GAME_H */
