#pragma once
#include <QObject>
#include <QTimer>
#include <vector>
#include "graphics/HexTile.h"

class ClimateSystem : public QObject {
    Q_OBJECT
public:
    explicit ClimateSystem(QObject* parent = nullptr);
    void applyClimate(std::vector<HexTile>& tiles);

signals:
    void climateUpdated();

private:
    QTimer m_timer;
    void updateClimate(std::vector<HexTile>& tiles);
};