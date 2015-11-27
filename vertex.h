#pragma once
typedef unsigned short ushort;
#include "point.h"
#include <vector>
#include <QDebug>
const ushort USHORT_MAX = 65535;
struct Vertex {
    Vertex(Point position) :
        position(position) {
        lengthMinWay = USHORT_MAX;
    }
    bool visited = false;
    unsigned int lengthMinWay;
    Point position;
    std::vector<Vertex*> connections;
};
