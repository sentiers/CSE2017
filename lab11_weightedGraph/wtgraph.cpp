// CSE2017-01 Data Structure
// Lab 11 - Weighted Graph
// 
// Name: Hyunji Cho
// StudentID: 2019113581
// Email: sentiers@naver.com
// Date: 2021 May 26
//
// wtgraph.cpp
// :Implementation of the Weighted Graph ADT


#include "wtgraph.h"
#include <iostream>
#include <string>

//--------------------------------------------------------------------

WtGraph::WtGraph(int maxNumber) :maxSize(maxNumber), size(0) {
	vertexList = new Vertex[maxSize];
	adjMatrix = new int[maxSize * maxSize];
	pathMatrix = new int[maxSize * maxSize];
}

WtGraph::~WtGraph() {
	delete[] vertexList;
	delete[] adjMatrix;
	delete[] pathMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (strcmp(vertexList[i].label, v) == 0) {
			index = i;
			break;
		}
	}
	return index;
}

int WtGraph::getEdge(int row, int col) {
	return adjMatrix[maxSize * row + col];
}

void WtGraph::setEdge(int row, int col, int wt) {
	adjMatrix[maxSize * row + col] = wt;
}

//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex) {
	if (isFull()) {
		cout << "Graph is Full" << endl;
	}
	else {
		int index = getIndex(newVertex.label);
		if (index == -1) { // if newVertex is new
			vertexList[size] = newVertex;
			size++;
			for (int i = 0; i < size; i++) {
				setEdge(size - 1, i, infiniteEdgeWt);
				setEdge(i, size - 1, infiniteEdgeWt);
			}
		}
		else { // if newVertex is already exist in the graph
			vertexList[index] = newVertex;
		}
	}
}

void WtGraph::insertEdge(char* v1, char* v2, int wt) {
	int index1 = getIndex(v1);
	int index2 = getIndex(v2);

	if (index1 == -1) {
		cout << "Vertex " << v1 << " is NOT in the graph" << endl;
	}
	else if (index2 == -1) {
		cout << "Vertex " << v2 << " is NOT in the graph" << endl;
	}
	else {
		setEdge(index1, index2, wt);
		setEdge(index2, index1, wt);
	}
}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData) {
	bool result = false;
	for (int i = 0; i < size; i++) {
		if (strcmp(vertexList[i].label, v) == 0) {
			vData = vertexList[i];
			result = true;
		}
	}
	return result;
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt) {
	bool result = false;
	int index1 = getIndex(v1);
	int index2 = getIndex(v2);
	wt = getEdge(index1, index2);

	if (index1 == -1) {
		cout << "Vertex " << v1 << " is NOT in the graph" << endl;
	}
	else if (index2 == -1) {
		cout << "Vertex " << v2 << " is NOT in the graph" << endl;
	}
	else if (wt != infiniteEdgeWt) {
		result = true;
	}
	return result;
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v) {
	int index = getIndex(v);

	if (index == -1) {
		cout << "Vertex " << v << " is NOT in the graph" << endl;
	}
	else {
		if (index != size - 1) { // if v is not the last vertex in the list

			for (int i = index; i < size - 1; i++) {
				vertexList[i] = vertexList[i + 1];
			}

			for (int i = index; i < size - 1; i++) { // row
				for (int j = 0; j < size; j++) {
					setEdge(i, j, getEdge(i + 1, j));
				}
			}

			for (int i = index; i < size - 1; i++) { // col
				for (int j = 0; j < size; j++) {
					setEdge(j, i, getEdge(j, i + 1));
				}
			}
		}
		size--;
	}
}

void WtGraph::removeEdge(char* v1, char* v2) {
	int index1 = getIndex(v1);
	int index2 = getIndex(v2);

	if (index1 == -1) {
		cout << "Vertex " << v1 << " is NOT in the graph" << endl;
	}
	else if (index2 == -1) {
		cout << "Vertex " << v2 << " is NOT in the graph" << endl;
	}
	else {
		setEdge(index1, index2, infiniteEdgeWt);
		setEdge(index2, index1, infiniteEdgeWt);
	}
}

//--------------------------------------------------------------------

void WtGraph::clear() {
	size = 0;
}

bool WtGraph::isEmpty() const {
	return (size == 0);
}

bool WtGraph::isFull() const {
	return (size == maxSize);
}

//--------------------------------------------------------------------

void WtGraph::showStructure() {
	// Outputs a graph's vertex list, adjacency matrix, and path matrix.
	// This operation is intended for testing/debugging purposes only.
	int wt,         // Edge weight
		row, col;   // Loop counters

	if (size == 0)
		cout << "Empty graph" << endl;
	else {
		cout << endl << "Vertex list : " << endl;
		for (row = 0; row < size; row++)
			cout << row << '\t' << vertexList[row].label << endl;

		cout << endl << "Edge matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++) {
			cout << row << '\t';
			for (col = 0; col < size; col++) {
				wt = getEdge(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}

		cout << endl << "Path matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++) {
			cout << row << '\t';
			for (col = 0; col < size; col++) {
				wt = getPath(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}
	}
}

//--------------------------------------------------------------------

int WtGraph::getPath(int row, int col) {
	return pathMatrix[maxSize * row + col];
}

void WtGraph::setPath(int row, int col, int wt) {
	pathMatrix[maxSize * row + col] = wt;
}

void WtGraph::computePaths() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			(i == j) ? setPath(i, j, 0) : setPath(i, j, getEdge(i, j));
		}
	}

	for (int m = 0; m < size; m++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				int p1 = getPath(j, m);
				int p2 = getPath(m, k);
				int p3 = getPath(j, k);

				if ((p1 > 0 && p1 < infiniteEdgeWt) && (p2 > 0 && p2 < infiniteEdgeWt)) {
					if ((p1 + p2) < p3) {
						setPath(j, k, p1 + p2);
					}
				}
			}
		}
	}
}