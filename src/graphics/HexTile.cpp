#include "HexTile.h"

HexTile::HexTile(int q, int r, TerrainType terrain, ClimateType climate)
    : m_q(q), m_r(r), m_terrain(terrain), m_climate(climate) {}

int HexTile::q() const { return m_q; }
int HexTile::r() const { return m_r; }
HexTile::TerrainType HexTile::terrain() const { return m_terrain; }
HexTile::ClimateType HexTile::climate() const { return m_climate; }

QColor HexTile::tileColor() const {
    QColor base;
    switch (m_terrain) {
        case Plain: base = QColor(100, 200, 100); break;
        case Forest: base = QColor(30, 120, 60); break;
        case Mountain: base = QColor(100, 100, 100); break;
        case Water: base = QColor(50, 100, 255); break;
    }

    switch (m_climate) {
        case Rain: base = base.darker(110); break;
        case Snow: base = QColor(220, 240, 255); break;
        case Storm: base = base.darker(150); break;
        default: break;
    }

    return base;
}