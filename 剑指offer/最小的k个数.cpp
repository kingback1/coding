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

//题目描述：输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

//方法一：用快排，第K个，那么在k左边的就是k小
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
	//最小k个数，找快排中第k-1个数
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


//海量数据最小k个数,用最大堆。
//set和multiset都是红黑树实现，查找，删除和插入操作都只需要O(logN)的时间
//两者的差别是，后者允许元素重复而前者不允许
#include <set>
#include <functional>

//这里greater是仿函数类模板
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
			//获得最大堆的最大值
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

