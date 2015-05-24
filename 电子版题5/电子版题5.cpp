//
//  main.cpp
//  ex5
//
//  Created by Robin on 15/5/22.
//  Copyright (c) 2015年 Robin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct {
    int weight;
    int parent, lchild, rchild;
} HTNode;                           //结点


void CreateHuffmanTree (HTNode T[],int fr[],int n) {      //建立 Huffman 树，fr[]为权值数组，n 为外结点个数
    int i;
    int m=2*n-1;
    for (i = 0; i < n; i++) T[i].weight = fr[i];
    for (i = 0; i < m; i++) {
        T[i].parent = T[i].lchild = T[i].rchild = -1;
    }

    int sumoffr=0;
    for (i=0; i<n; i++) {
        sumoffr+=fr[i];
    }

    for (i = n; i < m; i++){
        int min1=sumoffr+1, min2=sumoffr+1;
        int pos1=0, pos2=0;
        for (int j = 0; j < i; j++){
            if (T[j].parent == -1)
            {if (T[j].weight < min1) {
                pos2 = pos1;  min2 = min1;
                pos1 = j;  min1 = T[j].weight;
            }
            else if (T[j].weight < min2)
            { pos2 = j;  min2 = T[j].weight; }
            }
        }
        T[i].lchild = pos1;  T[i].rchild = pos2;
        T[i].weight = T[pos1].weight+T[pos2].weight;
        T[pos1].parent = T[pos2].parent = i;
    }
};

int Pathlength(HTNode T[],int i){          //返回 Huffman 编码长度
    int count=0;
    int j=i;
    while(T[j].parent!=-1) {
        count++;
        j=T[j].parent;
    }
    return count;
}

int main() {
    
    int N;
    char command[100];
    
    while(cin>>N){
    int sum=0;
    int fr[N];
    if (N==0) {
        cout<<"0 0";
    }
    else{
    int len=0;
    for (int i=0; i<N; i++) {
        cin>>command>>fr[i];
        for (int j=0; j<100; j++) {
            if(command[j]=='\0'){
                len=j;break;
            }
        }
        sum=sum+len*fr[i];
        len=0;
    }
        
    cout<<sum<<' ';
        
    HTNode T[2*N-1];        //一共有2N-1个结点
    CreateHuffmanTree(T, fr, N);
    int result=0;
    for(int i=0;i<N;i++){
        result+=Pathlength(T, i)*T[i].weight;
    }
    if(N==1) result=fr[0];
        cout<<result<<endl;
    }
    }
    return 0;
}

