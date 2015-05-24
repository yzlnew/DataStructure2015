//
//  main.cpp
//  7_27
//
//  Created by Robin on 15/5/23.
//  Copyright (c) 2015年 Robin. All rights reserved.
//

#include <iostream>
using namespace std;
#include "BST.h"
int main(int argc, const char * argv[]) {
    
    BST<int> Tree;
    BSTNode<int> *first=new BSTNode<int>(3);
    Tree.setroot(first);
    Tree.Insert(5, first, NULL);
    Tree.Insert(4, first, NULL);
    Tree.Insert(3, first, NULL);
    Tree.Insert(2, first, NULL);
    Tree.Insert(5, first, NULL);
    Tree.print(first);
    cin.get();
}
