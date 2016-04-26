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

//��ָoffer�ϵĽ��

//˼�룺ʵ�ֿ�������Ĺؼ���������������ѡ��һ�����֣��������ѡȡ����Ϊ��ŦԪ������ŦԪ������������Ԫ�ؽ���ʹ����ŦԪ
//�뿪Ҫ���ָ�����ݶ�,�������б���ŦԪС��Ԫ�ض��ƶ��������ߣ��������б���ŦԪ���Ԫ�ض��ƶ�������ұ�

//������������ʱ�临�Ӷ�ΪO(n ^ 2);
//����ʱ�临�Ӷ�ΪO(nlogn)
//ƽ��ʱ�临�Ӷ�ΪO(nlogn)
int partition(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (n <= 0 || start < 0 || end >= n)
	{
		throw("invalid parameters");
	}

	//����� [start, end] ֮��ȡֵ
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

