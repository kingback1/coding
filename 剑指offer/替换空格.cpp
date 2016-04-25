// algorithm1.cpp : 定义控制台应用程序的入口点。
//
//
//题目：请实现一个函数，把字符串中的每个空格替换成"%20"，例如“We are happy.”，则输出“We%20are%20happy.”。
//
//算法思想：先遍历一遍s，计算空格数，因为多一个空格长度就增加2，所以可以先计算总长度。再从尾部遍历s，
//拷贝至新的str。从尾部遍历，就避免了从首部遍历，要移动后面的字符。

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <cstdint>
#include <sstream>
#include <queue>
#include <limits>
#include <stack>

using namespace std;

void RepSpace(string &s)
{
	int slen = s.size();

	if (slen<0)
	{
		return;
	}

	int spacelen = 0;
	for (int i = 0; i < slen; i++)
	{
		if (s[i] == ' ')
		{
			spacelen++;
		}
	}

	int totallen = slen + spacelen * 2;

	string str(totallen,' ');
	int j = totallen-1;
	for (int i = slen - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			str[j] = s[i];
			j--;
		}
		else
		{
			str[j - 2] = '%';
			str[j - 1] = '2';
			str[j] = '0';
			j -= 3;
		}
	}

	s = str;
	return;
}

int main()
{
	string s("hello world h");
	RepSpace(s);

	system("pause");
	return 0;
}

