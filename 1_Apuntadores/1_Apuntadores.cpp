// 1_Apuntadores.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>

void PruebadeArgumentos(int argc, char** argv)
{
    //si el programa tiene argumentos
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::cout << argv[i] << "\n";
            //toda cadena termina con un caracter /0
            int j = 0;
            int value = 0;
            std::cout << " ";
            do
            {
                value = (int)argv[i][j];
                std::cout << argv[i][j] << " = " << value << " 0x" << std::hex << value << "\n ";
                j++;
            } while (argv[i][j] != 0);

            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "No se dio argumentos" << "\n";
    }
}

void Promedio(int argc, char** argv)
{
    //ejercicio 2 de apuntadores

    //forma C++ de asignar la memoria
    int* x = new int;

    *x = 99;

    std::cout << "sizeof int " << sizeof(int) << "\n";
    std::cout << " x " << *x << " en " << x << "\n";

    *x = 'k';

    std::cout << "sizeof int " << sizeof(int) << "\n";
    std::cout << " x " << *x << " en " << x << "\n";

    *(x + 1) = 18;
    std::cout << " x+1 " << *(x + 1) << " en " << x + 1 << "\n";


    int* y = new int[100];

    //luego sacar el promedio
    int* acumulador = new int;
    *acumulador = 0;
    char* isit = new char;
    *isit = 64;
    float* cumulus = new float;
    *cumulus = 0.0;
    memset(y, 64, 100 * sizeof(int));
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Pon un numero \n";
        std::cin >> y[i];

        if (y[i] > 0 && y[i] < 2147483647)
        {
            std::cout << " y[ " << i << " en " << "] = " << y[i] << "\n";
            *acumulador += y[i];
            *cumulus += 1.0;

            std::cout << "Desea continuar y/n? \n";
            std::cin >> isit;

            if (*isit == 121)
            {

            }
            else if (*isit == 110)
            {
                std::cout << "Gracias participar, su promedio es \n";
                break;
            }
            else
            {
                std::cout << (int)*isit << "\n";
                std::cout << "Respuesta no valida \n";
                std::cout << "Se continuara el proceso \n";
            }
        }
        else
        {
            std::cout << "Input no valido terminando proceso\n";
            *cumulus += 1.0;
            break;
        }
    }
    float promedio = *acumulador / *cumulus;

    //hacer un programa el cual pida el usuario una serie de valores
    //y luego pida el promedio.

    std::cout << " promedio = " << promedio << "\n";
}

int main(int argc, char** argv)
{
    //apuntador a funcion
    void (*Proceso)(int, char**) = nullptr;

    //preguntar al usuario la funcion deseada
    std::cout << "Funciones disponibles: \n";
    std::cout << "1. Prueba de Argumentos \n";
    std::cout << "2. Promedio \n";
    std::cout << "Teclea el numero de la funcion que quieres \n";

    int seleccion;
    std::cin >> seleccion;

    if (seleccion == 1)
        Proceso = &PruebadeArgumentos;
    else if (seleccion == 2)
        Proceso = &Promedio;
    else
    {
        std::cout << "Opcion no valida \n";
        main(argc, argv);
    }

  


    return 0;
}