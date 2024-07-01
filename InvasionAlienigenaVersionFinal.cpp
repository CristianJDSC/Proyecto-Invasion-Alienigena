#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <conio.h>
#include <string.h>
#include <limits>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;

//Integrantes: Ana Rivas, Cristian De Sousa, Jose Ignacio Rivas

//-------------------------------------------------------------------VECTOR DE LOS AMBIENTES------------------------------------------------------------------
vector<string> vector_ambientes = {};

//-------------------------------------------------------------------FUNCIONES DE MENUS------------------------------------------------------------------


void menuPrincipal(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Principal.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Especies" << endl;
    cout << "2. Ambientes" << endl;
    cout << "3. Accesorios" << endl;
    cout << "4. Soldados intergalacticos" << endl;
    cout << "5. Guerra Intergalactica" << endl;
    cout << "0. Salir" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}

void menuEspecies(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Especies.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Ver las especies y sus caracteristicas" << endl;
    cout << "2. Agregar especies" << endl;
    cout << "3. Eliminar especies" << endl;
    cout << "4. Modificar especies" << endl;
    cout << "0. Regresar" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}

void menuAmbientes(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Ambientes.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Ver los ambientes" << endl;
    cout << "2. Agregar ambientes" << endl;
    cout << "3. Eliminar ambientes" << endl;
    cout << "4. Modificar ambientes" << endl;
    cout << "0. Regresar" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}

void menuAccesorios(){

    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Accesorios.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Ver los accesorios" << endl;
    cout << "2. Agregar accesorios" << endl;
    cout << "3. Eliminar accesorios" << endl;
    cout << "4. Modificar accesorios" << endl;
    cout << "0. Regresar" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";

}

void menuAccesoriosTipos () {
    system ("cls");
    cout << " Seleccione el tipo del accesorio: " << endl;
    cout << " [1] Ataque " << endl;
    cout << " [2] Defensa " << endl;
    cout << " [3] Supervivencia " << endl;
    cout << " [4] Acondicionamiento " << endl;
    cout << "Elija una opcion: ";
}

void menuSoldados () {
    system("cls");
    cout << "--------------------" << endl;
    cout << "  .Menu Soldados Intergalacticos.  " << endl;
    cout << "--------------------" << endl;
    cout << "1. Ver los soldados" << endl;
    cout << "2. Enlistar soldados" << endl;
    cout << "3. Dar de baja soldados" << endl;
    cout << "4. Modificar soldados" << endl;
    cout << "0. Regresar" << endl;
    cout << "--------------------" << endl;
    cout << " Introduzca una opcion: ";
}

//-------------------------------------------------------------------VALIDACIONES GNRALES------------------------------------------------------------------

