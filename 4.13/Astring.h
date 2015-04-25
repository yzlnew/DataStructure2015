#define _CRT_SECURE_NO_WARNINGS
#ifndef ASTRING_H	//定义在文件“Astring.h”中
#define ASTRING_H
#include <string>
#include <iostream>
using namespace std;
class AString {
	//对象: 零个或多个字符的一个有限序列。
private:
	char *ch;			      //串存放数组
	int curLength;		      //串的实际长度
	int maxSize;		      //存放数组的最大长度
public:
	AString(int sz = 128);  //构造函数  创建一个空串
	AString(const char *init);  //构造函数从已有字符数组*init复制
	AString(const AString& ob); //复制构造函数从已有串ob复制
	~AString() { delete []ch; }	      //析构函数
	int Length() const { return curLength; }	 //求长度
	AString& operator() (int pos, int len);   //求子串
	bool operator == (AString& ob) const
	{
		return strcmp(ch, ob.ch) == 0;
	}
	//判串相等. 若串相等, 则函数返回true
	bool operator != (AString& ob) const
	{
		return strcmp(ch, ob.ch) != 0;
	}
	//判串不等. 若串不相等, 则函数返回true  
	bool operator ! () const { return curLength == 0; }
	//判串空否。若串空, 则函数返回true
	AString& operator = (AString& ob);      //串赋值
	AString& operator += (AString& ob);	//串连接
	char operator [] (int i);		//取第 i 个字符
	int Find(AString& pat, int k) const;     	//串匹配
};

AString::AString(const char *init) {
	//复制构造函数: 从已有字符数组*init复制
	int len = strlen(init);
	maxSize = (len > 128) ? len : 128;
	ch = new char[maxSize + 1];     //创建串数组
	if (ch == NULL)
	{
		cerr << "存储分配错 !\n";  exit(1);
	}
	curLength = len;	 	   //复制串长度
	strcpy(ch, init);		             //复制串值	
};

AString::AString(const AString& ob) {
	//复制构造函数：从已有串ob复制
	maxSize = ob.maxSize;               //复制串最大长度
	ch = new char[maxSize + 1];   //创建串数组
	if (ch == NULL)
	{
		cerr << "存储分配错!\n";  exit(1);
	}
	curLength = ob.curLength;          //复制串长度
	strcpy(ch, ob.ch);                         //复制串值
};

AString& AString::operator = (AString& ob) {
	if (&ob != this) {	//若两个串相等为自我赋值
		delete []ch;
		ch = new char[ob.maxSize + 1];  //P160修改 
		if (ch == NULL)
		{
			cerr << "存储分配失败!\n";  exit(1);
		}
		curLength = ob.curLength;  strcpy(ch, ob.ch);
	}
	else cout << "字符串自身赋值出错!\n";
	return *this;
};

char AString::operator [] (int i) {
	//串重载操作：取当前串*this的第i个字符
	if (i < 0 || i >= curLength)    
	{
		cout << "字符串下标超界!\n"; exit(1);
	}
	return ch[i];
};

#endif