// Ivan Estrada A01643642
#include "MyHashTable.h"

// Complejidad: O(1)
MyHashTable::MyHashTable() {
    sizeA = 11;  
    size = 0;
    tabla = new list<HashNode>[sizeA];
}

// Complejidad: O(1)
MyHashTable::~MyHashTable() {
    delete[] tabla;
}

// Complejidad: O(n)
void MyHashTable::rehashing() {
    int newSizeA = sizeA * 2 + 1; 
    list<HashNode>* newTabla = new list<HashNode>[newSizeA]; // Nuevo arreglo

    // Copiar los elementos al nuevo arreglo
    for (int i = 0; i < sizeA; ++i) {
        for (const auto& node : tabla[i]) {
            int newPos = getPos(node.key); // Calcular nueva posicion
            newTabla[newPos].emplace_back(node); // Insertar en nueva poscion
        }
    }

    delete[] tabla;
    sizeA = newSizeA;
    tabla = newTabla;
}

// Complejidad: O(1)
int MyHashTable::getPos(string key) {
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeA;
}

// Complejidad: O(1) en el mejor caso, O(n) en el peor caso al hacer rehashing
void MyHashTable::put(string key, Dato *data) {
    if (size > sizeA * 0.75) {
        rehashing();
    }
    int pos = getPos(key);
    tabla[pos].emplace_back(key, data); 
    size++;
}

// Complejidad: O(1) en el mejor caso, O(n) en el peor caso (cuando hay colisiones)
void MyHashTable::get(string key) {
    int pos = getPos(key);
    for (const auto& node : tabla[pos]) {
        if (node.key == key) {
            cout << node.data->getFullDate() << endl;
        }
    }
}

// Complejidad: O(n), donde n es el número de elementos en la lista correspondiente a la posicion en el arreglo
void MyHashTable::remove(string key) {
    int pos = getPos(key);
    auto& listAtPos = tabla[pos];

    // Utilizar un iterador para encontrar el elemento con la clave dada y eliminarlo
    auto it = listAtPos.begin();
    while (it != listAtPos.end()) {
        if (it->key == key) {
            it = listAtPos.erase(it);
            size--;
            return; // Salir del método después de eliminar el elemento
        }
        else {
            ++it;
        }
    }
}

// Complejidad: O(1)
bool MyHashTable::isEmpty() {
    return size == 0;
}
