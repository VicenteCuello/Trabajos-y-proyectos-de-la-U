#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>     //con ayuda de Pedro Gajardo

char *nombresPersonas[] = {"Vicente","Pedro","Nicolas","Max","Eduardo","Cesar","Franco","Benja","Martin","Gaspar","Antonio","Francisco",
                            "Diego","Fernanda","Tomas","Bastian","Lucas","Veronica", "Jorge","Matias"};   //20 nombres
char *nombreEquipos[] = {"Colo Colo","Universidad de Chile","Universidad Católica","River Plate","Boca Juniors","Liverpool",
                         "Manchester United","Manchester City", "Arsenal","Tottenham","Real Madrid","Barcelona","Atletico de Madrid",
                         "Real Betis", "Villareal","Paris Saint Germain","Sevilla","Juventus","Inter de Milan","Napoli","Flamengo"}; //21 equipos


Fanatico *crearFanaticos(int numFanaticos){
    srand(time(NULL));
    Fanatico *fanaticos = (Fanatico *)malloc(numFanaticos * sizeof(Fanatico));     //vemos la cantidad de memoria que nececita el arreglo
    for (int i = 0; i < numFanaticos; ++i){
        strcpy(fanaticos[i].nombre, nombresPersonas[rand() % 20]);  //se elije uno de los 20 nombres al azar  
        fanaticos[i].edad = 10 + rand() % 80;                       //se elije una edad al azar
        fanaticos[i].agresividad = rand() % 101;                   //le damos una agresividad al azar
    }

    return fanaticos;
}

void liberarFanaticos(Fanatico *fans)       //libera la memoria usada por el arreglo fans{
    free(fans);
    fans = NULL;
}

Staff *crearStaff(int numDT, int numPrepArq, int numPrepFis, int numAsis, int numFisio, int numDoc){
    srand(time(NULL));
    int numStaff = numDT + numPrepArq + numPrepFis + numAsis + numFisio + numDoc; //vemos la cantida total que hay de parte del staff
    Staff *staff = (Staff *)malloc((numStaff) * sizeof(Staff));  //memoria necesaria para almcenar los datos de staff
    for (int i = 0; i < numStaff; i++){
        strcpy(staff[i].nombre, nombresPersonas[rand() %20]);   //le damos un nombre y edad random
        staff[i].edad = 18 + rand() % 32;                      
        staff[i].experriencia = rand() % 101;            //le damos un valor random de experiencia
        if (i < numDT){  
            strcpy(staff[i].rol, "DT"); 
        }
        else if (i - numDT < numPrepArq){                         //Dependiendo de su valor en staff se le asigna un rol
        }
            strcpy(staff[i].rol, "Preparador de Arqueros"); 
        else if (i - (numDT + numPrepArq) < numPrepFis){ 
            strcpy(staff[i].rol, "Preparador Fisico");
        }  
        else if (i - (numDT + numPrepArq + numPrepFis) < numAsis){   
            strcpy(staff[i].rol, "Asistente"); 
        } 
        else if (i - (numDT + numPrepArq + numPrepFis + numAsis) < numFisio){ 
            strcpy(staff[i].rol, "Fisioterapeuta"); 
        }
        else{   
            strcpy(staff[i].rol, "Doctor"); 
         }
    }

    return staff;
}

void liberarStaff(Staff *staff)   //liberamos la memoria que hay en el arreglo staff{
    free(staff);
    staff = NULL;
}

Jugador *crearJugadores(int numArq, int numDef, int numCent, int numDel){
    srand(time(NULL));
    Jugador *jugadores = (Jugador *)malloc((numArq + numDef + numCent + numDel) * sizeof(Jugador)); //le asignamos memoria para los jugadores
    for (int i = 0; i < (numArq + numDef + numCent + numDel); ++i){
        strcpy(jugadores[i].nombre, nombresPersonas[rand() % 20]);  //le asignamos nombre y edad random
        jugadores[i].edad = 18 + rand() % 23;   
        jugadores[i].regate = (rand() % 101) / 7;      //le asignamos regate, defensa, reflejos,velocidad,dureza y resistencia random
        jugadores[i].defensa = (rand() % 101) / 7;  
        jugadores[i].reflejos = (rand() % 101) / 7; 
        jugadores[i].velocidad = (rand() % 101) / 7;    
        jugadores[i].dureza = (rand() % 101) / 7;   
        jugadores[i].resistencia = (rand() % 101) / 7;  
        if (i < numArq){  
            strcpy(jugadores[i].posicion, "Arquero");     //Dependiendo de su valor en jugadores se le asigna una posicion
        }
        else if (i - numArq < numDef){   
            strcpy(jugadores[i].posicion, "Defensa");  
        } 
        else if (i - (numArq + numDef) < numCent){   
            strcpy(jugadores[i].posicion, "Medio");
        } 
        else{    // finalmente
            strcpy(jugadores[i].posicion, "Delantero"); 
         }
    }
    return jugadores;
}

void liberarJugadores(Jugador *jugadores) {    //libera memoria del arreglo jugadores
    free(jugadores);
    jugadores = NULL;
}

Equipo *crearEquipo(int numEquipos){
    srand(time(NULL));
    Equipo *equipos = (Equipo *)malloc(numEquipos * sizeof(Equipo));  //asignamos la memoria necesaria para equipo
    for (int i = 0; i < numEquipos; i++){
        equipos[i].numFanaticos = rand() % 10000;   //le asignamos un valor aleatorio de numero de fanaticos
        for (int j = 0; j < 4; ++j){                     //hay 4 posiciones para un jugador
            equipos[i].numJugadores[j] = rand() % 23;   //se le asigna un valor aleatorio dependiendo de la posicion
        }
        for (int j = 0; j < 6; ++j){                     //hay 6 roles en staff
            equipos[i].numStaff[j] = rand() % 23;       //se le asigna un valor aleatorio dependiendo del rol
        strcpy(equipos[i].nombre, nombreEquipos[rand() % 21]);  //le damos un nombre random de la lista de equipos
        equipos[i].anyoFundacion = 1880 + rand() % 123;          //le damos un año de fundacion random entre 1880 y 2022
        equipos[i].staff = crearStaff(equipos[i].numStaff[0], equipos[i].numStaff[1], equipos[i].numStaff[2], equipos[i].numStaff[3], equipos[i].numStaff[4], equipos[i].numStaff[5]);  
        equipos[i].jugadores = crearJugadores(equipos[i].numJugadores[0], equipos[i].numJugadores[1], equipos[i].numJugadores[2], equipos[i].numJugadores[3]);  
        equipos[i].fanaticos = crearFanaticos(equipos[i].numFanaticos);   //creamos el staff, el equipo y los fanaticos
    }
    for(int i = 0; i < numEquipos; ++i){
        for(int j = i+1; j < numEquipos; ++j){
            char *dif;
            sprintf(dif,"%d",j);
            if(strcmp(equipos[i].nombre,equipos[j].nombre) == 0){    //si dos equipos tienes el mismo nombre se le agrega un numero al segundo
                strcat(equipos[j].nombre,dif); 
            }
    }    }
            
    return equipos;
}

void liberarEquipos(Equipo *equipos, int numEquipos){   //libera la memoria de equipo
    for (int i = 0; i < numEquipos; ++i){
        liberarJugadores(equipos[i].jugadores);
        liberarFanaticos(equipos[i].fanaticos);
        liberarStaff(equipos[i].staff);
    }
    free(equipos);
    equipos = NULL;
}