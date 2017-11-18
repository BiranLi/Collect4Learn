#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <cstdio>
#include <vector>
#include <functional>

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 100
#define INFINITY 65535 // reference for none

typedef std::function<void (const char*)> CallBackFunc;

typedef struct EdgeNode{
    int adjvex;
    EdgeType weight;  // for directed graph
    EdgeNode* next;
} * pEdgeNode;

typedef struct VertexNode{
    VertexType data;
    pEdgeNode first_edge;
} pVertexNode, AdjList[MAXVEX];

typedef std::pair<pVertexNode, pVertexNode> BiEdgeNode;

class MGraph
{
public:
	MGraph();
    MGraph(int numVertex, int numEdge);
    ~MGraph();

private:
    int Create(const std::vector<BiEdgeNode>&);
    int Destroy();
    int Locate(pVertexNode);
	int GetVex(pVertexNode);
	int PushVex(pVertexNode, VertexType);
	int InsertVex(pVertexNode);
	int DeleteVex(pVertexNode);
	int InsertArc(pVertexNode, pVertexNode);
	int DeleteArc(pVertexNode, pVertexNode);
	int DFS(CallBackFunc, const char*);
	int BFS(CallBackFunc, const char*);

private:
    //VertexType _vex[MAXVEX];				// vertex
    //EdgeType _arc[MAXVEX][MAXVEX];		//adjacency matrix

    AdjList _adjlist;
	int _length;							// len of _adjlist

    int _numVertex;
    int _numEdge;
} ;

#endif // _GRAPH_H_
