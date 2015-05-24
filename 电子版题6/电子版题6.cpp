//
//  main.cpp
//  ex6
//
//  Created by Robin on 15/5/23.
//  Copyright (c) 2015年 Robin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void creat(string s, int store[])
{
    int num = s.length();
    for (int i = 0; i < num; i++)       //存储字符串，从第一个字符开始
    {
        int temp = s[i] - '0';
        for (int j = 1; j <= 1023;)     //从1开始存储
        {
            if (store[j] == -1)
            {
                store[j] = temp;
                break;
            }
            else if (temp<store[j])
                j = j * 2;
            else
            {
                j = j * 2 + 1;
            }
        }
    }
    
}

int main()
{
    int store1[1024],store2[1024];        //最多右10的字符，所以最多存2^10=1024
    int n;
    int i;
    string s1,s2;
    while (cin >> n)
    {
        for (i = 0; i < 1024; i++){
            store1[i] = -1;
        }
        cin>>s1;
        creat(s1, store1);
        while (n--)
        {
            for (i = 0; i < 1024; i++){
                store2[i] = -1;
            }
            cin >> s2;
            creat(s2, store2);
            for (i = 0; i < 1024;i++){
                if (store1[i] != store2[i]) {
                    cout<<"NO"<<endl;break;
                }
            }
            if (i==1024) {
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}