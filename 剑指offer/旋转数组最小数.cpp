// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣

//��Ŀ�� ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�� ���ǳ�֮�������ת������һ����������������һ����ת�� 
//�����ת�������СԪ�ء���������{3��4, 5, 1, 2 ��Ϊ�� l1,2,3, 4��5}��һ����ת�����������СֵΪ 1��

//˼�룺1��˳����ң�2�����ֲ���

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

//��ָoffer���
//���������������Ǿ��Ե������飬��β��Ǿ��ԣ�����ȵ��������ô��Ҫ����index1, mid, index2����ȵ������
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

		//������Ǿ��Ե������飬��ô��index1==index2==mid���������ʱֻ����˳����ҡ�

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

