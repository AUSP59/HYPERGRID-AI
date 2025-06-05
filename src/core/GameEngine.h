#pragma once
#include <QObject>

class GameEngine : public QObject {
    Q_OBJECT
public:
    explicit GameEngine(QObject* parent = nullptr);
    void initialize();
};