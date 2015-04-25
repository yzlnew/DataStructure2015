#include "AString.h"
#include <iostream>
using namespace std;
bool huiwen(AString& a){
	int b = 0, c = a.Length() - 1;
	while (b < c){
		if (a[b] != a[c]) return false;
		b++; c--;
	}
	return true;
}
int main(){
	AString a = "12121";
	AString b = "123";
	cout << huiwen(a) << huiwen(b);
	return 0;
}