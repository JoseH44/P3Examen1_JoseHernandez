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
				/*int num_random1,num_random2;//numero random
				
				srand(time(NULL));
				num_random1 = 0 + rand()% (101-1);
				num_random2 = 0 + rand()% (101-1);*/
				
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
				//acumula el valor de carga de todas las tareas
				for(int i = 0;i < lista_tareas.size();i++){
					N += lista_tareas[i]->getCarga_Tarea();
				}
				int dias_esperados;
				//determina la cantidad de días necesarios para terminar el proyecto
				dias_esperados = N+(N*0.20);
				int subMenu = 0;
				while(subMenu != 3){
					cout<<endl<<"1.Siguiente Dia"<<endl<<"2.Generar Reporte"<<endl<<"3.Salir"<<endl<<"Escoja una Opcion:";
					cin >> subMenu;
					switch(subMenu){
						case 1:{
							break;
						}
						case 2:{
							break;
						}
						case 3:{
							cout<<"Ha Salido del Proyecto"<<endl;
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
