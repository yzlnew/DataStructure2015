//
//  main.cpp
//  ex2new
//
//  Created by Robin on 15/3/24.
//  Copyright (c) 2015年 Robin. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPrime(int m){
    for (int n = 2; (n * n) < (m + 1); n++){
        if (!(m % n)){
            return false;
        }
    }
    return true;
};

int J(int n, int p,int m[])
{
    if (n==1) return 0;
    else {
        return (J(n-1, p+1, m) + m[p]) % n;
    }
};

int main() {
    int n;
    int m[3600]; 								//用来存素数
    int count=0;
    int Josephus(int n, int p);
    for (int i = 2; i < 36000; ++i)
    {
        if(isPrime(i)) {m[count]=i;
            count++;
            if (count>=3600) break;};
    }
    while(1){
        cin>>n;
        if(n!=0){
        cout<<J(n,0,m)+1<<endl;
        }
        else break;
    }
    return 0;
}

