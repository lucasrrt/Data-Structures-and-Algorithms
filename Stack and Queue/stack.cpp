#include <iostream>

using namespace std;

class stack{
	public:
	int *values;
	int size;
	int position;
	
	stack(){
		size = 1;
		values = new int(size);
		position = -1;
	}

	int getSize(){
		return size;
	}

	void push(int value){
		position++; 
		if(position == size){
			size*=2;
			values = (int*) realloc(values, sizeof(int)*size);
		}
		values[position] = value;
		cout << value << " inserido com sucesso!\n";
	}
	
	int pop(){
		if(position > -1){
			if(position <= size/4){
				size/=2;
				values = (int*) realloc(values, sizeof(int)*size);
			}
			position--;
			return values[position+1];
		}
		else{
			cout << "Empty stack!" << endl;
			return -1;
		}
	}

	bool isEmpty(){
		if(position == -1)
			return 1;
		return 0;
	}

	int peek(){
		return values[position];
	}

	void info(){
		cout << "Tamanho: " << getSize() << endl;
		cout << "Topo: " << peek() << endl;
	}

};

int main(){
	stack first;
	cout << first.getSize() << endl;
	cout << (first.isEmpty()?"Pilha vazia":"Pilha não vazia") << endl;
	first.pop();
	first.push(1);
	first.info();

	first.push(2);
	cout << "Topo: " << first.peek() << endl;
	
	first.push(3);
	first.info();
	
	first.push(4);
	first.info();

	first.push(5);
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();
	
	first.pop();
	first.info();

	cout << (first.isEmpty()?"Pilha vazia":"Pilha não vazia") << endl;
	cout << first.pop() << endl;
	cout << "Topo: " << first.peek() << endl;

	return 0;
}