int obtenerEnteroPositivo() {  //valida entrada hasta que sea un solo char numerico >=1 (se usa para recibir datos en los que no admitimos ceros)
    while (true) {
        string entrada;
        cin >> entrada;
        bool esNumeroValido;
    
        esNumeroValido = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumeroValido = false;
                break;
            }
        }

        if (esNumeroValido && stoi(entrada) >= 1) {
            return stoi(entrada);
        } else {
            //system("cls");
            cout << "----------------------   PELIGRO   ------------------" << endl;
            cout << "           El dato ingresado no es valido "  << endl;
            cout << "      Por favor, verifique el dato a introducir :     " << endl;
            cout << " Debe ser solo un caracter numerico entero positivo >= 1 :     " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int obtenerPorcentaje() {  //valida entrada hasta que sea solo un numero >=1 y <=100 
    string entrada;
    bool esNumeroValido;

    while (true) {
        cout << endl;
        cout << "Por favor, introduzca un porcentaje (1-100): ";
        cin >> entrada;

        esNumeroValido = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumeroValido = false;
                break;
            }
        }

        if (esNumeroValido && stoi(entrada) >= 1 && stoi(entrada) <= 100) {
            return stoi(entrada);

        } else {
            cout << endl;
            cout << "----------------------   PELIGRO   ------------------" << endl;
            cout << "           El dato ingresado no es valido "  << endl;
            cout << "      Por favor, verifique el dato a introducir :     " << endl;
            cout << "   Debe ser solo un numero entero positivo del 1 al 100 :     " << endl;
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char obtenerOpcionMenu(char max) {
    while (true) {
        string entrada;
        cin >> entrada;

        if (entrada.length() == 1 && (entrada[0] >= '0' && entrada[0] <= max)) {
            system("cls");
            return entrada[0];
        } else {
            cout << "----------------------   PELIGRO   ------------------" << endl;
            cout << "           El dato ingresado no es valido "  << endl;
            cout << "      Por favor, verifique el dato a introducir :     " << endl;
            cout << "Debe ser solo un caracter numerico entero positivo del 0 al "<<max<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

char obtenerOpcionRecurso() { //valida la opc de recursos (salud o energia) que recupera x accesorio. 
    while (true) {
        string entrada;
        cin >> entrada;

        if (entrada.length() == 1 && (entrada[0] >= '1' && entrada[0] < '3')) {
            system("cls");
            return entrada[0];
        } else {
            cout << "----------------------   PELIGRO   ------------------" << endl;
            cout << "           El dato ingresado no es valido "  << endl;
            cout << "      Por favor, verifique el dato a introducir :     " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

//-------------------------------------------------------------------FUNCIONES DE ESPECIES------------------------------------------------------------------

struct especie{
    string nombre;
    int energia;
    int salud;
    string ambiente;
    struct especie *prox;
};
typedef struct especie *especiePTR;

especiePTR listaEspecie = NULL;

especiePTR crearNodoEspecie(string nombre, int energia, int salud,  string ambiente){
    especiePTR p;
    p = new(struct especie);
    p->nombre = nombre;
    p->energia = energia;
    p->salud = salud;
    p->ambiente = ambiente;
    p->prox = NULL;
    return(p);
}

void RegistroListaEspecie(especiePTR &listaEspecie, string nombre, int energia, int salud, string ambiente){
    especiePTR p = crearNodoEspecie(nombre, energia, salud, ambiente);
	if(listaEspecie == NULL){
		listaEspecie = p;
	}
	else {
		especiePTR t = listaEspecie;
		while(t->prox != NULL){
			t= t->prox;
		}
		t->prox = p;
	}
} 

void MostrarEspecies(especiePTR &listaEspecie){
    int cont = 1;
    if(listaEspecie == NULL){
		cout << "Wow, la galaxia esta vacia :/... Aun no se ha creado ninguna especie" << endl;
	}
    else {
        especiePTR t = listaEspecie;
        cout << "       e s p e c i e s" << endl;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << left << setw(30) << setfill(' ') << "NOMBRE" << left << setw(30) << setfill(' ') << "ENERGIA" << left << setw(30) << setfill(' ') << "SALUD" << left << setw(20) << setfill(' ') << "AMBIENTE" << endl;
        cout << endl;
        while(t != NULL){
            cout << "Especie N" << cont << endl;
            cout << left << setw(30) << setfill(' ') << t->nombre;
            cout << left << setw(30) << setfill(' ') << t->energia;
            cout << left << setw(30) << setfill(' ') << t->salud;
            cout << left << setw(30) << setfill(' ') << t->ambiente << endl;
            cout << endl;
            t = t->prox;
            cont = cont + 1;
        }
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
}

void MostrarEspecie (especiePTR t) { //muestra una sola especie en especifico
    cout << endl;
    cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ENERGIA" << left << setw(20) << setfill(' ') << "SALUD" << left << setw(20) << setfill(' ') << "AMBIENTE" << endl;
    cout << endl;
    cout << left << setw(20) << setfill(' ') << t->nombre;
    cout << left << setw(20) << setfill(' ') << t->energia;
    cout << left << setw(20) << setfill(' ') << t->salud;
    cout << left << setw(20) << setfill(' ') << t->ambiente << endl;
    cout << endl;
}

bool ExisteNombreEspecie(especiePTR &listaEspecie, string nombre){
    especiePTR p = listaEspecie;
    while(p != NULL){
        if(p->nombre == nombre){
            return true;
        }
        p = p->prox;
    }
    return false;
}

string ValidarNombreEspecie (especiePTR &listaEspecie) { //para evitar especies con nombres repetidos
    while (true) {
        system("cls");
        string nombre;
        cout << "Ingrese el nombre de la especie: "; cin.ignore(); getline(cin, nombre);
        
        if (!ExisteNombreEspecie(listaEspecie, nombre)) {
            return nombre;
        } else {
            cout << "El nombre " << nombre << " ya se encuentra ocupado. Intentelo de nuevo" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            system("PAUSE");
        }
    }
}


/*void EliminarEspecie (especiePTR &listaEspecie) { //lo movi al final porque necesita cosas de soldados
    especiePTR p, ant; p = listaEspecie;
    int cont, posicion; cont = 0;
    bool found = false;
    
    MostrarEspecies(listaEspecie);

    if (listaEspecie != NULL) {
        cout << "Ingrese el numero N de la especie que desea exterminar: "; posicion = obtenerEnteroPositivo();

        while (p != NULL) {
            cont++;
            if (cont == posicion) {
                found = true;
                if (p == listaEspecie) {
                    listaEspecie = listaEspecie->prox;
                } else {
                    ant->prox = p->prox;
                }
                ActualizarSoldadosEspecies(listaSoldados, p); //antes de eliminar la especie, declara campo especie en soldado como NULL
                delete(p);
                cout << "La especie ha sido encontrada y eliminada" << endl;
                return;
            }
            ant = p;
            p = p->prox;
        }
        if (!found) {
            cout << "La especie N" << posicion << " no se encuentra registrada" << endl;
        }
    } 
}*/

//-------------------------------------------------------------------FUNCIONES DE AMBIENTES------------------------------------------------------------------

bool ExisteNombreAmbiente(vector<string>& vector_ambientes, string ambiente){
    int vecsize = static_cast<int>(vector_ambientes.size());
    for (int i = 0; i < vecsize; i++){
        if (vector_ambientes[i] == ambiente) {
            return true;
        }
    }
    return false;
}

void MostrarAmbientes(vector<string>& vector_ambientes){
    int vecsize = static_cast<int>(vector_ambientes.size());
    if (vector_ambientes.size()!=0){
        cout << "       a m b i e n t e s" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for (int l=0; l<vecsize; l++){
            cout << "Ambiente N" << l+1 << ": " << vector_ambientes[l] << endl;
        }
        cout << "--------------------------------------------------------------------------" << endl;
    }else{
        cout << "Wow, la galaxia esta vacia :/... Aun no se ha creado ningun ambiente" << endl;
    }
    
}

void AgregarAmbiente(vector<string>& vector_ambientes, string ambiente){
    if(!ExisteNombreAmbiente(vector_ambientes, ambiente)){
        vector_ambientes.push_back(ambiente);
        cout << "El ambiente " << ambiente << " ha sido aniadido: " << endl;
        MostrarAmbientes(vector_ambientes);
    } else {
        cout << "El ambiente " << ambiente << " ya se encuentra registrado" << endl;
    }
}

bool ExisteAmbiente(vector<string>& vector_ambientes, int N){
    int vecsize = static_cast<int>(vector_ambientes.size());
    for (int i = 0; i < vecsize; i++){
        if (i == N-1) {
            return true;
        }
    }
    return false;
}

string ConsultarAmbiente (vector<string> &vector_ambiente) {
    int N;
    while (true) {
        cout << "Ingrese el numero de ambiente: "; N = obtenerEnteroPositivo();
        if (ExisteAmbiente(vector_ambiente, N)) {
            return vector_ambiente[N-1];
        } else {
            cout << "El ambiente introducido aun no ha sido registrado." << endl;
        }
    }
    
}

//-------------------------------------------------------------------FUNCIONES DE ACCESORIOS------------------------------------------------------------------

struct accesorio{
    string nombre;
    string tipo;
    int valor;
    string tipo_valor;
    int energia;
    int contenedor;
    struct accesorio *prox;
};
typedef struct accesorio *accesorioPTR;

accesorioPTR listaAccesorio = NULL;

accesorioPTR crearNodoAccesorio(string nombre, string tipo, int valor, string tipo_valor, int energia, int contenedor){
    accesorioPTR p;
    p = new(struct accesorio);
    p->nombre = nombre;
    p->tipo = tipo;
    p->valor = valor;
    p->tipo_valor = tipo_valor;
    p->energia = energia;
    p->contenedor = contenedor;
    p->prox = NULL;
    return(p);
}

void RegistroListaAccesorio(accesorioPTR &listaAccesorio, string nombre, string tipo, int valor, string tipo_valor, int energia, int contenedor){
    accesorioPTR p = crearNodoAccesorio(nombre, tipo, valor, tipo_valor, energia, contenedor);
	if(listaAccesorio == NULL){
		listaAccesorio = p;
	}
	else {
		accesorioPTR t = listaAccesorio;
		while(t->prox != NULL){
			t= t->prox;
		}
		t->prox = p;
	}
} 

void MostrarAccesorios(accesorioPTR &listaAccesorio){
    int cont = 1;
    if(listaAccesorio == NULL){
		cout << "Aun no ha creado ningun accesorio" << endl;
	}
    else {
        accesorioPTR t = listaAccesorio;
        cout << "                                                                          a c c e s o r i o s" << endl;
        cout << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << left << setw(45) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "TIPO" << left << setw(20) << setfill(' ') << "VALOR" << left << setw(20) << setfill(' ') << "TIPO VALOR" << left << setw(30) << setfill(' ') << "CONSUMO de MIDICLORIAS" << left << setw(30) << setfill(' ') << "VALOR INCIAL de PROTECCION" << endl;
        cout << endl;
        while(t != NULL){
            cout << "Accesorio N" << cont << endl;
            cout << left << setw(45) << setfill(' ') << t->nombre;
            cout << left << setw(20) << setfill(' ') << t->tipo;
            cout << left << setw(20) << setfill(' ') << t->valor;
            cout << left << setw(20) << setfill(' ') << t->tipo_valor;
            cout << left << setw(30) << setfill(' ') << t->energia;
            cout << left << setw(30) << setfill(' ') << t->contenedor << endl;
            cout << endl;
            t = t->prox;
            cont = cont + 1;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
}

void MostrarAccesorio (accesorioPTR t) {
    cout << endl;
    cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "TIPO" << left << setw(20) << setfill(' ') << "VALOR" << left << setw(20) << setfill(' ') << "TIPO VALOR" << left << setw(30) << setfill(' ') << "CONSUMO de MIDICLORIAS" << left << setw(30) << setfill(' ') << "VALOR INCIAL de PROTECCION" << endl;
    cout << endl;
    cout << left << setw(20) << setfill(' ') << t->nombre;
    cout << left << setw(20) << setfill(' ') << t->tipo;
    cout << left << setw(20) << setfill(' ') << t->valor;
    cout << left << setw(20) << setfill(' ') << t->tipo_valor;
    cout << left << setw(30) << setfill(' ') << t->energia;
    cout << left << setw(30) << setfill(' ') << t->contenedor << endl;
    cout << endl;
}

void MostrarDatosAccesorio (accesorioPTR t) {
    cout << "Nombre: " << t->nombre << endl;
    cout << "Tipo: " << t->tipo << endl;
    cout << "Valor: " << t->valor << endl;
    cout << "Tipo valor: " << t->tipo_valor << endl;
    cout << "Consumo de midiclorias: " << t->energia << endl;
    cout << "Valor de proteccion inicial: " << t->contenedor << endl;
    cout << endl;
}

bool ExisteNombreAccesorio(accesorioPTR &listaAccesorio, string nombre){
    accesorioPTR p = listaAccesorio;
    while(p != NULL){
        if(p->nombre == nombre){
            return true;
        }
        p = p->prox;
    }
    return false;
}

string ValidarNombreAccesorio (accesorioPTR &listaAccesorio) {
    while (true) {
        system("cls");
        string nombre;
        cout << "Ingrese el nombre del accesorio: "; cin.ignore(); getline(cin, nombre);
        
        if (!ExisteNombreAccesorio(listaAccesorio, nombre)) {
            return nombre;
        } else {
            cout << "El nombre del accesorio ya se encuentra ocupado. Intentelo de nuevo" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            system("PAUSE");
        }
    }
}

//-------------------------------------------------------FUNCION DE ELIMINACION Y MODIFICACION DE AMBIENTES-------------------------------------------------------------------------
void EliminarAmbiente(vector<string>& vector_ambientes, especiePTR &listaEspecie, accesorioPTR &listaAccesorio){
    int posicion; 
    bool found = false;
    string ambientemodif;
    especiePTR p = listaEspecie;
    accesorioPTR q = listaAccesorio;
    int vecsize = static_cast<int>(vector_ambientes.size());

    if (!vector_ambientes.empty()) {
        
        MostrarAmbientes(vector_ambientes);
        cout << "Ingrese el numero N del ambiente que desea eliminar: "; posicion = obtenerEnteroPositivo();

        for (int i = 0; i < vecsize; i++) {
            if (i == posicion - 1) {
                found = true;

                //TOMO EN CUENTA LAS ESPECIES YA REGISTRADAS CON EL AMBIENTE QUE ACABAMOS DE ELIIMINAR:
                if (listaEspecie != NULL) {
                    while (p != NULL) {
                        if (p->ambiente == vector_ambientes[i]) {
                            system("cls");
                            cout << "----------------------   PELIGRO   ------------------" << endl;
                            cout << "        Este ambiente aun pertenece a una especie  "  << endl;
                            cout << "          Por favor, reubique la especie...     " << endl;
                            MostrarEspecie(p);
                            cin.clear();
                            cin.sync(); 
                            cout << "Ingrese el nuevo ambiente de la especie: ";  getline(cin, ambientemodif);
                            if (!ExisteNombreAmbiente(vector_ambientes, ambientemodif)) {
                                AgregarAmbiente(vector_ambientes, ambientemodif);
                            }
                            p->ambiente = ambientemodif;
                            cout << endl << "La especie ha sido modificada" << endl;
                            system("PAUSE");
                        }
                        p = p->prox;
                    }
                }

                if (listaAccesorio!=NULL){
                    while (q != NULL) {
                        if (q->tipo_valor == vector_ambientes[i]) {
                            system("cls");
                            cout << "---------------------------   PELIGRO   ---------------------------" << endl;
                            cout << "  Este ambiente aun pertenece a un accesorio de acondicionamiento  "  << endl;
                            cout << "               Por favor, asigne un nuevo ambiente ...     " << endl;
                            MostrarAccesorio(q);
                            cin.clear();
                            cin.sync(); 
                            cout << "Ingrese el nuevo ambiente del accesorio: "; getline(cin, ambientemodif);
                            if (!ExisteNombreAmbiente(vector_ambientes, ambientemodif)) {
                                AgregarAmbiente(vector_ambientes, ambientemodif);
                            }
                            q->tipo_valor = ambientemodif;
                            cout << endl << "El accesorio ha sido modificado" << endl;
                            system("PAUSE");
                        }
                        q = q->prox;
                    }
                }

                system("cls");
                vector_ambientes.erase(vector_ambientes.begin() + i);
                cout << "El ambiente ha sido eliminado" << endl;
                break;
            }
        }
        if (!found) {
            cout << "El ambiente N" << posicion << " no se encuentra registrado" << endl;
        }
    } else {
        cout << "No hay ambientes registrados..." << endl;
    }
}

void ModificarAmbiente(vector<string>& vector_ambientes, especiePTR &listaEspecie, accesorioPTR &listaAccesorio, string ambiente){ //(en el vector)
    int vecsize = static_cast<int>(vector_ambientes.size());
    string ambientenew;
    bool found;
    for (int l=0; l<vecsize; l++){
        if (vector_ambientes[l] == ambiente){
            while (true){  //Ciclo para evitar ambientes repetidos dentro del vector
                cout << "Ingrese el nuevo nombre del ambiente: "; getline(cin,ambientenew);
                if (ExisteNombreAmbiente (vector_ambientes, ambientenew) ) {
                    cout << "El ambiente " << ambientenew << " ya se encuentra registrado" << endl;
                }
                else {
                    system("cls");
                    vector_ambientes[l] = ambientenew;
                    cout << "El ambiente '" << ambiente << "' ha sido modificado por '" << ambientenew << "'" << endl;
                    //buscar en lista p ambiente
                    especiePTR p = listaEspecie;
                    while (p != NULL) {
                        if (p->ambiente == ambiente ) {
                            p->ambiente = ambientenew;
                            cout << "El ambiente tambien ha sido modificado en la especie '" << p->nombre << "'." << endl;
                        }
                        p = p->prox;
                    }
                    //buscar en lista q accesorio
                    accesorioPTR q = listaAccesorio;
                    while (q != NULL) {
                        if (q->tipo_valor == ambiente ) {
                            q->tipo_valor = ambientenew;
                            cout << "El ambiente tambien ha sido modificado en el accesorio '" << q->nombre << "'." << endl;
                        }
                        q = q->prox;
                    }
                    break;
                }
            }
            found = true;
        }
    }
    if (!found){
        cout << "El ambiente " << ambiente << " no se encuentra registrado" << endl;
    }
}

//------------------------------------------------------------------------------TODO DE SOLDADOS-------------------------------------------------------------------------
especiePTR ObtenerEspecie () {
    especiePTR p;
    int cont, posicion; 
    bool found = false;

    cout << "Un vistazo a las especies..." << endl;
    MostrarEspecies(listaEspecie);

    if (listaEspecie != NULL) {
        while(!found){
            cont = 0;
            cout << "Escriba el numero N de la especie que desea asignar al soldado: "; posicion = obtenerEnteroPositivo();
            p = listaEspecie;
            while (p != NULL) {
                cont++;
                if (cont == posicion) {
                    found = true;
                    return (p);
                }
                p = p->prox;
            }
            if (!found) {
                cout << "Parece que la especie N" << posicion << " no existe... Intentelo de nuevo" << endl;
            }
        }
    }
    
}

accesorioPTR ObtenerAccesorio (accesorioPTR &listaAccesorio) {
    accesorioPTR t;
    int cont, posicion;
    cout << "Un vistazo a los accesorios..." << endl;
    MostrarAccesorios(listaAccesorio);

    if (listaAccesorio == NULL) {
        return NULL;
    }

    while (true) {
        cont = 0;
        if (listaAccesorio != NULL) {
            cout << "Escriba el numero N del accesorio que desea empacar: "; posicion = obtenerEnteroPositivo();
            t = listaAccesorio;

            while (t != NULL) {
                cont++;
                if (cont == posicion) {
                    return (t);
                }
                t = t->prox;
            }
            cout << "Parece que el accesorio N" << posicion << " no existe... Intentelo de nuevo." << endl;
        }
    }
}

struct soldado {
    string nombre;
    especiePTR especie;
    int salud;
    int energia;
    accesorioPTR mochila[5];
    struct soldado *prox;
};
typedef struct soldado *soldadoPTR;

soldadoPTR listaSoldados = NULL;

void EmpacarMochila (soldadoPTR p) {
    bool found=false;

    while(!found){
        cout << endl << "Puedes elegir hasta 5 accesorios para empacar en la mochila! (Tiene que haber como minimo un accesorio de tipo ataque)" << endl << endl;;
        for (int i = 0; i<5; i++ ) {
            p->mochila[i] = ObtenerAccesorio(listaAccesorio);
        }
        for (int i = 0; i<5; i++ ) {
            if (p->mochila[i]->tipo=="Ataque"){
                found=true;
            }
        }
        if(!found){
            cout<<"ERROR. Debe guardar como minimo un accesorio de ataque. Selecione los 5 accesorios nuevamente"<<endl;
            system ("PAUSE");
            system ("cls");
        }
    }
}

soldadoPTR crearNodoSoldado (string nombre) {
    soldadoPTR p;
    p = new (struct soldado);
    p->nombre = nombre;
    p->especie = ObtenerEspecie();
    p->salud=(p->especie)->salud;
    p->energia=(p->especie)->energia;
    EmpacarMochila(p);
    p->prox = NULL;
    return(p);
}

void RegistroListaSoldados (soldadoPTR &listaSoldados, string nombre){
    soldadoPTR p = crearNodoSoldado(nombre);
	if(listaSoldados == NULL){
		listaSoldados = p;
	}
	else {
		soldadoPTR t = listaSoldados;
		while(t->prox != NULL){
			t= t->prox;
		}
		t->prox = p;
	}
} 

void MostrarMochila (soldadoPTR &p) {
    for (int i = 0; i<5; i++ ) {
        if (p->mochila[i] != NULL) {
            cout << right << setw(50) << setfill(' ') << i+1 << "- " << p->mochila[i]->nombre << endl;
        } else {
            cout << right << setw(50) << setfill(' ') << i+1 << "- Espacio sin objeto" << endl;
        }
    }
}

void MostrarDatosEspecie (especiePTR &t) {
    if (t != NULL) {
        cout << "Nombre: " << t->nombre << endl; 
        cout << right << setw(33) << setfill(' ') << "Midiclorias: " << t->energia << endl;
        cout << right << setw(27) << setfill(' ') << "Salud: " << t->salud << endl;
        cout << right << setw(30) << setfill(' ') << "Ambiente: " << t->ambiente << endl;
    } else {
        cout << "Sin especie" << endl;
    }
    
}

void MostrarSoldados(soldadoPTR &listaSoldados){
    int cont = 1;
    if(listaSoldados == NULL){
		cout << "Wow, la guerra esta perdida :/... Aun no se ha enlistado ningun soldado" << endl;
	}
    else {
        soldadoPTR t = listaSoldados;
        cout << "       s o l d a d o s   i n t e r g a l a c t i c o s" << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ESPECIE" << right << setw(22) << setfill(' ') << "MOCHILA" << right << setw(47) << setfill(' ') << "SALUD" << right << setw(16) << setfill(' ') << "ENERGIA" << endl;
        cout << endl;
        while(t != NULL){
            cout << "Soldado N" << cont << endl;
            cout << left << setw(20) << setfill(' ') << t->nombre;
            MostrarDatosEspecie(t->especie);
            MostrarMochila(t);
            cout << right << setw(106) << setfill(' ') <<t->salud << right << setw(13) << setfill(' ') <<t->energia;
            cout << endl;
            t = t->prox;
            cont = cont + 1;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
}

void MostrarSoldado (soldadoPTR &t) {
    cout << endl;
    cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ESPECIE" << right << setw(16) << setfill(' ') << "MOCHILA" << right << setw(48) << setfill(' ') << "SALUD" << right << setw(16) << setfill(' ') << "ENERGIA" << endl;
    cout << endl;
    cout << endl;;
    cout << endl;
    cout << left << setw(20) << setfill(' ') << t->nombre;
    MostrarDatosEspecie(t->especie);
    MostrarMochila(t);
    cout << right << setw(102) << setfill(' ') <<t->salud << right << setw(14) << setfill(' ') <<t->energia;
    cout << endl;
}

int ContarSoldados(soldadoPTR &listaSoldados){
    int cont;
    if(listaSoldados == NULL){
		cont=0;
	}
    else {
        soldadoPTR t = listaSoldados;
        while(t != NULL){
            t = t->prox;
            cont = cont + 1;
        }
    }
    return cont;
}

bool ExisteNombreSoldado(soldadoPTR &listaSoldados, string nombre){
    soldadoPTR p = listaSoldados;
    while(p != NULL){
        if(p->nombre == nombre){
            return true;
        }
        p = p->prox;
    }
    return false;
}

string ValidarNombreSoldado (soldadoPTR &listaSoldados) {
    while (true) {
        system("cls");
        string nombre;
        cout << "Ingrese el nombre del soldado: "; cin.ignore(); getline(cin, nombre);
        
        if (!ExisteNombreSoldado(listaSoldados, nombre)) {
            return nombre;
        } else {
            cout << "El nombre " << nombre << " ya se encuentra ocupado. Intentelo de nuevo" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            system("PAUSE");
        }
    }
}

bool RequisitosSoldado (especiePTR &listaEspecie, accesorioPTR &listaAccesorio, vector<string> &vector_ambientes) {
    if (listaEspecie != NULL && listaAccesorio != NULL && !vector_ambientes.empty()) {
        return true;
    }
    cout << "Asegurate de contar con especies, accesorios y ambientes disponibles para proveer a tus tropas!" << endl;
    cout << "Regresa al Menu Principal, crealos e intentalo de nuevo" << endl;
    return false;
}

void EliminarSoldado (soldadoPTR &listaSoldados) {
    soldadoPTR p, ant;
    int cont, posicion; cont = 0;
    bool found = false;
    
    MostrarSoldados(listaSoldados);

    if (listaSoldados != NULL) {
        p = listaSoldados;
        cout << "Ingrese el numero N del soldado que desea despedir: "; posicion = obtenerEnteroPositivo();

        while (p != NULL) {
            cont++;
            if (cont == posicion) {
                found = true;
                if (p == listaSoldados) {
                    listaSoldados = listaSoldados->prox;
                } else {
                    ant->prox = p->prox;
                }
                delete(p);
                cout << "El soldado ha sido encontrado y despedido" << endl;
                return;
            }
            ant = p;
            p = p->prox;
        }
        if (!found) {
            cout << "El soldado N" << posicion << " no se encuentra registrado" << endl;
        }
    } 
}



//-----------------------------------------------------------FUNCION DE MODIFICACION GRAL DE ESPECIES------------------------------------------------------------------

void ModificarDatosEspecie(especiePTR &listaEspecie, vector<string> &vector_ambientes) {
    char opc;
    bool found;
    string nombre, ambiente;
    int energia, posicion, cont; cont = 0;
    especiePTR p = listaEspecie;

    MostrarEspecies(listaEspecie);

    if (listaEspecie != NULL) {
        cout << "Ingrese el numero N de la especie que desea modificar: "; posicion = obtenerEnteroPositivo();

        while (p != NULL) {
            cont++;
            if (cont == posicion) {
                found = true;

                do {
                    system ("cls");
                    MostrarEspecie(p);
                    cout << " Que desea modificar? " << endl;
                    cout << " [1] Nombre " << endl;
                    cout << " [2] Energia " << endl;
                    cout << " [3] Ambiente " << endl;
                    cout << " [0] Nada, quiero volver... " << endl;
                    cout << "Elija una opcion: ";
                    opc = obtenerOpcionMenu('3');

                    switch (opc){

                        case '1':
                        system("cls");
                        cout << "Escriba el nuevo nombre de la especie: ";
                        p->nombre = ValidarNombreEspecie(listaEspecie);
                        cout << "Los datos de la especie N" << posicion << " han sido actualizados." << endl;
                        MostrarEspecie(p);
                        system("PAUSE");
                        break;

                        case '2':
                        system("cls");
                        cout << "Ingrese la nueva cantidad de energia: "; energia = obtenerEnteroPositivo();
                        p->energia = energia;
                        cout << "Los datos de la especie N" << posicion << " han sido actualizados." << endl;
                        MostrarEspecie(p);
                        system("PAUSE");
                        break;

                        case '3':
                        system("cls");
                        cout << "Ingrese el nuevo ambiente de la especie: "; cin.ignore(); getline(cin, ambiente);
                        if (!ExisteNombreAmbiente(vector_ambientes, ambiente)){
                            AgregarAmbiente(vector_ambientes, ambiente);
                        }
                        p->ambiente = ambiente;
                        cout << "Los datos de la especie N" << posicion << " han sido actualizados." << endl;
                        MostrarEspecie(p);
                        system("PAUSE");
                        break;
                        
                        default:
                        system("cls");
                        if (opc!='0') {
                            cout << "Introduzca una opcion valida" << endl;
                            system("PAUSE");
                        }
                    }
                } while(opc!='0');
            }
            p = p->prox;
        }
        if (!found) {
            cout << "La especie N" << posicion << " no se encuentra registrada" << endl;
        }
    }
}

//-----------------------------------------------------------FUNCION DE MODIFICACION GRAL DE ACCESORIOS------------------------------------------------------------------

void ModificarAccesorio (accesorioPTR &listaAccesorio, vector<string> &vector_ambientes) {
    char opc, opcTipo, opcRecurso;
    int cont=0, posicion;
    bool menuTipos, found = false;
    accesorioPTR p = listaAccesorio;
    
    MostrarAccesorios(listaAccesorio);

    if (listaAccesorio != NULL) {
        cout << "Ingrese el numero N del accesorio que desea modificar: "; posicion = obtenerEnteroPositivo();
        while (p != NULL) {
            cont++;
            if (cont == posicion) {
                found = true;
                do {
                    system ("cls");
                    MostrarAccesorio(p);
                    cout << " Que desea modificar? " << endl;
                    cout << " [1] Nombre " << endl;
                    cout << " [2] Consumo de midiclorias " << endl;
                    cout << " [3] Tipo " << endl;
                    cout << " [0] Nada, quiero volver... " << endl;
                    cout << "Elija una opcion: ";
                    opc = obtenerOpcionMenu('3');

                    switch (opc) {
                        case '1':
                        system("cls");
                        p->nombre = ValidarNombreAccesorio(listaAccesorio);
                        system("PAUSE");
                        break;

                        case '2':
                        system("cls");
                        cout << "Ingrese el valor de midiclorias que consumira el uso del accesorio: "; 
                        p->energia = obtenerEnteroPositivo();
                        system("PAUSE");
                        break;

                        case '3':
                        system("cls");
                        menuTipos = true;
                        do {
                            menuAccesoriosTipos();
                            opcTipo = obtenerOpcionMenu('4');

                            switch (opcTipo)  {

                                case '1':
                                p->tipo = "Ataque";
                                cout << "Ingrese el PORCENTAJE de DANIO que podra realizar sobre el oponente: "; 
                                p->valor = obtenerPorcentaje();
                                p->tipo_valor = "0";
                                p->contenedor = 0;
                                break;

                                case '2':
                                p->tipo = "Defensa";
                                cout << "Ingrese el PORCENTAJE de DEFENSA contra el oponente: "; 
                                p->valor = obtenerPorcentaje();
                                p->tipo_valor = "0";
                                cout << "Ingrese el valor inicial de proteccion que otorgara su uso: "; 
                                p->contenedor = obtenerEnteroPositivo();
                                break;

                                case '3':
                                p->tipo = "Supervivencia";
                                p->contenedor = 0;
                                cout << " Seleccione el tipo de recurso que recupera" << endl;
                                cout << " [1] Energia " << endl;
                                cout << " [2] Salud " << endl;
                                cout << "Elija una opcion: ";
                                opcRecurso = obtenerOpcionRecurso();
                                switch (opcRecurso) {
                                    case '1':
                                    p->tipo_valor = "Energia";
                                    cout << "Ingrese el PORCENTAJE de ENERGIA que se podra recuperar con su uso: "; 
                                    p->valor = obtenerPorcentaje();
                                    break;

                                    case '2':
                                    p->tipo_valor = "Salud";
                                    cout << "Ingrese el PORCENTAJE de SALUD que se podra recuperar con su uso: "; 
                                    p->valor = obtenerPorcentaje();
                                    break;
                                }
                                break;

                                case '4':
                                p->tipo = "Acondicionamiento";
                                p->valor = 0;
                                p->contenedor = 0;
                                MostrarAmbientes(vector_ambientes);
                                cout << "Para cual ambiente esta diseniado?: " << endl;
                                p->tipo_valor = ConsultarAmbiente(vector_ambientes);
                                break;

                            }
                            cout << "El accesorio " << p->nombre << " ha sido modificado" << endl;
                            menuTipos = false;             
                        } while (menuTipos);
                        system("PAUSE");
                        break;

                    }
                } while(opc!='0');
                break;
            }
            p=p->prox;
        }
        if (!found) {
            cout << "El accesorio N" << posicion << " no se encuentra registrado" << endl;
        }
    } 
}

//-----------------------------------------------------------MODIFICACION GRAL Y ACTUALIZACION DE SOLDADOS------------------------------------------------------------------------------------------

void ModificarMochila (soldadoPTR &p, vector<string> &vector_ambientes) {
    char opc;
    int posicion; int cant_ataque=0;
    bool menu = true, mochila_full=true;

    do {
        system("cls");
        MostrarMochila(p);

        cout << " Que modificaciones desea realizar? " << endl;
        cout << " [1] Agregar un objeto " << endl;
        cout << " [2] Desempacar un objeto " << endl;
        cout << " [3] Modificar un objeto " << endl;
        cout << " [0] Nada, quiero volver... " << endl;
        cout << "Elija una opcion: ";
        opc = obtenerOpcionMenu('3');

        switch (opc) {
            case '1':
            system("cls");
            MostrarMochila(p);
            for (int i = 0; i<5; i++) {
                if (p->mochila[i] == NULL) {
                    p->mochila[i] = ObtenerAccesorio(listaAccesorio);
                    mochila_full=false;
                }
            }
            if (mochila_full){
                cout << "m o c h i l a  f u l l" << endl;
            }
            mochila_full=true;
            menu = false; 
            break;
            
            case '2':
            system("cls");
            MostrarMochila(p);

            for (int i = 0; i<5; i++) {
                if (p->mochila[i]!=NULL){
                    if (p->mochila[i]->tipo=="Ataque"){
                        cant_ataque+=1;
                    }   
                }
            }
            
            while(true){
                cout << "Ingrese el numero N del accesorio que desea desempacar: "; posicion = obtenerEnteroPositivo();
                if (posicion>5){
                    cout << "Parece que el accesorio N" << posicion << " no existe... Intentelo de nuevo." << endl;
                }else{
                    if (cant_ataque==1){
                        if (p->mochila[posicion-1]!=NULL){
                            if (p->mochila[posicion-1]->tipo=="Ataque"){
                                cout<<"No puede desempacar este accesorio debido a que es el unico de ataque guardado en la mochila"<<endl;
                            }else{
                                break;
                            }
                        }else{
                            cout<<"No puede desempacar un espacio sin objeto"<<endl;
                        }
                        
                    }
                }
            }

            for (int i = 0; i<5; i++) {
                if (i == posicion-1 && p->mochila[i] != NULL) {
                    p->mochila[i] = NULL;
                    cout << "El accesorio N" << posicion << " ha sido desempacado." << endl;
                }
            }
            menu = false; 
            cant_ataque=0;
            break;

            case '3':
            system("cls");
            MostrarMochila(p);

            for (int i = 0; i<5; i++) {
                if (p->mochila[i]!=NULL){
                    if (p->mochila[i]->tipo=="Ataque"){
                        cant_ataque+=1;
                    }   
                }
            }
            
            while(true){
                cout << "Escriba el numero N del accesorio que desea modificar: "; posicion = obtenerEnteroPositivo();
                if (posicion>5){
                    cout << "Parece que el accesorio N" << posicion << " no existe... Intentelo de nuevo." << endl;
                }else{
                    if (cant_ataque==1){
                        if (p->mochila[posicion-1]!=NULL){
                            if (p->mochila[posicion-1]->tipo=="Ataque"){
                                cout<<"No puede modificar este accesorio debido a que es el unico de ataque guardado en la mochila"<<endl;
                            }else{
                                break;
                            }
                        }else{
                            cout<<"No puede modificar un espacio sin objeto"<<endl;
                        }
                        
                    }
                    
                }
            }
            
            for (int i = 0; i<5; i++) {
                if (i == posicion-1 && p->mochila[i] != NULL) {
                    p->mochila[i] = ObtenerAccesorio(listaAccesorio);
                }
            }
            menu = false; 
            cant_ataque=0;
            break;

            case '0':
            menu = false; 
            break;
        
        } 
    } while (menu);
}

void ModificarSoldado (soldadoPTR &listaSoldados, vector<string> &vector_ambientes) {
    char opc;
    bool found, menu;
    int posicion, cont = 0;
    soldadoPTR p = listaSoldados;

    MostrarSoldados(listaSoldados);

    if (listaSoldados != NULL) {
        cout << "Ingrese el numero N del soldado que desea modificar: "; posicion = obtenerEnteroPositivo();

        while (p != NULL) {
            cont++;
            if (cont == posicion){
                found = true;
                menu = true;

                do {
                    system ("cls");
                    MostrarSoldado(p);
                    cout << " Que desea modificar? " << endl;
                    cout << " [1] Nombre " << endl;
                    cout << " [2] Especie " << endl;
                    cout << " [3] Mochila " << endl;
                    cout << " [0] Nada, quiero volver... " << endl;
                    cout << "Elija una opcion: ";
                    opc = obtenerOpcionMenu('3');

                    switch (opc) {
                        case '1':
                        system ("cls");
                        p->nombre = ValidarNombreSoldado(listaSoldados);
                        system ("PAUSE");
                        menu = false; 
                        break;

                        case '2':
                        system ("cls");
                        p->especie = ObtenerEspecie();
                        system ("PAUSE");
                        menu = false; 
                        break;

                        case '3':
                        system ("cls");
                        ModificarMochila(p, vector_ambientes);
                        system ("PAUSE");
                        menu = false; 
                        break;

                        case '0':
                        menu = false;
                        break;

                    }
                    
                } while (menu);
                cout << "El soldado " << p->nombre << " ha sido modificado" << endl;
            }
            p = p->prox;
        }
        if (!found) {
            cout << "El soldado N" << posicion << " no se encuentra registrado" << endl;
        }
    }
}

void ActualizarSoldadosEspecies (soldadoPTR &listaSoldados, especiePTR e) {
    
    if (listaSoldados != NULL) {
        soldadoPTR p = listaSoldados;
        while (p != NULL) {
            if (p->especie == e) {
                p->especie = NULL;
            }
            p = p->prox;
        }
    }
}

void EliminarEspecie (especiePTR &listaEspecie) {
    especiePTR p, ant; p = listaEspecie;
    int cont, posicion; cont = 0;
    bool found = false;
    
    MostrarEspecies(listaEspecie);

    if (listaEspecie != NULL) {
        cout << "Ingrese el numero N de la especie que desea exterminar: "; posicion = obtenerEnteroPositivo();

        while (p != NULL) {
            cont++;
            if (cont == posicion) {
                found = true;
                if (p == listaEspecie) {
                    listaEspecie = listaEspecie->prox;
                } else {
                    ant->prox = p->prox;
                }
                ActualizarSoldadosEspecies(listaSoldados, p); //antes de eliminar la especie, declara campo especie en soldado como NULL
                delete(p);
                cout << "La especie ha sido encontrada y eliminada" << endl;
                return;
            }
            ant = p;
            p = p->prox;
        }
        if (!found) {
            cout << "La especie N" << posicion << " no se encuentra registrada" << endl;
        }
    } 
}

void ActualizarSoldadosAccesorios (soldadoPTR &listaSoldados, accesorioPTR a) {
    
    if (listaSoldados != NULL) {
        soldadoPTR p = listaSoldados;
        while (p != NULL) {
            for (int i = 0; i<5; i++) {
                if (p->mochila[i] == a) {
                    p->mochila[i] = NULL;
                }
            }
            p = p->prox;
        }
    }
}

void EliminarAccesorio(accesorioPTR &listaAccesorio){
    accesorioPTR p, ant; p = listaAccesorio;
    int cont, posicion; cont = 0;
    bool found = false;

    MostrarAccesorios(listaAccesorio);

    if (listaAccesorio != NULL) {
        cout << "Ingrese el numero N del accesorio que desea destruir: "; posicion = obtenerEnteroPositivo();
        while (p != NULL) {
            cont++;
            if (cont == posicion) {
                found = true;
                if (p == listaAccesorio){
                    listaAccesorio = listaAccesorio->prox;
                } else {
                    ant->prox = p->prox;
                }
                ActualizarSoldadosAccesorios(listaSoldados, p);
                delete(p);
                cout << "El accesorio ha sido desechado" << endl;
                return;
            }
            ant = p;
            p = p->prox;
        }
        if (!found) {
            cout << "El accesorio" << posicion << " no se encuentra registrado" << endl;
        }
    }
}


//-------------------------------------------------------------------LEER ARCHIVOS---------------------------------------------------------------------------
string GuardarDato(string texto){
    bool take=false;
    string aux, dato;
    for (int i=0;i<texto.size();i++){
        if(take==true){
            aux +=texto[i];
        }
        else if(texto[i]==':'){
            take=true;
        }
    }
    dato=aux;
    aux="";
    take=false;
    return dato;
}


void AlmacenarDatosEspecie(){
    ifstream archivo;
    string linea, nombre, ambiente, energia, salud;
    int cont;

    archivo.open("especies.inv", ios::in);

    while(!archivo.eof()){
        getline(archivo,linea);
        if (cont==1){
            nombre=linea;
            cont+=1;
        }
        else if (cont==2){
            energia=GuardarDato(linea);
            cont+=1;
        }else if (cont==3){
            salud=GuardarDato(linea);
            cont+=1;
        }else if (cont==4){
            ambiente=linea;
            cont+=1;
        }
        
        if(linea[0]=='-'){
            cont=1;
        }
        if(cont==5){
            RegistroListaEspecie(listaEspecie, nombre, stoi(energia), stoi(salud), ambiente);
        }
    }
    archivo.close();
}


void AlmacenarDatosAmbiente(){
    ifstream archivo;
    string linea;
    int cont;
    bool repetido=false;

    archivo.open("ambiente.inv", ios::in);

    while(!archivo.eof()){
        getline(archivo,linea);
        if (cont==1){
            for(int i=0; i<vector_ambientes.size();i++){
                if(linea==vector_ambientes[i]){
                    repetido=true;
                    break;
                }
            }
            if(repetido==false){
                vector_ambientes.push_back(linea);
            }
            repetido=false;
            cont+=1;
        }
        
        if(linea[0]=='-'){
            cont=1;
        }
    }
    archivo.close();
}


void AlmacenarDatosAccesorio(){
    ifstream archivo;
    string linea, nombre, tipo, tipo_valor, valor, energia, contenedor_str;
    int cont, contenedor;

    archivo.open("accesorios.inv", ios::in);

    while(!archivo.eof()){
        getline(archivo,linea);
        if (cont==1){
            nombre=linea;
            cont+=1;
        }else if (cont==2){
            tipo=GuardarDato(linea);
            cont+=1;
        }else if (cont==3){
            valor=GuardarDato(linea);
            cont+=1;
        }else if (cont==4){
            tipo_valor=GuardarDato(linea);
            if(tipo_valor==""){
                tipo_valor="0";
            }
            cont+=1;
        }else if (cont==5){
            energia=GuardarDato(linea);
            cont+=1;
        }else if (cont==6){
            contenedor_str=GuardarDato(linea);
            contenedor=stoi(contenedor_str);
            cont+=1;
        }
        
        if(linea[0]=='-'){
            cont=1;
        }
        if(cont>6){
            RegistroListaAccesorio(listaAccesorio, nombre, tipo, stoi(valor), tipo_valor, stoi(energia), contenedor);
        }
    }
    archivo.close();
}

//-------------------------------------------------------------------FUNCIONES GUERRA---------------------------------------------------------------------------
struct jugador1 {
    string nombre;
    especiePTR especie;
    int salud;
    int salud_combate;
    int energia;
    int energia_combate;
    int contenedor=0;
    accesorioPTR mochila[5];
    vector<accesorioPTR> mochila_combate;
    bool descanso;
    string estado="Intacto";
    struct jugador1 *prox;
    };

typedef struct jugador1 *jugador1PTR;
jugador1PTR listaJugador1 = NULL;

struct jugador2 {
    string nombre;
    especiePTR especie;
    int salud;
    int salud_combate;
    int energia;
    int energia_combate;
    int contenedor=0;
    accesorioPTR mochila[5];
    vector<accesorioPTR> mochila_combate;
    bool descanso;
    string estado="Intacto";
    struct jugador2 *prox;
    };

typedef struct jugador2 *jugador2PTR;
jugador2PTR listaJugador2 = NULL;



int GenerarAmbiente(){
    srand(time(NULL));
    int limite=vector_ambientes.size()-1;
    return (rand() % (limite+1));
}

void GenerarSoldadosJugador1(soldadoPTR &listaSoldados){
    srand(time(NULL));
    int limite;
    int cont, num_soldado;

    cout<<"A continuacion se muestran los soldados que fueron asignados al jugador 1. "; system ("PAUSE");
    system("cls");
    cout << "       s o l d a d o s   j u g a d o r  1" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ESPECIE" << right << setw(16) << setfill(' ') << "MOCHILA" << right << setw(28) << setfill(' ') << "SALUD" << right << setw(16) << setfill(' ') << "ENERGIA" << endl;
    cout << endl;

    for (int i=1; i<4; i++){
        cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
        limite=ContarSoldados(listaSoldados);
        num_soldado=rand() % limite+1;
        cont=1;
        soldadoPTR s, ant;
        s=listaSoldados;
        while(true){
            if(cont==num_soldado){
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                cout << "Soldado N" << i << endl;
                cout << left << setw(20) << setfill(' ') << s->nombre;
                MostrarDatosEspecie(s->especie);
                MostrarMochila(s);
                cout << right << setw(81) << setfill(' ') <<s->salud << right << setw(13) << setfill(' ') <<s->energia;
                cout << endl;
                if (s == listaSoldados) {
                    listaSoldados = listaSoldados->prox;
                } else {
                    ant->prox = s->prox;
                }
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                jugador1PTR p;
                p = new (struct jugador1);
                p->nombre = s->nombre;
                p->especie = s->especie;
                p->salud=s->salud;
                p->salud_combate=s->salud;
                p->energia=s->energia;
                p->energia_combate=s->energia;
                for (int i=0; i<5;i++){
                    p->mochila[i]=s->mochila[i];
                }
                p->prox = NULL;
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                if(listaJugador1 == NULL){
                    listaJugador1 = p;
                }
                else {
                    jugador1PTR t = listaJugador1;
                    while(t->prox != NULL){
                        t= t->prox;
                    }
                    t->prox = p;
                }
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                delete(s);
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                break;
            }
            cont += 1;
            ant = s;
            s = s->prox;
        }
    }
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void GenerarSoldadosJugador2(soldadoPTR &listaSoldados){
    srand(time(NULL));
    int limite;
    int cont, num_soldado;

    cout<<"A continuacion se muestran los soldados que fueron asignados al jugador 2. "; system ("PAUSE");
    system("cls");
    cout << "       s o l d a d o s   j u g a d o r  2" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ESPECIE" << right << setw(16) << setfill(' ') << "MOCHILA" << right << setw(28) << setfill(' ') << "SALUD" << right << setw(16) << setfill(' ') << "ENERGIA" << endl;
    cout << endl;

    for (int i=1; i<4; i++){
        cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
        limite=ContarSoldados(listaSoldados);
        num_soldado=rand() % limite+1;
        cont=1;
        soldadoPTR s, ant;
        s=listaSoldados;
        while(true){
            if(cont==num_soldado){
                cout << "Soldado N" << i << endl;
                cout << left << setw(20) << setfill(' ') << s->nombre;
                MostrarDatosEspecie(s->especie);
                MostrarMochila(s);
                cout << right << setw(81) << setfill(' ') <<s->salud << right << setw(13) << setfill(' ') <<s->energia;
                cout << endl;
                if (s == listaSoldados) {
                    listaSoldados = listaSoldados->prox;
                } else {
                    ant->prox = s->prox;
                }
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                jugador2PTR q;
                q = new (struct jugador2);
                q->nombre = s->nombre;
                q->especie = s->especie;
                q->salud=s->salud;
                q->salud_combate=s->salud;
                q->energia=s->energia;
                q->energia_combate=s->energia;
                for (int i=0; i<5;i++){
                    q->mochila[i]=s->mochila[i];
                }
                q->prox = NULL;
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                if(listaJugador2 == NULL){
                    listaJugador2 = q;
                }
                else {
                    jugador2PTR t = listaJugador2;
                    while(t->prox != NULL){
                        t= t->prox;
                    }
                    t->prox = q;
                }
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                delete(s);
                cout<<"siiiiiiiiiiiiiiiiiii"<<endl;
                break;
            }
            cont += 1;
            ant = s;
            s = s->prox;
        }
    }
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << endl; system ("PAUSE");
}

bool GenerarPrioridad(){
    srand(time(NULL));
    int num_jugador=rand() % 2+1;
    
    if(num_jugador==1){
        return true;
    }else{
        return false;
    }
}

void MostrarMochilaJugador1 (jugador1PTR &p) {
    for (int i = 0; i<5; i++ ) {
        if (p->mochila[i] != NULL) {
            cout << right << setw(50) << setfill(' ') << i+1 << "- " << p->mochila[i]->nombre << endl;
        } else {
            cout << right << setw(50) << setfill(' ') << i+1 << "- Espacio sin objeto" << endl;
        }
    }
}


void MostrarSoldadosJugador1(jugador1PTR &listaJugador1){
    int cont = 1;
    
        jugador1PTR t = listaJugador1;
        cout << "       s o l d a d o s   J u g a d o r  1" << endl;
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ESPECIE" << right << setw(16) << setfill(' ') << "MOCHILA" << right << setw(28) << setfill(' ') << "SALUD" << right << setw(16) << setfill(' ') << "ENERGIA" << right << setw(16) << setfill(' ') << "ESTADO"<< endl;
        cout << endl;
        while(t != NULL){
            cout << "Soldado N" << cont << endl;
            cout << left << setw(20) << setfill(' ') << t->nombre;
            MostrarDatosEspecie(t->especie);
            MostrarMochilaJugador1(t);
            cout << right << setw(81) << setfill(' ') <<t->salud_combate << right << setw(16) << setfill(' ') <<t->energia_combate<< right << setw(16) << setfill(' ')<<t->estado;
            cout << endl;
            t = t->prox;
            cont = cont + 1;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    
}

jugador1PTR SeleccionarSoldadoJugador1 (jugador1PTR &listaJugador1) {
    jugador1PTR p;
    int cont, posicion; cont = 0;
    bool found = false;
    
    MostrarSoldadosJugador1(listaJugador1);

    if (listaJugador1 != NULL) {
        
        while(!found){
            cout << "Ingrese el numero N del soldado que desea seleccionar: "; posicion = obtenerEnteroPositivo();
            p = listaJugador1;
            while (p != NULL) {
                cont++;
                if (cont == posicion) {
                    if (p->estado=="K.O."){
                        cout << "El soldado N"<<cont<<" no se puede seleccionar debido a que fue derrotado" << endl;
                        break;
                    }else{
                        found = true;
                        cout << "El soldado N"<<cont<<" ha sido sleccionado" << endl;
                        return p;
                    }
                    
                }
                p = p->prox;
            }
            if (!found) {
                cout << "El soldado N" << posicion << " no es una opcion valida" << endl;
                cont=0;
            }
        }
        
    } 
}

void seleccionarAccesoriosJugador1(jugador1PTR &p, int num_combate){
    int posicion, cont;
    bool found, repeat, exists_atq;
    vector <int> posiciones;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "       m o c h i l a   s o l d a d o              " << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << left << setw(35) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "TIPO" << left << setw(20) << setfill(' ') << "VALOR" << left << setw(20) << setfill(' ') << "TIPO VALOR" << left << setw(30) << setfill(' ') << "CONSUMO de MIDICLORIAS" << left << setw(30) << setfill(' ') << "VALOR INCIAL de PROTECCION" << endl;
    cout << endl;
    for (int k=0;k<5;k++){
        cout << "Accesorio N" << k+1 << endl;
        cout << left << setw(35) << setfill(' ') << p->mochila[k]->nombre;
        cout << left << setw(20) << setfill(' ') << p->mochila[k]->tipo;
        cout << left << setw(20) << setfill(' ') << p->mochila[k]->valor;
        cout << left << setw(20) << setfill(' ') << p->mochila[k]->tipo_valor;
        cout << left << setw(30) << setfill(' ') << p->mochila[k]->energia;
        cout << left << setw(30) << setfill(' ') << p->mochila[k]->contenedor << endl;
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<endl;

    cout<<"Ahora debe escoger los TRES objetos que llevara a la batalla (debe seleccionar como minimo uno de ataque)"<<endl;
    
    exists_atq=false;
    while(true){
        for (int i=0;i<3;i++){
            cont=1;
            found=false;
            
            while(!found){
                while(true){
                    repeat=false;
                    cout<<"ingrese el numero N del accesorio N"<<i+1<<" que llevara al combate N"<<num_combate<<": "; posicion = obtenerEnteroPositivo();
                    for (int l=0;l<posiciones.size();l++){
                        if (posiciones[l]==posicion){
                            repeat=true;
                        }
                    }
                    if(repeat){
                        cout<<"Este accesorio ya fue seleccionado. Pruebe con otro"<<endl;
                    }else{
                        break;
                    }
                }
                while (cont!=6) {
                    if (cont == posicion) {
                        found = true;
                        cout << "El accesorio N"<<cont<<" ha sido seleccionado" << endl;
                        p->mochila_combate.push_back(p->mochila[cont-1]);
                        posiciones.push_back(posicion);
                        break;
                    }
                    cont++;
                }
                if (!found) {
                    cout << "El accesorio N" << posicion << " no se encuentra registrado" << endl;
                    cont=0;
                }
            }
                
        }

        for (int j=0;j<p->mochila_combate.size();j++){
            if (p->mochila_combate[j]->tipo=="Ataque"){
                exists_atq=true;
            }
        }
        if (exists_atq){
            break;
        }else{
            cout<<"Debe seleccionar como minimo un accesorio de ataque para el combate"<<endl;
            cout<<"Seleccione los TRES accesorios nuevamente"<<endl;
            p->mochila_combate.erase(p->mochila_combate.begin(), p->mochila_combate.end());
            posiciones.erase(posiciones.begin(), posiciones.end());
        }
    }
}

void MostrarMochilaJugador2 (jugador2PTR &q) {
    for (int i = 0; i<5; i++ ) {
        if (q->mochila[i] != NULL) {
            cout << right << setw(50) << setfill(' ') << i+1 << "- " << q->mochila[i]->nombre << endl;
        } else {
            cout << right << setw(50) << setfill(' ') << i+1 << "- Espacio sin objeto" << endl;
        }
    }
}


void MostrarSoldadosJugador2(jugador2PTR &listaJugador2){
    int cont = 1;
    
        jugador2PTR t = listaJugador2;
        cout << "       s o l d a d o s   J u g a d o r  2" << endl;
        cout << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << left << setw(20) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "ESPECIE" << right << setw(16) << setfill(' ') << "MOCHILA" << right << setw(28) << setfill(' ') << "SALUD" << right << setw(16) << setfill(' ') << "ENERGIA"<< right << setw(16) << setfill(' ') << "ESTADO" << endl;
        cout << endl;
        while(t != NULL){
            cout << "Soldado N" << cont << endl;
            cout << left << setw(20) << setfill(' ') << t->nombre;
            MostrarDatosEspecie(t->especie);
            MostrarMochilaJugador2(t);
            cout << right << setw(81) << setfill(' ') <<t->salud_combate << right << setw(16) << setfill(' ') <<t->energia_combate<< right << setw(16) << setfill(' ')<<t->estado;
            cout << endl;
            t = t->prox;
            cont = cont + 1;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    
}

jugador2PTR SeleccionarSoldadoJugador2 (jugador2PTR &listaJugador2) {
    jugador2PTR q;
    int cont, posicion; cont = 0;
    bool found = false;
    
    MostrarSoldadosJugador2(listaJugador2);

    if (listaJugador2 != NULL) {

        while(!found){
            cout << "Ingrese el numero N del soldado que desea seleccionar: "; posicion = obtenerEnteroPositivo();
            q = listaJugador2;
            while (q != NULL) {
                cont++;
                if (cont == posicion) {
                    if (q->estado=="K.O."){
                        cout << "El soldado N"<<cont<<" no se puede seleccionar debido a que fue derrotado" << endl;
                        break;
                    }else{
                        found = true;
                        cout << "El soldado N"<<cont<<" ha sido sleccionado" << endl;
                        return q;
                    }
                    
                }
                q = q->prox;
            }
            if (!found) {
                cout << "El soldado N" << posicion << " no es una opcion valida" << endl;
                cont=0;
            }
        }
        
    } 
}

void seleccionarAccesoriosJugador2(jugador2PTR &q, int num_combate){
    int posicion, cont;
    bool found, repeat, exists_atq;
    vector <int> posiciones;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "       m o c h i l a   s o l d a d o              " << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << left << setw(35) << setfill(' ') << "NOMBRE" << left << setw(20) << setfill(' ') << "TIPO" << left << setw(20) << setfill(' ') << "VALOR" << left << setw(20) << setfill(' ') << "TIPO VALOR" << left << setw(30) << setfill(' ') << "CONSUMO de MIDICLORIAS" << left << setw(30) << setfill(' ') << "VALOR INCIAL de PROTECCION" << endl;
    cout << endl;
    for (int k=0;k<5;k++){
        cout << "Accesorio N" << k+1 << endl;
        cout << left << setw(35) << setfill(' ') << q->mochila[k]->nombre;
        cout << left << setw(20) << setfill(' ') << q->mochila[k]->tipo;
        cout << left << setw(20) << setfill(' ') << q->mochila[k]->valor;
        cout << left << setw(20) << setfill(' ') << q->mochila[k]->tipo_valor;
        cout << left << setw(30) << setfill(' ') << q->mochila[k]->energia;
        cout << left << setw(30) << setfill(' ') << q->mochila[k]->contenedor << endl;
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"Ahora debe escoger los TRES objetos que llevara a la batalla"<<endl;
    
    exists_atq=false;
    while(true){
        for (int i=0;i<3;i++){
            cont=1;
            found=false;
            
            while(!found){
                while(true){
                    repeat=false;
                    cout<<"ingrese el numero N del accesorio N"<<i+1<<" que llevara al combate N"<<num_combate<<": "; posicion = obtenerEnteroPositivo();
                    for (int l=0;l<posiciones.size();l++){
                        if (posiciones[l]==posicion){
                            repeat=true;
                        }
                    }
                    if(repeat){
                        cout<<"Este accesorio ya fue seleccionado. Pruebe con otro"<<endl;
                    }else{
                        break;
                    }
                }
                while (cont!=6) {
                    if (cont == posicion) {
                        found = true;
                        cout << "El accesorio N"<<cont<<" ha sido seleccionado" << endl;
                        q->mochila_combate.push_back(q->mochila[cont-1]);
                        posiciones.push_back(posicion);
                        break;
                    }
                    cont++;
                }
                if (!found) {
                    cout << "El accesorio N" << posicion << " no se encuentra registrado" << endl;
                    cont=0;
                }
            }
        }
        
        for (int j=0;j<q->mochila_combate.size();j++){
            if (q->mochila_combate[j]->tipo=="Ataque"){
                exists_atq=true;
            }
        }
        if (exists_atq){
            break;
        }else{
            cout<<"Debe seleccionar como minimo un accesorio de ataque para el combate"<<endl;
            cout<<"Seleccione los TRES accesorios nuevamente"<<endl;
            q->mochila_combate.erase(q->mochila_combate.begin(), q->mochila_combate.end());
            posiciones.erase(posiciones.begin(), posiciones.end());
        }
        
    }
}

void mostrarInfoCombate_caso1(jugador1PTR &soldado_jugador1, jugador2PTR &soldado_jugador2, bool adaptacionJ1){
    int posicion1, posicion2; int cont;
    bool found, correct_type;
    bool consumir_acc1=false; bool consumir_acc2=false;
    bool es_defensa=false;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "       A T A Q U E    j u g a d o r  1              " << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout<<"Situacion de "<<soldado_jugador1->nombre<<":"<<endl;
    cout<<"Salud restante: "<<soldado_jugador1->salud_combate <<endl; 
    cout<<"Contenedor: "<<soldado_jugador1->contenedor<<endl;
    cout<<"Energia restante: "<<soldado_jugador1->energia_combate <<endl;
    cout<<"Mochila: "<<"1) "<<soldado_jugador1->mochila_combate[0]->nombre<<endl;
    for (int i=1;i<soldado_jugador1->mochila_combate.size();i++){
        cout<< "         " <<i+1<<") "<<soldado_jugador1->mochila_combate[i]->nombre<<endl;
    }
    cout<<endl;

    
    found=false;
    while (!found){
        cont=1;
        correct_type=true;
        cout<<"Escoja el N accesorio que usara en este turno: "; posicion1 = obtenerEnteroPositivo();
        while(cont<=soldado_jugador1->mochila_combate.size()){
            if (posicion1==cont){
                if(soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Defensa"){
                    cout << "No puede utilizar el accesorio N" << posicion1 << " en este turno porque es del tipo defensa" << endl;
                    correct_type=false;
                    break;
                }else{
                    found=true;
                    correct_type=true;
                    break;
                }
                
            }
            cont+=1;
        }
        if (!found && correct_type){
            cout << "El accesorio N" << posicion1 << " no se encuentra registrado" << endl;
            cont=0;
        }
    }
    
    

    system ("PAUSE");

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "       D E F E N S A    j u g a d o r  2              " << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout<<"Situacion de "<<soldado_jugador2->nombre<<":"<<endl;
    cout<<"Salud restante: "<< soldado_jugador2->salud_combate <<endl;
    cout<<"Contenedor: "<<soldado_jugador2->contenedor<<endl;
    cout<<"Energia restante: "<< soldado_jugador2->energia_combate <<endl;
    cout<<"Mochila: 1) "<< soldado_jugador2->mochila_combate[0]->nombre<<endl;
    for (int i=1;i<soldado_jugador2->mochila_combate.size();i++){
        cout<< "         " <<i+1<<") "<< soldado_jugador2->mochila_combate[i]->nombre<<endl;
    }
    cout<<endl;

    
    found=false;
    while (!found){
        cont=1;
        correct_type=true;
        cout<<"Escoja el N accesorio que usara en este turno (o introduzca 5 para pasar en este turno): "; posicion2 = obtenerEnteroPositivo();
        while(cont<=soldado_jugador2->mochila_combate.size()){
            if (posicion2==cont){
                if(soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Ataque"){
                    cout << "No puede utilizar el accesorio N" << posicion2 << " en este turno porque es del tipo ataque" << endl;
                    correct_type=false;
                    break;
                }else{
                    found=true;
                    correct_type=true;
                    if(soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Defensa"){
                        es_defensa=true;
                    }
                    break;
                }
                
            }
            cont+=1;
        }
        if (!found && correct_type && posicion2!=5){
            cout << "El accesorio N" << posicion2 << " no se encuentra registrado" << endl;
            cont=0;
        }
        if (posicion2==5){
            found=true;
        }
    }

    system ("PAUSE");
    cout<<endl;

    if (posicion2!=5){
        if (soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Supervivencia"){

            if(soldado_jugador2->mochila_combate[posicion2-1]->tipo_valor=="Salud"){
                if(soldado_jugador2->salud_combate==soldado_jugador2->salud){
                    cout<<soldado_jugador2->nombre<<" no ha recuperado nada. Su salud esta al maximo"<<endl;
                }else{
                    soldado_jugador2->salud_combate+=soldado_jugador2->mochila_combate[posicion2-1]->valor;
                    if (soldado_jugador2->salud_combate>soldado_jugador2->salud){
                        soldado_jugador2->salud_combate=soldado_jugador2->salud;
                        cout<<soldado_jugador2->nombre<<" ha recuperado toda su salud"<<endl;
                    }else{
                        cout<<soldado_jugador2->nombre<<" ha recuperado "<<soldado_jugador2->mochila_combate[posicion2-1]->valor<<" puntos de salud"<<endl;
                    }
                }
                    
            }else if(soldado_jugador2->mochila_combate[posicion2-1]->tipo_valor=="Energia"){
                if (soldado_jugador2->energia_combate==soldado_jugador2->energia){
                    cout<<soldado_jugador2->nombre<<" no ha recuperado nada. Su energia esta al maximo"<<endl;
                }else{
                    soldado_jugador2->energia_combate+=soldado_jugador2->mochila_combate[posicion2-1]->valor;
                    if (soldado_jugador2->energia_combate>soldado_jugador2->energia){
                        soldado_jugador2->energia_combate=soldado_jugador2->energia;
                        cout<<soldado_jugador2->nombre<<" ha recuperado toda su energia"<<endl;
                    }else{
                        cout<<soldado_jugador2->nombre<<" ha recuperado "<<soldado_jugador2->mochila_combate[posicion2-1]->valor<<" midiclorias de energia"<<endl;
                    }
                }
                    
            }
            cout<<soldado_jugador2->nombre<<" ha gastado "<<soldado_jugador2->mochila_combate[posicion2-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
            soldado_jugador2->energia_combate-=soldado_jugador2->mochila_combate[posicion2-1]->energia;
            cout<<"El accesorio "<<soldado_jugador2->mochila_combate[posicion2-1]->nombre<<" de "<<soldado_jugador2->nombre<<" ha sido consumido"<<endl;
            consumir_acc2=true;
            cout<<endl;
        }
    }
    


    if (soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Ataque" && !es_defensa){
        cout<<soldado_jugador1->nombre<<" ha atacado a "<<soldado_jugador2->nombre<<"!"<<endl;
        if (!adaptacionJ1){
            cout<<soldado_jugador1->nombre<<" ha perdido "<<soldado_jugador1->salud/3<<" puntos de salud por las circunstancias ambientales"<<endl;
            soldado_jugador1->salud_combate-=soldado_jugador1->salud/3;
        }
        cout<<soldado_jugador1->nombre<<" ha gastado "<<soldado_jugador1->mochila[posicion1-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
        soldado_jugador1->energia_combate-=soldado_jugador1->mochila[posicion1-1]->energia;
        cout<<endl;

        if (soldado_jugador2->contenedor>0){
            if (soldado_jugador2->contenedor<soldado_jugador1->mochila[posicion1-1]->valor){
                soldado_jugador2->salud-=(soldado_jugador1->mochila[posicion1-1]->valor-soldado_jugador2->contenedor);
                soldado_jugador2->contenedor=0;
                cout<<"El contenedor de "<<soldado_jugador2->nombre<<" ha perdido toda su salud"<<endl;
                cout<<soldado_jugador2->nombre<<" ha perdido "<<soldado_jugador1->mochila[posicion1-1]->valor-soldado_jugador2->contenedor<<" puntos de salud"<<endl;
            }else{
                soldado_jugador2->contenedor-=soldado_jugador1->mochila[posicion1-1]->valor;
                cout<<"El contenedor de "<<soldado_jugador2->nombre<<" ha perdido "<<soldado_jugador1->mochila[posicion1-1]->valor<<" puntos de salud"<<endl;
            }
        }else{
            soldado_jugador2->salud_combate-=soldado_jugador1->mochila[posicion1-1]->valor;
            cout<<soldado_jugador2->nombre<<" ha perdido "<<soldado_jugador1->mochila[posicion1-1]->valor<<" puntos de salud"<<endl;
        }
        cout<<endl;
    }

    //Cuando el jugador que va a la defensiva elige un accesorio
    if (posicion2!=5){
        
        if (soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Defensa"){
            if (soldado_jugador2->mochila_combate[posicion2-1]->contenedor!=0){
                soldado_jugador2->contenedor+=soldado_jugador2->mochila_combate[posicion2-1]->contenedor;
                cout<<"Se ha aniadido al contenedor de "<<soldado_jugador2->nombre<<" una proteccion de "<<soldado_jugador2->mochila_combate[posicion2-1]->contenedor<<" puntos de salud"<<endl;
                soldado_jugador2->mochila_combate[posicion2-1]->contenedor=0;
            }
            cout<<soldado_jugador2->nombre<<" ha recibido una proteccion contra el danio del "<<soldado_jugador2->mochila_combate[posicion2-1]->valor<<"% en este turno"<<endl;
            cout<<soldado_jugador2->nombre<<" ha gastado "<<soldado_jugador2->mochila_combate[posicion2-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
            soldado_jugador2->energia_combate-=soldado_jugador2->mochila_combate[posicion2-1]->energia;
            cout<<endl;

            if (soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Ataque"){
                cout<<soldado_jugador1->nombre<<" ha atacado a "<<soldado_jugador2->nombre<<"!"<<endl;
                if (!adaptacionJ1){
                    cout<<soldado_jugador1->nombre<<" ha perdido "<<soldado_jugador1->salud/3<<" puntos de salud por las circunstancias ambientales"<<endl;
                    soldado_jugador1->salud_combate-=soldado_jugador1->salud/3;
                }
                cout<<soldado_jugador1->nombre<<" ha gastado "<<soldado_jugador1->mochila[posicion1-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
                soldado_jugador1->energia_combate-=soldado_jugador1->mochila[posicion1-1]->energia;
                cout<<endl;

                if (soldado_jugador2->contenedor>0){
                    if (soldado_jugador2->contenedor<(soldado_jugador1->mochila[posicion1-1]->valor * soldado_jugador2->mochila_combate[posicion2-1]->valor)/100){
                        soldado_jugador2->salud-=((soldado_jugador1->mochila[posicion1-1]->valor * soldado_jugador2->mochila_combate[posicion2-1]->valor)/100)-soldado_jugador2->contenedor;
                        soldado_jugador2->contenedor=0;
                        cout<<"El contenedor de "<<soldado_jugador2->nombre<<" ha perdido toda su salud"<<endl;
                        cout<<soldado_jugador2->nombre<<" ha perdido "<<((soldado_jugador1->mochila[posicion1-1]->valor * soldado_jugador2->mochila_combate[posicion2-1]->valor)/100)-soldado_jugador2->contenedor<<" puntos de salud"<<endl;
                    }else{
                        soldado_jugador2->contenedor-=(soldado_jugador1->mochila[posicion1-1]->valor * soldado_jugador2->mochila_combate[posicion2-1]->valor)/100;
                        cout<<"El contenedor de "<<soldado_jugador2->nombre<<" ha perdido "<<(soldado_jugador1->mochila[posicion1-1]->valor * soldado_jugador2->mochila_combate[posicion2-1]->valor)/100<<" puntos de salud"<<endl;
                    }
                }else{
                    soldado_jugador2->salud_combate-=(soldado_jugador1->mochila[posicion1-1]->valor * soldado_jugador2->mochila_combate[posicion2-1]->valor)/100;
                    cout<<soldado_jugador2->nombre<<" ha perdido "<<(soldado_jugador1->mochila[posicion1-1]->valor * soldado_jugador2->mochila_combate[posicion2-1]->valor)/100<<" puntos de salud"<<endl;
                }
                cout<<endl;
            }
        }
    }else{
        cout<<soldado_jugador2->nombre<<" ha decidido no usar ningun accesorio en este turno"<<endl;
        cout<<endl;
    }
    

    if (soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Supervivencia"){
        
        if(soldado_jugador1->mochila_combate[posicion1-1]->tipo_valor=="Salud"){
            if (soldado_jugador1->salud_combate==soldado_jugador1->salud){
                cout<<soldado_jugador1->nombre<<" no ha recuperado nada. Su salud esta al maximo"<<endl;
            }else{
                soldado_jugador1->salud_combate+=soldado_jugador1->mochila_combate[posicion1-1]->valor;
                if (soldado_jugador1->salud_combate>soldado_jugador1->salud){
                    soldado_jugador1->salud_combate=soldado_jugador1->salud;
                    cout<<soldado_jugador1->nombre<<" ha recuperado toda su salud"<<endl;
                }else{
                    cout<<soldado_jugador1->nombre<<" ha recuperado "<<soldado_jugador1->mochila_combate[posicion1-1]->valor<<" puntos de salud"<<endl;
                }
            }
            
        }else if(soldado_jugador1->mochila_combate[posicion1-1]->tipo_valor=="Energia"){
            if (soldado_jugador1->energia_combate==soldado_jugador1->energia){
                cout<<soldado_jugador1->nombre<<" no ha recuperado nada. Su energia esta al maximo"<<endl;
            }else{
                soldado_jugador1->energia_combate+=soldado_jugador1->mochila_combate[posicion1-1]->valor;
                if (soldado_jugador1->energia_combate>soldado_jugador1->energia){
                    soldado_jugador1->energia_combate=soldado_jugador1->energia;
                    cout<<soldado_jugador1->nombre<<" ha recuperado toda su energia"<<endl;
                }else{
                    cout<<soldado_jugador1->nombre<<" ha recuperado "<<soldado_jugador1->mochila_combate[posicion1-1]->valor<<" midiclorias de energia"<<endl;
                }
            }
            
        }

        cout<<soldado_jugador1->nombre<<" ha gastado "<<soldado_jugador1->mochila_combate[posicion1-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
        soldado_jugador1->energia_combate-=soldado_jugador1->mochila_combate[posicion1-1]->energia;
        cout<<"El accesorio "<<soldado_jugador1->mochila_combate[posicion1-1]->nombre<<" de "<<soldado_jugador1->nombre<<" ha sido consumido"<<endl;
        consumir_acc1=true;
        cout<<endl;
    }

    

    if (consumir_acc2){
        soldado_jugador2->mochila_combate.erase(soldado_jugador2->mochila_combate.begin()+posicion2-1);
    }
    if (consumir_acc1){
        soldado_jugador1->mochila_combate.erase(soldado_jugador1->mochila_combate.begin()+posicion1-1);
    }


    system ("PAUSE");


}


void mostrarInfoCombate_caso2(jugador1PTR &soldado_jugador1, jugador2PTR &soldado_jugador2, bool adaptacionJ2){
    int posicion1, posicion2; int cont;
    bool found, correct_type;
    bool consumir_acc1=false; bool consumir_acc2=false;
    bool es_defensa=false;

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "       A T A Q U E    j u g a d o r  2              " << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout<<"Situacion de "<<soldado_jugador2->nombre<<":"<<endl;
    cout<<"Salud restante: "<< soldado_jugador2->salud_combate <<endl;
    cout<<"Contenedor: "<< soldado_jugador2->contenedor <<endl;
    cout<<"Energia restante: "<< soldado_jugador2->energia_combate <<endl;
    cout<<"Mochila: 1) "<< soldado_jugador2->mochila_combate[0]->nombre<<endl;
    for (int i=1;i<soldado_jugador2->mochila_combate.size();i++){
        cout<< "         "<<i+1<<") " << soldado_jugador2->mochila_combate[i]->nombre<<endl;
    }
    cout<<endl;

    
    found=false;
    while (!found){
        cont=1;
        correct_type=true;
        cout<<"Escoja el N accesorio que usara en este turno: "; posicion2 = obtenerEnteroPositivo();
        while(cont<=soldado_jugador2->mochila_combate.size()){
            if (posicion2==cont){
                if(soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Defensa"){
                    cout << "No puede utilizar el accesorio N" << posicion2 << " en este turno porque es del tipo defensa" << endl;
                    correct_type=false;
                    break;
                }else{
                    found=true;
                    correct_type=true;
                    break;
                }
                
            }
            cont+=1;
        }
        if (!found && correct_type){
            cout << "El accesorio N" << posicion2 << " no se encuentra registrado" << endl;
            cont=0;
        }
    }


    system ("PAUSE");

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "       D E F E N S A    j u g a d o r  1              " << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout<<"Situacion de "<<soldado_jugador1->nombre<<":"<<endl;
    cout<<"Salud restante: "<<soldado_jugador1->salud_combate <<endl; 
    cout<<"Contenedor: "<< soldado_jugador1->contenedor <<endl;
    cout<<"Energia restante: "<<soldado_jugador1->energia_combate <<endl;
    cout<<"Mochila: 1) "<< soldado_jugador1->mochila_combate[0]->nombre<<endl;
    for (int i=1;i<soldado_jugador1->mochila_combate.size();i++){
        cout<< "         " <<i+1<<") "<< soldado_jugador1->mochila_combate[i]->nombre<<endl;
    }
    cout<<endl;

    
    found=false;
    while (!found){
        cont=1;
        correct_type=true;
        cout<<"Escoja el N accesorio que usara en este turno (o introduzca 5 para pasar en este turno): "; posicion1 = obtenerEnteroPositivo();
        while(cont<=soldado_jugador1->mochila_combate.size()){
            if (posicion1==cont){
                if(soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Ataque"){
                    cout << "No puede utilizar el accesorio N" << posicion1 << " en este turno porque es del tipo ataque" << endl;
                    correct_type=false;
                    break;
                }else{
                    found=true;
                    correct_type=true;
                    if(soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Defensa"){
                        es_defensa=true;
                    }
                    break;
                }
                
            }
            cont+=1;
        }
        if (!found && correct_type && posicion1!=5){
            cout << "El accesorio N" << posicion1 << " no se encuentra registrado" << endl;
            cont=0;
        }
        if (posicion1==5){
            found=true;
        }
    }

    system ("PAUSE");
    cout<<endl;

    if (posicion1!=5){
        if (soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Supervivencia"){

            if(soldado_jugador1->mochila_combate[posicion1-1]->tipo_valor=="Salud"){
                if(soldado_jugador1->salud_combate==soldado_jugador1->salud){
                    cout<<soldado_jugador1->nombre<<" no ha recuperado nada. Su salud esta al maximo"<<endl;
                }else{
                    soldado_jugador1->salud_combate+=soldado_jugador1->mochila_combate[posicion1-1]->valor;
                    if (soldado_jugador1->salud_combate>soldado_jugador1->salud){
                        soldado_jugador1->salud_combate=soldado_jugador1->salud;
                        cout<<soldado_jugador1->nombre<<" ha recuperado toda su salud"<<endl;
                    }else{
                        cout<<soldado_jugador1->nombre<<" ha recuperado "<<soldado_jugador1->mochila_combate[posicion1-1]->valor<<" puntos de salud"<<endl;
                    }
                }
                    
                    
            }else if(soldado_jugador1->mochila_combate[posicion1-1]->tipo_valor=="Energia"){
                if (soldado_jugador1->energia_combate==soldado_jugador1->energia){
                    cout<<soldado_jugador1->nombre<<" no ha recuperado nada. Su energia esta al maximo"<<endl;
                }else{
                    soldado_jugador1->energia_combate+=soldado_jugador1->mochila_combate[posicion1-1]->valor;
                    if (soldado_jugador1->energia_combate>soldado_jugador1->energia){
                        soldado_jugador1->energia_combate=soldado_jugador1->energia;
                        cout<<soldado_jugador1->nombre<<" ha recuperado toda su energia"<<endl;
                    }else{
                        cout<<soldado_jugador1->nombre<<" ha recuperado "<<soldado_jugador1->mochila_combate[posicion1-1]->valor<<" midiclorias de energia"<<endl;
                    }
                }
                    
            }
            cout<<soldado_jugador1->nombre<<" ha gastado "<<soldado_jugador1->mochila_combate[posicion1-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
            soldado_jugador1->energia_combate-=soldado_jugador1->mochila_combate[posicion1-1]->energia;
            cout<<"El accesorio "<<soldado_jugador1->mochila_combate[posicion1-1]->nombre<<" de "<<soldado_jugador1->nombre<<" ha sido consumido"<<endl;
            consumir_acc1=true;
            cout<<endl;
        }
    }
    

    if (soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Ataque" && !es_defensa){
        cout<<soldado_jugador2->nombre<<" ha atacado a "<<soldado_jugador1->nombre<<"!"<<endl;
        if (!adaptacionJ2){
            cout<<soldado_jugador2->nombre<<" ha perdido "<<soldado_jugador2->salud/3<<" puntos de salud por las circunstancias ambientales"<<endl;
            soldado_jugador2->salud_combate-=soldado_jugador2->salud/3;
        }
        cout<<soldado_jugador2->nombre<<" ha gastado "<<soldado_jugador2->mochila[posicion2-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
        soldado_jugador2->energia_combate-=soldado_jugador2->mochila[posicion2-1]->energia;
        cout<<endl;

        if (soldado_jugador1->contenedor>0){
            if (soldado_jugador1->contenedor<soldado_jugador2->mochila[posicion2-1]->valor){
                soldado_jugador1->salud-=(soldado_jugador2->mochila[posicion2-1]->valor-soldado_jugador1->contenedor);
                soldado_jugador1->contenedor=0;
                cout<<"El contenedor de "<<soldado_jugador1->nombre<<" ha perdido toda su salud"<<endl;
                cout<<soldado_jugador1->nombre<<" ha perdido "<<soldado_jugador2->mochila[posicion2-1]->valor-soldado_jugador1->contenedor<<" puntos de salud"<<endl;
            }else{
                soldado_jugador1->contenedor-=soldado_jugador2->mochila[posicion2-1]->valor;
                cout<<"El contenedor de "<<soldado_jugador1->nombre<<" ha perdido "<<soldado_jugador2->mochila[posicion2-1]->valor<<" puntos de salud"<<endl;
            }
        }else{
            soldado_jugador1->salud_combate-=soldado_jugador2->mochila[posicion2-1]->valor;
            cout<<soldado_jugador1->nombre<<" ha perdido "<<soldado_jugador2->mochila[posicion2-1]->valor<<" puntos de salud"<<endl;
        }
        cout<<endl;
    }

    //Cuando el jugador que va a la defensiva elige un accesorio
    if (posicion1!=5){

        
        if (soldado_jugador1->mochila_combate[posicion1-1]->tipo=="Defensa"){
            if (soldado_jugador1->mochila_combate[posicion1-1]->contenedor!=0){
                soldado_jugador1->contenedor+=soldado_jugador1->mochila_combate[posicion1-1]->contenedor;
                cout<<"Se ha aniadido al contenedor de "<<soldado_jugador1->nombre<<" una proteccion de "<<soldado_jugador1->mochila_combate[posicion1-1]->contenedor<<" puntos de salud"<<endl;
                soldado_jugador1->mochila_combate[posicion1-1]->contenedor=0;
            }
            cout<<soldado_jugador1->nombre<<" ha recibido una proteccion contra el danio del "<<soldado_jugador1->mochila_combate[posicion1-1]->valor<<"% en este turno"<<endl;
            cout<<soldado_jugador1->nombre<<" ha gastado "<<soldado_jugador1->mochila_combate[posicion1-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
            soldado_jugador1->energia_combate-=soldado_jugador1->mochila_combate[posicion1-1]->energia;
            cout<<endl;

            if (soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Ataque"){
                cout<<soldado_jugador2->nombre<<" ha atacado a "<<soldado_jugador1->nombre<<"!"<<endl;
                if (!adaptacionJ2){
                    cout<<soldado_jugador2->nombre<<" ha perdido "<<soldado_jugador2->salud/3<<" puntos de salud por las circunstancias ambientales"<<endl;
                    soldado_jugador2->salud_combate-=soldado_jugador2->salud/3;
                }
                cout<<soldado_jugador2->nombre<<" ha gastado "<<soldado_jugador2->mochila[posicion2-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
                soldado_jugador2->energia_combate-=soldado_jugador2->mochila[posicion2-1]->energia;
                cout<<endl;

                if (soldado_jugador1->contenedor>0){
                    if (soldado_jugador1->contenedor<(soldado_jugador2->mochila[posicion2-1]->valor * soldado_jugador1->mochila_combate[posicion1-1]->valor)/100){
                        soldado_jugador1->salud-=((soldado_jugador2->mochila[posicion2-1]->valor * soldado_jugador1->mochila_combate[posicion1-1]->valor)/100)-soldado_jugador1->contenedor;
                        soldado_jugador1->contenedor=0;
                        cout<<"El contenedor de "<<soldado_jugador1->nombre<<" ha perdido toda su salud"<<endl;
                        cout<<soldado_jugador1->nombre<<" ha perdido "<<((soldado_jugador2->mochila[posicion2-1]->valor * soldado_jugador1->mochila_combate[posicion1-1]->valor)/100)-soldado_jugador1->contenedor<<" puntos de salud"<<endl;
                    }else{
                        soldado_jugador1->contenedor-=(soldado_jugador2->mochila[posicion2-1]->valor * soldado_jugador1->mochila_combate[posicion1-1]->valor)/100;
                        cout<<"El contenedor de "<<soldado_jugador1->nombre<<" ha perdido "<<(soldado_jugador2->mochila[posicion2-1]->valor * soldado_jugador1->mochila_combate[posicion1-1]->valor)/100<<" puntos de salud"<<endl;
                    }
                }else{
                    soldado_jugador1->salud_combate-=(soldado_jugador2->mochila[posicion2-1]->valor * soldado_jugador1->mochila_combate[posicion1-1]->valor)/100;
                    cout<<soldado_jugador1->nombre<<" ha perdido "<<(soldado_jugador2->mochila[posicion2-1]->valor * soldado_jugador1->mochila_combate[posicion1-1]->valor)/100<<" puntos de salud"<<endl;
                }
                cout<<endl;
            }
        }
    }else{
        cout<<soldado_jugador1->nombre<<" ha decidido no usar ningun accesorio en este turno"<<endl;
        cout<<endl;
    }
    

    if (soldado_jugador2->mochila_combate[posicion2-1]->tipo=="Supervivencia"){
        
        if(soldado_jugador2->mochila_combate[posicion2-1]->tipo_valor=="Salud"){
            if (soldado_jugador2->salud_combate==soldado_jugador2->salud){
                cout<<soldado_jugador2->nombre<<" no ha recuperado nada. Su salud esta al maximo"<<endl;
            }else{
                soldado_jugador2->salud_combate+=soldado_jugador2->mochila_combate[posicion2-1]->valor;
                if (soldado_jugador2->salud_combate>soldado_jugador2->salud){
                    soldado_jugador2->salud_combate=soldado_jugador2->salud;
                    cout<<soldado_jugador2->nombre<<" ha recuperado toda su salud"<<endl;
                }else{
                    cout<<soldado_jugador2->nombre<<" ha recuperado "<<soldado_jugador2->mochila_combate[posicion2-1]->valor<<" puntos de salud"<<endl;
                }
            }
            
        }else if(soldado_jugador2->mochila_combate[posicion2-1]->tipo_valor=="Energia"){
            if (soldado_jugador2->energia_combate==soldado_jugador2->energia){
                cout<<soldado_jugador2->nombre<<" no ha recuperado nada. Su energia esta al maximo"<<endl;
            }else{
                soldado_jugador2->energia_combate+=soldado_jugador2->mochila_combate[posicion2-1]->valor;
                if (soldado_jugador2->energia_combate>soldado_jugador2->energia){
                    soldado_jugador2->energia_combate=soldado_jugador2->energia;
                    cout<<soldado_jugador2->nombre<<" ha recuperado toda su energia"<<endl;
                }else{
                    cout<<soldado_jugador2->nombre<<" ha recuperado "<<soldado_jugador2->mochila_combate[posicion2-1]->valor<<" midiclorias de energia"<<endl;
                }
            }
            
        }
        
        cout<<soldado_jugador2->nombre<<" ha gastado "<<soldado_jugador2->mochila_combate[posicion2-1]->energia<<" midiclorias de energia en el uso del accesorio"<<endl;
        soldado_jugador2->energia_combate-=soldado_jugador2->mochila_combate[posicion2-1]->energia;
        cout<<"El accesorio "<<soldado_jugador2->mochila_combate[posicion2-1]->nombre<<" de "<<soldado_jugador2->nombre<<" ha sido consumido"<<endl;
        consumir_acc2=true;
        cout<<endl;
    }


    if(consumir_acc1){
        soldado_jugador1->mochila_combate.erase(soldado_jugador1->mochila_combate.begin()+posicion1-1);
    }
    if (consumir_acc2){
        soldado_jugador2->mochila_combate.erase(soldado_jugador2->mochila_combate.begin()+posicion2-1);
    }
    system ("PAUSE");


}


void eliminarAccAcondicionamiento(vector <accesorioPTR> &mochila_combate){
    vector <accesorioPTR> mochila_nueva;
    bool found=false;
    for (int k=0;k<mochila_combate.size();k++){
        if (mochila_combate[k]->tipo!="Acondicionamiento"){
            found=true;
            mochila_nueva.push_back(mochila_combate[k]);
        }
    }
    if (found){
        mochila_combate=mochila_nueva;
    }
    
}


bool ComprobarAcondicionamiento(vector <accesorioPTR> &mochila_combate, string ambiente, string nombre_soldado, char J){
    vector <accesorioPTR> mochila_nueva;
    for (int i=0;i<3;i++){
        if (mochila_combate[i]->tipo_valor==ambiente){
            cout<<"El soldado "<<nombre_soldado<<" del jugador "<<J<<" ha consumido el accesorio: "<<mochila_combate[i]->nombre<<endl;
            cout<<"¡Ahora podra luchar en el ambiente "<<ambiente<<" sin perder salud al atacar!"<<endl;
            eliminarAccAcondicionamiento(mochila_combate);
            return true;
        }
            
    }
    cout<<"El soldado "<<nombre_soldado<<" del jugador "<<J<<" no cuenta con un accesorio de acondicionamiento que lo proteja del ambiente "<<ambiente<<endl;
    eliminarAccAcondicionamiento(mochila_combate);
    return false;
}


void RecuperarRecursos(jugador1PTR &listaJugador1, jugador2PTR &listaJugador2){
    jugador1PTR p;

    if (listaJugador1 != NULL) {
        p = listaJugador1;
        

        while (p != NULL) {
            if (p->descanso) {
                if (p->salud_combate<(p->salud*60)/100){
                    p->salud_combate+=(15*p->salud/100);
                }else{
                    p->salud_combate+=(5*p->salud/100);
                }
                
                p->energia_combate+=(25*p->energia/100);
            }
            
            p = p->prox;
        }
    } 

    jugador2PTR q;

    if (listaJugador2 != NULL) {
        q = listaJugador2;
        

        while (q != NULL) {
            if (q->descanso) {
                if (q->salud_combate<(q->salud*60)/100){
                    q->salud_combate+=(15*q->salud/100);
                }else{
                    q->salud_combate+=(5*q->salud/100);
                }
                
                q->energia_combate+=(25*q->energia/100);
            }
            
            q = q->prox;
        }
    } 
}

bool ComprobarSoldadosJugador1(jugador1PTR listaJugador1){
    jugador1PTR p;

    if (listaJugador1 != NULL) {
        p = listaJugador1;
        
        while (p != NULL) {
            if (p->estado!="K.O.") {
                return false;
            }
            
            p = p->prox;
        }
    } 
    return true;
}

bool ComprobarSoldadosJugador2(jugador2PTR listaJugador2){
    jugador2PTR q;

    if (listaJugador2 != NULL) {
        q = listaJugador2;
        
        while (q != NULL) {
            if (q->estado!="K.O.") {
                return false;
            }
            
            q = q->prox;
        }
    } 
    return true;
}

//-------------------------------------------------------------------INICIO DEL MAIN---------------------------------------------------------------------------
int main() {
    //Variables para: especies, ambientes, accesorios, menus...
    int energia, salud, valor, contenedor;
    string nombre, ambiente, tipo, tipo_valor;
    bool menuTipos, adaptacion_J1, adaptacion_J2; 
    char opcionMenuPrincipal, opcionMenuEspecies, opcionMenuAmbientes, opcionMenuAccesorios, opcionTipoAcc, opcionRecurso, opcionMenuSoldados;

    AlmacenarDatosEspecie();
    AlmacenarDatosAmbiente();
    AlmacenarDatosAccesorio();

    do {
        menuPrincipal();
        opcionMenuPrincipal = obtenerOpcionMenu('5');

        switch (opcionMenuPrincipal) {

            //OPCION ESPECIES
            case '1':
            do {
                menuEspecies();
                opcionMenuEspecies = obtenerOpcionMenu('4');

                switch (opcionMenuEspecies) {
                    case '1':
                    system ("cls");
                    MostrarEspecies (listaEspecie);
                    system ("PAUSE");
                    break;

                    case '2':
                    system ("cls");
                    nombre = ValidarNombreEspecie(listaEspecie);
                    cout << "Ingrese la energia: "; energia = obtenerEnteroPositivo();
                    cout << "Ingrese la salud: "; salud = obtenerEnteroPositivo();
                    MostrarAmbientes(vector_ambientes);
                    if (!vector_ambientes.empty()) {
                        RegistroListaEspecie(listaEspecie, nombre, energia, salud, ConsultarAmbiente(vector_ambientes));
                        cout << "La especie " << nombre << " ha sido aniadida" << endl;
                    } else {
                        cout << "No se encuentra ningun ambiente registrado. Agregue al menos uno e intentelo de nuevo" << endl;
                    }
                    system("PAUSE");
                    break;

                    case '3':
                    system ("cls");
                    EliminarEspecie(listaEspecie);
                    system("PAUSE");
                    break;

                    case '4':
                    system ("cls");
                    ModificarDatosEspecie(listaEspecie, vector_ambientes);
                    system("PAUSE");
                    break;
                }
            } while(opcionMenuEspecies != '0');
            break;

            //OPCION AMBIENTES
            case '2':
            do {
                menuAmbientes();
                opcionMenuAmbientes = obtenerOpcionMenu('4');

                switch (opcionMenuAmbientes) {

                    case '1':
                    system("cls");
                    MostrarAmbientes(vector_ambientes);
                    system ("PAUSE");
                    break;

                    case '2':
                    system("cls");
                    cin.ignore(); cout << "Ingrese el ambiente que desea agregar: "; getline(cin,ambiente);
                    AgregarAmbiente(vector_ambientes, ambiente);
                    system("PAUSE");
                    break;
                    
                    case '3':
                    system("cls");
                    EliminarAmbiente(vector_ambientes, listaEspecie, listaAccesorio);
                    system("PAUSE");
                    break;

                    case '4':
                    cin.ignore(); cout << "Ingrese el ambiente que desea modificar: "; getline(cin,ambiente);
                    ModificarAmbiente(vector_ambientes, listaEspecie, listaAccesorio, ambiente);
                    system("PAUSE");
                    break;
                }
            }while (opcionMenuAmbientes != '0');
            break;

            //OPCION ACCESORIOS
            case '3':
            do {
                menuAccesorios();
                opcionMenuAccesorios = obtenerOpcionMenu('4');

                switch(opcionMenuAccesorios) {

                    case '1':
                    system("cls");
                    MostrarAccesorios(listaAccesorio);
                    system("PAUSE");
                    break;

                    case '2':
                    nombre = ValidarNombreAccesorio(listaAccesorio);
                    cout << "Ingrese el valor de midiclorias que consumira el uso del accesorio: "; 
                    energia = obtenerEnteroPositivo();
                    menuTipos = true;
                    do {
                        menuAccesoriosTipos();
                        opcionTipoAcc = obtenerOpcionMenu('4');

                        switch (opcionTipoAcc)  {

                            case '1':
                            tipo = "Ataque";
                            cout << "Ingrese el PORCENTAJE de DANIO que podra realizar sobre el oponente: "; 
                            valor = obtenerPorcentaje();
                            tipo_valor = "0";
                            contenedor = 0;
                            break;

                            case '2':
                            tipo = "Defensa";
                            cout << "Ingrese el PORCENTAJE de DEFENSA contra el oponente: "; 
                            valor = obtenerPorcentaje();
                            tipo_valor = "0";
                            cout << "Ingrese el valor inicial de proteccion que otorgara su uso: "; 
                            contenedor = obtenerEnteroPositivo();
                            break;

                            case '3':
                            tipo = "Supervivencia";
                            contenedor = 0;
                            cout << " Seleccione el tipo de recurso que recupera" << endl;
                            cout << " [1] Energia " << endl;
                            cout << " [2] Salud " << endl;
                            cout << "Elija una opcion: ";
                            opcionRecurso = obtenerOpcionRecurso();
                            switch (opcionRecurso) {
                                case '1':
                                tipo_valor = "Energia";
                                cout << "Ingrese el PORCENTAJE de ENERGIA que se podra recuperar con su uso: "; 
                                valor = obtenerPorcentaje();
                                break;

                                case '2':
                                tipo_valor = "Salud";
                                cout << "Ingrese el PORCENTAJE de SALUD que se podra recuperar con su uso: "; 
                                valor = obtenerPorcentaje();
                                break;
                            }
                            break;

                            case '4':
                            tipo = "Acondicionamiento";
                            valor = 0;
                            contenedor = 0;
                            MostrarAmbientes(vector_ambientes);
                            cout << "Para cual ambiente esta diseniado?: " << endl;
                            tipo_valor = ConsultarAmbiente(vector_ambientes);
                            break;

                        }
                        RegistroListaAccesorio(listaAccesorio, nombre, tipo, valor, tipo_valor, energia, contenedor);
                        cout << "El accesorio " << nombre << " ha sido aniadido" << endl;
                        menuTipos = false;
                        system("PAUSE");                
                    } while (menuTipos);
                    break;

                    case '3':
                    system ("cls");
                    EliminarAccesorio(listaAccesorio);
                    system("PAUSE");  
                    break;

                    case '4':
                    system ("cls");
                    ModificarAccesorio(listaAccesorio, vector_ambientes);
                    system("PAUSE");  
                    break;
                }    
            } while(opcionMenuAccesorios != '0');
            break;

            //OPCION SOLDADOS
            case '4':
                do {
                    menuSoldados();
                    opcionMenuSoldados = obtenerOpcionMenu('4');

                    switch (opcionMenuSoldados) {
                        case '1':
                        system("cls");
                        MostrarSoldados(listaSoldados);
                        system ("PAUSE");
                        break;

                        case '2':
                        system ("cls");
                        if (RequisitosSoldado(listaEspecie, listaAccesorio, vector_ambientes)) {
                            cout << "***e n l i s t a r   s o l d a d o ***" << endl; cout << endl;
                            nombre = ValidarNombreSoldado(listaSoldados);
                            RegistroListaSoldados(listaSoldados, nombre);
                            system ("cls");
                            cout << "El soldado " << nombre << " ha sido reclutado!" << endl; cout << endl;
                            MostrarSoldados(listaSoldados);
                        }
                        system ("PAUSE");
                        break;

                        case '3':
                        system ("cls");
                        EliminarSoldado(listaSoldados);
                        system ("PAUSE");
                        break;

                        case '4':
                        system ("cls");
                        ModificarSoldado(listaSoldados, vector_ambientes);
                        system ("PAUSE");
                        break;
                    }
                } while (opcionMenuSoldados != '0');
                break;
            
            //OPCION GUERRA
            case '5':
                if (ContarSoldados(listaSoldados)<6){
                    cout<<"No existen soldados suficientes para iniciar la guerra. Deben existir por lo menos 6 soldados"<<endl;
                    system ("PAUSE");
                    break;
                }else{
                    string ambiente_guerra=vector_ambientes[GenerarAmbiente()];
                    cout<<"La guerra se disputara en el ambiente: "<<ambiente_guerra<<endl;
                    cout<<"ATENCION! Los soldados que vayan a la guerra sin tener los medios necesarios para luchar en el ambiente "<<ambiente_guerra<<" perderan un tercio de su salud por cada ataque que realicen"<<endl;
                    cout<<"Si se lleva un accesorio de acondicionamiento incompatible con el ambiente "<<ambiente_guerra<<", este sera consumido"<<endl;
                    system ("PAUSE"); 
                    system ("cls");
                    GenerarSoldadosJugador1(listaSoldados);
                    GenerarSoldadosJugador2(listaSoldados);
                    system ("cls");
                    cout<<"A continuacion se sortearan los soldados de cada bando y el jugador que comenzara atacando. "; system ("PAUSE"); 
                    bool prioridad=GenerarPrioridad();

                    int num_combate=1;
                    while(true){
                        if (prioridad){
                            cout<<"El primer ataque del combate "<<num_combate<<" sera realizado por el jugador 1"<<endl;
                            system ("PAUSE"); 
                            jugador1PTR soldado_jugador1=SeleccionarSoldadoJugador1(listaJugador1);
                            soldado_jugador1->descanso=false;
                            seleccionarAccesoriosJugador1(soldado_jugador1, num_combate);
                            
                            system ("PAUSE");
                            system ("cls");
                            
                            cout<<"El jugador 2 iniciara a la defensiva"<<endl;
                            system ("PAUSE"); 
                            jugador2PTR soldado_jugador2=SeleccionarSoldadoJugador2(listaJugador2);
                            soldado_jugador2->descanso=false;
                            seleccionarAccesoriosJugador2(soldado_jugador2, num_combate);
                            
                            RecuperarRecursos(listaJugador1, listaJugador2);

                            system ("PAUSE");
                            system ("cls");

                            //cout<<"A continuacion se sortearan nuevamente los soldados entre los dos bandos"<<endl;

                            if (soldado_jugador1->especie->ambiente==ambiente_guerra){
                                cout<<"¡El soldado "<<soldado_jugador1->nombre<<" del jugador 1 puede luchar en el ambiente "<<ambiente_guerra<<" sin necesidad de un accesorio!"<<endl;
                                adaptacion_J1=true;
                                eliminarAccAcondicionamiento(soldado_jugador1->mochila_combate);
                            }else{
                                adaptacion_J1=ComprobarAcondicionamiento(soldado_jugador1->mochila_combate, ambiente_guerra, soldado_jugador1->nombre, '1');
                            }
                            
                            if (soldado_jugador2->especie->ambiente==ambiente_guerra){
                                cout<<"¡El soldado "<<soldado_jugador2->nombre<<" del jugador 2 puede luchar en el ambiente "<<ambiente_guerra<<" sin necesidad de un accesorio!"<<endl;
                                adaptacion_J2=true;
                                eliminarAccAcondicionamiento(soldado_jugador2->mochila_combate);
                            }else{
                                adaptacion_J2=ComprobarAcondicionamiento(soldado_jugador2->mochila_combate, ambiente_guerra, soldado_jugador2->nombre, '2');
                            }


                            cout<<"E L  C O M B A T E  H A  C O M E N Z A D O"<<endl;
                            system ("PAUSE");
                            system ("cls");

                            while(true){
                                if(prioridad){
                                    mostrarInfoCombate_caso1(soldado_jugador1, soldado_jugador2, adaptacion_J1);

                                    if ((soldado_jugador1->salud_combate<=0 || soldado_jugador2->energia_combate<=0) && (soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0)){
                                        cout<<soldado_jugador1->nombre<<" y "<<soldado_jugador2->nombre<<" se han quedado sin salud o energia"<<endl;
                                        cout<<"Ambos soldados han sido derrotados"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="K.O.";
                                        break;
                                    }else if (soldado_jugador1->salud_combate<=0 || soldado_jugador1->energia_combate<=0){
                                        cout<<soldado_jugador1->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="Descanzo";
                                        soldado_jugador2->descanso=true;
                                        if(soldado_jugador2->energia_combate>0){
                                            soldado_jugador1->energia_combate+=soldado_jugador2->energia_combate;
                                            cout<<soldado_jugador1->nombre<<" ha absorbido la energia restante de "<<soldado_jugador2->nombre<<endl;
                                        }
                                        break;
                                    }else if(soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0){
                                        cout<<soldado_jugador2->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador2->estado="K.O.";
                                        soldado_jugador1->estado="Descanzo";
                                        soldado_jugador1->descanso=true;
                                        if(soldado_jugador1->energia_combate>0){
                                            soldado_jugador2->energia_combate+=soldado_jugador1->energia_combate;
                                            cout<<soldado_jugador2->nombre<<" ha absorbido la energia restante de "<<soldado_jugador1->nombre<<endl;
                                        }
                                        break;
                                    }

                                    prioridad=false;
                                    

                                }else{
                                    mostrarInfoCombate_caso2(soldado_jugador1, soldado_jugador2, adaptacion_J2);
                                    
                                    if ((soldado_jugador1->salud_combate<=0 || soldado_jugador2->energia_combate<=0) && (soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0)){
                                        cout<<soldado_jugador1->nombre<<" y "<<soldado_jugador2->nombre<<" se han quedado sin salud o energia"<<endl;
                                        cout<<"Ambos soldados han sido derrotados"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="K.O.";
                                        break;
                                    }else if (soldado_jugador1->salud_combate<=0 || soldado_jugador1->energia_combate<=0){
                                        cout<<soldado_jugador1->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="Descanzo";
                                        soldado_jugador2->descanso=true;
                                        if(soldado_jugador2->energia_combate>0){
                                            soldado_jugador1->energia_combate+=soldado_jugador2->energia_combate;
                                            cout<<soldado_jugador1->nombre<<" ha absorbido la energia restante de "<<soldado_jugador2->nombre<<endl;
                                        }
                                        break;
                                    }else if(soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0){
                                        cout<<soldado_jugador2->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador2->estado="K.O.";
                                        soldado_jugador1->estado="Descanzo";
                                        soldado_jugador1->descanso=true;
                                        if(soldado_jugador1->energia_combate>0){
                                            soldado_jugador2->energia_combate+=soldado_jugador1->energia_combate;
                                            cout<<soldado_jugador2->nombre<<" ha absorbido la energia restante de "<<soldado_jugador1->nombre<<endl;
                                        }
                                        break;
                                    }

                                    prioridad=true;
                                    
                                }
                            }
                            system ("PAUSE");
                            system ("cls");


                        }else{
                            cout<<"El primer ataque del combate "<<num_combate<<" sera realizado por el jugador 2"<<endl;
                            system ("PAUSE"); 
                            jugador2PTR soldado_jugador2=SeleccionarSoldadoJugador2(listaJugador2);
                            soldado_jugador2->descanso=false;
                            seleccionarAccesoriosJugador2(soldado_jugador2, num_combate);
                            
                            system ("PAUSE"); 
                            system ("cls");

                            cout<<"El jugador 1 iniciara a la defensiva"<<endl;
                            system ("PAUSE"); 
                            jugador1PTR soldado_jugador1=SeleccionarSoldadoJugador1(listaJugador1);
                            soldado_jugador1->descanso=false;
                            seleccionarAccesoriosJugador1(soldado_jugador1, num_combate);
                            
                            RecuperarRecursos(listaJugador1, listaJugador2);

                            system ("PAUSE");
                            system ("cls");

                            if (soldado_jugador1->especie->ambiente==ambiente_guerra){
                                cout<<"¡El soldado "<<soldado_jugador1->nombre<<" del jugador 1 puede luchar en el ambiente "<<ambiente_guerra<<" sin necesidad de un accesorio!"<<endl;
                                adaptacion_J1=true;
                                eliminarAccAcondicionamiento(soldado_jugador1->mochila_combate);
                            }else{
                                adaptacion_J1=ComprobarAcondicionamiento(soldado_jugador1->mochila_combate, ambiente_guerra, soldado_jugador1->nombre, '1');
                            }
                            
                            if (soldado_jugador2->especie->ambiente==ambiente_guerra){
                                cout<<"¡El soldado "<<soldado_jugador2->nombre<<" del jugador 2 puede luchar en el ambiente "<<ambiente_guerra<<" sin necesidad de un accesorio!"<<endl;
                                adaptacion_J2=true;
                                eliminarAccAcondicionamiento(soldado_jugador2->mochila_combate);
                            }else{
                                adaptacion_J2=ComprobarAcondicionamiento(soldado_jugador2->mochila_combate, ambiente_guerra, soldado_jugador2->nombre, '2');
                            }

                            cout<<"E L  C O M B A T E  H A  C O M E N Z A D O"<<endl;
                            system ("PAUSE");
                            system ("cls");

                            while(true){
                                if(prioridad){
                                    mostrarInfoCombate_caso1(soldado_jugador1, soldado_jugador2, adaptacion_J1);
                                    
                                    if ((soldado_jugador1->salud_combate<=0 || soldado_jugador2->energia_combate<=0) && (soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0)){
                                        cout<<soldado_jugador1->nombre<<" y "<<soldado_jugador2->nombre<<" se han quedado sin salud o energia"<<endl;
                                        cout<<"Ambos soldados han sido derrotados"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="K.O.";
                                        break;
                                    }else if (soldado_jugador1->salud_combate<=0 || soldado_jugador1->energia_combate<=0){
                                        cout<<soldado_jugador1->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="Descanzo";
                                        soldado_jugador2->descanso=true;
                                        if(soldado_jugador2->energia_combate>0){
                                            soldado_jugador1->energia_combate+=soldado_jugador2->energia_combate;
                                            cout<<soldado_jugador1->nombre<<" ha absorbido la energia restante de "<<soldado_jugador2->nombre<<endl;
                                        }
                                        break;
                                    }else if(soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0){
                                        cout<<soldado_jugador2->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador2->estado="K.O.";
                                        soldado_jugador1->estado="Descanzo";
                                        soldado_jugador1->descanso=true;
                                        if(soldado_jugador1->energia_combate>0){
                                            soldado_jugador2->energia_combate+=soldado_jugador1->energia_combate;
                                            cout<<soldado_jugador2->nombre<<" ha absorbido la energia restante de "<<soldado_jugador1->nombre<<endl;
                                        }
                                        break;
                                    }

                                    prioridad=false;
                                    

                                }else{
                                    mostrarInfoCombate_caso2(soldado_jugador1, soldado_jugador2, adaptacion_J2);

                                    if ((soldado_jugador1->salud_combate<=0 || soldado_jugador2->energia_combate<=0) && (soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0)){
                                        cout<<soldado_jugador1->nombre<<" y "<<soldado_jugador2->nombre<<" se han quedado sin salud o energia"<<endl;
                                        cout<<"Ambos soldados han sido derrotados"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="K.O.";
                                        break;
                                    }else if (soldado_jugador1->salud_combate<=0 || soldado_jugador1->energia_combate<=0){
                                        cout<<soldado_jugador1->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador1->estado="K.O.";
                                        soldado_jugador2->estado="Descanzo";
                                        soldado_jugador2->descanso=true;
                                        if(soldado_jugador2->energia_combate>0){
                                            soldado_jugador1->energia_combate+=soldado_jugador2->energia_combate;
                                            cout<<soldado_jugador1->nombre<<" ha absorbido la energia restante de "<<soldado_jugador2->nombre<<endl;
                                        }
                                        break;
                                    }else if(soldado_jugador2->salud_combate<=0 || soldado_jugador2->energia_combate<=0){
                                        cout<<soldado_jugador2->nombre<<" se ha quedado sin salud o energia. Por lo que ha sido derrotado"<<endl;
                                        soldado_jugador2->estado="K.O.";
                                        soldado_jugador1->estado="Descanzo";
                                        soldado_jugador1->descanso=true;
                                        if(soldado_jugador1->energia_combate>0){
                                            soldado_jugador2->energia_combate+=soldado_jugador1->energia_combate;
                                            cout<<soldado_jugador2->nombre<<" ha absorbido la energia restante de "<<soldado_jugador1->nombre<<endl;
                                        }
                                        break;
                                    }

                                    prioridad=true;
                                    
                                }
                            }
                            system ("PAUSE");
                            system ("cls");


                        }

                        num_combate+=1;
                        
                        if (ComprobarSoldadosJugador1(listaJugador1) && ComprobarSoldadosJugador2(listaJugador2)){
                            cout<<"A ningun jugador le quedan soldados para luchar"<<endl;
                            cout<<"La guerra ha terminado en un empate"<<endl;
                            break;
                        }else if(ComprobarSoldadosJugador1(listaJugador1)){
                            cout<<"Al jugador 1 no le quedan soldados para luchar"<<endl;
                            cout<<"El jugador 2 ha resultado victorioso!!!"<<endl;
                            break;
                        }else if(ComprobarSoldadosJugador2(listaJugador2)){
                            cout<<"Al jugador 2 no le quedan soldados para luchar"<<endl;
                            cout<<"El jugador 1 ha resultado victorioso!!!"<<endl;
                            break;
                        }

                    }
                    
                }
                system ("PAUSE");
                opcionMenuPrincipal='0';

        } //fin switch menu ppal

    }while(opcionMenuPrincipal != '0');

    system("PAUSE");
    return 0;
}
