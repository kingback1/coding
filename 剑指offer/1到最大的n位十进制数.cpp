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

//题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数即999。
int counti(int n)
{
	int c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return c;
}

void printn(int n, int len, int num)
{
	if (counti(num) - counti(num-1))
	{
		len++;
	}

	if (len > n)
	{
		return;
	}

	cout << num << " ";
	
	printn(n, len, num + 1);
}

//全排列
bool fullpermutation(vector<vector<int>> &r, vector<int> &v, int len)
{
	if (len >= v.size())
	{
		return false;
	}

	for (int i = 0; i < 10; i++)
	{
		v[len] = i;

		//这里会重复push一个数
		//fullpermutation(r, v, len + 1);
		//r.push_back(v);

		if (!fullpermutation(r, v, len + 1))
			r.push_back(v);
	}

	return true;
}

//递归
void permutation(vector<int> &n, vector<vector<int>> &p, int len)
{
	if (len >= n.size())
	{
		p.push_back(n);
		return;
	}

	for (int i = len; i < n.size(); i++)
	{
		int tmp = n[i];
		n[i] = n[len];
		n[len] = tmp;

		permutation(n, p, len + 1);
		
		tmp = n[i];
		n[i] = n[len];
		n[len] = tmp;
	}

	return;
}

bool mem(vector<vector<int>> &r, vector<int> &v, int len)
{
	if (len>v.size() - 1)
	{
		return false;
	}

	for (int i = 0; i < 10; i++)
	{
		v[len] = i;
		mem(r, v, len + 1);
		r.push_back(v);
	}

}

int main()
{
	vector<vector<int>> r;
	int n1;
	cin >> n1;
	vector<int> v(n1);
	fullpermutation(r, v, 0);
	//mem(r, v, 0);

	for (int i = 0; i < r.size(); i++)
	{
		int j = 0;
		while (j < v.size() && !r[i][j])
		{
			j++;
			//continue;
		}

		if (j == v.size())
		{
			continue;
		}

		for (int k = j; k < v.size(); k++)
		{
			cout << r[i][k];
		}
		
		cout << endl;
	}

	vector<int> n = { 1, 7, 3 };
	sort(n.begin(), n.end());
	vector<int> t(3);
	vector<vector<int>> p;
	permutation(n, p, 0);

	system("pause");
	return 0;
}

