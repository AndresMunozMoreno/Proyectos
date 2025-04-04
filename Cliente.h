// Cliente.h
// Clase que representa a un cliente de la droguería.
// Responsabilidades:
// - Almacenar información del cliente (nombre).
// - Mantener un registro de los productos comprados o de interés por parte del cliente.
// Colaboraciones:
// - Colabora con la clase Producto para registrar los productos comprados por el cliente.
// - Colabora con la clase Drogueria para gestionar los clientes y realizar búsquedas de productos.
// Autor:Victor Buchlei
// Editores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:victor.bucheli@correounivalle.edu.co

#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include <memory>
#include "Producto.h"
using namespace std;

class Cliente {
private:
    string nombre;  // Nombre del cliente
    vector<Producto*> productosComprados;  // Productos comprados por el cliente

public:
    Cliente(string nombre);

    string getNombre() const;
    
    void agregarProductoComprado(Producto* auxProducto);
    void verCanastadeCompras();
};

#endif  // CLIENTE_H
