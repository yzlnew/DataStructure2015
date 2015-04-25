#include <iostream>  //具体 实现时的一种头文件形式
#include <assert.h>
#include "stack.h"
using namespace std;

template <class T>
struct StackNode {                    //栈结点类定义

	T data;			          //栈结点数据
	StackNode<T> *link;            //结点链指针

	StackNode(T d = 0, StackNode<T> *next = NULL)
		: data(d), link(next) { }     //构造函数
};
template <class T>
class LinkedStack : public Stack<T> { //链式栈类定义   
private:
	StackNode<T> *top;		            //栈顶指针
	static void output(ostream& os,
		StackNode <T> *ptr, int i);
	//递归输出栈的所有元素
public:
	LinkedStack() : top(NULL) {}	   //构造函数
	~LinkedStack() { makeEmpty(); }   //析构函数
	void Push(T x);		             	   //进栈
	bool Pop(T& x);			   //退栈
	bool getTop(T& x) const;		//取栈顶  	
	bool IsEmpty() const { return top == NULL; }
	bool IsFull() const { return false; }
	//思考为何直接返回为假
	void makeEmpty();			//清空栈的内容

	friend ostream& operator << (ostream& os,
		LinkedStack<T>& s) //教材94页给出一种简单实现
	{
		cout << “Show stack” << endl;
		output(os, s.top, 0); return os;
	} //函数实现			//输出栈元素的重载操作 <<
};

template <class T>
void LinkedStack<T>::makeEmpty() {
	//逐次删去链式栈中的元素直至栈顶指针为空。
	StackNode<T> *p;
	while (top != NULL)		//逐个结点释放
	{
		p = top;  top = top->link;  delete p;
	}
};

template <class T>
void LinkedStack<T>::Push(T x) {
	//将元素值x插入到链式栈的栈顶, 即链头。
	top = new StackNode<T>(x, top); //创建含x新结点
	assert(top != NULL);		         //创建失败退出
};


template <class T>
bool LinkedStack<T>::Pop(T& x) {
	//删除栈顶结点, 返回被删栈顶元素的值。
	if (IsEmpty() == true) return false;   //栈空返回
	StackNode<T> *p = top;		//暂存栈顶指针
	top = top->link;			//退栈顶指针
	x = p->data;
	delete p;		                               //释放结点
	return true;
};
template <class T>
void LinkedStack<T>::output(ostream& os,
	StackNode<T> *ptr, int i) {
	//递归输出栈中所有元素（沿链逆向输出）
	if (ptr != NULL) {
		i++;
		if (ptr->link != NULL)
			output(os, ptr->link, i);   //递归输出
		os << i << “ : ” << ptr->data << endl;
		//逐个输出栈中元素的值   
	}   // ptr 最开始指向栈顶，i=0
};

template <class T>
bool LinkedStack<T>::getTop(T& x) const {
	if (IsEmpty() == true) return false;   //栈空返回
	x = top->data;                       //返回栈顶元素的值
	return true;
};
