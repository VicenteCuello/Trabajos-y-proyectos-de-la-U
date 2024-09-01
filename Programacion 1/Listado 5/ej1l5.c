#include <stdio.h>         //solo
#include <stdlib.h>

typedef struct{
    char nombre[100];
    char edad;
    double agresividad;
}Fanatico;

typedef struct{
    char nombre [100];
    char edad;
    char posicion[11];
    float regate;
    float defensa;
    float reflejos;
    float velocidad;
    float dureza;
    float resistencia;
}Jugador;

typedef struct{
    char nombre[100];
    char edad;
    char rol[50];
    char experriencia;
}Staff;

typedef struct{
    char nombre[100];
    unsigned int anyoFundacion;
    Staff *staff;
    int numStaff[6];
    Jugador *jugadores;
    int numJugadores[4];
    Fanatico *fanaticos;
    int numFanaticos;
}Equipo;
  