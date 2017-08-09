// Next Permutation.cpp : 定义控制台应用程序的入口点。
//

//Next Permutation
//
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1
//
//
//
//题目意思：
//
//给定一组数字，求他的下一个排列。如果已经是最大的排列了，那么就把他调整成最小的排列。而且必须是在num数组中原地调整，不能增加额外的内存分配。
//
//题目的意思是：123的全排列按字典顺序为：
//123 132 213 231 312 321//
//如果输入其中某一个序列，返回它的下一个序列。如：输入：213 输出：231 ；输入：321 输出：123
//
//解题思路：
//
//又是一道全排列的题目，我突然就想到了之前的那个求Permutation的题，于是乎第一反应就是不管三七二十一先把你所有的排列都求出来然后存起来，跟给定的排列比较，然后按顺序的下一个就是了。转念一想这样太麻烦了，况且题目还要求了不能分配额外的内存了，所以不可行。
//
//在网上研究了别人解题的算法，大概是这样子的。以num（6 5 4 8 7 5 1）举例：
//
//第一步：先从后往前找，8，7, 5, 1都是降序排列，我们先找到出现升序的那个地方。即num[2]和num[3]，此时我们假设index的值为3。
//
//第二步：在num[index]~num[len - 1]中找到比num[2]大的最小数。即num[5]。下标记为exchangeIndex。
//
//第三步：交换num[index - 1]和num[exchangeIndex]的值。
//
//第四步：重新调整num[index]~num[len - 1]为升序序列。

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void nextnum(vector<int> &num)
{
	if (num.size() < 2) return;

	int cur = 0;
	int sea = num.size() - 2;

	while (num[sea] > num[sea + 1] && sea >= 0)
	{
		sea--;
	}

	if (sea < 0)
	{
		sort(num.begin(), num.end());
		return;
	}

	int be = sea + 1;
	while (be < num.size() && num[sea] < num[be])
	{
		be++;
	}

	be--;

	swap(num[be], num[sea]);
	sort(num.begin() + sea + 1, num.end());

}

void nextPermutation(vector<int> &nums)
{
	int n = nums.size();

	if (n<2)
	{
		return;
	}

	int index = -1;

	for (int i = n-1; i >0; i--)
	{
		if (nums[i - 1] < nums[i])
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		reverse(nums.begin(), nums.end());
		return;
	}

	int j = n-1;
	for (int i = index; i < n; i++)
	{
		if (nums[i] > nums[index - 1])
		{
			j = i;
		}
	}

	swap(nums[index - 1], nums[j]);
	reverse(nums.begin() + index, nums.end());
	return;
}

int main(int argc, char* argv[])
{

	vector<int> a = { 5, 1, 1 };
	vector<int> b = { 5, 1, 1 };

	nextPermutation(a);
	nextnum(b);
	int c = 2;

	return 0;
}
