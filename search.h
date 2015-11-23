#pragma once
#include "vertex.h"
#include <vector>

class Search {
public:
    Search(std::vector<Vertex*>&);
    virtual ~Search();
    virtual Vertex* oneStep(Vertex*, ushort, ushort) = 0;
protected:
    std::vector<Vertex*>& vertices;
    std::vector<Vertex*> queue;
    ushort width,height;
};
