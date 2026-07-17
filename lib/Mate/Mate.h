#ifndef MATE_H
#define MATE_H

#include <Arduino.h> // Necesario para usar la función random()

class Mate
{
  private:
    int lista[10];
    int contador;

  public:
    Mate();
    int contar();
    void agregar();
    int sumar();
    float promediar();
};

#endif // MATE_H