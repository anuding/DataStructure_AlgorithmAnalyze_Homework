
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  11/14/2017 6:57:07 PM
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
#define UNVISITED 0
#define VISITED 1
using namespace std;


Graphl MST(5);
int main()
{

	int minVertex(Graphl* G, int *D);
	void Prim(Graph* G, int* D, int s);


	Graphl g1(5);
	g1.setEdge(0, 1, 10);
	g1.setEdge(0, 2, 3);
	g1.setEdge(0, 3, 20);
	g1.setEdge(2, 1, 2);
	g1.setEdge(1, 3, 5);
	g1.setEdge(2, 4, 15);
	g1.setEdge(3, 4, 11);
	int *D, s = 0;
	D = new int[g1.n()];
	Prim(&g1, D, s);
	for (int i = 0; i < g1.n(); i++)
		cout << D[i] << " ";
	getchar();
    return 0;
}

void AddEdgetoMST(int V, int v)
{
	MST.setEdge(0, v, 1);
}


int minVertex(Graphl* G, int *D)//找到最小节点
{
	int i, v = -1;//初始化v为未访问节点
	for (i = 0; i<G->n(); i++)
		if (G->getMark(i) == UNVISITED) { v = i; break; }
	for (i++; i < G->n(); i++)//找到最小D值
		if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
			v = i;
	return v;
}

void Prim(Graphl* G, int* D, int s)
{
	int V[5];
	int i, w;
	for (i = 0; i < G->n(); i++)
	{
		int v = minVertex(G, D);	
		G->setMark(v, VISITED);
		if (v != s)
			AddEdgetoMST(V[v], v);
		if (D[v] == INFINITY)	return;
		for (w = G->first(v); w < G->n();w=G->next(v,w))
			if (D[w] > G->weight(v, w))
			{
				D[w] = G->weight(v, w);
				V[w] = v;
			}
	}
}