#include <iostream>
#include "SparseMatrix.h"
using namespace std;
int main(){
	int Rw, Cl, Tm;
	int row, col, value;
	cin >> Rw >> Cl >> Tm;
	SparseMatrix<int> A(Rw, Cl, Tm);
	for (int i = 0; i<Tm; i++){
		cin >> row >> col >> value;
		A.initialize(i, row, col, value);
	}
	SparseMatrix<int> B(Rw, Cl, Tm);
	A.Transpose(B);
	B.display();
	A.Multiply(B);
}