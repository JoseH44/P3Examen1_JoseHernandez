#include <iostream>
using namespace std;


#include <string>
using std::string;

#include "Empleado.h"

#include "Tarea.h"

#include<vector>

#include <stdlib.h>
#include <time.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	vector<Empleado*> lista_empleados;
	vector<Tarea*> lista_tareas;
	Empleado* empleado = NULL;
	Tarea* tarea1 = NULL;
	int opcion = 0;
	while(opcion != 7){
		cout<<"*********************"<<endl<<"1.Contratar Empleado"<<endl<<"2.Despedir Empleado"<<endl<<"3.Listar Empleados"
			<<endl<<"4.Crear Tarea"<<endl<<"5.Listar Tarea"<<endl<<"6.Iniciar Proyecto"<<endl<<"7.Salir"<<endl<<"Escoja una opcion:";
		cin >> opcion;
		switch(opcion){
			case 1:{
				string nombre;
				int edad,nivel,porc_habilidad,porc_pereza;
				
				
				cout<<endl<<"Ingrese el Nombre del Empleado:";
				cin >> nombre;
				cout<<endl<<"Ingrese la edad del Empleado:";
				cin >> edad;
				cout<<endl<<"Ingrese el Nivel del Empleado de 1-3:";
				cin >> nivel;
				
				while(nivel < 1 || nivel > 3){
					cout<<endl<<"El nivel debe ser entre 1 y 3";
					cout<<endl<<"Ingrese el Nivel del Empleado de 1-3:";
					cin >> nivel;
				}//validacion del nivel del empleado
				cout<<endl<<"Ingrese el Porcentaje de Habilidad del Empleado:";
				cin>>porc_habilidad;
				cout<<endl<<"Ingrese el Porcentaje de Pereza del Empleado:";
				cin >> porc_pereza;
				
				
				//creacion del empleado, con estado en 0 que representa que está desocupado
				empleado = new Empleado(nombre,edad,nivel,porc_habilidad,porc_pereza,0);
				//empleado añadido al vector
				lista_empleados.push_back(empleado);
				cout<<endl<<"Empleado Contratado Correctamente"<<endl;
				
				break;
			}
			case 2:{//despedir empleado
				int indice;
				cout<<endl<<"Ingrese el indice del Empleado a Despedir:";
				cin >> indice;
				while(indice < 0 || indice >= lista_empleados.size()){
					cout<<endl<<"El indice es Menor que 0 o no existe en la lista"<<endl;
					cout<<endl<<"Ingrese el indice del Empleado a Despedir:";
					cin >> indice;
				}//while de validacion
				lista_empleados.erase(lista_empleados.begin()+indice);
				cout<<"Empleado Despedido Exitosamente"<<endl;
				
				break;
			}
			case 3:{//listado de los empleados
				cout<<endl;
				for(int i = 0;i < lista_empleados.size();i++){
					cout<<i<<"-"<<lista_empleados[i]->getNombre()<<endl;
				}
				break;
				cout<<endl;
			}
			case 4:{//crear tarea
				string descripcion;
				int nivelT;
				int carga_tarea;
				cout<<endl<<"Ingrese La Descripcion de la tarea:";
				cin >> descripcion;
				cout<<endl<<"Ingrese El Nivel de la tarea de 1-3:";
				cin >> nivelT;
				while(nivelT < 1 || nivelT > 3){
					cout<<endl<<"El nivel debe ser entre 1 y 3";
					cout<<endl<<"Ingrese el Nivel de la tarea de 1-3:";
					cin >> nivelT;
				}//validacion del nivel de la tarea
				
				cout<<endl<<"Ingrese La carga de Tarea:";
				cin >> carga_tarea;
				//creacion de la tarea
				tarea1 = new Tarea(descripcion,nivelT,carga_tarea);
				//añadido al vector de tareas
				lista_tareas.push_back(tarea1);
				cout<<endl<<"Tarea Creada Exitosamente!"<<endl;
				break;
			}
			case 5:{//listar tareas
				cout<<endl;
				for(int i = 0;i < lista_tareas.size();i++){
					cout<<i<<"-"<<lista_tareas[i]->getDescripcion()<<endl;
				}
				break;
			}
			case 6:{//proyecto
				int N = 0;
				int tareas_proceso = 0;
				int empleados_perezosos = 0;
				int empleados_fallidos = 0;
				int empleados_lograron_dia = 0;
				//acumula el valor de carga de todas las tareas
				for(int i = 0;i < lista_tareas.size();i++){
					N += lista_tareas[i]->getCarga_Tarea();
				}
				int dias_esperados;
				//determina la cantidad de días necesarios para terminar el proyecto
				dias_esperados = N+(N*0.20);
				int subMenu = 0;
				while(subMenu != 3){
					//imprime los días restantes
					cout<<endl<<"Dias para terminar el Proyecto: "<<dias_esperados<<endl;
					cout<<endl<<"1.Siguiente Dia"<<endl<<"2.Generar Reporte"<<endl<<"3.Salir"<<endl<<"Escoja una Opcion:";
					cin >> subMenu;
					switch(subMenu){
						case 1:{
							int pereza,habilidad;//numero random
							srand(time(NULL));
							pereza = 0 + rand()% (101-0);
							habilidad = 0 + rand()% (101-0);
							
							//asignacion de tareas
							for(int i = 0;i < lista_empleados.size();i++){//for de empleados
								for(int j = 0;i < lista_tareas.size();i++){//for de tareas
									if(lista_empleados[i]->getEstado() == 0 && (lista_empleados[i]->getNivel() <= lista_tareas[i]->getNivelT() )){//revisa si esta desocupado y si tiene el nivel requerido
										lista_empleados[i]->setTarea(lista_tareas[j]);//le asigna la tarea
										lista_tareas.erase(lista_tareas.begin()+j);//elimina esa tarea del vector
										lista_empleados[i]->setEstado(1);//cambia el estado del empleado
										tareas_proceso++;//agrega +1 a las tareas que se están ejecutando
									}
								}//fin del for de las tareas
							}//fin del for de los empleados
							dias_esperados--;
							
							for(int i = 0;i < lista_empleados.size();i++){
								if(lista_empleados[i]->getEstado() == 1){//revisa si tiene una tarea en ejecucion
									
									if(lista_empleados[i]->getPorcentajePereza() < pereza){//revisa si la pereza del empleado es menor a la pereza general
										
										if(lista_empleados[i]->getPorcentajeHabilidad() > habilidad){//revisa si la habilidad del empleado es mayor a la requerida
											empleados_lograron_dia++;//agrega +1 a los empleados que lograron al dia
											int ref_carga = lista_empleados[i]->getTarea()->getCarga_Tarea();//guarda la carga de la tarea que tiene ese empleado
											lista_empleados[i]->getTarea()->setCarga_Tarea(ref_carga-1);//le setea el valor de la carga menos 1
											if(lista_empleados[i]->getTarea()->getCarga_Tarea() == 0){//si la carga de la tarea llega a 0 el empleado se desocupa
												lista_empleados[i]->setEstado(0);
											}
										}else{
											empleados_fallidos++;//empleado que no pudo realizar la tarea
										}
									}else{
										empleados_perezosos++;
									}
								}
							}
							break;
							
						}
						case 2:{//reporte del día
							cout<<endl;
							int tareas_en_backlog = lista_tareas.size();
							cout<<"Tareas en Blacklog: "<<tareas_en_backlog<<endl;
							cout<<"Tareas en Progreso: "<<tareas_proceso<<endl;
							cout<<"Empleados Perezosos: "<<empleados_perezosos<<endl;
							cout<<"Empleados que Fallaron: "<<empleados_fallidos<<endl;
							cout<<"Empleados que Lograron el Dia: "<<empleados_lograron_dia<<endl;
							
							
						}
						case 3:{
							cout<<"Ha Salido del Proyecto"<<endl;
							lista_tareas.erase(lista_tareas.begin());
							break;
						}
					}//fin del switch dentro del proyecto
				}//fin del while que está dentro del proyecto
				
				break;
			}
			case 7:{
				cout<<endl<<"Vuelva Pronto!";
				break;
			}
			
		}//fin del switch
		
	}//fin del while
	
	delete empleado;
	delete tarea1;
	lista_empleados.erase(lista_empleados.begin());
	lista_tareas.erase(lista_tareas.begin());
	return 0;
}
