// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

string reverseString(string s) 
{
	int n = s.size();
	string str(n,' ');

	for (int i = 0; i < n; i++)
	{
		str[n - 1 - i] = s[i];
	}

	return str;
}

int main()
{
	string s = "hello";

	string str = reverseString(s);


	system("pause");
	return 0;
}

