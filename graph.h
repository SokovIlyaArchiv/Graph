#pragma once
#include "vertex.h"
#include "search.h"
#include "depthfirstsearch.h"
#include "breadthfirstsearch.h"
enum class TYPE { COMMON, START, FINISH, CURRENT };
class Graph {
public:
    Graph();
    void init();
    void oneStep();
    void restart();
    void setDFSMode();
    void setBFSMode();
    void setStartVertex(Vertex*);
    void setFinishVertex(Vertex*);
    void addVertex(Point);
    void addEdge(Vertex*, Vertex*);
    void delEdge(Vertex*, Vertex*);
    void delVertex(Vertex*);
    ushort getAmountVertices();
    Vertex* getVertex(ushort);
    TYPE getVertexType(Vertex*);
private:
    Vertex *startVertex, *finishVertex, *currentVertex;
    std::vector<Vertex*> vertices;
    Search *search;
    DepthFirstSearch *depthSearch;
    BreadthFirstSearch *breadthSearch;
};
