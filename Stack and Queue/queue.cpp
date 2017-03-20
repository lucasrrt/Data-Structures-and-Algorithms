#include <iostream>

using namespace std;

class queue{
	public:
	int* values;
	int size;
	int first;
	int last;
	
	queue(){
		size = 8;
		values = new int(size);
		first = -1;
		last = -1;
	}

	bool isEmpty(){
		return (first == -1)?1:0;
	}

	void push(int value){
		if(first == -1){
			first++;
			last++;
			values[first] = value;
		}
		else if((last+1)%size == first){
			cout << "Full Queue!\n";
		}
		else{
			last = (last+1)%size;
			values[last] = value;
		}
	}

	int pop(){
		if(last == -1){
			cout << "Empty Queue\n";
			return -1;
		}
		else if(first == last){
			int ret = values[first];
			first = -1;
			last = -1;
			return ret;
		}
		else{
			int ret = values[first];
			first = (first+1)%size;
			return ret;
		}
	}

	int peek(){
		if(!isEmpty())
			return values[first];
		else
			return -1;
	}

};

int main(){
	queue first;
	first.pop();
	cout << first.peek() << endl;

	first.push(1);
	cout << "peek: " << first.peek() << endl;
	first.push(2);
	first.push(3);
	cout  << "peek: " << first.peek() << endl;
	first.push(4);
	first.push(5);
	first.push(6);
	cout  << "peek: " << first.peek() << endl;
	first.push(7);
	first.push(8);

	first.push(9);
	cout << first.peek() << endl;
	
	cout << "Testando saídas: \n";

	cout << first.pop() << endl;
	cout << "peek: "  << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout << "peek: "  << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	cout << first.pop() << endl;
	cout  << "peek: " << first.peek() << endl;
	
	return 0;
}
