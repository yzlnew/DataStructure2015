#include <iostream>
#include "SparseMatrix"
using namespace std;
int main(){
    int Rw,Cl,Tm;
    int row,col,value;
    cin>>Rw>>Cl>>Tm;
    SparseMatrix<int>* A = new SparseMatrix<int>(Rw,Cl,Tm);
    for(int i=0;i<Tm;i++){
        cin>>row>>col>>value;
        A.smArray[i].row=row;
        A.smArray[i].col=col;
        A.smArray[i].value=value;
    }
    SparseMatrix<int>* B = new SparseMatrix<int>(Rw,Cl,Tm);
    SparseMatrix<int>* C = new SparseMatrix<int>(Rw,Cl,Tm);
    A.Transpose(B);
    for(int j=0;j<Tm;j++){
        cout<<B.smArray[j].row
        <<B.smArray[j].col
        <<B.smArray[j].value
        <<endl
    }
    A.Multiply(C);
    for(int k=0;k<Tm;k++){
        cout<<C.smArray[k].row
        <<C.smArray[k].col
        <<C.smArray[k].value
        <<endl
    }
}