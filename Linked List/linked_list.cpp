#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int value;
	node *next;
};

void insertEnd(int value, node *&root){
	node *current = root;
	node *new_node = new node;
	new_node->value = value;
	new_node->next = NULL;
	if(current == NULL)
		root = new_node;
	else{
		while(current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void insertBegin(int value, node* &root){
	node *new_node = new node;
	new_node->value = value;
	new_node->next = root;
	root = new_node;
}

void removeFirst(node *&root){
	node* current = root;
	if(current != NULL){
		root = current->next;
		free(current);
	}
}

void removeValue(int value, node *&root){
	node *current = root;
	while(current->value == value){
		removeFirst(root);
		current = root;
	}
	node *previous = current;
	current = current->next;
	while(current != NULL){
		if(current->value == value){
			previous->next = current->next;
			free(current);
			current = previous->next;
		}
		else{
			previous = current;
			current = current->next;
		}
	}
}

void printList(node *root){
	node* current = root;
	while(current != NULL){
		cout << current->value << "\n";
		current = current->next;
	}
}

void invertList(node *&root){
	node *current = root;
	node *previous, *next;
	if(current != NULL){
		previous = current;
		next = current->next;
		current->next = NULL;
		current = next;
		while(current != NULL){
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		root = previous;
	}
}

int main(){
	node *first = new node;
	first->value = 24;
	first->next = NULL;
	insertBegin(10, first);
	insertBegin(1,first);
	insertBegin(1,first);
	insertEnd(24,first);
	insertEnd(24,first);
	insertEnd(2,first);
	insertEnd(1,first);
	insertEnd(3,first);
	insertEnd(4,first);

	cout << "first print: " << "\n";
	printList(first);

	invertList(first);
	
	cout << "Inverted List: " << "\n";
	printList(first);

	removeValue(1,first);
	removeValue(24,first);
	
	cout << "second print: " << "\n";
	printList(first);

	invertList(first);
	
	cout << "Inverted List: " << "\n";
	printList(first);
	
	removeFirst(first);
	removeFirst(first);
	removeFirst(first);
	removeFirst(first);
	
	cout << "third print: " << "\n";
	printList(first);
	
	invertList(first);
	
	cout << "Inverted List: " << "\n";
	printList(first);
	
	insertEnd(24,first);
	insertBegin(23,first);
	
	cout << "fourth print: " << "\n";
	printList(first);
	
	invertList(first);
	
	cout << "Inverted List: " << "\n";
	printList(first);
}
