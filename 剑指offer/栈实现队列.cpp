// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣

//��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail ��deleteHead��
//�ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�

//�㷨˼�룺stack1 push, Ȼ��ѹ��stack2�У��������϶����Ƚ��ȳ�

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

template <typename T> class CQueue
{
public:
	CQueue();
	~CQueue();

	void appendTail(const T& node)
	{
		stack1.push(node);
	}

	T deleteHead()
	{
		if (stack2.size() != 0)
		{
			return stack2.pop();
		}
		else
		{
			for (int i = 0; i < stack1.size(); i++)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		T head = stack2.top();
		stack2.pop();

		return head;
	}

private:
	stack<T> stack1;
	stack<T> stack2;
};


int main()
{



	system("pause");
	return 0;
}

