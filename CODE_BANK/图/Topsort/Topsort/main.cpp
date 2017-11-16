
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  11/16/2017 5:21:16 PM
*          CLR：  4.0.30319.42000
*
*/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "Graphl.h"
using namespace std;
int main()
{
	void topsort(Graph* G);
	void tophelp(Graph* G, int v);

	Graphl g1(6);
	cout << "节点数:" << g1.n() << endl;
	cout << "边数:" << g1.e() << endl << endl;
	//设置边
	//cout << "设置3条权为1的边...(1,2),(1,3),(2,3)" << endl << endl;
	g1.setEdge(0, 1, 10);
	g1.setEdge(0, 5, 2);
	g1.setEdge(0, 3, 20);
	g1.setEdge(1, 2, 3);
	g1.setEdge(1, 3, 5);
	g1.setEdge(2, 4, 15);
	g1.setEdge(3, 5, 10);
	g1.setEdge(3, 4, 11);
	g1.setEdge(5, 4, 3);
	cout << "节点数:" << g1.n() << endl;
	cout << "边数:" << g1.e() << endl << endl;

	cout << "开始拓扑排序..." << endl;
	topsort(&g1);
	
	getchar();
    return 0;
}


void tophelp(Graph* G, int v) { // Process vertex v
	G->setMark(v, VISITED);
	for (int w = G->first(v); w<G->n(); w = G->next(v, w))
		if (G->getMark(w) == UNVISITED)
			tophelp(G, w);
	cout << v+1 << " "; // PostVisit for Vertex v
}
void topsort(Graph* G) { // Topological sort: recursive
	int i;
	for (i = 0; i<G->n(); i++) // Initialize Mark array
		G->setMark(i, UNVISITED);
	for (i = 0; i<G->n(); i++) // Process all vertices
		if (G->getMark(i) == UNVISITED)
			tophelp(G, i); // Call recursive helper function
}
