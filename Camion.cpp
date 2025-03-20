/*
Proyecto: Camion
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

  Descripción:
    Este proyecto busca arreglar errores y mejorar el codigo de un proyecto
    completo en FPOO depurando el codigo
    programar una clase camion

      Autor: Andres Felipe Munoz Moreno
      Correo: ignacio.henao@correounivalle.edu.co
      Fecha: Marzo 2025
      Contribuidor: Sebastian orejuela,Jairo Tegue,Juan Tapia
*/
#include "Camion.h"
#include <iostream>
Camion::Camion(string laPlaca, int laCapacidadMaxima) { // definimos el constructor
    pl = laPlaca;                                       // la pl va a ser igual a laPlaca
    cm = laCapacidadMaxima;                             // definimos la capacidad maxima del camion
    ptc = 0;                                            // peso total del camion en cero por que no a cargado nada
}
bool Camion::CargarUnObjeto(int pesoDelobjeto) { //vamos a ver si de pudo o no se pudo cargar el objeto
    if (ptc+pesoDelobjeto <= cm) {
        ptc = ptc+pesoDelobjeto;
        return true;
    }else {
        return false;
    }
}
int Camion::hacerMudanza() { // retorna el peso total cargado por el camion
    return ptc;
}
string Camion::getCualEsLaPlaca() {
    return pl;
}
