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

int main()
{
	int n = 123456;
	char str[10];
	
	//������תΪ�ַ�����sprintf���ص����ַ������ȣ�����������Ŀմ����ȡ�strҲ����Ч���ȡ�
	int len = sprintf_s(str, "%d", n);

	//nת��Ϊ��string����ʱ�Ϳ�����string�������֣�����ȡ������ȥ����
	string s(str);

	//C��������ת�ַ�����str��������Ч���ַ������Գ�����10
	//_itoa_s(n, str, 10);

	char ss[] = "0123";
	int nn = 0;

	//�ַ���ת����������������ȥ���ڸ�λ��0
	sscanf_s(ss, "%d", &nn);

	//C���ַ���ת����������ȥ���ڸ�λ��0
	nn = atoi(ss);

	system("pause");
	return 0;
}

