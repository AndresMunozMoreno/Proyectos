/*
Proyecto: Drogueria
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una Drogueria, proporcionando
    funcionalidades para registrar, buscar y analizar la información de la drogueria.


    Autores: Andres Muñoz, Sebastian Orejuela,Juan Sebastian Tapia,Jairo Tegue
    Correo: andres.f.munoz.m@correounivalle.edu.co
    Fecha: Abril 2025
*/
#include <iostream> // Para imprimir
#include <string> // lo incluimos para usar string
#include <vector> // Incluimos para manejar vectores
#include "Drogueria.h" // Incluimos drogueria.h
#include "Producto.h" // Incluiimos producto.h
#include "Categoria.h" // Incluimos categoria .h
#include "Cliente.h" // Incluimos cliente. h
#include "SistemaLogin.h" // Incluimos SistemaLogin.h
using namespace std; // para no usar el std::

// Función para mostrar los detalles de un producto
void mostrarDetallesProducto(const Producto& producto) {
    // Mostramos las caracteristicas del producto
    cout << "ID: " << producto.getId() << endl;
    cout << "Nombre: " << producto.getNombre() << endl;
    cout << "Precio: $" << producto.getPrecio() << endl;
    cout << "Cantidad en stock: " << producto.getCantidadStock() << " unidades" << endl;
}

// Función para mostrar un vector de productos
void mostrarProductos(const vector<Producto>& productos) {
    // Si no hay productos
    if (productos.empty()) {
        cout << "No se encontraron productos." << endl; // Mostramos un mensaje indicándolo
        return; // Terminamos la función
    }

    // Recorremos el vector de productos
    for (const Producto& producto : productos) {
        cout << "-----------------------------" << endl; // Separamos
        mostrarDetallesProducto(producto); // Mostramos los detalles del producto
    }
}

