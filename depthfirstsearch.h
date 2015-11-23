#pragma once
#include "search.h"
class DepthFirstSearch : public Search{
public:
    DepthFirstSearch(std::vector<Vertex*>&);
    Vertex* oneStep(Vertex*, ushort, ushort);
};
