// CSE2017-01 Data Structure
// Lab 11 - Weighted Graph
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 26
//
// wtgraph.h
// :Class declaration for the adjacency matrix implementation of the Weighted Graph ADT


#include <climits>    // For INT_MAX

using namespace std;

const int defMaxGraphSize = 10,      // Default number of vertices
vertexLabelLength = 11,    // Length of a vertex label
infiniteEdgeWt = INT_MAX;  // "Weight" of a missing edge

//--------------------------------------------------------------------

class Vertex
{
public:

	char label[vertexLabelLength];   // Vertex label
};

//--------------------------------------------------------------------

class WtGraph
{
public:

	// Constructor
	WtGraph(int maxNumber = defMaxGraphSize);

	// Destructor
	~WtGraph();

	// Graph manipulation operations
	void insertVertex(Vertex newVertex);                // Insert vertex
	void insertEdge(char* v1, char* v2, int wt);        // Insert edge
	bool retrieveVertex(char* v, Vertex& vData);     // Get vertex
	bool getEdgeWeight(char* v1, char* v2, int& wt);    // Get edge wt.
	void removeVertex(char* v);                         // Remove vertex
	void removeEdge(char* v1, char* v2);                // Remove edge
	void clear();                                      // Clear graph

	// Graph status operations
	bool isEmpty() const;                            // Graph is empty
	bool isFull() const;                             // Graph is full

	// Output the graph structure -- used in testing/debugging
	void showStructure();

	// In-lab operation
	void computePaths();

private:

	// Facilitator functions
	int getIndex(char* v);                  // Converts vertex label to an
											   //   adjacency matrix index

	int getEdge(int row, int col);          // Get edge weight using
											   //   adjacency matrix indices

	void setEdge(int row, int col, int wt);  // Set edge weight using
											   //   adjacency matrix indices

	// In-lab functions
	int getPath(int row, int col);               // Get path weight using
												  //   path matrix indices

	void setPath(int row, int col, int wt);    // Set path weight using
												 //   path matrix indices

	// Data members
	int maxSize,          // Maximum number of vertices in the graph
		size;             // Actual number of vertices in the graph
	Vertex* vertexList;   // Vertex list
	int* adjMatrix;       // Adjacency matrix
	int* pathMatrix;      // (In-lab) Path matrix

};
