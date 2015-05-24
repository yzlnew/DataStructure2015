//
//  main.cpp
//  5_37
//
//  Created by Robin on 15/5/23.
//  Copyright (c) 2015年 Robin. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
struct TreeNode{
    T data;
    TreeNode<T> *firstChild, *nextSibling;

    TreeNode (T value = 0, TreeNode<T> *fc = NULL,
              TreeNode<T> *ns = NULL)
    : data (value), firstChild (fc), nextSibling (ns) { }
};

template <class T>
void printTree(TreeNode<T> *ptr,int level){
    for (int i=0; i<level; i++) {
        cout<<' ';
    }
    cout<<ptr->data<<endl;
    if (ptr->firstChild!=NULL) {
        printTree(ptr->firstChild,level+4);
    }
    if (ptr->nextSibling!=NULL) {
        printTree(ptr->nextSibling,level);
    }
}

void CreatTree(TreeNode<char> Tree[]){
    Tree[0].firstChild=&Tree[1];
    Tree[1].firstChild=&Tree[4];
    Tree[1].nextSibling=&Tree[2];
    Tree[2].firstChild=&Tree[6];
    Tree[2].nextSibling=&Tree[3];
    Tree[3].firstChild=&Tree[7];
    Tree[4].nextSibling=&Tree[5];
    Tree[6].firstChild=&Tree[8];
    Tree[8].nextSibling=&Tree[9];
}

int main(int argc, const char * argv[]) {
    TreeNode<char> Tree[10];
    for(int i=0;i<10;i++){
        Tree[i]=TreeNode<char>(65+i);
    }
    CreatTree(Tree);
    printTree(&Tree[0], 0);
}
