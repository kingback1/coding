// algorithm1.cpp : 定义控制台应用程序的入口点。

//题目：输入个链表的头结点，从尾到头反过来打印出每个结点的值。
//思想：用栈，后进先出

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
		//这里要定义一个函数对象，才能调用伪函数
		print  print;
		print(b);
	}

	//直接调用伪函数
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

