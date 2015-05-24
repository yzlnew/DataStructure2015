//
//  BST.h
//  7_27
//
//  Created by Robin on 15/5/23.
//  Copyright (c) 2015年 Robin. All rights reserved.
//

#ifndef BST_h
#define BST_h
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class E>
struct BSTNode{			 //二叉搜索树结点类
    E data;				    //数据域
    int count=1;            //默认计数1
    BSTNode<E> *left;
    BSTNode<E> *right;  //左子女和右子女
    BSTNode() { left = NULL; right = NULL; }
    //构造函数
    BSTNode (const E d, BSTNode<E> *L = NULL,
             BSTNode<E> *R = NULL)
    { data = d; left = L; right = R;}
    //构造函数
    ~BSTNode() {}				//析构函数

};

template <class E>
class BST{				  //二叉搜索树类定义
public:
    BST(){}	  //构造函数
    ~BST() {};			  //析构函数
    void print(BSTNode<int>* ptr) const;   //输出
    bool Insert(E x, BSTNode<E> *current, BSTNode<E> *par);
    BSTNode<E>* getroot(){return root;}
    void setroot(BSTNode<int>* ptr){
        root=ptr;
    }
private:
    BSTNode<E> *root;	//根指针
};

template <class E>
void BST<E>::print(BSTNode<int>* ptr)const{
    if (ptr!=NULL) {
        cout<<ptr->data<<' '<<ptr->count<<endl;
        print(ptr->left);
        print(ptr->right);
    }
}

template <class E>
bool BST<E>::Insert(E x, BSTNode<E> *current, BSTNode<E> *par){
    BSTNode<E> *p=current;
    while (p!=NULL) {
        if (p->data!=x) {
            par=p;
            if (x<p->data) {
                p=p->left;
            }
            else {p=p->right;
            }
        }
        else{p->count=p->count+1; return 0;}
    }
    BSTNode<E> *add = new BSTNode<E>;
    add->data=x;
    if (x<par->data) {
        par->left=add;
    }
    else par->right=add;
    return 1;
}
#endif
