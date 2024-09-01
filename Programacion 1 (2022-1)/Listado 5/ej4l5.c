#include <stdio.h>
#include <stdlib.h>    //con ayuda de Pedro Gajardo


void ImprimirJugadores(Equipo *equipo){   //funcion para imprimir las estadisticas de los jugadores
    int total = equipo->numJugadores[0] + equipo->numJugadores[1] + equipo->numJugadores[2] + equipo->numJugadores[3];
    for (int i = 0; i < total; ++i){  
        Jugador jugador = equipo->jugadores[i];
        printf("(%d) Nombre: %s\n", i + 1, jugador.nombre);    //imprime el nombre,edad,regate,defensa,reflejos,velocidad,dureza
        printf("Posicion: %s\n", jugador.posicion);          // y resistencia de cada jugador
        printf("Edad: %u\n", jugador.edad);  
        printf("Regate: %f\n", jugador.regate); 
        printf("Defensa: %f\n", jugador.defensa);   
        printf("Reflejos: %f\n", jugador.reflejos);  
        printf("Velocidad: %f\n", jugador.velocidad);   
        printf("Dureza: %f\n", jugador.dureza);  
        printf("Resistencia: %f\n", jugador.resistencia);   
        printf("\n");
    }
}

void ImprimirStaff(Equipo *equipo){   //creamos una funcion que imprima a los miembros del staff del equipo
    int total = equipo->numStaff[0] + equipo->numStaff[1] + equipo->numStaff[2] + equipo->numStaff[3] + equipo->numStaff[4] + equipo->numStaff[5];
    for (int i = 0; i < total; ++i){   
        Staff staff = equipo->staff[i];
        printf(("%d) Nombre: %s\n", i + 1,staff.nombre);     //imprimimos el nombre,edad,rol y experiencia de cada miembro del staff
        printf("Edad: %u\n", staff.edad);   
        printf("Rol: %s\n", staff.rol); 
        printf("Experiencia: %u\n", staff.experriencia);    
    }
}
void ImprimirFanaticos(Equipo *equipo){   //creamos una funcion que imprima a los fans del equipo  
    for (int i = 0; i < equipo->numFanaticos; i++){
        Fanatico fan = equipo->fanaticos[i];
        printf("(%d) Nombre: %s\n", i + 1,fan.nombre);    //imprimimos el nombre,edad y agresividad de cada fan
        printf("Edad: %u\n", fan.edad); 
        printf("Agresividad: %lf\n", fan.agresividad);  
    }
}

void ImprimirDB(Equipo *equipo, int *numEquipos){   //creamos la funcion que imprima los datos del equipo entero
    for (int i = 0; i < *numEquipos; ++i){   //para cada equipo que tengamos almcenado
        Equipo team = equipo[i];
        printf("Miembros del Equipo %s\n", team.nombre);      //imprimimos el nombre del equipo y año de fundacion
        printf("Año de Fundacion: %d\n",team.anyoFundacion);    
        printf("\n");
        printf("Jugadores: \n");
        printf("\n");
        ImprimirJugadores(&team);   // imprimimos los datos de los jugadores del equipo
        printf("\n");
        printf("Staff:\n");
        printf("\n");
        ImprimirStaff(&team);   // imprimimos los datos de los miembros del staff del equipo
        printf("\n");
        printf("Fans:\n");
        printf("\n");
        ImprimirFanaticos(&team);   //imprimimos los datos de los fans del equipo
        printf("\n");
    }
}