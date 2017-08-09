// algorithm1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

//leetcode 题目：判断链表是否有环。https://leetcode.com/problems/linked-list-cycle/?sort=hot


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//算法思想：用两个指针，一个指针走一步，另一个指针每次走两步，若遇到则说明有环，否则遇到了NULL，则说明没有环。
bool hasCycle(ListNode *head) 
{
	if (head == NULL)
		return false;
	if (head->next == NULL)
		return false;
	if (head->next == head)
		return true;

	ListNode *pSlow = head;
	ListNode *pFast = head;

	pSlow = pSlow->next;
	pFast = pFast->next->next;

	while (pSlow != pFast)
	{
		pSlow = pSlow->next;
		if (pSlow == NULL || pFast == NULL)
		{
			return false;
		}
		if (pFast->next == NULL)
		{
			return false;
		}
		else
		{
			pFast = pFast->next;
			if (pFast->next == NULL)
			{
				return false;
			}
			else
			{
				pFast = pFast->next;
			}
		}
	}

	if (pSlow == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}

}

//leetcode discuss解答
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;

		ListNode *fast = head;
		ListNode *slow = head;

		//注意这里是判断fast的next和fast next next，而没有判断slow的next
		while (fast->next && fast->next->next){
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
		}

		return false;
	}
};

int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p4;

	bool a = hasCycle(p1);

	system("pause");
	return 0;
}

