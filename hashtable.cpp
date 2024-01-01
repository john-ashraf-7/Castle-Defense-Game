#include "Hashtable.h"
#include <QDebug>
#include <QHash>

Hashtable::Hashtable(int size) : size(size) {
    table.resize(size, qMakePair(-1, qMakePair("", "")));
}

int Hashtable::hash(int key) {
    return qHash(key) % size;
}

void Hashtable::insert(int key, QPair<QString, QString> value) {
    int index = hash(key);
    while (table[index].first != -1 && table[index].first != key) {
        index = (index + 1) % size;
    }
    table[index] = qMakePair(key, value);
}

QPair<QString, QString> Hashtable::search(int key) {
    int index = hash(key);
    while (table[index].first != -1) {
        if (table[index].first == key) {
            return table[index].second;
        }
        index = (index + 1) % size;
    }
    return qMakePair("", "");
}

void Hashtable::remove(int key) {
    int index = hash(key);
    while (table[index].first != -1) {
        if (table[index].first == key) {
            table[index].first = -1; // mark as deleted
            table[index].second = qMakePair("", "");
            return;
        }
        index = (index + 1) % size;
    }
}

void Hashtable::print() {
    for (int i = 0; i < size; i++) {
        if (table[i].first != -1) {
            qDebug() << table[i].first << ": " << table[i].second;
        }
    }
}
