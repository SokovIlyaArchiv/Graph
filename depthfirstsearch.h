#pragma once
#include "search.h"
class DepthFirstSearch : public Search{
public:
    DepthFirstSearch(std::vector<Vertex*>&);
    void oneStep();
};
