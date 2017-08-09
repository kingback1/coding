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

//��Ŀ��Say you have an array for which the ith element is the price of a given stock on day i.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock), 
//design an algorithm to find the maximum profit.

//��Ŀ�����Ĳ��Ǻ��������һ��discuss����˵�ĺ���� https://leetcode.com/discuss/71433/please-explain-the-problem-more-clearly
//If you were only permitted to complete at most one buy and at most one sell during the whole period of days, design an algorithm such that your profit, i.e., sell price minus buy price, is maximized.Note that you can only not sell a stock before you buy one.
//
//For example :
//
//[1, 2, 3, 4] == > returns 3 (buy at 1 and sell at 4)
//
//[4, 3, 2, 1] == > returns 0 (don't buy)
//
//[4, 10, 25, 2, 10] == > returns 21 (buy at 4 and sell at 25)


// brute force ��������һ����AC���˵�
int maxProfit(vector<int>& prices) 
{
	int n = prices.size();

	if (n < 2)
		return 0;

	int maxp = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (prices[j] > prices[i])
			{
				maxp = max(maxp, prices[j] - prices[i]);
			}
		}
	}

	return maxp;
}

//discuss����Ľ�𣬺����һ�α����Ϳ��ԡ�
int maxProfit1(vector<int>& prices) 
{
	int minN = INT_MAX;
	int maxP = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		minN = min(prices[i], minN);
		maxP = max(maxP, prices[i] - minN);
	}

	return maxP;
}

int main()
{
	vector<int> v = { 4, 10, 25, 2, 10 };

	int a = maxProfit(v);

	system("pause");
	return 0;
}

