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

//����һ��ֱ�ӱ�����
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

//��������
//ͨ���������ݵĹ��ɣ�������nΪ21345�����ǿ��԰����ֿ���1�ĸ�����
//
//��һ���������λ��1�ĸ�������10000��19999��10000��1��
//
//�ڶ������������λ��1�ĸ����⣬������λ��1�ĸ��������ǰ�������̷ֳ�1346��21345��1��1345�Ĺ���
//
//��Ϊ��1��1345��1�ĸ�������ʹ�õݹ��ˡ���ô���Ǿ�ֻҪ��1346��21345�г�����λ���⣬����λ1�ĸ�����
//
//Ϊ2 * 4 * 10 * 10 * 10 = 8000����Ϊʲô�أ�
//
//2����Ϊ1346��21345��������������Կ���1346��11345��11346��21345�������̣�ÿ�������У����ĸ�λ�����ѡȡһ��Ϊ1��
//������λ
//
//Ϊ0 - 9��10����������ÿ��������10 * 10 * 10 * 4 = 4000�����������̼���������8000����
//
//����������ظ���
//
//����1111�����������ϸ���룬��Ϊ1111���ĸ�1.���ظ�Ҳֻ���ظ���3�Σ���������4�Ρ���˲����ж��������������

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

	//���������λ����1�Ĵ���
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = power10(len - 1);
	}
	else
	{
		numFirstDigit = atoi((str.substr(1)).c_str()) + 1;
	}

	//�ټ�����˵�һλ֮��ʣ�µ�1�ĸ���
	int numOtherDigit = first*(len - 1)*power10(len - 2);

	//�ݹ�
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

