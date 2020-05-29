#include "Empleado.h"

Empleado::Empleado()
{
}

Empleado::Empleado(string nombre,int edad,int nivel,int porc_habilidad,int porc_pereza,int estado){
	this->nombre = nombre;
	this->edad = edad;
	this->nivel = nivel;
	this->porc_habilidad = porc_habilidad;
	this->porc_pereza = porc_pereza;
	this->estado = estado;
}

string Empleado::getNombre(){
	return (nombre);
}

void Empleado::setNombre(string pNombre){
	nombre = pNombre;
}

int Empleado::getEdad(){
	return (edad);
}

void Empleado::setEdad(int pEdad){
	edad = pEdad;
}

int Empleado::getNivel(){
	return (nivel);
}

void Empleado::setNivel(int pNivel){
	nivel = pNivel;
}

int Empleado::getPorcentajeHabilidad(){
	return (porc_habilidad);
}

void Empleado::setPorcentajeHabilidad(int pPorcentajeHabilidad){
	porc_habilidad = pPorcentajeHabilidad;
}

int Empleado::getPorcentajePereza(){
	return (porc_pereza);
}

void Empleado::setPorcentajePereza(int pPorcentajePereza){
	porc_pereza = pPorcentajePereza;
}

Tarea* Empleado::getTarea(){
	return tarea;
}

void Empleado::setTarea(Tarea* pTarea){
	tarea = pTarea;
}

int Empleado::getEstado(){
	return (estado);
}

void Empleado::setEstado(int pEstado){
	estado = pEstado;
}

Empleado::~Empleado()
{
}
