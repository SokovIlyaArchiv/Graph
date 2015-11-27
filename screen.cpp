#include "screen.h"
#include <math.h>
#include <QPolygon>
Vertex *Screen::freePlace(Point vertex) {
    for(ushort c = 0; c < graph->getAmountVertices(); c++) {
        if(distance(graph->getVertex(c)->position,vertex) <= 20) {
            return graph->getVertex(c);
        }
    }
    return nullptr;
}

void Screen::restart() {
    graph->restart();
    update();
}

void Screen::timer() {
    bool check = false;
    for(ushort c = 0; c < graph->getAmountVertices(); c++) {
        if(graph->getVertexType(graph->getVertex(c)) == TYPE::FINISH) {
            check = true;
        }
    }
    if(check) {
        graph->oneStep(width(),height());
        update();
    } else {
        setTimer();
    }
}
void Screen::setTimer() {
    if(mTimer->isActive()) {
        mTimer->stop();
    } else {
        mTimer->start(300);
    }
}

void Screen::clearAll() {
    graph->clearAll();
    update();
}

void Screen::setDSAMode() {
    graph->setDSAMode();
    graph->restart();
}

void Screen::setDFSMode() {
    graph->setDFSMode();
}

void Screen::setBFSMode() {
    graph->setBFSMode();
}

void Screen::setStart() {
    mode = MODE::START;
}

void Screen::setFinish() {
    mode = MODE::FINISH;
}

void Screen::drawVertex(QPainter &painter) {
    painter.setPen(QPen(QColor(0,0,0,255),3));
    for(ushort c = 0; c < graph->getAmountVertices(); c++) {
        switch( graph->getVertexType(graph->getVertex(c)) ) {
            case TYPE::CURRENT:
                painter.setBrush(QColor(40,230,10,255));
                break;
            case TYPE::START:
                painter.setBrush(QColor(250,250,250,255));
                break;
            case TYPE::FINISH:
                painter.setBrush(QColor(0,0,0,255));
                break;
            case TYPE::COMMON:
                painter.setBrush(QColor(230,50,10,255));
                if(graph->getVertex(c)->visited == true) {
                    painter.setBrush(QColor(80,80,80,255));
                }
        }
        if(graph->getVertex(c) == activeVertex) {
            painter.setBrush(Qt::blue);
        }
        painter.setPen(QPen(Qt::black,3));
        painter.drawEllipse(QPoint(width()/graph->getVertex(c)->position.x,
                                   height()/graph->getVertex(c)->position.y),
                                   20,20);
    }
}
void Screen::drawEdge(QPainter &painter) {
    painter.setBrush(Qt::red);
    for(ushort c = 0; c < graph->getAmountVertices(); c++) {
        for(auto& vertex:graph->getVertex(c)->connections) {
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine( QPoint(width()/graph->getVertex(c)->position.x, height()/graph->getVertex(c)->position.y),
                              QPoint(width()/vertex->position.x, height()/vertex->position.y) );
            int x1 = width()/graph->getVertex(c)->position.x,
                y1 = height()/graph->getVertex(c)->position.y,
                x2 = width()/vertex->position.x,
                y2 = height()/vertex->position.y,x3,y3;
            x1 = (x1+x2)/2;
            y1 = (y1+y2)/2;
            float a = (double)(y2-y1)/(x2-x1);
            x3 = (int)(sqrt(225/(1+pow(a,2)))+0.5);
            if((x1 != x2)&&(abs(x1-x2) > 8)) {
                y3 =  a*x3;
                if(x1 < x2) {
                    x3+=x1;
                    y3+=y1;
                } else {
                    x3=x1-x3;
                    y3=y1-y3;
                }
            } else {
                y3 = 15;
                x3 = 0;
                if(y1 < y2) {
                    x3+=x1;
                    y3+=y1;
                } else {
                    x3=x1-x3;
                    y3=y1-y3;
                }
            }
            painter.setPen(QPen(Qt::red,1));
            QPolygon    polygon;
            polygon << QPoint(x1,y1) << QPoint(x1-(y3-y1),y1+(x3-x1)) << QPoint(x3,y3) << QPoint(x1+(y3-y1),y1-(x3-x1));
            painter.drawPolygon(polygon);
        }
    }
}

