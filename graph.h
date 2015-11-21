#pragma once
#include "vertex.h"
enum class TYPE { COMMON, START, FINISH };
class Graph {
public:
    void addVertex(Point);
    void addEdge(Vertex*, Vertex*);
    void delEdge(Vertex*, Vertex*);
    void delVertex(Vertex*);
    ushort getAmountVertices();
    Vertex* getVertex(ushort);
    TYPE getVertexType(Vertex*);
private:
    Vertex *startVertex, *finishVertex;
    std::vector<Vertex*> vertices;
};
