// Drogueria.h
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
// Editores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:victor.bucheli@correounivalle.edu.co


#ifndef DROGUERIA_H
#define DROGUERIA_H

#include <vector>
#include <memory>
#include "Producto.h"
#include "Categoria.h"
#include "Cliente.h"
using namespace std;

class Drogueria {
private:
    vector<Producto> productos;  // Productos disponibles en la droguería
    vector<Cliente> clientes;  // Clientes registrados

public:
    Drogueria();

    void registrarProducto(Producto auxProducto);

    vector<Producto> buscarPorNombre(string nombre);
    vector<Producto> buscarPorPrecio(double precio);

    void verificarStockMinimo(int stockMinimo);
};

#endif  // DROGUERIA_H
