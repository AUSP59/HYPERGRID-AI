#include "ClimateSystem.h"
#include <cstdlib>
#include <ctime>

ClimateSystem::ClimateSystem(QObject* parent) : QObject(parent) {
    std::srand(std::time(nullptr));
    connect(&m_timer, &QTimer::timeout, this, [this]() {
        emit climateUpdated();
    });
    m_timer.start(5000);
}

void ClimateSystem::applyClimate(std::vector<HexTile>& tiles) {
    updateClimate(tiles);
    emit climateUpdated();
}

void ClimateSystem::updateClimate(std::vector<HexTile>& tiles) {
    for (auto& tile : tiles) {
        int roll = std::rand() % 100;
        if (roll < 70) tile = HexTile(tile.q(), tile.r(), tile.terrain(), HexTile::Normal);
        else if (roll < 80) tile = HexTile(tile.q(), tile.r(), tile.terrain(), HexTile::Rain);
        else if (roll < 90) tile = HexTile(tile.q(), tile.r(), tile.terrain(), HexTile::Snow);
        else tile = HexTile(tile.q(), tile.r(), tile.terrain(), HexTile::Storm);
    }
}