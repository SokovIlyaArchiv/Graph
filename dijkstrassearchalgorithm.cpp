#include "dijkstrassearchalgorithm.h"
#include <math.h>

DijkstrasSearchAlgorithm::DijkstrasSearchAlgorithm(std::vector<Vertex *> &vertices) :
    Search(vertices) {

}

ushort DijkstrasSearchAlgorithm::distance(Point pointOne, Point pointTwo, ushort width, ushort height) {
    return sqrt(pow( width/pointOne.x - width/pointTwo.x, 2) + pow( height/pointOne.y - height/pointTwo.y,2));
}

Vertex* DijkstrasSearchAlgorithm::oneStep(Vertex* current, ushort width, ushort height) {
    if(queue.size() == 0) {
        queue.push_back(current);
    }
    for(auto& vertex:current->connections) {
        if(vertex->lengthMinWay >= current->lengthMinWay + distance(current->position, vertex->position, width, height)) {
            queue.push_back(vertex);
            vertex->lengthMinWay = current->lengthMinWay +
                                   distance(current->position, vertex->position, width, height);
        }
    }
    for(ushort c = 0; c < queue.size(); c++) {
        if(queue[c] == current) {
            queue.erase(queue.begin()+c);
            break;
        }
    }
    ushort min = USHORT_MAX;
    Vertex* ptrMin = nullptr;
    for(ushort c = 0; c < queue.size(); c++) {
        if(queue[c]->lengthMinWay <= min) {
            min = queue[c]->lengthMinWay;
            ptrMin = queue[c];
        }
    }
    if(ptrMin == nullptr) {
        ptrMin = current;
    }
    ptrMin->visited = true;
    return ptrMin;
}
