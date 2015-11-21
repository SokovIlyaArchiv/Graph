#pragma once
#include "vertex.h"
#include <vector>

class Search {
public:
    Search(std::vector<Vertex*>&);
    virtual ~Search();
    virtual void oneStep() = 0;
    void setStartVertex(Vertex*);
    void setFinishVertex(Vertex*);
    Vertex *getCurrentVertex();
protected:
    Vertex *startVertex, *finishVertex, *currentVertex;
    std::vector<Vertex*>& vertices;
};
