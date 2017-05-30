#include<bits/stdc++.h>
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

	void addEdge(int v1, int v2, int weight){
		adj[v1].push_back(make_pair(v2, weight));
		adj[v2].push_back(make_pair(v1, weight));
	}

	void prim(){
		// Heap com chave menor no topo. Representa os pares 
		// (key[v], v), onde v são s vértices e key[v] é o menor
		// peso de aresta para chegar naquele vértice. O vértice
		// de origem é armazenado em parent.
		priority_queue<iPair,vector<iPair>,greater<iPair> > pqueue;
		int src = 0;

		vector<int> key(vertices, INF);

		vector<int> parent(vertices, -1);

		vector<bool> inMST(vertices, false);

		pqueue.push(make_pair(0, src));
		key[src] = 0;

		while(!pqueue.empty()){
			//Pegar o primeiro vértice do heap
			int u = pqueue.top().second;
			pqueue.pop();

			inMST[u] = true;
			list<iPair>::iterator i;
			for(i = adj[u].begin(); i != adj[u].end(); ++i){
				int v = i->first;
				int weight = i->second;

				// Vai atualizar os valores de v se, e somente
				// se, ele não estiver na árvore e se o peso
				// dessa aresta for menor que o valor guardado
				// em key[v]
				if(inMST[v] == false && key[v] > weight){
					key[v] = weight;
					pqueue.push(make_pair(key[v], v));
					parent[v] = u;
				}
			}
		}

		for(int i = 1; i < vertices; ++i){
			if(parent[i] < i)
				cout << parent[i]+1 << " " << i+1 << endl;
			else
				cout << i+1 << " " << parent[i]+1 << endl;
		}
	}

};

int main(){
	int vertices, edges, v1, v2, weight;
	cin >> vertices >> edges;

	int teste = 0;
	while(vertices){
		Graph g(vertices);

		for(int i = 0; i < edges; i++){
			cin >> v1 >> v2 >> weight;
			g.addEdge(v1-1, v2-1, weight);
		}

		cout << "Teste " << ++teste << endl;
		g.prim();
		cout << endl;

		cin >> vertices >> edges;
	}
	return 0;
}
