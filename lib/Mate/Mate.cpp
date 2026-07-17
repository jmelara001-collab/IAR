#include "Mate.h"

Mate::Mate()
{
  contador = 0;
}

int Mate::contar()
{
  return contador;
}

void Mate::agregar()
{
  if (contador < 10)
  {
    lista[contador] = random(10);
    contador++;
  }
}

int Mate::sumar()
{
  int suma = 0;
  for (int i = 0; i < contador; i++)
  {
    suma = suma + lista[i];
  }
  return suma;
}

float Mate::promediar()
{
  if (contador == 0) return 0.0; // Protección para evitar división por cero
  float prom = (float)sumar() / contador;
  return prom;
}