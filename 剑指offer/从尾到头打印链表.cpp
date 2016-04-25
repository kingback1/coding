// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣

//��Ŀ������������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
//˼�룺��ջ������ȳ�

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

struct ListNode
{
	ListNode(int a) :m_nkey(a), m_pNext(NULL){};
	int m_nkey;
	ListNode *m_pNext;
};

struct print
{
	void operator() (int a)
	{
		cout << a << endl;
	}
};

void PrintReverseList(ListNode *head)
{
	if (!head)
	{
		return;
	}

	vector<int> nums;

	ListNode *p = head;
	while (p)
	{
		nums.push_back(p->m_nkey);
		p = p->m_pNext;
	}

	for (int i = nums.size() - 1; i >= 0; i--)
	{
		int b = nums[i];
		//����Ҫ����һ���������󣬲��ܵ���α����
		print  print;
		print(b);
	}

	//ֱ�ӵ���α����
	/*reverse(nums.begin(), nums.end());
	for_each(nums.begin(), nums.end(), print());*/
}


int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);

	a->m_pNext = b;
	b->m_pNext = c;
	c->m_pNext = d;

	PrintReverseList(a);

	delete a;
	delete b;
	delete c;
	delete d;

	system("pause");
	return 0;
}

