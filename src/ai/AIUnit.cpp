#include "AIUnit.h"
#include "PathfindingSystem.h"

AIUnit::AIUnit(int q, int r) : m_q(q), m_r(r), m_targetQ(q), m_targetR(r) {}

QPoint AIUnit::position() const {
    return QPoint(m_q, m_r);
}

void AIUnit::setTarget(int q, int r) {
    m_targetQ = q;
    m_targetR = r;
    computePath();
}

void AIUnit::update() {
    if (!m_path.empty()) {
        QPoint next = m_path.front();
        m_path.erase(m_path.begin());
        m_q = next.x();
        m_r = next.y();
    }
}

void AIUnit::computePath() {
    m_path = PathfindingSystem::findPath(QPoint(m_q, m_r), QPoint(m_targetQ, m_targetR));
}