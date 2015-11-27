#pragma once
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "screen.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Screen* screen;
    QMenuBar* menuBar;
    QMenu *global,*init, *method;
    QAction *start, *finish,
            *restart, *clearAll,
            *setDFS, *setBFS, *setDSA,
            *autoStep, *load, *save;
    void createUI();
    void createObjects();
    void createConnects();
};
