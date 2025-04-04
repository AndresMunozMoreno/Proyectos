// Producto.cpp
// Clase que representa un producto en la droguería.
// Responsabilidades:
// - Almacenar la información del producto (nombre, precio, cantidad en stock, y categorías).
// - Permitir la actualización de stock y la verificación de stock mínimo.
// - Permitir agregar y eliminar categorías asociadas.
// Colaboraciones:
// - Colabora con la clase Categoria para asociar categorías.
// - Colabora con la clase Drogueria para registrar productos y realizar búsquedas.
// Autores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:andres.f.munoz.m@correounivalle.edu.co

#include "Producto.h"   // incluimos producto.h
#include <iostream>    // lo incluimos para imprimir
using namespace std;  // lo incluimos para evitar el std

// constructor de la clase producto
Producto::Producto(int id, string nombre, double precio, int cantidadStock) {
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidadStock = cantidadStock;
}

//getters
int Producto::getId() const {// para obtener la id del producto
    return id; //retorna el id
}
string Producto::getNombre() const { // para obtener el nombre
    return nombre;// retorna el nombre
}
double Producto::getPrecio() const {// para obtener el precio
    return precio;// devuelve el precio
}
int Producto::getCantidadStock() const {// para obtener la cantidad del producto
    return cantidadStock;// retorna la cantidad que hay
}
//funciones de producto
// funcion agregar un producto
void Producto::agregarCategoria(Categoria* auxCategoria) {// vamos a agregar una categoria al vector categorias
    categorias.push_back(auxCategoria); // agregamos la categoria al vector categorias
}
// funcion eliminar un producto
void Producto::eliminarCategoria(Categoria* auxCategoria) {//vamos a eliminar una categoria del vector categorias
    //vamos a byscar la categoria en el vector y la vamos a eliminar
    for (auto it = categorias.begin(); it != categorias.end(); ++it) {// vamos a empezar a buscar desde el inicio del vector hasta el final del vector sumado uno mas y vamos sumandole al iterador
        if (*it == auxCategoria) {// si la direccion del iterador conincide con el que esta guardado entonces dentra al if
            categorias.erase(it); // eliminamos el elemento
        }
    }
}
// funcion para comprobar el stock minimo
bool Producto::verificarStockMinimo(int stockMinimo) {/// vamos ver si estamos en la cantidad minima del producto
    return cantidadStock < stockMinimo;// si la cantidad es menor a la cantidad minima entonces nos lanza un verdadero
}
// funcion para actulizar la cantidad de producto
void Producto::actualizarStock(int cantidad) {
    cantidadStock += cantidad;// actuazlicamos la cantidad de stock
}
// funcion para mostrar las categorias a las que pertenece el producto
void Producto::verCategorias() {
    cout << "Categorias del producto "<<nombre<<":"<< endl;// imprimimos esto en consola
    for (Categoria* cat : categorias) {// Cat recorre el vector
        cout << cat->getCategoria() << endl;// imprime la categoria
    }
}

