// Drogueria.cpp
// Clase que representa la droguería, gestionando productos, categorías y clientes.
// Responsabilidades:
// - Registrar y gestionar productos y categorías en la droguería.
// - Permitir la búsqueda de productos por nombre, precio o categoría.
// - Verificar el stock mínimo de los productos y notificar al propietario.
// Colaboraciones:
// - Colabora con la clase Producto para gestionar los productos disponibles.
// - Colabora con la clase Categoria para gestionar las categorías de los productos.
// - Colabora con la clase Cliente para gestionar clientes y realizar búsquedas de productos.
// Autor:Victor Buchlei
// Autores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:andres.f.munoz.m@correounivalle.edu.co
#include "Drogueria.h"// incluimos drogueria.h
#include <iostream> // para poder imprimir
#include <algorithm> // para usar algoritmos en los contenedores

// constructor de la clase Drogueria
Drogueria::Drogueria() {

}
// funcion para agregar un nuevo producto en la drogueria
void Drogueria::registrarProducto(Producto auxProducto) {
    productos.push_back(auxProducto);// agregamos un producto al vector productos
}
//funcion para buscar productos por su nombres
vector<Producto> Drogueria::buscarPorNombre(string nombre) {
    vector<Producto> resultado;// almacena los productos que conincidan por el nombre
    // recorremos el vector de productos
    for (const Producto& producto : productos) {
        // si el nombre del producto contiene el nombre buscado
        if (producto.getNombre().find(nombre) != string::npos) {
            resultado.push_back(producto);// se agrega el producto
        }
    }
    return resultado;// se da el vector de resultado
}
//funcion para buscar productos por precio
vector<Producto> Drogueria::buscarPorPrecio(double precio) {
    vector<Producto> resultado;// almacena los que conincidan en el vector
    // recorrer el vector de productos
    for (const Producto& producto : productos) {
        if (producto.getPrecio() == precio) {// si el producto es igual al precio ingresado dentra en el if
            resultado.push_back(producto);
        }
    }
    return resultado;// retorna lo que se guardo en el vector
}
//Funcion para verificar el stock minimo de todos los productos
void Drogueria::verificarStockMinimo(int stockMinimo) {
    cout<<"Productos con stock bajo el minimo ("<<stockMinimo<<"):"<<endl;
    bool hayProductosBajoStock = false; // variable para controlar si hay productos de bajo stock
    // recorremos el vector de productos
    for (const Producto& producto : productos) {
        // si el producto tiene un stock mas bajo que el minimo
        if (producto.getCantidadStock()< stockMinimo) {
            hayProductosBajoStock = true ; // se actualiza  la variable

            //Mostramos detalles de los productos
            cout<<"- Alerta: El producto "<<producto.getNombre()
                <<" (ID: "<<producto.getId()
                <<") tiene un stock de "<<producto.getCantidadStock()
                <<" unidades, por debajo del minimo."<<endl;

        }
    }
    if (!hayProductosBajoStock) {
        cout<<"No hay productos con stock bajo el minimo."<<endl;
    }

}


