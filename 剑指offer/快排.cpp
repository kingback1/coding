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

void QuickSort(vector<int> &nums, int start, int end)
{
	int base = nums[end];

	if (start == end)
	{
		return;
	}

	int up = start - 1;
	bool flag = false;
	for (int i = start; i < end; i++)
	{
		if (nums[i] < base && up >= start)
		{
			swap(nums[i], nums[up]);
			up = i;
		}
		else if (nums[i] > base && !flag)
		{
			up = i;
			flag = true;
		}
	}

	if (up == start -1)
	{
		up++;
	}
	
	if (nums[up] > nums[end])
	{
		swap(nums[up], nums[end]);
	}
	
	if (up > start)
	{
		QuickSort(nums, start, up - 1);
	}
	if (up < end)
	{
		QuickSort(nums, up + 1, end);
	}
	
	return;
}

//剑指offer上的解答

//思想：实现快速排序的关键是首先在数组中选择一个数字（这里随机选取）作为枢纽元，将枢纽元与数组中最后的元素交换使得枢纽元
//离开要被分割的数据段,将数组中比枢纽元小的元素都移动数组的左边，将数组中比枢纽元大的元素都移动数组的右边

//快速排序的最差时间复杂度为O(n ^ 2);
//最优时间复杂度为O(nlogn)
//平均时间复杂度为O(nlogn)
int partition(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (n <= 0 || start < 0 || end >= n)
	{
		throw("invalid parameters");
	}

	//随机在 [start, end] 之间取值
	int index = (rand() % (end - start + 1)) + start;

	swap(nums[index], nums[end]);

	int small = start - 1;
	for (int i = start; i < end; i++)
	{
		if (nums[i] < nums[end])
		{
			++small;
			if (small != i)
			{
				swap(nums[small], nums[i]);
			}
		}
	}

	++small;
	swap(nums[small], nums[end]);

	return small;
}

void QS(vector<int> &nums, int start, int end)
{
	if (start == end)
	{
		return;
	}

	int index = partition(nums, start, end);
	if (index>start)
	{
		QS(nums, start, index - 1);
	}
	if (index<end)
	{
		QS(nums, index + 1, end);
	}

	return;
}

int main()
{

	vector<int> nums = { 2, 3, 4, 1, 6, 12, 9,5 };

	QS(nums, 0, nums.size() - 1);

	system("pause");
	return 0;
}

