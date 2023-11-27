#include <iostream>
#include "Dato.h"
#include <map>
#include "LinkedList.h"
#include "MyHashTable.h"

using namespace std;

#define LINUX_PREFIX "./"

int main(){

    string line;        // Var donde se almacenará la linea que se está leyendo del txt
    LinkedList llDatos; // Linked list donde se almacenarán los datos

    // leemos el archivo de texto
    cout << "Recolectando Datos del Archivo" << endl;

    ifstream File(LINUX_PREFIX"bitacora3-1.txt");

    // inicializamos el mapa donde registraremos la cantidad de veces que se repiten las direcciones ip
    map<string, int> ipMap; // como clave tenemos la direccion ip, sin el su puerto, y como valor, las n veces que se repite
    MyHashTable hashTable;

    // obtenemos cada linea del archivo de texto
    int lines_num = 0;
    while(getline(File, line)){
        Dato *current = new Dato(line); // creamos un nuevo dato con la linea obtenida
        string strIP = current->getIpNoPort(); // obtenemos la ip del primer dato del vector
        hashTable.put(strIP, current); // insertamos el dato en la tabla hash
        lines_num++; // Aumentar contador de lineas
        
        // Desconozco si esto es necesario de hacer
    }
    File.close();

    if (lines_num == 0)
    {
        cout << "No se pudieron cargar los datos\n";
    }

    /*

    cout << "Ordenando los datos de la bitacora " << endl;
    // ordenamos los datos de la bitacora por direcciones ip con un bubble sort
    llDatos.bubbleSort();
    cout << "Se ordenaron los datos de la bitacora correctamente" << endl;

    ofstream File2(LINUX_PREFIX"bitacoraOrdenadaIP-Eq7-BST.txt");
    File2 << llDatos;
    File2.close();

    // creamos un BST llamado bst, donde ingresaremos las distintas ip con sus n repeticiones
    // dichas repeticiones seran la clave de cada nodo del BST

    // para recorrer el mapa que construimos previamente, me base en la siguiente liga:
    // https://stackoverflow.com/questions/26281979/c-loop-through-map
    map<string, int>::iterator i;
    for (i = ipMap.begin(); i != ipMap.end(); i++)
    {
        string clave = i->first;
        int valor = i->second;
    }

    cout << "Imprimiendo las direcciones IP de la bitacora mas repetidas" << endl;
    // Buscamos las direcciones IP que mas veces trataron de ingresar

    */

    string ipbusqueda;
    cout << "Ingresa una direccion IP (no incluir su puerto)" << "\n";
    cout << "XX.XX.XXX.XXX -> ";
    cin >> ipbusqueda;

    hashTable.get(ipbusqueda);


    return 0;
}