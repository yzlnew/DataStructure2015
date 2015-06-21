//
//  head.h
//  8.31
//
//  Created by Robin on 15/6/21.
//  Copyright (c) 2015年 Robin. All rights reserved.
//

#ifndef __31_head_h
#define __31_head_h
#include <iostream>
using namespace std;
#define maxValue 10000
#define DefaultEdges 25
#define DefaultVertices 25



class disjoint{
    int parent[DefaultVertices];
public:
    disjoint(){
        for(int i=0;i<DefaultVertices;i++) parent[i]=-1;
    };
    int  Find (int i){
        if(parent[i]<0) return i;
        else return(Find(parent[i]));
    };
    void Unions(int i ,int j){
        parent[i]+=parent[j];
        parent[j]=i;
    };
    int Father(int i){
        if(i>=0) return parent[i];
        else return i;
    };
    int commonAncestors(int i,int j)
    {
        int p=0,q=0,k;
        for(k=i;parent[k]>=0;k=parent[k]) p++;
        for(k=j;parent[k]>=0;k=parent[k]) q++;
        while(parent[i]!=parent[j])
        {
            if(p<q) {j=parent[j]; q--;}
            else if(p>q) {i=parent[i]; p--;}
            else{i=parent[i]; j=parent[j];}
        }
        return i;
    };
    int Remove(int i){
        int k=0;
        while(k<DefaultVertices && parent[k]!=i) k++;
        if(k<DefaultVertices)
        {
            parent[k]=parent[i];parent[i]=-1;return k;
        }
        else return -1;
    }
};


template <class T, class E>
class Graphmtx {
    friend istream& operator >> ( istream& in,   Graphmtx<T, E>& G);
    friend ostream& operator << (ostream& out, Graphmtx<T, E>& G);
private:
    int maxVertices;
    int numEdges;
   	int numVertices;
    T *VerticesList;
   	E **Edge;
    int getVertexPos (T vertex) {
        
        for (int i = 0; i < numVertices; i++)
            if (VerticesList[i] == vertex) return i;
        return -1;
    };
public:
    Graphmtx (int sz = DefaultVertices);
    ~Graphmtx () {
        delete [ ]VerticesList;
        delete [ ]Edge;
    }
    int NumberOfVertices () { return numVertices; }
    T getValue (int i) {
        return i >= 0 && i <= numVertices ?
        VerticesList[i] : NULL;
    }
   	E getWeight (int v1, int v2) {
        return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
    }
   	bool insertVertex (const T& vertex);
    
   	bool insertEdge (int v1, int v2, E cost);
    
};

template <class T, class E>
bool Graphmtx<T,E>::insertVertex(const T& vertex){
    if(numVertices==maxVertices) return false;
    VerticesList[numVertices++]=vertex;
    return true;
};

template <class T, class E>
bool Graphmtx<T,E>::insertEdge(int v1,int v2,E cost){
    if(v1>-1 && v1<numVertices && v2>-1 && v2<numVertices && Edge[v1][v2]==maxValue){
        Edge[v1][v2]=Edge[v2][v1] =cost;
        numEdges++;
        return true;
    }
    else return false;
};


template <class T, class E>
Graphmtx<T, E>::Graphmtx (int sz) {
    maxVertices = sz;
    numVertices = 0;  numEdges = 0;
    int i, j;
    VerticesList = new T[maxVertices];
    Edge = (E **) new E *[maxVertices];
    for (i = 0; i < maxVertices; i++)
        Edge[i] = new E[maxVertices];
   	for (i = 0; i < maxVertices; i++)
        for (j = 0; j < maxVertices; j++)
            Edge[i][j] = (i == j) ? 0 : maxValue;
};

template <class T, class E>
istream& operator >> ( istream& in,   Graphmtx<T, E>& G){
    int i,j,k,n,m;
    T e1,e2;
    E weight;
    in>>n>>m;
    for(i=0;i<n;i++)
    {
        in>>e1;
        G.insertVertex(e1);
    }
    i=0;
    while(i<m){
        in>>e1>>e2>>weight;
        j= G.getVertexPos(e1);k=G.getVertexPos(e2);
        if(j==-1||k==-1)
            cout<<"error"<<endl;
        else{
            G.insertEdge(j,k,weight); i++;
        }
    }
    return in;
};
struct MSTEdgeNode {
    int tail, head;
   	int cost;
    MSTEdgeNode() : tail(-1), head(-1), cost(0) { }
};
int edgevalue1tail[5]={1,2,3,4,1};
int edgevalue1head[5]={2,3,4,6,5};
int edgevalue1cost[5]={15,6,7,11,14};
class MinSpanTree {
protected:
    MSTEdgeNode *edgevalue;
    int maxSize, n;
public:
    MinSpanTree (int sz = DefaultEdges) :
    maxSize (sz), n (0) {
        edgevalue = new MSTEdgeNode[sz];
   	}
   	bool Insert (MSTEdgeNode& item) {
        if(n<maxSize) {edgevalue[n++] = item; return true;}
        return false;
   	}
    void print()
    {
        for(int i =0;i<5;i++)
        {
            cout<<edgevalue1tail[i]<<"&"<<edgevalue1head[i]<<"_"<<edgevalue1cost[i]<<endl;
        }
    }
    
};

void Dijkstra (Graphmtx<int,int>&G, MinSpanTree &ST){
    MSTEdgeNode nd;
    int n=G.NumberOfVertices();
    int i,j,p,q,k,s1,s2,t1,t2;
    int w,max1,max2;
    disjoint D;
    if(1==0)
    {
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++){
                w=G.getWeight(i,j);
                if(w<maxValue){
                    p=D.Find(i); q=D.Find(j);
                    if(p!=q){
                        D.Unions(i,j);
                        nd.tail =j; nd.head=i;nd.cost=w;ST.Insert(nd);
                    }
                }
                else {
                    k=D.commonAncestors(i,j);
                    p=i;  q=D.Father(p);
                    max1=-maxValue;
                    while(q<=k){
                        if(G.getWeight(p,q)>max1)
                        {
                            max1=G.getWeight(p,q);s1=p;s2=q;
                        }
                        p=q; q=D.Father(p);
                    }
                    p=j; q=D.Father(p);
                    max2=-maxValue;
                    while(q<=k){
                        if(G.getWeight(p,q)>max2)
                        {
                            max2=G.getWeight(p,q);t1=p;t2=q;
                        }
                        p=q; q=D.Father(p);
                    }
                    if(max1<=max2) {s1=t1;s2=t2;max1=max2;}
                    if(D.Remove(s1)>=0){
                        D.Unions(s1,s2);
                        nd.tail=s2; nd.head=s1;nd.cost=max1;ST.Insert(nd);
                    }
                }
            }
    }
};



#endif
