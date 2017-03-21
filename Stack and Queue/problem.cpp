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
	}
	
	int pop(){
		if(position > -1){
			if(position <= size/4 && position > 0){
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

class queue{
	public:
	stack pilha1;
	stack pilha2;

	bool isEmpty(){
		return pilha1.isEmpty()?1:0;
	}

	void push(int value){
		pilha1.push(value);
	}

	int pop(){
		if(!isEmpty()){
			while(!pilha1.isEmpty()){
				pilha2.push(pilha1.pop());
			}
			cout << pilha2.peek() << endl << endl;
			int ret = pilha2.pop();
			while(!pilha2.isEmpty())
				pilha1.push(pilha2.pop());
			return ret;
		}
		else{
			return -1;
		}
	}
};

int main(){
	queue fila;
	cout << (fila.isEmpty()?"Empty Stack":"Not Empty Stack") << endl;
	
	cout << "pop ";
	cout << fila.pop() << endl;
	cout << (fila.isEmpty()?"Empty Stack":"Not Empty Stack") << endl;

	cout << "push 10\n";
	fila.push(10);
	cout << (fila.isEmpty()?"Empty Stack":"Not Empty Stack") << endl;
	
	cout << "push 11\n";
	fila.push(11);
	cout << (fila.isEmpty()?"Empty Stack":"Not Empty Stack") << endl;

	cout << "pop ";
	cout << fila.pop() << endl;
	cout << (fila.isEmpty()?"Empty Stack":"Not Empty Stack") << endl;

	cout << "pop ";
	fila.pop();
	cout << (fila.isEmpty()?"Empty Stack":"Not Empty Stack") << endl;
	
	cout << "pop ";
	fila.pop();
	cout << (fila.isEmpty()?"Empty Stack":"Not Empty Stack") << endl;
	return 0;
}
