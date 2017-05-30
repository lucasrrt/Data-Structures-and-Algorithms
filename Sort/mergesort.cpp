#include <iostream>

using namespace std;

#define INF 9999;

int ceil(int n){
	if (n%2)
		return n/2 + 1;
	else
		return n/2;
}

void merge(int *U, int size1, int *V, int size2, int *L){
	int i = 0; int j = 0;
	U[size1] = INF;
	V[size2] = INF;
	for (int k = 0; k < size1+size2; k++){
		if(U[i] < V[j]){
			L[k] = U[i];
			i++;
		}
		else{
			L[k] = V[j];
			j++;
		
		}
	}
}

void mergesort(int *p, int size){
	if(size > 1){
		int U[size/2], V[ceil(size)];
		for (int i=0;i<size/2;i++)
			U[i] = p[i];
		for(int i = 0; i<ceil(size); i++)
			V[i] = p[i+ceil(size)];
		mergesort(U, size/2);
		mergesort(V, ceil(size));
		merge(U, size/2, V, ceil(size), p);
	}
}

int main(void)
{
	int n = 10;
	int p[] = {5,4,3,2,8,9,0,1,6,7};
	mergesort(p, n);
	for(int i = 0; i < 10; i++)
		cout << p[i] << " ";
	cout << endl;
	
	return 0;
}
