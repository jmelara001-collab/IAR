#include <Arduino.h>
#include "Mate.h"

Mate lista1;
Mate lista2;
Mate lista3;

void setup() 
{
  Serial.begin(115200);

  // Inicializamos la semilla del random con una lectura analógica al aire
  randomSeed(analogRead(0)); 

  lista1.agregar();
  lista1.agregar();

  lista2.agregar();
  lista2.agregar();  
  lista2.agregar();
}

void loop() 
{
  Serial.print("Lista 1 - Cantidad: ");
  Serial.println(lista1.contar());
  Serial.print("Lista 1 - Suma: ");
  Serial.println(lista1.sumar());
  Serial.print("Lista 1 - Promedio: ");
  Serial.println(lista1.promediar());
  Serial.println("--------------------");
 
  Serial.print("Lista 2 - Cantidad: ");
  Serial.println(lista2.contar());
  Serial.print("Lista 2 - Suma: ");
  Serial.println(lista2.sumar());
  Serial.print("Lista 2 - Promedio: ");
  Serial.println(lista2.promediar());
  Serial.println("====================");

  delay(5000); // 5 segundos para que no sature el monitor serie
}