void Screen::drawText(QPainter &painter) {
    for(ushort c = 0; c < graph->getAmountVertices(); c++) {
        painter.setPen(QPen(Qt::yellow,3));
        QFont font = painter.font();
        font.setPixelSize(15);
        painter.setFont(font);
        if(graph->getVertex(c)->lengthMinWay == USHORT_MAX) {
            painter.drawText(QPoint(width()/graph->getVertex(c)->position.x-15,
                                    height()/graph->getVertex(c)->position.y+5),
                             "NON");

        } else {
            int value = graph->getVertex(c)->lengthMinWay;
            int central = -10;
            if(value > 9) {
                central += 2;
            } else {
                central += 6;
            }
            if(value > 99) {
                central -= 4;
            }
            if(value > 999) {
                central -= 3;
            }
            painter.drawText(QPoint(width()/graph->getVertex(c)->position.x+central,
                                    height()/graph->getVertex(c)->position.y+5),
                             QString::number(value));
        }
    }
}

bool Screen::distanceNearest(Point point) {
    for(ushort c = 0; c < graph->getAmountVertices(); c++) {
        if(distance(graph->getVertex(c)->position,point) <= 40) {
            return false;
        }
    }
    return true;
}

Screen::Screen(QWidget *parent) : QWidget(parent) {
    mode = MODE::NO;
    graph = new Graph;
    activeVertex = nullptr;
    mTimer = new QTimer(this);
    connect(mTimer,&QTimer::timeout, this, &Screen::timer);
}


void Screen::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setBrush(QColor(230,50,10,128));
    drawEdge(painter);
    drawVertex(painter);
    drawText(painter);
}

ushort Screen::distance(Point pointOne, Point pointTwo) {
    return sqrt(pow( width()/pointOne.x - width()/pointTwo.x, 2) + pow( height()/pointOne.y - height()/pointTwo.y,2));
}
Vertex* Screen::getVertex(QMouseEvent* event) {
    return freePlace (Point((double)width()/event->pos().x(),(double)height()/event->pos().y()));
}

void Screen::load() {
    graph->load();
    update();
}

void Screen::save() {
    graph->save();
}

void Screen::mousePressEvent(QMouseEvent *event) {
    if(event->buttons() == Qt::LeftButton) {
        switch(mode) {
            case MODE::START:
                graph->setStartVertex(getVertex(event));
                mode = MODE::NO;
                break;
            case MODE::FINISH:
                graph->setFinishVertex(getVertex(event));
                mode = MODE::NO;
                break;
            default:
                if(getVertex(event)   == nullptr ) {
                    if( distanceNearest( Point((double)width()/event->pos().x(),(double)height()/event->pos().y()) ) ) {
                            graph->addVertex( Point(
                                                    (double)width()/event->pos().x(),
                                                    (double)height()/event->pos().y()
                                                   )
                                            );
                    }
                } else {
                    if(activeVertex == nullptr) {
                        activeVertex = getVertex(event);
                    } else {
                       graph->addEdge( activeVertex,getVertex(event));
                       activeVertex = nullptr;
                    }
                }
        }
    }

    if(event->buttons() == Qt::RightButton) {
        if(activeVertex == nullptr) {
            if(getVertex(event) != nullptr) {
                graph->delVertex(getVertex(event));
            }
        } else {
            if( getVertex(event) != nullptr) {
                graph->delEdge(activeVertex, getVertex(event));
            }
            activeVertex = nullptr;
        }
    }

    if(event->buttons() == Qt::MiddleButton) {
        graph->oneStep(width(),height());
    }
    update();
}
