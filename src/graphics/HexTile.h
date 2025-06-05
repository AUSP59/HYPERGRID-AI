#pragma once
#include <QColor>

class HexTile {
public:
    enum TerrainType { Plain, Forest, Mountain, Water };
    enum ClimateType { Normal, Rain, Snow, Storm };

    HexTile(int q = 0, int r = 0, TerrainType terrain = Plain, ClimateType climate = Normal);
    int q() const;
    int r() const;
    TerrainType terrain() const;
    ClimateType climate() const;
    QColor tileColor() const;

private:
    int m_q, m_r;
    TerrainType m_terrain;
    ClimateType m_climate;
};