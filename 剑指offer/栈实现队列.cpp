// algorithm1.cpp : 定义控制台应用程序的入口点。

//题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail 和deleteHead，
//分别完成在队列尾部插入结点和在队列头部删除结点的功能。

//算法思想：stack1 push, 然后压入stack2中，这样符合队列先进先出

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

