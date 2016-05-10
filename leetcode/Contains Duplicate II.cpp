// Contains Duplicate II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

//题目描述：Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array 
//such that nums[i] = nums[j] and the difference between i and j is at most k.


//方法一，暴力遍历法，没通过leetcode，复杂度太高
class so1
{
public:
	bool containsNearbyDuplicate(vector<int> &nums, int k)
	{
		//nums 大小
		int nums_size = nums.size();

		if (k <= 0 || nums_size == 1)
		{
			return false;
		}

		if (nums_size < k)
		{
			//k大，那么就和k无关，暴力的遍历找相同数。复杂度O(N*N)
			for (int i = 0; i < nums_size - 1; i++)
			{
				int value = nums[i];
				for (int j = i + 1; j < nums_size; j++)
				{
					if (value == nums[j])
					{
						return true;
					}
				}
			}
		}
		else
		{
			//复杂度O(k*N)
			for (int i = 0; i < nums_size - k; i++)
			{
				int value = nums[i];
				for (int j = 1; j <= k; j++)
				{
					if (value == nums[i + 1])
					{
						return true;
					}
				}
			}

			//到达n-k后，依次递减遍历查找相同数。
			for (int i = nums_size - k; i < nums_size - 1; i++)
			{
				int value = nums[i];
				for (int j = i + 1; j < nums_size; j++)
				{
					if (value == nums[j])
					{
						return true;
					}
				}
			}
		}

		return false;
	}

};


//方法二：维护一个K维的vector，没通过leetcode，复杂度太高
//因为查找、遍历vector都是O(N)
#include <map>
#include <vector>
#include <algorithm>

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
	//nums 大小
	int nums_size = nums.size();

	if (k <= 0 || nums_size == 1)
	{
		return false;
	}

	if (nums_size <= k)
	{
		map<int, int > m;
		for (int i = 0; i < nums_size; i++)
		{
			if (m.find(nums[i]) != m.end())
			{
				return true;
			}
			else
			{
				m[nums[i]] = 1;
			}
		}

		return false;
	}
	else
	{
		vector<int> v(1);
		v[0] = nums[0];
		for (int i = 1; i < k; i++)
		{
			if (find(v.begin(), v.end(), nums[i]) == v.end())
			{
				v.push_back(nums[i]);
			}
			else
			{
				return true;
			}
		}

		for (int i = k; i < nums_size; i++)
		{
			if (find(v.begin(), v.end(), nums[i]) == v.end())
			{
				v[i%k] = nums[i];
			}
			else
			{
				return true;
			}
		}

		return false;
	}
}

//方法三：用红黑树，插入，查找都是O(logN)
#include <set>

bool containsNearbyDuplicate(vector<int> &nums, int k)
{

	int nums_size = nums.size();

	if (k <= 0 || nums_size == 1)
	{
		return false;
	}

	set<int> s;
	if (nums_size <= k) k = nums_size - 1; 

	for (int i = 0; i < nums_size; i++)
	{
		if (i > k)
			s.erase(nums[i - k - 1]);
		if (s.find(nums[i]) != s.end())
			return true;
		else
			s.insert(nums[i]);
	}

	return false;
	
}


//方法四：用map
#include <map>
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
	
	int nums_size = nums.size();

	if (k <= 0 || nums_size == 1)
	{
		return false;
	}

	map<int, int> m;
	for (int i = 0; i < nums_size; i++)
	{
		if (m.find(nums[i]) == m.end())
		{
			m[nums[i]] = i;
		}
		else
		{
			if (i - m[nums[i]] <= k)
			{
				return true;
			}
			else
			{
				m[nums[i]] = i;
			}
		}
	}

	return false;

}

int main()
{
	vector<int> nums = { 1, 9, 3, 4, 5, 6, 7, 8,  9 };
		
	clock_t begin = clock();

	bool a = containsNearbyDuplicate(nums, 3);

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << elapsed_secs << endl;

	system("pause");
	return 0;
}
