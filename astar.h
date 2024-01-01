#ifndef ASTAR_H
#define ASTAR_H
#include <Qvector>
#include <QPair>
#include <QPoint>
#include <QHash>
#include <QSet>
class Astar
{

private:
    QVector<QVector<int>> map;
    QPoint start;
    QPoint end;
public:
    Astar(QVector<QVector<int>> map,QPoint start,QPoint end);
    QVector<QPoint> findpath();
    QVector<QPoint> redefinepath(QHash<QPoint,QPoint> parent,QPoint end);
    int calculateH(QPoint a,QPoint b);
    QPoint getLowestFScore(const QSet<QPoint> &openSet, const QHash<QPoint, int> &fScore);
};

#endif // ASTAR_H
