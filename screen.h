#pragma once
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include "graph.h"
enum class MODE{ START,FINISH,NO };
class Screen : public QWidget {
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = 0);
    Vertex* freePlace(Point);
    Vertex *getVertex(QMouseEvent*);
    void load();
    void save();
    void restart();
    void setTimer();
    void clearAll();
    void setDSAMode();
    void setDFSMode();
    void setBFSMode();
    void setStart();
    void setFinish();
protected:
    virtual void paintEvent(QPaintEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
private:
    void timer();
    void drawVertex(QPainter&);
    void drawEdge(QPainter&);
    void drawText(QPainter& painter);
    bool distanceNearest(Point);
    ushort distance(Point, Point);
    MODE mode;
    QTimer* mTimer;
    Graph *graph;
    Vertex *activeVertex;
};
