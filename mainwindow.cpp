#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    createObjects();
    createUI();
    createConnects();
    resize(800,600);
}

MainWindow::~MainWindow() {

}

void MainWindow::createUI() {
    setCentralWidget(screen);
    setMenuBar(menuBar);
    menuBar->addMenu(global);
    global->addMenu(init);
    global->addMenu(method);
    global->addAction(restart);
    init->addAction(start);
    init->addAction(finish);
    method->addAction(setDFS);
    method->addAction(setBFS);
}

void MainWindow::createObjects() {
    screen = new Screen(this);
    menuBar = new QMenuBar(this);
    global = new QMenu("Действие",this);
    init = new QMenu("Вершина",this);
    method = new QMenu("Установить метод",this);
    start = new QAction("Установить стартовую вершину",this);
    finish = new QAction("Установить финишную вершину",this);
    restart = new QAction("Рестарт",this);
    setDFS = new QAction("Поиск в глубину",this);
    setBFS = new QAction("Поиск в ширину",this);
}

void MainWindow::createConnects() {
    connect(start, &QAction::triggered, screen, &Screen::setStart);
    connect(finish, &QAction::triggered, screen, &Screen::setFinish);
    connect(setDFS, &QAction::triggered, screen, &Screen::setDFSMode);
    connect(setBFS, &QAction::triggered, screen, &Screen::setBFSMode);
    connect(restart, &QAction::triggered, screen, &Screen::restart);
}
