#include "iostream"
using namespace std;
int main(){
	int test[1000];
	//初始化测试數組
	for(int i=0;i<1000;++i){
		test[i]=rand()%10001;
	}
	int Hash[10001];
	//初始化Hash
	for (int i = 0; i < 10002; ++i)
	{
		Hash[i]=0;
	}
	//建立Hash
	for (int i = 0; i < 1000; ++i)
	{
		Hash[test[i]]=test[i];
	}
	//排序结果返回测试數組
	int j=0;
	for (int i = 0; i < 10002; ++i)
	{
		if (Hash[i]!=0)
		{
			test[j++]=Hash[i];
		}
	}
	//输出前10个数
	for (int i = 0; i < 10; ++i)
	{
		cout<<test[i]<<endl;
	}
	return 0;
}