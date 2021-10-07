/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.c
 * Author: Dani
 * 
 * Created on October 5, 2021, 1:18 PM
 */

#include "../header_files/Game.h"

int accionConsecutiva;

void empezarJuego()
{
    accionConsecutiva = 0;
    
    inicializarTablero(6, 6);
    
    menu();
    
    liberarMemoriaTablero();
}

void printTable()
{    
//    printf("\n \n \n \n \t \t");
    
    int tam = table.col_count * table.row_count + 9;
    
    for(int j = 0; j < table.col_count; j++)
    {
        printf("\t %i", j);
    }
    
    printf("\n \n \t");
    
    for(int j = 0; j < tam; j++)
    {
        printf("*");
    }
    
    printf("\n \n");
    
    char row = 'A';
    
    for(int i = 0; i < table.row_count; i++)
    {
        printf(" %c", row);
        
        for(int j = 0; j < table.col_count; j++)
        {
            if(table.tablero[i][j].estado == 3 || table.tablero[i][j].estado == 2)
            {
                printf("\t[%c]", table.tablero[i][j].letra);
            }
            else
            {
                printf("\t[ ]");
            }
        }
        
        printf("\n \n");
        
        row++;
    }
}

void menu()
{
    int cantidad_parejas = 0, cantidad_movimientos = 0, cantidad_maxima = (table.col_count * table.row_count) / 2, resultado_accion;

    do
    {
        printf("\e[1;1H\e[2J");
        
        printf("Numero de movimientos: %i \n", cantidad_movimientos);
        printf("Numero de pares encontrado: %i \n \n", cantidad_parejas);
        
        printTable();
        
        resultado_accion = pedirAccion();
        
        if(resultado_accion == 1)
        {
            cantidad_parejas++;
        }
        
        if(resultado_accion != -420)
        {
            cantidad_movimientos = cantidad_movimientos + 1;;
        }
        
        if(cantidad_parejas == cantidad_maxima)
        {
            break;
        }
        
    } while(resultado_accion != -100);
    
    if(cantidad_parejas == cantidad_maxima)
    {
        printf("Felicidades !! \n Usted gano el juego \n Movimientos realizados: %i \n", cantidad_movimientos);
        printf("Saliendo en 3 ");
        fflush(stdout);
        sleep(2);
        printf("2 ");
        fflush(stdout); // Force the output to be printed
        sleep(2);
        printf("1 ");
        fflush(stdout); // Force the output to be printed
        sleep(2);
    }
    else{
        printf("Usted decidio retirarse, que pena...\n");
        printf("Saliendo en 3 ");
        fflush(stdout);
        sleep(1);
        printf("2 ");
        fflush(stdout); // Force the output to be printed
        sleep(1);
        printf("1 ");
        fflush(stdout); // Force the output to be printed
    }
}

int pedirAccion()
{
    char row;
    
    int col;
    
    printf("Digite la fila de la casilla que desea observar la letra.\n");
    
    printf("Rango valido: ");
    
    int row_name = 'A';
    
    for(int i = 0; i < table.row_count; i++)
    {
        if(i == 0)
        {
            printf("( %c,", row_name);
        }
        else if(i == table.row_count - 1)
        {
            printf(" %c ) \n", row_name);
        }
        else
        {
            printf(" %c,", row_name);
        }
        
        row_name++;
    }
    
    printf("O digite 'S' / 's' para salir del juego\n-> ");
    
    scanf("%c", &row);
    
    if(row == 's' || row == 'S')
    {
        return -100;
    }
    
    row = toupper(row);
    
    if(checkIfValidRow(row) == -1)
    {
        return -420;
    }
    
    printf("Digite la columna de la casilla que desea observar la letra.\n");
    
    printf("Rango valido: ");
    
    for(int i = 0; i < table.col_count; i++)
    {
        if(i == 0)
        {
            printf("( %i,", i);
        }
        else if(i == table.col_count - 1)
        {
            printf(" %i ) \n", i);
        }
        else
        {
            printf(" %i,", i);
        }
    }
    
    printf("-> ");
    
    scanf("%i", &col);
    
    if(checkIfValidCol(col) == -1)
    {
        return -420;
    }
    
    int response = revealIfPossible(row, col);
    
    if(response == -1)
    {
        return -420;
    }
    
    accionConsecutiva += 1;
    
    if(accionConsecutiva == 2)
    {
        printf("\e[1;1H\e[2J");
        
        int resultado_verificacion = checkIfRevealedAreEquals();

        printTable();
        
        if(resultado_verificacion == 1)
        {
            printf("Las casillas reveladas son iguales.\n");
        }
        else
        {
            printf("Las casillas reveladas son diferentes.\n");
        }
        
        sleep(3);
        
        if(resultado_verificacion == 1)
        {
            accionConsecutiva = 0;
            
            return 1;
        }
        
        hideRevealed();
        
        accionConsecutiva = 0;
        
        return -1;
    }
    
    return -1;
}