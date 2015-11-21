#include "graph.h"

void Graph::addVertex(Point position) {
    vertices.push_back( new Vertex(position) );
}

void Graph::addEdge(Vertex *vertexOne, Vertex *vertexTwo) {
    vertexOne->connections.push_back(vertexTwo);
}

void Graph::delEdge(Vertex *vertexOne, Vertex *vertexTwo) {
    for(ushort c = 0; c < vertexOne->connections.size(); c++) {
        if(vertexOne->connections[c] == vertexTwo) {
            vertexOne->connections.erase(vertexOne->connections.begin()+c);
        }
    }
}

void Graph::delVertex(Vertex *vertex) {
   for(ushort c = 0; c < vertices.size(); c++) {
       if(vertices[c] == vertex) {
           vertices.erase(vertices.begin()+c);
       }
   }
   for(auto& mVertex:vertices) {
       for(ushort c = 0; c < mVertex->connections.size(); c++) {
           if(mVertex->connections[c] == vertex) {
               mVertex->connections.erase(mVertex->connections.begin()+c);
           }
       }
   }
   delete vertex;
}

ushort Graph::getAmountVertices() {
    return vertices.size();
}

Vertex *Graph::getVertex(ushort number) {
    if(vertices.size() > number) {
        return vertices[number];
    } else {
        return nullptr;
    }
}

TYPE Graph::getVertexType(Vertex *vertex) {
    if(vertex == startVertex) {
        return TYPE::START;
    }
    if(vertex == finishVertex){
        return TYPE::FINISH;
    }
    return TYPE::COMMON;
}

