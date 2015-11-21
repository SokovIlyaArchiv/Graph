#pragma once
#include "point.h"
#include <vector>
const ushort USHORT_MAX = 65535;
struct Vertex {
    Vertex(Point position) :
        position(position) {
        lengthMinWay = USHORT_MAX;
    }
    bool visited;
    ushort lengthMinWay;
    Point position;
    std::vector<Vertex*> connections;
};
