#include <iostream>
using namespace std;
template<class T>
void print(int i,int n,T A[]){
	if((i-1)/2>0) cout<<"Parent:"<<A[(i-1)/2]<<endl;
	else cout<<"No Parent"<<endl;
	if(2*i+1<n) cout<<"leftChild:"<<A[2*i+1]<<endl;
	else cout<<"No leftChild"<<endl;
	if(2*i+1<n) cout<<"rightChild:"<<A[2*i+1]<<endl;
	else cout<<"No rightChild"<<endl;
}

int main(){
	int tree[9];
	//initialize tree
	for(int i=0;i<9;i++){
		tree[i]=2*i;
	}
	print<int>(4,9,tree);
	return 0;
}