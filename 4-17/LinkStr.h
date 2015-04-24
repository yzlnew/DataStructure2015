#include <iostream>
#include <string.h>
using namespace std;
struct LinkNode {	 	       //链表结点类的定义 !!
	char data;			       //数据域
	LinkNode *link;     //链指针域
	LinkNode() { link = NULL; }    //构造函数, 不带数据
	LinkNode(char& item, LinkNode *ptr = NULL)
	{
		data = item;  link = ptr;
	}     //构造函数, 带数据
	bool operator == (char x) { return data == x; }
	bool operator != (char x) { return data != x; }
};

class List {

protected:
	LinkNode *first;
public:
	List() { first = new LinkNode; }  //构造函数
	List(char x) { first = new LinkNode(x); } //带数据
	List(List& L);		//复制构造函数
	~List(){ }				//析构函数

	int Length() const;
	LinkNode *Search(char x);	    //搜索含x元素 
	LinkNode *Locate(int i);    //定位第i个元素
	bool getData(int i, char& x); //取出第i个元素值
	void setData(int i, char& x);	    //更新第i个元素值
	bool Insert(int i, char& x);           //在第i个元素后插入
	bool Remove(int i, char& x);	    //删除第i个元素
	bool IsEmpty() const 		    //判表空否
	{
		return first->link == NULL ? true : false;
	}
	void data(string str);
	LinkNode *getFirst() const { return first; }
	List& Find(int location, int length,List& substr);
	int subLocate(List& substr);
	
	bool operator==(List& L);
	bool operator+(List& L);
	void output();
};
//输出
void List::output(){
	LinkNode *p = first->link;
	while (p != NULL){
		cout << p->data;
		p = p->link;
	}
}
//定位
LinkNode* List::Locate(int i){
	LinkNode* current = first; int k = 0;
	while (current != NULL&&k < i){
		current = current->link;
		k++;
	}
	return current;
}
//取值
bool List::getData(int i, char& x){
	LinkNode* p = Locate(i);
	x = p->data;
	return true;
}
//设定值
void List::setData(int i, char& x){
	LinkNode* p = Locate(i);
	p->data=x;
}
//计算长度
int List::Length() const{
	LinkNode* p = first->link;
	int count = 0;
	while (p != NULL){
		p = p->link;
		count++;
	}
	return count;
}
//赋值
void List::data(string a){
	LinkNode* newNode;
	int flag = 0;
	int l = a.length();
	while (flag<l){
		newNode = new LinkNode(a[l-flag-1]);
		newNode->link = first->link;
		first->link = newNode;
		flag++;
	}
}
//判断相等
bool List::operator==(List& L){
	LinkNode *p, *q;
	p = first;
	q = L.getFirst();
	int flag = 0;
	while (p->link != NULL&&q->link != NULL){
		if (p->link->data != q->link->data) break;
		p = p->link;
		q = q->link;
	}
	if (p->link == NULL&&q->link == NULL) return 1;
	else return 0;
}
//连接
bool List::operator+(List& L){
	LinkNode* p = first->link;
	while (p ->link != NULL){
		p = p->link;
	}
	LinkNode* q = L.getFirst();
	LinkNode* newNode;
	while (q->link != NULL){
		newNode = new LinkNode(q->link->data);
		p->link = newNode;
		p = newNode;
		q = q->link;
	}
	return true;
}
//求子串
List& List::Find(int location, int length,List& substr){
	LinkNode* p = Locate(location);
	LinkNode* current = substr.getFirst();
	
	int count = 1;
	while (count < length+1){
		current -> link = new LinkNode(p->data);
		
		p = p->link;
		current = current->link;
		count++;
	}
	return substr;
}
//求子串在串中的位置
int List::subLocate(List& substr){
	int i, j;LinkNode* p, *q;
	int l1 = Length(); int l2 = substr.Length();
	for (i = 0; i <= l1 - l2; i++){
		for (j = 1; j < l2; j++){
			
			p = Locate(i + j);
			q = substr.Locate(j);
			if (p->data != q->data) break;
		}
		if (j == l2) return i+1;
	}
	return -1;
}



