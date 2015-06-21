//
//  main.cpp
//  ex7
//
//  Created by Robin on 15/6/15.
//  Copyright (c) 2015年 Robin. All rights reserved.
//



#include<iostream>
using namespace std;


int g[1000][1000];
int cost[1000];
bool visit[1000];
int prim(int n)
{

    int res = 0;
    for(int i=0;i<=n;i++)
    {
        cost[i] = g[0][i];
        visit[i] = 0;
    }
    visit[0] = 1;
    
    for(int i=0;i<n;i++)
    {
        int k = -1,Min = 100001;
        for(int j=0;j<=n;j++)
            if(!visit[j] && Min > cost[j]) {
                k = j;
                Min = cost[j];
            }
        visit[k] = 1;
        res += Min;
        for(int j=0;j<=n;j++)
            if(!visit[j]&&cost[j] > g[k][j])
                cost[j] = g[k][j];
    }
    
    return res;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    
    cout<<prim(n);
    return 0;
}

