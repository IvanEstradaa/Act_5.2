#include <iostream>
#include "Dato.h"
#include <map>
#include "MyHashTable.h"
#include "LinkedList.h"

using namespace std;

#define LINUX_PREFIX "./"

int main(){
    string line;        // Var donde se almacenará la linea que se está leyendo del txt

    // leemos el archivo de texto
    cout << "Recolectando Datos del Archivo" << endl;

    ifstream File(LINUX_PREFIX "bitacora3-1.txt");

    MyHashTable hashTable;

    // obtenemos cada linea del archivo de texto
    int lines_num = 0;
    while (getline(File, line)){
        Dato *current = new Dato(line);        // creamos un nuevo dato con la linea obtenida
        string strIP = current->getIpNoPort(); // obtenemos la ip del primer dato del vector
        hashTable.put(strIP, current);         // insertamos el dato en la tabla hash
        lines_num++;                           // Aumentar contador de lineas

        // Desconozco si esto es necesario de hacer
    }
    File.close();

    if (lines_num == 0){
        cout << "No se pudieron cargar los datos\n";
    }

    cout << "Datos cargados exitosamente\n";

    int repetir = 1;

    while(repetir == 1){
        string ipbusqueda;
        cout << "Ingresa una direccion IP (no incluir su puerto)"
            << "\n";
        cout << "XX.XX.XXX.XXX -> "; cin >> ipbusqueda;

        hashTable.get(ipbusqueda);

        cout << "Desea buscar otra IP? (1 = si, 0 = no) -> "; cin >> repetir;
    }
    

    return 0;
}