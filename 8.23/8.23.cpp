//
//  main.cpp
//  8.23
//
//  Created by Robin on 15/6/21.
//  Copyright (c) 2015年 Robin. All rights reserved.
//



#include"head.h"
    int main()
    {
        Graphmtx<int,int> G;
        MinSpanTree ST;
        for(int i=0;i<=5;i++)
            G.insertVertex(i);
        
        G.insertEdge(0,1,15);
        G.insertEdge(0,4,14);
        G.insertEdge(0,5,21);
        G.insertEdge(1,5,19);
        G.insertEdge(1,3,9);
        G.insertEdge(2,1,6);
        G.insertEdge(2,3,7);
        G.insertEdge(3,4,18);
        G.insertEdge(3,5,11);
        G.insertEdge(4,5,26);
        
        Dijkstra(G,ST);
        ST.print();

        return 0;
    }
