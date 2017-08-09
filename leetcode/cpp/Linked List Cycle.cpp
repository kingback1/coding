// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

//leetcode ��Ŀ���ж������Ƿ��л���https://leetcode.com/problems/linked-list-cycle/?sort=hot


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//�㷨˼�룺������ָ�룬һ��ָ����һ������һ��ָ��ÿ������������������˵���л�������������NULL����˵��û�л���
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

//leetcode discuss���
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;

		ListNode *fast = head;
		ListNode *slow = head;

		//ע���������ж�fast��next��fast next next����û���ж�slow��next
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

