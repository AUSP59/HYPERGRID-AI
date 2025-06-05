#pragma once
#include <QPoint>
#include <vector>

class AIUnit {
public:
    AIUnit(int q, int r);
    QPoint position() const;
    void setTarget(int q, int r);
    void update();

private:
    int m_q, m_r;
    int m_targetQ, m_targetR;
    std::vector<QPoint> m_path;
    void computePath();
};