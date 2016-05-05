// algorithm1.cpp : 定义控制台应用程序的入口点。
//

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

//方法一：直接暴力法
int Cal1(int n)
{
	int count = 0; 
	while (n)
	{
		int tmp = n % 10;
		if (tmp == 1)
		{
			count++;
		}
		n = n / 10;
	}

	return count;
}

//方法二：
//通过分析数据的规律，例如若n为21345，我们可以把它分开求1的个数：
//
//第一：先求出万位上1的个数，即10000到19999共10000个1；
//
//第二：求出除了万位上1的个数外，其它四位上1的个数，我们把这个过程分成1346到21345和1到1345的过程
//
//因为求1到1345中1的个数可以使用递归了。那么我们就只要求1346到21345中除了万位上外，其它位1的个数。
//
//为2 * 4 * 10 * 10 * 10 = 8000个，为什么呢？
//
//2是因为1346到21345有两万个数，可以看成1346到11345和11346到21345两个过程，每个过程中，在四个位中随便选取一个为1，
//其它三位
//
//为0 - 9的10个数，所以每个过程是10 * 10 * 10 * 4 = 4000个。两个过程加起来就是8000个。
//
//这样求会有重复吗？
//
//比如1111这种情况。仔细想想，因为1111算四个1.而重复也只是重复了3次，正好满足4次。因此不会有多计算的情况发生。

int power10(int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

int NumberOf1(string str)
{
	int len = str.size();
	if (len == 0)
		return 0;

	int first = str[0] - '0';

	if (len == 1 && first == 0)
	{
		return 0;
	}
	if (len == 1 && first > 0)
	{
		return 1;
	}

	//首先算最高位出现1的次数
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = power10(len - 1);
	}
	else
	{
		numFirstDigit = atoi((str.substr(1)).c_str()) + 1;
	}

	//再计算除了第一位之后剩下的1的个数
	int numOtherDigit = first*(len - 1)*power10(len - 2);

	//递归
	int numRecursive = NumberOf1(str.substr(1));

	return numFirstDigit + numOtherDigit + numRecursive;
}

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;

	char str[10];
	sprintf_s(str, "%d", n);

	string s(str);
	
	return NumberOf1(s);
}


int main()
{
	int total = 0;
	int n = 52014;

	total = NumberOf1Between1AndN(n);

	cout << total << endl;

	system("pause");
	return 0;
}

