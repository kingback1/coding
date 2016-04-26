// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣
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

//�ݹ�
//�õݹ鷽�������ʱ�临�Ӷ����� n ��ָ����ʽ�����ġ�

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

//���������õݹ飬���Ӷ���O(N)
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

//�����ַ�����쳲�������������ѧ��ʽ�������þ���ĳ˷�����𡣸��Ӷ���O(logN)

int main()
{
	cout << Fibo(3) << endl;


	system("pause");
	return 0;
}

