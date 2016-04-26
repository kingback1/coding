// algorithm1.cpp : 定义控制台应用程序的入口点。

//题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如：前序遍历序列｛ 1， 2， 4，7，3，5，6，8｝和中序遍历序列｛4，7，2，1，5，3，8，6}，重建出下图所示的二叉树并输出它的头结点。

//算法思想：前序的第一个节点就是根节点，然后在中序中找到根节点，左边就是左子树，右边就是右子树，然后递归。

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

struct BinaryTreeNode
{
	BinaryTreeNode(int a) :m_nValue(a), m_pLeft(NULL), m_pRight(NULL){};
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode* Construct(const vector<int> &preorder, const vector<int> &inorder)
{
	int prelen = preorder.size();
	int inlen = inorder.size();

	if (prelen!=inlen || prelen == 0)
	{
		return NULL;
	}

	int rootValue = preorder[0];
	BinaryTreeNode *root = new BinaryTreeNode(rootValue);
	root->m_pLeft = NULL;
	root->m_pRight = NULL;

	auto it = find(inorder.begin(),inorder.end(), rootValue);
	if (it == inorder.end())
	{
		//没有找到
		return NULL;
	}
		
	int leftlen = it - inorder.begin();
	int rightlen = inorder.end() - it - 1;

	if (leftlen > 0)
	{
		//这里用的是vector的临时对象，注意这里vector的初始化。
		//begin(),end(),end()是数组的最后一位加1，所以我们在初始化的时候要把赋值的
		//最后一个地址加1，不然长度有误
		root->m_pLeft = Construct(vector<int>(preorder.begin() + 1, preorder.begin() + leftlen + 1),
			                      vector<int>(inorder.begin(), inorder.begin() + leftlen));
	}

	if (rightlen >0)
	{
		root->m_pRight = Construct(vector<int>(preorder.begin() + 1 + leftlen, preorder.end()),
			                       vector<int>(inorder.begin() + 1 + leftlen, inorder.end()));
	}

	return root;
}

int main()
{
	vector<int> a = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> b = { 4, 7, 2, 1, 5, 3, 8, 6 };

	BinaryTreeNode *p = Construct(a, b);

	system("pause");
	return 0;
}

