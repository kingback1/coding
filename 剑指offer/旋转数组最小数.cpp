// algorithm1.cpp : 定义控制台应用程序的入口点。

//题目： 把一个数组最开始的若干个元素搬到数组的末尾， 我们称之数组的旋转。输入一个递增排序的数组的一个旋转， 
//输出旋转数组的最小元素。例如数组{3，4, 5, 1, 2 ｝为｛ l1,2,3, 4，5}的一个旋转，该数组的最小值为 1。

//思想：1，顺序查找；2，二分查找

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

int Min(vector<int> &nums, int start, int end)
{
	if (start == end)
	{
		return nums[start];
	}
	if ((end-start) == 1)
	{
		return nums[start] > nums[end] ? nums[end] : nums[start];
	}

	int mid = (start + end) / 2;
	if (mid > start && mid<end && nums[mid] >= nums[mid - 1] && nums[mid] <= nums[mid + 1])
	{
		if (nums[mid]>nums[end])
		{
			return Min(nums, mid + 1, end);
		}
		else
		{
			return Min(nums, start, mid);
		}
		
	}
	if (mid > start && nums[mid] >= nums[mid - 1] && nums[mid] > nums[mid + 1])
	{
		return nums[mid + 1];
	} 
	if (mid>start && mid<end && nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
	{
		return nums[mid];
	}
	if (mid>start && mid<end && nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
	{
		return nums[mid-1];
	}
}

//剑指offer解答
//这里假设的是数组是绝对递增数组，如何不是绝对，有相等的情况，那么还要考虑index1, mid, index2都相等的情况。
int Min1(vector<int> &nums)
{
	int n = nums.size();
	int index1 = 0;
	int index2 = n - 1;
	int mid = index1;

	while (nums[index1] >= nums[index2])
	{
		if (index2 - index1 == 1)
		{
			mid = index2;
			break;
		}

		mid = (index2 + index1) / 2;

		//如果不是绝对递增数组，那么有index1==index2==mid的情况，此时只能用顺序查找。

		if (nums[mid] >= nums[index1])
		{
			index1 = mid;
		}
		else if (nums[mid] <= nums[index2])
		{
			index2 = mid;
		}
	}

	return nums[mid];
}

int main()
{
	vector<int> nums = { 5, 6, 7 ,1, 2, 3, 4 };

	int a = Min1(nums);

	system("pause");
	return 0;
}

