// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣
//
//
//��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"�����硰We are happy.�����������We%20are%20happy.����
//
//�㷨˼�룺�ȱ���һ��s������ո�������Ϊ��һ���ո񳤶Ⱦ�����2�����Կ����ȼ����ܳ��ȡ��ٴ�β������s��
//�������µ�str����β���������ͱ����˴��ײ�������Ҫ�ƶ�������ַ���

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

