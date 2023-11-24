#include <iostream>
#include "Dato.h"
#include <map>
#include "LinkedList.h"

using namespace std;

int main()
{

    string line;        // Var donde se almacenará la linea que se está leyendo del txt
    LinkedList llDatos; // Linked list donde se almacenarán los datos

    // leemos el archivo de texto
    cout << "Recolectando Datos del Archivo" << endl;

    ifstream File("bitacora2.txt");

    // inicializamos el mapa donde registraremos la cantidad de veces que se repiten las direcciones ip
    map<string, int> ipMap; // como clave tenemos la direccion ip, sin el su puerto, y como valor, las n veces que se repite

    // obtenemos cada linea del archivo de texto
    int lines_num = 0;
    while (getline(File, line))
    {
        llDatos.insertLast(new Dato(line));
        string strIP = (llDatos.last())->getIpNoPort(); // obtenemos la ip del primer dato del vector
        if (ipMap.find(strIP) == ipMap.end())
        {
            ipMap[strIP] = 1; // si la ip no ha sido registrada en el mapa, le asignamos el valor de 1 repeticion
        }
        else
        {
            ipMap[strIP]++; // si la ip ya habia sido registrada en el mapa, le incrementamos en 1 la cantidad de repeticiones
        }
        lines_num++; // Aumentar contador de lineas
    }
    File.close();

    if (lines_num == 0)
    {
        cout << "No se pudieron cargar los datos\n";
    }

    cout << "Ordenando los datos de la bitacora " << endl;
    // ordenamos los datos de la bitacora por direcciones ip con un bubble sort
    llDatos.bubbleSort();
    cout << "Se ordenaron los datos de la bitacora correctamente" << endl;

    ofstream File2("bitacoraOrdenadaIP-Eq7-BST.txt");
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

    return 0;
}