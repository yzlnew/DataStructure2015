#include <iostream>
#include "LinkStr.h"
using namespace std;

int main(){
	List a,b,sub;
	string str1, str2,str3;
	str1 = "1234";
	str2 = "1234";
	str3 = "23";
	a.data(str1);
	b.data(str2);
	sub.data(str3);
	cout << "长度：" << a.Length() << ' ' << b.Length() << endl;
	int equal = (a == b);
	cout << "判断相等：" << equal<<endl;
	a.Find(2, 2, sub);
	cout << "输出子串："; 
	sub.output(); cout << endl;
	cout << "输出合成串：";
	if (a + b){ a.output(); }
	cout << endl;
	cout<<"子串位置："<<b.subLocate(sub);
	cout << endl;
}