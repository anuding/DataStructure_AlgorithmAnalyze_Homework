#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include "Graphl.h"
#include "DijkElem.h"
#include "minheap.h"
using namespace std;

int main()
{
	void DijkstrawithQ(Graph* G, int* D, int s);
	void Dijkstra(Graphl* G, int *D, int s);
	int minVertex(Graphl* G, int *D);
	Graphl g1(6);
	g1.setEdge(0, 1, 10);
	g1.setEdge(0, 5, 2);
	g1.setEdge(0, 3, 20);
	g1.setEdge(1, 2, 3);
	g1.setEdge(1, 3, 5);
	g1.setEdge(2, 4, 15);
	g1.setEdge(3, 5, 10);
	g1.setEdge(3, 4, 11);
	g1.setEdge(5, 4, 3);
	int *D,s=0;
	D = new int[g1.n()];

	Dijkstra(&g1, D, s);
	for (int i = 0; i < g1.n(); i++)
		cout << D[i] << " ";
	getchar();
	return 0;
}

int minVertex(Graphl* G, int* D) { // Find min cost vertex
	int i, v = -1;
	// Initialize v to some unvisited vertex
	for (i = 0; i<G->n(); i++)
		if (G->getMark(i) == UNVISITED) { v = i; break; }
	for (i=0; i<G->n(); i++) // Now find smallest D value
		if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
			v = i;
	return v;
}

void Dijkstra(Graphl* G, int* D, int s) {
	int i, v, w;
	for (int i = 0; i<G->n(); i++) // Initialize
		D[i] = INFINITY;
	D[0] = 0;
	for (i = 0; i<G->n(); i++)
	{ // Process the vertices
		v = minVertex(G, D);
		if (D[v] == INFINITY) return; // Unreachable vertices
		G->setMark(v, VISITED);
		for (w = G->first(v); w<G->n(); w = G->next(v, w))
			if (D[w] >(D[v] + G->weight(v, w)))
				D[w] = D[v] + G->weight(v, w);
	}
}


////WTF!!!!!!!!!!!!!
// Dijkstra¡¯s shortest paths algorithm with priority queue
//void DijkstrawithQ(Graph* G, int* D, int s) {
//	int i, v, w; // v is current vertex
//	DijkElem temp;
//	DijkElem E[G->e()]; // Heap array with lots of space
//	temp.distance = 0; temp.vertex = s;
//	E[0] = temp; // Initialize heap array
//	heap<DijkElem, DDComp> H(E, 1, G->e()); // Create heap
//	for (int i = 0; i<G->n(); i++) // Initialize
//		D[i] = INFINITY;
//	D[0] = 0;
//	for (i = 0; i<G->n(); i++) { // Now, get distances
//		do {
//			if (H.size() == 0) return; // Nothing to remove
//			temp = H.removefirst();
//			v = temp.vertex;
//		} while (G->getMark(v) == VISITED);
//		G->setMark(v, VISITED);
//		if (D[v] == INFINITY) return; // Unreachable vertices
//		for (w = G->first(v); w<G->n(); w = G->next(v, w))
//			if (D[w] >(D[v] + G->weight(v, w))) { // Update D
//				D[w] = D[v] + G->weight(v, w);
//				temp.distance = D[w]; temp.vertex = w;
//				H.insert(temp); // Insert new distance in heap
//			}
//	}
//}