// Función para mostrar el menú de administrador
void menuAdministrador(SistemaLogin& usuario, Drogueria& miDrogueria) {
    // Verificamos que la sesión esté activa
    if (!usuario.getSesionActiva()) {
        cout << "Error: No hay sesión activa." << endl; // Mostramos un mensaje de error
        return; // Terminamos la función
    }

    int opcion = 0; // Variable para almacenar la opción seleccionada
    string nombreBusqueda; // Variable para almacenar el nombre a buscar
    double precioBusqueda; // Variable para almacenar el precio a buscar

    // el menu que estara apareciendo mientras opcion sea diferente de 6
    while (opcion != 6 && usuario.getSesionActiva()) {
        // Mostramos las opciones del menú
        cout << "\n==== SISTEMA DE GESTIÓN DE DROGUERÍA (ADMINISTRADOR) ====" << endl;
        cout << "1. Buscar productos por nombre" << endl;
        cout << "2. Buscar productos por precio" << endl;
        cout << "3. Verificar stock mínimo de productos" << endl;
        cout << "4. Ver información de clientes" << endl;
        cout << "5. Cambiar contraseña" << endl;
        cout << "6. Cerrar sesión" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion; // la opción ingresada por el usuario

        // Procesamos la opción seleccionada
        switch (opcion) {
            case 1: // Buscar productos por nombre
                cout << "Ingrese el nombre a buscar: ";
                cin.ignore(); // Ignoramos el salto de línea pendiente
                getline(cin, nombreBusqueda); // Leemos el nombre ingresado por el usuario
                cout << "\nResultados de la búsqueda por nombre '" << nombreBusqueda << "':" << endl;
                mostrarProductos(miDrogueria.buscarPorNombre(nombreBusqueda)); // Mostramos los resultados
                break;

            case 2: // Buscar productos por precio
                cout << "Ingrese el precio a buscar: ";
                cin >> precioBusqueda; // Leemos el precio ingresado por el usuario
                cout << "\nResultados de la búsqueda por precio $" << precioBusqueda << ":" << endl;
                mostrarProductos(miDrogueria.buscarPorPrecio(precioBusqueda)); // Mostramos los resultados
                break;

            case 3: // Verificar stock mínimo
                miDrogueria.verificarStockMinimo(20); // Verificamos productos con stock menor a 20
                break;

            case 4: // Ver información de clientes
                cout << "Bucheli Guerrero, Sebastian Orejuela" << endl; // se muestran los clientes
                break;

            case 5: { // Cambiar contraseña
                string nuevaPassword; // Variable para almacenar la nueva contraseña
                cout << "Ingrese la nueva contraseña: ";
                cin >> nuevaPassword; // Leemos la nueva contraseña ingresada por el usuario

                // Intentamos cambiar la contraseña
                if (usuario.cambiarPassword(nuevaPassword)) {
                    cout << "Contraseña cambiada exitosamente." << endl; // Mensaje de éxito
                } else {
                    cout << "Error al cambiar la contraseña." << endl; // Mensaje de error
                }
                break;
            }

            case 6: // Cerrar sesión
                usuario.cerrarSesion(); // Cerramos la sesión
                cout << "Sesión cerrada. Volviendo al menú principal." << endl;
                break;

            default: // Opción inválida
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    }
}

// Función para mostrar el menú de cliente
void menuCliente(SistemaLogin& usuario, Drogueria& miDrogueria, Cliente& cliente) {
    // Verificamos que la sesión esté activa
    if (!usuario.getSesionActiva()) {
        cout << "Error: No hay sesión activa." << endl; // Mostramos un mensaje de error
        return; // Terminamos la función
    }

    int opcion = 0; // Variable para almacenar la opción seleccionada
    string nombreBusqueda; // Variable para almacenar el nombre a buscar
    double precioBusqueda; // Variable para almacenar el precio a buscar

    //  menú se mostrara mientras opcion sea diferente de 5
    while (opcion != 5 && usuario.getSesionActiva()) {
        // Mostramos las opciones del menú
        cout << "\n==== SISTEMA DE GESTIÓN DE DROGUERÍA (CLIENTE) ====" << endl;
        cout << "1. Buscar productos por nombre" << endl;
        cout << "2. Buscar productos por precio" << endl;
        cout << "3. Ver canasta de compras" << endl;
        cout << "4. Cambiar contraseña" << endl;
        cout << "5. Cerrar sesión" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion; // Leemos la opción ingresada por el usuario

        // Procesamos la opción seleccionada
        switch (opcion) {
            case 1: // Buscar productos por nombre
                cout << "Ingrese el nombre a buscar: ";
                cin.ignore(); // Ignoramos el salto de línea pendiente
                getline(cin, nombreBusqueda); // Leemos el nombre ingresado por el usuario
                cout << "\nResultados de la búsqueda por nombre '" << nombreBusqueda << "':" << endl;
                mostrarProductos(miDrogueria.buscarPorNombre(nombreBusqueda)); // Mostramos los resultados
                break;

            case 2: // Buscar productos por precio
                cout << "Ingrese el precio a buscar: ";
                cin >> precioBusqueda; // Leemos el precio ingresado por el usuario
                cout << "\nResultados de la búsqueda por precio $" << precioBusqueda << ":" << endl;
                mostrarProductos(miDrogueria.buscarPorPrecio(precioBusqueda)); // Mostramos los resultados
                break;

            case 3: // Ver canasta de compras
                cliente.verCanastadeCompras(); // Mostramos los productos en la canasta del cliente
                break;

            case 4: { // Cambiar contraseña
                string nuevaPassword; // Variable para almacenar la nueva contraseña
                cout << "Ingrese la nueva contraseña: ";
                cin >> nuevaPassword; // Leemos la nueva contraseña ingresada por el usuario

                // Intentamos cambiar la contraseña
                if (usuario.cambiarPassword(nuevaPassword)) {
                    cout << "Contraseña cambiada exitosamente." << endl; // Mensaje de éxito
                } else {
                    cout << "Error al cambiar la contraseña." << endl; // Mensaje de error
                }
                break;
            }

            case 5: // Cerrar sesión
                usuario.cerrarSesion(); // Cerramos la sesión
                cout << "Sesión cerrada. Volviendo al menú principal." << endl;
                break;

            default: // Opción inválida
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    }
}

// Función principal del programa
int main() {
    // Creamos una instancia de la droguería
    Drogueria miDrogueria;

    // Creamos algunas categorías
    Categoria catAnalgésicos("Analgésicos");
    Categoria catAntibióticos("Antibióticos");
    Categoria catVitaminas("Vitaminas");
    Categoria catCuidadoPersonal("Cuidado Personal");
    Categoria catHogar("Hogar");

    // Creamos algunos productos
    Producto prod1(1, "Aspirina", 5000, 50);
    Producto prod2(2, "Amoxicilina", 15000, 30);
    Producto prod3(3, "Vitamina C", 10000, 40);
    Producto prod4(4, "Acetaminofen", 1000, 10);
    Producto prod5(5, "Jabón Antibacterial", 8000, 25);
    Producto prod6(6, "Jabon Rey", 3000, 15);
    Producto prod7(7, "xRaydol", 20000, 5);

    // Agregamos categorías a los productos
    prod1.agregarCategoria(&catAnalgésicos);
    prod2.agregarCategoria(&catAntibióticos);
    prod3.agregarCategoria(&catVitaminas);
    prod4.agregarCategoria(&catAnalgésicos);
    prod5.agregarCategoria(&catCuidadoPersonal);
    prod5.agregarCategoria(&catAntibióticos); // Un producto puede pertenecer a varias categorías
    prod6.agregarCategoria(&catHogar);
    prod7.agregarCategoria(&catAnalgésicos);
    prod7.agregarCategoria(&catAntibióticos);// Un producto puede pertenecer a varias categorías

    // Registramos los productos en la droguería
    miDrogueria.registrarProducto(prod1);
    miDrogueria.registrarProducto(prod2);
    miDrogueria.registrarProducto(prod3);
    miDrogueria.registrarProducto(prod4);
    miDrogueria.registrarProducto(prod5);
    miDrogueria.registrarProducto(prod6);
    miDrogueria.registrarProducto(prod7);

    // Creamos los clientes
    Cliente cliente1("Bucheli Guerrero");
    Cliente cliente2("Sebastian Orejuela");

    // El cliente compra algunos productos
    cliente1.agregarProductoComprado(&prod1);
    cliente1.agregarProductoComprado(&prod3);
    cliente1.agregarProductoComprado(&prod6);
    cliente2.agregarProductoComprado(&prod2);
    cliente2.agregarProductoComprado(&prod4);

    // Variables para el sistema de login
    string nombre, password; // Variables para almacenar las credenciales de inicio de sesión
    char tipoUsuario; // Variable para almacenar el tipo de usuario
    int opcionLogin; // Variable para almacenar la opción seleccionada en el menú de login

    // Creamos usuarios para el sistema
    SistemaLogin* usuarioActual = nullptr; // Puntero al usuario que tiene la sesión activa
    SistemaLogin adminUser("Andres", "Andres123", 'A'); // Usuario administrador
    SistemaLogin clienteUser("Bucheli", "Bucheli123", 'C'); // Usuario cliente
    SistemaLogin clienteUser2("Sebastian", "Sebastian123", 'C'); // Usuario cliente

    // Bucle principal del programa
    bool salir = false; // Variable para controlar la salida del programa

    while (!salir) {
        // Mostramos el menú de login
        cout << "\n==== SISTEMA DE DROGUERÍA - LOGIN ====" << endl;
        cout << "1. Iniciar sesión" << endl;
        cout << "2. Recuperar contraseña" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcionLogin; // Leemos la opción ingresada por el usuario

        // Procesamos la opción seleccionada
        switch (opcionLogin) {
            case 1: { // Iniciar sesión
                cout << "Ingrese nombre de usuario: ";
                cin >> nombre; // Leemos el nombre de usuario
                cout << "Ingrese contraseña: ";
                cin >> password; // Leemos la contraseña

                // Intentamos iniciar sesión como administrador
                if (adminUser.iniciarSesion(nombre, password)) {
                    usuarioActual = &adminUser; // El usuario actual es el administrador
                    menuAdministrador(adminUser, miDrogueria); // Mostramos el menú de administrador
                }
                // Intentamos iniciar sesión como cliente
                else if (clienteUser.iniciarSesion(nombre, password)) {
                    usuarioActual = &clienteUser; // El usuario actual es el cliente
                    menuCliente(clienteUser, miDrogueria, cliente1); // Mostramos el menú de cliente
                }
                // Credenciales incorrectas
                else {
                    cout << "Credenciales incorrectas. Intente nuevamente." << endl;
                }
                break;
            }

            case 2: // Recuperar contraseña
                cout << "Ingrese nombre de usuario: ";
                cin >> nombre; // Leemos el nombre de usuario

                // Verificamos si el usuario existe
                if (nombre == "admin" || nombre == "cliente") {
                    cout << "Se ha enviado un correo con instrucciones para recuperar la contraseña." << endl;
                    // En una aplicación real, aquí se enviaría un correo electrónico
                    adminUser.olvidarPassword(); // Mostramos mensaje para contactar al administrador
                } else {
                    cout << "Usuario no encontrado." << endl;
                }
                break;

            case 3: // Salir
                cout << "Gracias por usar el sistema. ¡Hasta pronto!" << endl;
                salir = true; // Indicamos que queremos salir del programa
                break;

            default: // Opción inválida
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    }

    return 0; // Terminamos el programa con éxito
}