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
using namespace std;
int main() {
    // Creacion de los camiones con sus respectivas placas y capacidades
    Camion unCamion("ABC-001", 10000);
    Camion otrocamion("DEF-002", 5000);

    // Arreglo con los pesos que va a transportar el camion
    int objetos[8] = {1000, 3000, 5000, 2000, 500, 1800, 4000, 30};

    // se carga los objetos a el camion
    for (int cualObjeto = 0; cualObjeto < 8; cualObjeto++) {
        int objetoATransportar = objetos[cualObjeto];
        // se intenrar cargar el objeto en unCamion a
        if (not unCamion.CargarUnObjeto(objetoATransportar)) {
            // si no cabe en unCamion entonces vamos a intentar cargarlos en otroCamion
            if (not otrocamion.CargarUnObjeto(objetoATransportar)) {
                cout << "El objeto numero "<< cualObjeto << " Que pesa "
                << objetos[cualObjeto] << " no se puede cargar en ningun camion" << endl;
            }
        }
    }

    // mostramos los resultados finales
    cout << "El camion " << unCamion.getCualEsLaPlaca() << " transporto "
    << unCamion.hacerMudanza() << " Kg" << endl;
    cout << "El camion " << otrocamion.getCualEsLaPlaca()<<" transporto "
    << otrocamion.hacerMudanza()<< " Kg" <<endl;


    return 0;





}
