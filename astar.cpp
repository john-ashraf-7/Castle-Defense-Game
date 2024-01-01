#include "astar.h"
#include <QDebug>

Astar::Astar(QVector<QVector<int>> map, QPoint start, QPoint end)
    : map(map), start(start), end(end) {}


int Astar::calculateH(QPoint a, QPoint b)
{
    return qAbs(a.x() - b.x()) + qAbs(a.y() - b.y());
}

QVector<QPoint> Astar::findpath()
{
    QSet<QPoint> closedSet;
    QSet<QPoint> openSet;
    QHash<QPoint, QPoint> cameFrom;
    QHash<QPoint, int> gScore;
    QHash<QPoint, int> fScore;

    openSet.insert(start);
    gScore[start] = 0;
    fScore[start] = calculateH(start, end);

    while (!openSet.isEmpty())
    {
        QPoint current = getLowestFScore(openSet, fScore);

        if (current == end)
        {
            return redefinepath(cameFrom, current);
        }

        openSet.remove(current);
        closedSet.insert(current);

        QVector<QPoint> neighbours;
        if (current.x() > 0)
            neighbours.append(QPoint(current.x() - 1, current.y()));
        if (current.x() < map[0].size() - 1)
            neighbours.append(QPoint(current.x() + 1, current.y()));
        if (current.y() > 0)
            neighbours.append(QPoint(current.x(), current.y() - 1));
        if (current.y() < map.size() - 1)
            neighbours.append(QPoint(current.x(), current.y() + 1));

        for (const QPoint &neighbour : neighbours)
        {
            if (closedSet.contains(neighbour)/* || map[neighbour.y()][neighbour.x()] == 4*/)
            {
                continue;
            }

            int weight = map[neighbour.y()][neighbour.x()];
            int tentativeGScore = gScore[current] + weight;

            if (!openSet.contains(neighbour) || tentativeGScore < gScore[neighbour])
            {
                cameFrom[neighbour] = current;
                gScore[neighbour] = tentativeGScore;
                fScore[neighbour] = gScore[neighbour] + calculateH(neighbour, end);

                if (!openSet.contains(neighbour))
                {
                    openSet.insert(neighbour);
                }
            }
        }
    }

    // Return an empty path if no valid path was found
    return QVector<QPoint>();
}

QPoint Astar::getLowestFScore(const QSet<QPoint> &openSet, const QHash<QPoint, int> &fScore)
{
    int minFScore = INT_MAX;
    QPoint result;

    for (const QPoint &point : openSet)
    {
        if (fScore[point] < minFScore)
        {
            minFScore = fScore[point];
            result = point;
        }
    }

    return result;
}

QVector<QPoint> Astar::redefinepath(QHash<QPoint, QPoint> cameFrom, QPoint current)
{
    QVector<QPoint> path;
    while (cameFrom.contains(current))
    {
        path.prepend(current);
        current = cameFrom.value(current);
    }

    // Add the start point to the path
    path.prepend(start);
    return path;
}
