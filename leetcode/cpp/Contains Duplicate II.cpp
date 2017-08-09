// Contains Duplicate II.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

//��Ŀ������Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array 
//such that nums[i] = nums[j] and the difference between i and j is at most k.


//����һ��������������ûͨ��leetcode�����Ӷ�̫��
class so1
{
public:
	bool containsNearbyDuplicate(vector<int> &nums, int k)
	{
		//nums ��С
		int nums_size = nums.size();

		if (k <= 0 || nums_size == 1)
		{
			return false;
		}

		if (nums_size < k)
		{
			//k����ô�ͺ�k�޹أ������ı�������ͬ�������Ӷ�O(N*N)
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
			//���Ӷ�O(k*N)
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

			//����n-k�����εݼ�����������ͬ����
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


//��������ά��һ��Kά��vector��ûͨ��leetcode�����Ӷ�̫��
//��Ϊ���ҡ�����vector����O(N)
#include <map>
#include <vector>
#include <algorithm>

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
	//nums ��С
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

//���������ú���������룬���Ҷ���O(logN)
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


//�����ģ���map
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
