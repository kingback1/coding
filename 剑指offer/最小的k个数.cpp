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

//��Ŀ����������n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��

//����һ���ÿ��ţ���K������ô��k��ߵľ���kС
int partition(vector<int> &nums, int start, int end)
{
	int n = nums.size();
	if (n <= 0 || start<0 || end>n - 1)
	{
		throw("Invalid Parameters");
	}

	int index = (rand() % (end - start + 1)) + start;

	swap(nums[index], nums[end]);

	int small = start - 1;

	for (int i = start; i < end; i++)
	{
		if (nums[i] < nums[end])
		{
			small++;
			if (small != i)
			{
				swap(nums[small], nums[i]);
			}
		}
	}

	small++;
	swap(nums[small], nums[end]);

	return small;
}

void fun(vector<int> &nums, int k)
{
	int index = partition(nums, 0, nums.size() - 1);
	//��Сk�������ҿ����е�k-1����
	while (index != k - 1)
	{
		if (index > k)
		{
			index = partition(nums, 0, index - 1);
		}
		else
		{
			index = partition(nums, index + 1, nums.size() - 1);
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << nums[i] << endl;
	}
}


//����������Сk����,�����ѡ�
//set��multiset���Ǻ����ʵ�֣����ң�ɾ���Ͳ��������ֻ��ҪO(logN)��ʱ��
//���ߵĲ���ǣ���������Ԫ���ظ���ǰ�߲�����
#include <set>
#include <functional>

//����greater�Ƿº�����ģ��
//http://www.cplusplus.com/reference/functional/greater/

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNum(vector<int> &nums, intSet &LeastNums, int k)
{
	int n = nums.size(); 
	if (n < k || k < 1)
	{
		return;
	}

	LeastNums.clear();

	for (int i = 0; i < n; i++)
	{
		if (LeastNums.size() < k)
		{
			LeastNums.insert(nums[i]);
		}
		else
		{
			//������ѵ����ֵ
			setIterator iterMax = LeastNums.begin();
			if (nums[i] < *iterMax)
			{
				LeastNums.erase(iterMax);
				LeastNums.insert(nums[i]);
			}
		}

	}

	setIterator itertmp = LeastNums.begin();
	for (; itertmp != LeastNums.end(); itertmp++)
	{
		cout << *itertmp << endl;
	}

	return;
}


int main()
{
	vector<int> nums = { 4, 5, 1, 6, 2, 7, 3, 8 };

	int k = 4;

	intSet LeastNums;
	GetLeastNum(nums, LeastNums, k);
	
	system("pause");
	return 0;
}

