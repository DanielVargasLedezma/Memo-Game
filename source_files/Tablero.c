/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.c
 * Author: Dani
 * 
 * Created on October 5, 2021, 1:06 PM
 */

#include "../header_files/Tablero.h"

Table table;

void inicializarTablero(int n, int m)
{
    table.row_count = n;

    table.col_count = m;

    table.tablero = (Casilla**) malloc(n * sizeof(Casilla*));

    for (int i = 0; i < n; i++)
    {
        (table.tablero)[i] = (Casilla*) malloc(m * sizeof(Casilla));
    }
    
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            table.tablero[i][j].estado = 1;
        }
    }
    
    randomizarTablero();
}

void randomizarTablero()
{
    int total = table.col_count * table.row_count;
    
    int tam = total / 2; 
    
    char letras[tam], inicio = 'A';
    
    for(int i = 0; i < tam; i++)
    {
        letras[i] = inicio;
        
        inicio++;
    }
    
    srand(time(NULL));
    
    int numRand = 0, contador = 0;
    
    inicio = 'A';
        
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            numRand = rand() % tam;

            while (checkIfTwice(letras[numRand]) == 1)
            {
                numRand = rand() % tam;
            }

            table.tablero[i][j].letra = letras[numRand];
            table.tablero[i][j].letra_fila = inicio;
            table.tablero[i][j].numero_col = j;
            
            contador++;

            if (contador == total)
            {
                break;
            }
        }
        
        inicio++;
    }
}

/*
 * Retorna 1 si esta dos veces;
 * Retorna -1 si no lo está. 
 */
int checkIfTwice(char letra)
{
    int contador = 0;
    
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if(table.tablero[i][j].letra == letra)
            {
                contador++;
                
                if(contador == 2)
                {
                    return 1;
                }
            }
        }
    }
    
    return -1;
}

/*
 * Retorna 1 si es válido;
 * Retorna -1 si no lo es. 
 */
int checkIfValidRow(char row)
{
    int total = table.col_count * table.row_count;
    
    int tam = total / 2; 
    
    char letras[tam], inicio = 'A';
    
    for(int i = 0; i < tam; i++)
    {
        letras[i] = inicio;
        
        inicio++;
    }
    
    for(int i = 0; i < tam; i++)
    {
        if(letras[i] == row)
        {
            return 1;
        }
    }
    
    return -1;
}

/*
 * Retorna 1 si es válido;
 * Retorna -1 si no lo es. 
 */
int checkIfValidCol(int col)
{
    if(col < table.col_count && col >= 0)
    {
        return 1;
    }
    
    return -1;
}

/*
 * Retorna 1 se hizo con exito;
 * Retorna -1 si ya esta revelado o si ya esta seleccionado. 
 */
int revealIfPossible(char row, int col)
{
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if(table.tablero[i][j].letra_fila == row && table.tablero[i][j].numero_col == col)
            {
                if(table.tablero[i][j].estado == 1)
                {
                    table.tablero[i][j].estado = 2;
                    
                    return 1;
                }
            }
        }
    }
    
    return -1;
}

void hideRevealed()
{
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if(table.tablero[i][j].estado == 2)
            {
                table.tablero[i][j].estado = 1;
            }
        }
    }
}

int checkIfRevealedAreEquals()
{
    int i_first, j_first;
    
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if(table.tablero[i][j].estado == 2)
            {
                i_first = i;
                j_first = j;
            }
        }
    }
    
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if(i != i_first || j != j_first){
                if(table.tablero[i][j].estado == 2)
                {
                    if(table.tablero[i][j].letra == table.tablero[i_first][j_first].letra)
                    {
                        table.tablero[i][j].estado = 3;
                        table.tablero[i_first][j_first].estado = 3;
                        return 1;
                    }
                }
            }
        }
    }
    
    return -1;
}

void liberarMemoriaTablero()
{
    for (int i = 0; i < table.row_count; i++)
    {
        free(table.tablero[i]);
    }
    
    free(table.tablero);
}