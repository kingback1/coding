// Next Permutation.cpp : �������̨Ӧ�ó������ڵ㡣
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
//1, 2, 3 �� 1, 3, 2
//3, 2, 1 �� 1, 2, 3
//1, 1, 5 �� 1, 5, 1
//
//
//
//��Ŀ��˼��
//
//����һ�����֣���������һ�����С�����Ѿ������������ˣ���ô�Ͱ�����������С�����С����ұ�������num������ԭ�ص������������Ӷ�����ڴ���䡣
//
//��Ŀ����˼�ǣ�123��ȫ���а��ֵ�˳��Ϊ��
//123 132 213 231 312 321//
//�����������ĳһ�����У�����������һ�����С��磺���룺213 �����231 �����룺321 �����123
//
//����˼·��
//
//����һ��ȫ���е���Ŀ����ͻȻ���뵽��֮ǰ���Ǹ���Permutation���⣬���Ǻ���һ��Ӧ���ǲ������߶�ʮһ�Ȱ������е����ж������Ȼ��������������������бȽϣ�Ȼ��˳�����һ�������ˡ�ת��һ������̫�鷳�ˣ�������Ŀ��Ҫ���˲��ܷ��������ڴ��ˣ����Բ����С�
//
//�������о��˱��˽�����㷨������������ӵġ���num��6 5 4 8 7 5 1��������
//
//��һ�����ȴӺ���ǰ�ң�8��7, 5, 1���ǽ������У��������ҵ�����������Ǹ��ط�����num[2]��num[3]����ʱ���Ǽ���index��ֵΪ3��
//
//�ڶ�������num[index]~num[len - 1]���ҵ���num[2]�����С������num[5]���±��ΪexchangeIndex��
//
//������������num[index - 1]��num[exchangeIndex]��ֵ��
//
//���Ĳ������µ���num[index]~num[len - 1]Ϊ�������С�

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
