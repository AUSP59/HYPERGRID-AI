#include "PathfindingSystem.h"
#include <queue>
#include <cmath>

struct Node {
    QPoint point;
    int cost;
    bool operator>(const Node& other) const { return cost > other.cost; }
};

static std::vector<QPoint> getNeighbors(const QPoint& hex) {
    static const std::vector<QPoint> directions = {
        {+1, 0}, {0, +1}, {-1, +1}, {-1, 0}, {0, -1}, {+1, -1}
    };
    std::vector<QPoint> neighbors;
    for (const auto& d : directions)
        neighbors.push_back(QPoint(hex.x() + d.x(), hex.y() + d.y()));
    return neighbors;
}

static int heuristic(const QPoint& a, const QPoint& b) {
    return std::abs(a.x() - b.x()) + std::abs(a.y() - b.y());
}

std::vector<QPoint> PathfindingSystem::findPath(const QPoint& start, const QPoint& goal) {
    std::priority_queue<Node, std::vector<Node>, std::greater<>> frontier;
    frontier.push({start, 0});
    std::map<QPoint, QPoint> came_from;
    std::map<QPoint, int> cost_so_far;
    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        QPoint current = frontier.top().point;
        frontier.pop();

        if (current == goal) break;

        for (const QPoint& next : getNeighbors(current)) {
            int new_cost = cost_so_far[current] + 1;
            if (!cost_so_far.contains(next) || new_cost < cost_so_far[next]) {
                cost_so_far[next] = new_cost;
                int priority = new_cost + heuristic(goal, next);
                frontier.push({next, priority});
                came_from[next] = current;
            }
        }
    }

    std::vector<QPoint> path;
    QPoint current = goal;
    while (current != start) {
        if (!came_from.contains(current)) return {};
        path.push_back(current);
        current = came_from[current];
    }
    std::reverse(path.begin(), path.end());
    return path;
}