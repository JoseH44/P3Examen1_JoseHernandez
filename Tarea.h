#ifndef TAREA_H
#define TAREA_H

#include <iostream>
using namespace std;

#include <string>
using std::string;

class Tarea
{
	private:
		string descripcion;
		int nivel;
		int carga_tarea;
		
	public:
		Tarea();
		Tarea(string,int,int);
		//setter y getter de la descripcion
		string getDescripcion();
		void setDescripcion(string);
		//setter y getter del nivel
		int getNivelT();
		void setNivelT(int);
		//getter y setter de la carga de la tarea
		int getCarga_Tarea();
		void setCarga_Tarea(int);
		~Tarea();
	
};

#endif
