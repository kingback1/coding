// algorithm1.cpp : 定义控制台应用程序的入口点。

//题目描述 
//输入一个整数，输出该数二进制表示中1的个数。

//思想：把一个整数减去1，再和原来的整数做与运算，会把该整数最右边一个1变为0

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

int countof1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1) & n;
	}

	return count;
}

int main()
{

	cout << countof1(3) << endl;

	system("pause");
	return 0;
}

