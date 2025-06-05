#include "GameEngine.h"
#include <QDebug>

GameEngine::GameEngine(QObject* parent) : QObject(parent) {}

void GameEngine::initialize() {
    qDebug() << "GameEngine initialized.";
}