// Ivan Estrada A01643642
#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <iostream>
#include <list>
#include "Dato.h"

using namespace std;

struct HashNode {
    string key;
    Dato *data;
    HashNode(const string& k, Dato *d) : key(k), data(d) {}
};

class MyHashTable {
public:
    MyHashTable(); 
    ~MyHashTable();
    bool isEmpty();
    void put(string key, Dato *data);
    void get(string key);
    void remove(string key);

private:
    list<HashNode>* tabla;
    int size; // Cantidad de valores que hay almacenados en la tabla
    int sizeA; // Cantidad del arreglo
    void rehashing(); // Crece el arreglo al doble del tamaño del arreglo actual + 1
    int getPos(string key);
};

#endif
