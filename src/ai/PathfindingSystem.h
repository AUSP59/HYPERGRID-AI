#pragma once
#include <vector>
#include <QPoint>
#include <map>

class PathfindingSystem {
public:
    static std::vector<QPoint> findPath(const QPoint& start, const QPoint& goal);
};