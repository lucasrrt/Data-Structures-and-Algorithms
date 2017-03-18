#include <iostream>

using namespace std;

struct node{
	int value;
	node *left, *right;
};

void insert(node* root, node* new_node){
	if(new_node->value > root->value){
		if(root->right == NULL){
			root->right = new_node;
			cout << "Valor " << new_node->value << " inserido com sucesso\n";
		}
		else
			insert(root->right, new_node);
	}
	else if(new_node->value < root->value){
		if(root->left == NULL){
			root->left = new_node;
			cout << "Valor " << new_node->value << " inserido com sucesso\n";
		}
		else
			insert(root->left, new_node);
	}
	else
		cout << "Essa árvore já possui esse valor!\n";
}

void insert(node* root, int value){
	node *new_node = new node;
	new_node->value = value;
	insert(root, new_node);
}

void children(node* root){
	cout << "Left: ";
	if(root->left)
		cout  << root->left->value << "\n";
	else
		cout << "NULL\n";
	
	cout << "Right: ";
	if(root->right)
		cout  << root->right->value << "\n";
	else
		cout << "NULL\n";
}

void preOrder(node* root){
	cout << root->value << " ";
	if(root->left)
		preOrder(root->left);
	if(root->right)
		preOrder(root->right);
}

void inOrder(node* root){
	if(root->left)
		inOrder(root->left);
	cout << root->value << " ";
	if(root->right)
		inOrder(root->right);
}

void postOrder(node* root){
	if(root->left)
		postOrder(root->left);
	if(root->right)
		postOrder(root->right);
	cout << root->value << " ";
}

bool search(node* root, int value){
	if(root->value == value){
		cout << "Valor " << value << " Encontrado!" << endl;
		return 1;
	}
	else if(value < root->value){
		if(root->left)
			return search(root->left, value);
		else{
			cout << "Valor " << value << " não encontrado!" << endl;
			return 0;
		}
	}
	else if(value > root->value){
		if(root->right)
			return search(root->right, value);
		else{
			cout << "Valor " << value << " não encontrado!" << endl;
			return 0;
		}
	}
}

int main(){
	node* A = new node;
	A->value = 20;

	insert(A, 10);
	insert(A, 15);
	insert(A, 5);
	insert(A, 5);
	insert(A, 2);
	insert(A, 1);
	insert(A, 3);
	insert(A, 30);
	insert(A, 40);
	insert(A, 35);

	children(A);

	cout << "Pre-Order:  ";
	preOrder(A);
	cout << endl;

	cout << "In-Order:   ";
	inOrder(A);
	cout << endl;
	
	cout << "Post-Order: ";
	postOrder(A);
	cout << endl;

	search(A, 7);
	search(A, 35);

	return 0;
}
