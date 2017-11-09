#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include "Graphl.h"
using namespace std;

int main()
{
	void Dijkstra(Graphl* G, int *D, int s);
	int minVertex(Graphl* G, int *D);
	Graphl g1(5);
	g1.setEdge(0, 1, 10);
	g1.setEdge(0, 2, 3);
	g1.setEdge(0, 3, 20);
	g1.setEdge(2, 1, 2);
	g1.setEdge(1, 3, 5);
	g1.setEdge(2, 4, 15);
	g1.setEdge(3, 4, 11);
	int *D,s;
	Dijkstra(&g1, D, s);
	for (int i = 0; i < g1.n(); i++)
		cout << D[i] << " ";
	getchar();
}

int minVertex(Graphl* G, int *D)//�ҵ���С�ڵ�
{
	int i, v = -1;//��ʼ��vΪδ���ʽڵ�
	for (i = 0; i<G->n(); i++)
		if (G->getMark(i) == UNVISITED) { v = i; break; }
	for (i++; i < G->n(); i++)//�ҵ���СDֵ
		if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
			v = i;
	return v;
}

void Dijkstra(Graphl* G, int *D, int s)
{
	int i, v, w;
	for (int i = 0; i < G->n(); i++)//��ʼ��
		D[i] = INFINITY;
	D[0] = 0;
	for (i = 0; i < G->n(); i++)//����ڵ�
	{
		v = minVertex(G, D);//Ѱ��δ���ʽڵ����СDֵ
		if (D[v] == INFINITY)	return;//�첻���Ľڵ�
		G->setMark(v,VISITED);
		for (w = G->first(v); w > G->n(); w = G->next(v, w))//w��v�ĵ�һ���ھӣ�w����v�ĵڶ����ھ�
			if (D[w] > (D[v] + G->weight(v, w)))
				D[w]= (D[v] + G->weight(v, w));
	}
}

