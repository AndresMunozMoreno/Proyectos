// Producto.h
// Clase que representa un producto en la droguería.
// Responsabilidades:
// - Almacenar la información del producto (nombre, precio, cantidad en stock, y categorías).
// - Permitir la actualización de stock y la verificación de stock mínimo.
// - Permitir agregar y eliminar categorías asociadas.
// Colaboraciones:
// - Colabora con la clase Categoria para asociar categorías.
// - Colabora con la clase Drogueria para registrar productos y realizar búsquedas.
// Autor:Victor Buchlei
// Editores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:victor.bucheli@correounivalle.edu.co


#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>
#include "Categoria.h"
using namespace std;

class Producto {
private:
    int id;  // Identificador único del producto
    string nombre;  // Nombre del producto
    double precio;  // Precio del producto
    int cantidadStock;  // Cantidad en stock
    vector<Categoria*> categorias;
public:
    //constructor
    Producto(int id, string nombre, double precio, int cantidadStock);
    int getId() const;
    string getNombre() const;
    double getPrecio() const;
    int getCantidadStock() const;

    //funciones de la clase producto
    void agregarCategoria(Categoria* auxCategoria);
    void eliminarCategoria(Categoria* auxCategoria);

    bool verificarStockMinimo(int stockMinimo);
    void actualizarStock(int cantidad);
    void verCategorias();
};

#endif  // PRODUCTO_H
