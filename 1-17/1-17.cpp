#include <iostream>
#include <fstream>
using namespace std;

int Count(int a [], int n, int count []){
	int b[5] = { 20, 50, 80, 130, 200 };	
	int i, j;
	for (i = 0; i < n; i++){
		for (j = 0; j < 5; j++){
			if (a[i] <= b[j]) break;
		}
		count[j]++;
	}
	return 0;
}

int main(){
	int n;
	int a[6];								
	ifstream infile("input.txt", ios::in);
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}

	for (int i = 0; i < 6; i++){
		infile >> a[i];
	}
	int count[5] = { 0, 0, 0, 0, 0 };
	Count(a, 6, count);
	for (int x = 0; x < 5; x++){
		cout << count[x] << endl;
	}
	return 0;
}