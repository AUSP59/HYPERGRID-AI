#pragma once
#include <QMainWindow>

class GameEngine;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(GameEngine* engine, QWidget* parent = nullptr);
};