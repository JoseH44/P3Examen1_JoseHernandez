#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using std::string;

#include <iostream>
using namespace std;



#include "Tarea.h"

class Empleado
{
	private:
		Tarea* tarea = NULL;
		string nombre;
		int edad;
		int nivel;
		int porc_habilidad;
		int porc_pereza;
	public:
		Empleado();
		Empleado(string,int,int,int,int);
		
		//setters y getters del nombre
		string getNombre();
		void setNombre(string);
		//setter y getter de la edad
		int getEdad();
		void setEdad(int);
		//setter y getter del nivel
		int getNivel();
		void setNivel(int);
		//setter y getter del porcentaje de habilidad
		int getPorcentajeHabilidad();
		void setPorcentajeHabilidad(int);
		//setter y getter del porcentaje de pereza
		int getPorcentajePereza();
		void setPorcentajePereza(int);
				
		~Empleado();
	
};

#endif
