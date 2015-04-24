#include <iostream>
using namespace std;

int Fib(int n){
    if(n>=2)
        return Fib(n-1)+Fib(n-2);
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    else
        return 0;
};

long FibIter(long n) {
    if (n <= 1) return n;
    long twoback = 0,  oneback = 1,  Current = 0;
    for (int i = 2; i <= n; i++) {
        Current = twoback + oneback;
        twoback = oneback;   oneback = Current;
    }
    return Current;
}


int main(){
    int n,temp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>temp;
        cout<<FibIter(temp)<<endl;
}
    return 0;
}