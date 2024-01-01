#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include <QPair>
#include <QString>

class Hashtable
{
private:
    QVector<QPair<int, QPair<QString, QString>>> table;
    int size;
    int hash(int key);

public:
    Hashtable(int size);
    void insert(int key, QPair<QString, QString> value);
    QPair<QString, QString> search(int key);
    void remove(int key);
    void print();
};

#endif // HASHTABLE_H
