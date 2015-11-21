#include "search.h"

Search::Search(std::vector<Vertex *> &vertices) :
    vertices(vertices) {
}

void Search::setStartVertex(Vertex *vertex) {
    startVertex = vertex;
}

void Search::setFinishVertex(Vertex *vertex) {
    finishVertex = vertex;
}

Vertex *Search::getCurrentVertex() {
    return currentVertex;
}
