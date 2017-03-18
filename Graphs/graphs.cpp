#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int value;
	bool marked = 0;
	vector<node*> adjacents;
};

vector<node*> pilha;
queue<node*> fila;

void createLink(node* A, node *B){
	A->adjacents.push_back(B);
	B->adjacents.push_back(A);
}

void printAdjacents(node *A){
	for(node* B : A->adjacents)
		cout << B->value << "\n";
}

void mark(node* A){
	A->marked = 1;
}

void dismark(node* A){
	A->marked = 0;
}

bool nodeInStack(node *A, vector<node*> stack){
	for(node *B : stack){
		if (B == A){
			return 1;
		}
	}
	return 0;
}

bool nodeInQueue(node *A, queue<node*> fila){
	queue<node*> temp = fila;
	while(!temp.empty()){
		node *B = temp.front();
		temp.pop();
		if (B->value == A->value){
			return 1;
		}
	}
	return 0;
}

void DFS(node *A){
	mark(A);
	pilha.push_back(A);
	cout << A->value << "\n";
	for(node* adj : A->adjacents){
		if(adj->marked == 0){
			DFS(adj);
		}
		else if(nodeInStack(adj, pilha) && !nodeInStack(adj, A->adjacents)){
		}
	}
	pilha.pop_back();
}

void BFS(node *A){
	mark(A);
	fila.push(A);
	while (!fila.empty()){
		node* current = fila.front();
		cout << current->value << endl;
		for (node* adj : current->adjacents){
			if(!adj->marked){
				mark(adj);
				fila.push(adj);
			}
		}
		fila.pop();
	}
}

int main(){

	node *A = new node;
	A->value = 1;
	
	node *B = new node;
	B->value = 2;
	node *C = new node;
	C->value = 3;
	node *D = new node;
	D->value = 4;
	node *E = new node;
	E->value = 5;
	node *F = new node;
	F->value = 6;
	node *G = new node;
	G->value = 7;
	
	createLink(A,B);
	createLink(A,D);
	createLink(B,C);
	createLink(B,D);
	createLink(B,E);
	createLink(C,E);
	createLink(C,F);
	createLink(D,E);
	createLink(D,G);
	createLink(E,F);
	createLink(E,G);
	createLink(F,G);

	printAdjacents(E);

	cout << "DFS" << "\n";

	DFS(A);

	cout << "Testing pertence in stack" << "\n";

	cout << "A: " << nodeInStack(A, pilha) << "\n";
	cout << "B: " << nodeInStack(B, pilha) << "\n";
	cout << "C: " << nodeInStack(C, pilha) << "\n";
	cout << "D: " << nodeInStack(D, pilha) << "\n";
	cout << "E: " << nodeInStack(E, pilha) << "\n";
	cout << "F: " << nodeInStack(F, pilha) << "\n";
	cout << "G: " << nodeInStack(G, pilha) << "\n";

	cout << "Testing marked" << "\n";

	cout << "A: " << A->marked << "\n"; dismark(A);
	cout << "B: " << B->marked << "\n"; dismark(B);
	cout << "C: " << C->marked << "\n"; dismark(C);
	cout << "D: " << D->marked << "\n"; dismark(D);
	cout << "E: " << E->marked << "\n"; dismark(E);
	cout << "F: " << F->marked << "\n"; dismark(F);
	cout << "G: " << G->marked << "\n"; dismark(G);
	
	cout << "BFS" << "\n";
	
	BFS(A);
	
	cout << "Testing pertence in queue" << "\n";

	cout << "A: " << nodeInQueue(A, fila) << "\n";
	cout << "B: " << nodeInQueue(B, fila) << "\n";
	cout << "C: " << nodeInQueue(C, fila) << "\n";
	cout << "D: " << nodeInQueue(D, fila) << "\n";
	cout << "E: " << nodeInQueue(E, fila) << "\n";
	cout << "F: " << nodeInQueue(F, fila) << "\n";
	cout << "G: " << nodeInQueue(G, fila) << "\n";

	return 0;
}
