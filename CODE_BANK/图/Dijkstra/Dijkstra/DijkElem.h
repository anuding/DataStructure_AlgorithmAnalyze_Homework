class DijkElem {
public:
	int vertex, distance;
	DijkElem() { vertex = -1; distance = -1; }
	DijkElem(int v, int d) { vertex = v; distance = d; }
};