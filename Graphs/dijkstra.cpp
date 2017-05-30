#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

class Graph{
	public:
		int vertices;
		list <iPair> *adj;
		Graph(int vertices):vertices(vertices){
			adj = new list<iPair>[vertices];
		}
		void addEdge(int u, int v, int weight){
			adj[u].push_back(make_pair(v, weight));
			adj[v].push_back(make_pair(u, weight));
		}
		void dijkstra(int src, int dest){
			// (distance, vertex)
			priority_queue<iPair, vector<iPair>, greater<iPair> > pqueue;
			vector<int> distance(vertices, INF);
			vector<int> parent(vertices, -1);

			distance[src] = 0;
			pqueue.push(make_pair(distance[src], src));

			int u;
			while(!pqueue.empty()){
				u = pqueue.top().second;
				pqueue.pop();

				if(u == dest){
					cout << "Caminho encontrado!" << endl;
					break;
				}

				list<iPair>::iterator i;
				for(i = adj[u].begin(); i != adj[u].end(); i++){
					int v = i->first;
					int weight = i->second;
					
					int new_dist = distance[u] + weight;
					if(new_dist < distance[v]){
						distance[v] = new_dist;
						parent[v] = u;
						pqueue.push(make_pair(distance[v], v));
					}
				}
			}

			if(u != dest)
				cout << "Caminho não encontrado!" << endl;
			else{
				cout << "Distancia: " << distance[dest] << endl;
				cout << "Caminho: " << endl;
				stack<int> path;
				int i = dest;
				while(i!=src){
					path.push(i);
					i = parent[i];
				}
				cout << src+1;
				while(!path.empty()){
					cout << " -> " << path.top()+1;
					path.pop();
				}
				cout << endl;
			}
		}
};

int main(void)
{
	int V, E, v1, v2, weight, src, dest;
	cin >> V >> E;
	Graph g(V);
	for(int i = 0; i < E; i++){
		cin >> v1 >> v2 >> weight;
		g.addEdge(v1-1,v2-1,weight);
	}
	cin >> src >> dest;
	g.dijkstra(src-1, dest-1);
	return 0;
}
