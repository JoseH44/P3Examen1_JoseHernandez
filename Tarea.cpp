#include "Tarea.h"

Tarea::Tarea()
{
}

Tarea::Tarea(string descripcion,int nivel,int carga_tarea){
	this->descripcion = descripcion;
	this->nivel = nivel;
	this->carga_tarea = carga_tarea;
}

string Tarea::getDescripcion(){
	return (descripcion);
}

void Tarea::setDescripcion(string pDescripcion){
	descripcion = pDescripcion;
}

int Tarea::getNivelT(){
	return (nivel);
}

void Tarea::setNivelT(int pNivel){
	nivel = pNivel;
}

int Tarea::getCarga_Tarea(){
	return carga_tarea;
}

void Tarea::setCarga_Tarea(int pCarga_tarea){
	carga_tarea = pCarga_tarea;
}

Tarea::~Tarea()
{
}
