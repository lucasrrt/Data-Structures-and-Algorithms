#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> iPair;

class Graph{
	public:
	int vertices;
	list <iPair> *adj;
	Graph(int vertices):vertices(vertices){
		adj = new list<iPair>[vertices];
	}

	void addEdge(int v, int u, int weight){
		adj[u].push_back(make_pair(v, weight));
		adj[v].push_back(make_pair(u, weight));
	}

	void kruskal(){
		//The world is beautiful
	}

};

int main(void){
	int vertices, edges, u, v, weight;
	cin >> vertices >> edges;

	Graph g(vertices);

	for(int i = 0; i < edges; i++){
		cin >> u >> v >> weight;
		g.addEdge(u-1, v-1, weight);
	}

	g.kruskal();

	return 0;
}
