// Ivan Estrada A01643642
#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <iostream>
#include <list>

using namespace std;

struct HashNode {
    string key;
    int value;
    HashNode(const string& k, int v) : key(k), value(v) {}
};

class MyHashTable {
public:
    MyHashTable(); 
    ~MyHashTable();
    bool isEmpty();
    void put(string key, int value);
    int get(string key);
    void remove(string key);

private:
    list<HashNode>* tabla;
    int size; // Cantidad de valores que hay almacenados en la tabla
    int sizeA; // Cantidad del arreglo
    void rehashing(); // Crece el arreglo al doble del tamaño del arreglo actual + 1
    int getPos(string key);
};

#endif
