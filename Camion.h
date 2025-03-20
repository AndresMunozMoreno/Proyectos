/* camion.h
/* Copyright (C) 2025 Victor Bucheli <victor.bucheli@correounivalle.edu.co>
/*
/*
/*    Clase: Camion
/*    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
/*    Universidad del Valle
/*
/*    Información CRC:
/*
/*    Clase: Camion
/*
/*    Responsabilidades:
/*      - simular una camion de mudanzas
/*		- simular distintos pesos que puede llevar el camion
/*		- simular la capacidad maxima del camion
/*		- Cada camion tiene que tener una placa
/*		- los objetos tienen diferentes pesos
/*		- si un objeto pasa la capacidad maxima debe ir al otro camion
/*
/*    Colaboradores:
/*        - este programa colabora con camion y otro camion y entre objetos para cargarlos si un camion no puede cargarlo pasa al otro camion
/*
/*    Este es un proyecto del curso FPOO de la Universidad del Valle,
/*    desarrollado con fines académicos. Puede ser utilizado con fines
/*    académicos dando los créditos de la autoría.
/*
/*
/*    Autor: Andres Felipe Muñoz Moreno
/*    Correo: andres.f.munoz.m@correounivalle.edu.co
/*    Contribuidor: Sebastian orejuela,Jairo Tegue,Juan Tapia
/*    Fecha: 17/03/2025
/*
/*
/*                        +---------------------+
/                        *|       Camion        |
/                   *+-------------------------------+
/                   *| - placa: string               |
/                   *| - Capacidad Camion: int       |
/                   *| - Peso total del camion: int  |
/               *+--------------------------------------+
/               *| + Camion(placa : string)             |
/               *| + Camion(capacidad: int)             |
/               *| + CargarUnObjeto(pesoDelObjeto: int) |
/               *| + hacerMudanza(): int                |
/               *| + cualEsLaPlaca(): string            |
/               *+--------------------------------------+
/*
*/
#ifndef CAMION_H
#define CAMION_H
#include <string>
using namespace std;


class Camion {   // definimos la clase camion
private:        // las caracteristicas privadas del camion lo que no se puede cambiar
    string pl; // la placa del camion
    int cm;   //capacidad del camion
    int ptc; // peso total del camion
public:     // las caracteriticas publicas del camion
    Camion(string laPlaca, int laCapacidadMaxima); // definimos el constructor
    bool CargarUnObjeto(int pesoDelobjeto);       //mira a ver si puede cargar el objeto true si puede false si no puede
    int hacerMudanza();                          // devuelve el peso cargado por el camion
    string getCualEsLaPlaca();                  //obtiene la placa del camion

};



#endif //CAMION_H
