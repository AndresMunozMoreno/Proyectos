// Categoria.cpp
// Clase que representa una categoría en la droguería.
// Responsabilidades:
// - Almacenar el nombre de la categoría.
// Colaboraciones:
// - Colabora con la clase Producto para asociar productos a la categoría.
// - Colabora con la clase Drogueria para registrar y gestionar categorías.
// Autores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:andres.f.munoz.m@correounivalle.edu.co
//
#include "Categoria.h" //incluimos el archivo .h

// el constructor de Categoria
Categoria::Categoria(string auxCategoria) {
    this->categoria = auxCategoria;
}
//getters
// da el nombre de categoria
string Categoria::getCategoria() const {
    return categoria;
}
