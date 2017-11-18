#include "graph.h"

using namespace std;

MGraph::MGraph() : _numEdge(0), _numVertex(1){
	Create({});
}

MGraph::MGraph(int numVertex, int numEdge){
    this->_numVertex = numVertex;
    this->_numEdge = numEdge;
	Create({});
}

MGraph::~MGraph(){

}

int MGraph::Create(const std::vector<BiEdgeNode>& connect){

}
