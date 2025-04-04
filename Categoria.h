// Categoria.h
// Clase que representa una categoría en la droguería.
// Responsabilidades:
// - Almacenar el nombre de la categoría.
// Colaboraciones:
// - Colabora con la clase Producto para asociar productos a la categoría.
// - Colabora con la clase Drogueria para registrar y gestionar categorías.
// Autor:Victor Buchlei
// Editores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
// mail:victor.bucheli@correounivalle.edu.co
// 

#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
using namespace std;

class Categoria {
private:
    string categoria;  // Nombre de la categoría

public:
    Categoria(string auxCategoria);
    string getCategoria() const;
};

#endif  // CATEGORIA_H
