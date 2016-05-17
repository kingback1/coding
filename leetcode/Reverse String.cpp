// algorithm1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

// Reverse String: https://leetcode.com/problems/reverse-string/
//Write a function that takes a string as input and returns the string reversed.
//
//Example:
//Given s = "hello", return "olleh".

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

