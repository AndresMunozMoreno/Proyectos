// Cliente.cpp
// Clase que representa a un cliente de la droguería.
// Responsabilidades:
// - Almacenar información del cliente (nombre).
// - Mantener un registro de los productos comprados o de interés por parte del cliente.
// Colaboraciones:
// - Colabora con la clase Producto para registrar los productos comprados por el cliente.
// - Colabora con la clase Drogueria para gestionar los clientes y realizar búsquedas de productos.
// Autores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:andres.f.munoz.m@correounivalle.edu.co

#include "Cliente.h"    // agregamos clientes .h
#include <iostream>    // agregamos libreria para imprimir
using namespace std;  // agregamos para evitarnos el std

//constructor de la clase cliente
Cliente::Cliente(string nombre) {
    this->nombre = nombre;
}

//getters obtiene el nombre del cliente
string Cliente::getNombre() const {
    return nombre;
}

//Funcion para que el cliente agregue productos
void Cliente::agregarProductoComprado(Producto* auxProducto) {
    productosComprados.push_back(auxProducto);// se agrega al vector productos comprados
}
//Funcion para que el cliente mire su canasta
void Cliente::verCanastadeCompras() {
    cout<<"Canasta de compras de "<<nombre<<":"<<endl;//Mostramos en pantalla
    for(Producto* producto : productosComprados) { // producto recorre el vector productosComprados
        cout<< "- ID: "<<producto->getId() // obtenemos el id
            << ", Nombre: "<<producto->getNombre()// obtenemos el nombre del producto
            << ", Precio: $"<<producto->getPrecio()// obtenemos el precio del producto
            << endl;
    }
}