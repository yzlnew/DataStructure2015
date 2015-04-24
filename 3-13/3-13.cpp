#include <iostream>
#include <fstream>
#include "LinkedStack.h"
using namespace std;

bool sytaxcheck(char* sfile){
	ifstream infile(sfile, ios::in);
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	LinkedStack<char> LS;
	char ch1, ch2;

	while (infile >> ch1){
		if (ch1 == '\''){
			while (infile >> ch1)
				if (ch1 == '\'')	break;
			if (!infile) return false;
		}
		if (ch1 == '\"'){
			while (infile >> ch1)
				if (ch1 == '\"')	break;
			if (!infile) return false;
		}

		switch (ch1){
		case '(': LS.Push(ch1); break;
		case '[': LS.Push(ch1); break;
		case '{': LS.Push(ch1); break;
		case ')': LS.getTop(ch2); 
					if (ch2 == '(') LS.Pop(ch2);
					else return false;
					break;
		case ']': LS.getTop(ch2);
			if (ch2 == '[') LS.Pop(ch2);
			else return false;
			break;
		case '}': LS.getTop(ch2);
			if (ch2 == '{') LS.Pop(ch2);
			else return false;
			break;
		}
	}
	if (LS.IsEmpty()) return true;
	else return false;
};

int main(){
	int flag=sytaxcheck("sfile.cpp");
	if (flag) cout << "true"<<endl;
	else cout << "false"<<endl;
	flag = sytaxcheck("wsfile.cpp");
	if (flag) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}