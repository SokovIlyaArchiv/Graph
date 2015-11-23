#include "search.h"

class DijkstrasSearchAlgorithm : public Search {
public:
    ushort distance(Point, Point, ushort, ushort);
    DijkstrasSearchAlgorithm(std::vector<Vertex*>&);
    Vertex* oneStep(Vertex*, ushort, ushort);
};
