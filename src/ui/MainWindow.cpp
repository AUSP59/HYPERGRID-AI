#include "MainWindow.h"
#include "core/GameEngine.h"
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(GameEngine* engine, QWidget* parent)
    : QMainWindow(parent) {
    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);
    QLabel* label = new QLabel("Welcome to HYPERGRID-AI!", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
    central->setLayout(layout);
    setCentralWidget(central);
}