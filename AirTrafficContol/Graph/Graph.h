#include<iostream>
#include<vector>

#include <CustomWidgets/draggablelabel.h>


using namespace std;

struct VertexNODE
{
	char name;
	bool visited = false;
	void *header = NULL;
	int count = 0;
	int distance = WINT_MAX;
	char previous = 0;
	VertexNODE* nextVertex = NULL;

    DraggableLabel *visualNode;
};
struct EdgeNODE
{
	char Source;
	VertexNODE* address = NULL;
	int weight = 1;
	bool picked = false;
	EdgeNODE* nextEdge;
};

class Graph
{
public:
    Graph();


    void InsertVertex(char name, DraggableLabel* visualNode);

    VertexNODE* getRoot();


    VertexNODE * searchVertex(char name);


    void InsertEdge(char VertexName, char EdgeName, int weight = 1);

    void InsertEdgeDirected(char VertexName, char EdgeName, int weight = 1);

    void InsertEdge(char VertexName, EdgeNODE* myEdge);


    void Delete(char VertexName, char Edge);


    EdgeNODE* Isconnected(char Vertex1, char Vertex2);
    string Path(char Source, char Destination, VertexNODE* delimiter = NULL);
    string Cycle(char Vertex);

	

    int Degree(char name);

		


	//------------------------------- S H O R T E S T    P A T H    A L G O R I T H M S -------------------------------
	
    Graph* KrushkalsMST();


    Graph* PrimsMST();



    string DjikstraShortestPath(char Source, char Destination);

	//------------------------------- U T I L I T Y    F U N C T I O N S -------------------------------

    EdgeNODE* LeastWeightEdge();

    void SortEdgesByWeight(char Vertex);

    void SortAllByWeight();


    bool AllVisited();



    void ResetVisited();


    void ResetPickedEdge();

    void ResetDistances();



    void PrintGraph();




	

private:
	VertexNODE * root;
	bool HelperVariableForInsertEdge = 0;
	int NumOFEdges = 0;
	

};

