

#include <iostream>
#include <vector>
#include "robot.h"
#include "robot_mecanico.h"
#include "robot_explorador.h"


using namespace std;

vector<RobotMecanico>lista_m;
vector<RobotExplorador>lista_e;
vector <RobotMecanico, RobotExplorador> lista;



void fabrica(){
    int opc;
    bool salida = false;
    
    do {
        cout<<"--fabrica de robots--"<<endl;
        cout<<"1.crear robot "<<endl;
        cout<<"2.listar robots "<<endl;
        cout<<"3.optimizar robot "<<endl;
        cout<<"4.mostar especificaciones "<<endl;
        cout<<"5.diagnostico general "<<endl;
        cout<<"6.salir "<<endl;
        cin>>opc;
        switch (opc) {
            case 1:
            {
                int tipo;
                string nombre;
                int bateria;
                int procesadores;
                int alcance;
                int cantidad_herramientas;
                string tipo_sensor;
                int potencia_herramientas;
                
                
                
                cout<<"tipo(1. explorador, 2. mecanico)"<<endl;
                cin >>tipo;
                switch (tipo) {
                    case 1:
                    {
                        cout<<"nombre: "<<endl;
                        cin>>nombre;
                        cout<<"bateria (1-10):"<<endl;
                        cin>>bateria;
                        cout<<"procesadores (1-10):"<<endl;
                        cin>>procesadores;
                        cout<<"alcance :"<<endl;
                        cin>>alcance;
                        cout<<"cantidad sensores :"<<endl;
                        cin>>cantidad_herramientas;
                        cout<<"tipo sensor :"<<endl;
                        cin>>tipo_sensor;
                        
                        lista_e.push_back(RobotExplorador(nombre, bateria, procesadores, alcance));
                        lista.push_back(RobotExplorador(nombre, bateria, procesadores, alcance));
                        
                        cout<<"robot explorador "<<" " <<
                        nombre<< " creado corrcectamente"<<endl;
                        
                        
                    }
                        break;
                    case 2:
                    {
                        cout<<"nombre: "<<endl;
                        cin>>nombre;
                        cout<<"bateria (1-10):"<<endl;
                        cin>>bateria;
                        cout<<"procesadores (1-10):"<<endl;
                        cin>>procesadores;
                        cout<<"potencia herramienta :"<<endl;
                        cin>>potencia_herramientas;
                        cout<<"cantidad herramientas :"<<endl;
                        cin>>cantidad_herramientas;
                        
                        lista_m.push_back(RobotMecanico(nombre, bateria, procesadores));
                        lista.push_back(RobotMecanico(nombre, bateria, procesadores));
                        
                        cout<<"robot mecanico "<<" " <<
                        nombre<< " creado corrcectamente"<<endl;
                    }
                        break;
                    default:
                        cout<<"tipo ingresado es invalido"<<endl;
                        break;
                }
                
            }
                break;
            case 2:
            {
                for (int i=0; i<lista_e.size(); i++) {
                    /* cout<<"[explorador]"<<lista_e[i].getNombre()
                     <<"|"<<" capacidad : "<<lista_e[i].getCapacidadTotal()<<"|"
                     <<" |"<<" alcance: "<<lista_e[i].getAlcanceTerreno()<<"|"
                     <<" |"<<endl;*/
                    lista_e[i].mostrarEspecificaciones();
                    
                    
                    
                    ;
                }
                
                for (int i=0; i<lista_m.size(); i++) {
                    /* cout<<"[mecanico]"<<lista_m[i].getNombre()
                     <<"|"<<"capacidad: "<<lista_m[i].getCapacidadTotal()<<"|"
                     <<" |"<<"potencia: "<<lista_m[i].getProcesadores()<<"|"
                     <<" |"<<endl;*/
                    lista_e[i].Robot::mostrarEspecificaciones();
                    
                    
                    ;
                }
                
            }
                break;
            case 3:
            {
                int opc_optimizar;
                int indice_optmizar;
                cout<<"1.optimizar mecanico 2.optimizar explorador"<<endl;
                cin>>opc_optimizar;
                switch (opc_optimizar) {
                    case 1:
                    {
                        for (int i=0; i<lista_m.size(); i++) {
                            cout<<i<<" "<<lista_m[i].getNombre()<<endl;
                            cout<<"ingrese el indice: ";
                            cin>> indice_optmizar;
                            lista_m[indice_optmizar].Robot::optimizar();
                            cout<<"robot " << lista_m[i].getNombre()<<" optimizado"<<endl;
                        }
                        
                    }
                        break;
                    case 2:
                    {
                        for (int i=0; i<lista_e.size(); i++) {
                            cout<<i<<" "<<lista_e[i].getNombre()<<endl;
                            cout<<"ingrese el indice: ";
                            cin>> indice_optmizar;
                            lista_e[indice_optmizar].Robot::optimizar();
                            cout<<"robot " << lista_e[i].getNombre()<<" optimizado"<<endl;
                        }
                        
                    }
                        break;
                    default:
                        cout<<"opcion ingresada es invalida"<<endl;
                        break;
                }
                
            }
                break;
            case 4:
            {
                int opc_lista;
                int indice;
                cout<<"1.lista de exploradores. 2.lista de mecanicos"<<endl;
                cin>>opc_lista;
                switch (opc_lista) {
                    case 1:
                    {
                        cout<<"lista de exploradores "<<endl<<endl;
                        for (int i=0; i<lista_e.size(); i++) {
                            cout<<i<<""<<lista_e[i].getNombre();
                        }
                        cout<<"ingrese el indice: "<<endl;
                        cin>>indice;
                        if (indice<lista_e.size()) {
                            cout<<"[explorador]"<<lista_e[indice].getNombre()
                            <<"|"<<" capacidad : "<<lista_e[indice].getCapacidadTotal()<<"|"
                            <<" |"<<" alcance: "<<lista_e[indice].getAlcanceTerreno()<<"|"
                            <<" |"<<endl;
                        }else{
                            cout<<"indice ingresado fuera de rango"<<endl;
                        }
                        
                    }
                        break;
                    case 2:
                    {
                        cout<<"lista de mecanicos "<<endl<<endl;
                        for (int i=0; i<lista_m.size(); i++) {
                            cout<<i<<""<<lista_m[i].getNombre();
                        }
                        cout<<"ingrese el indice: "<<endl;
                        cin>>indice;
                        if (indice<lista_m.size()) {
                            cout<<"[mecanico]"<<lista_e[indice].getNombre()
                            <<"|"<<"capacidad: "<<lista_m[indice].getCapacidadTotal()<<"|"
                            <<" |"<<"potencia: "<<lista_e[indice].getProcesadores()<<"|"
                            <<" |"<<endl;
                        }else{
                            cout<<"indice ingresado fuera de rango"<<endl;
                            
                        }
                        
                    }
                        break;
                    default:
                        cout<<"indice ingresado es invalido"<<endl;
                        break;
                }
                
                
                
            }
                break;
            case 5:
            {
                for (int i=0; i<lista_e.size(); i++) {
                    lista_e[i].necesitaMantenimiento();
                }
                for (int i=0; i<lista_m.size(); i++) {
                    lista_m[i].necesitaMantenimiento();
                }
                
            }
                break;
            case 6:
            {
                cout<<"abandonando el programa"<<endl;
                salida=true;
                delete lista;
              //  delete lista_e;
              //  delete lista_m;
                
            }
                break;
                
            default:
                cout<<"opcion ingresada es invalida"<<endl;
                break;
        }
        
    } while (salida!=true);
    
}


void menu(){
    fabrica();
}

int main(int argc, const char * argv[]) {
    menu();
    return 0;
}
