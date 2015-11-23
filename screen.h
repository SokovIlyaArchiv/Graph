#pragma once
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include "graph.h"
enum class MODE{ START,FINISH,NO };
class Screen : public QWidget {
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = 0);
    ushort distance(Point, Point);
    Vertex* freePlace(Point);
    void restart();
    void setDFSMode();
    void setBFSMode();
    void setStart();
    void setFinish();
    void drawVertex(QPainter&);
    void drawEdge(QPainter&);
    Vertex *getVertex(QMouseEvent*);
protected:
    virtual void paintEvent(QPaintEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
private:
    MODE mode;
    Graph *graph;
    Vertex *activeVertex;
};
