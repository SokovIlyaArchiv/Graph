#pragma once
#include "search.h"
class BreadthFirstSearch : public Search {
public:
    BreadthFirstSearch(std::vector<Vertex*>&);
    Vertex* oneStep(Vertex*);
};
