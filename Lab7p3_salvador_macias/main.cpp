

#include <iostream>
#include <vector>
#include "robot.h"
#include "robot_mecanico.h"
#include "robot_explorador.h"


using namespace std;

vector<RobotMecanico>lista_m;
vector<RobotExplorador>lista_e;
vector<Robot>lista;



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
                        cout<<"[explorador]"<<lista_e[i].getNombre()
                        <<"|"<<" capacidad : "<<lista_e[i].getCapacidadTotal()<<"|"
                        <<" |"<<" alcance: "<<lista_e[i].getAlcanceTerreno()<<"|"
                        <<" |"<<endl;
                        
                        
                        
                        ;
                    }
                    
                    for (int i=0; i<lista_m.size(); i++) {
                        cout<<"[mecanico]"<<lista_e[i].getNombre()
                        <<"|"<<"capacidad: "<<lista_m[i].getCapacidadTotal()<<"|"
                        <<" |"<<"potencia: "<<lista_e[i].getProcesadores()<<"|"
                        <<" |"<<endl;
                        
                        
                        
                        ;
                    }
                    
                }
                break;
            case 3:
            {
                
            }
            break;
            case 4:
            {
                for (int i=0; i<lista.size(); i++) {
                    lista[i].getNombre();
                }
                
            }
            break;
            case 5:
            {
                
            }
            break;
            case 6:
            {
                cout<<"abandonando el programa"<<endl;
                salida=true;
                
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
