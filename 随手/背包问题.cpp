// algorithm1.cpp : 定义控制台应用程序的入口点。
//

//背包问题：http://www.hawstein.com/posts/dp-knapsack.html

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

const int maxn = 1000;
const int maxc = 100000;

int V[maxn], W[maxn];
int d[maxn][maxc];

void solve(int num, int cap)
{
	for (int i = 0; i <= num; i++)
	{		
		for (int j = 0; j <= cap; j++)
		{

			if (i>0 && j >= V[i-1])
			{
				d[i][j] = max(d[i - 1][j], d[i - 1][j - V[i-1]] + W[i-1]);
			}

			//当前物品V[i - 1]的重量大于j，不选择
			if (i>0 && j < V[i - 1])
			{
				d[i][j] = d[i - 1][j];
			}
		}
	}
	
	cout << d[num][cap];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {

}

int main()
{
	int K;
	cin >> K;
	while (K)
	{
		int N = 0, M = 0;
		cin >> N >> M;

		//for (int i = 0; i < maxn; i++)
		//{
		//	for (int j = 0; j < maxc; j++)
		//	{
		//		d[i][j] = 0;
		//	}
		//}
		
		for (int i = 0; i < N; i++)
		{
			cin >> V[i];
			cin >> W[i];
		}

		solve(N, M);
		cout << "\r\n";

		K--;
	}
	
	system("pause");
	return 0;
}

