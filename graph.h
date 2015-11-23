#pragma once
#include "vertex.h"
#include "search.h"
#include "depthfirstsearch.h"
#include "breadthfirstsearch.h"
#include "dijkstrassearchalgorithm.h"
#include <QTimer>
enum class TYPE { COMMON, START, FINISH, CURRENT };
class Graph {
public:
    Graph();
    void oneStep(ushort, ushort);
    void restart();
    void clearAll();
    void setDSAMode();
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
    void init();
    Vertex *startVertex, *finishVertex, *currentVertex;
    std::vector<Vertex*> vertices;
    Search *search;
    DepthFirstSearch *depthSearch;
    BreadthFirstSearch *breadthSearch;
    DijkstrasSearchAlgorithm *dijkstrasSearch;
};
