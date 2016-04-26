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

//递归
//用递归方法计算的时间复杂度是以 n 的指数方式递增的。

long long Fib(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	return Fib(n - 1) + Fib(n - 2);
}

//迭代，不用递归，复杂度是O(N)
long long Fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	long long index1 = 0;
	long long index2 = 1;
	long long f = 0;

	for (int i = 2; i <= n; i++)
	{
		f = index1 + index2;
		index1 = index2;
		index2 = f;
	}

	return f;
}

//第三种方法，斐波那契数列有数学公式，可以用矩阵的乘方来解答。复杂度是O(logN)

int main()
{
	cout << Fibo(3) << endl;


	system("pause");
	return 0;
}

