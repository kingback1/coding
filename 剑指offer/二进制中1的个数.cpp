// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣

//��Ŀ���� 
//����һ��������������������Ʊ�ʾ��1�ĸ�����

//˼�룺��һ��������ȥ1���ٺ�ԭ���������������㣬��Ѹ��������ұ�һ��1��Ϊ0

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

