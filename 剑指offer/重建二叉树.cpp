// algorithm1.cpp : �������̨Ӧ�ó������ڵ㡣

//��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
//���磺ǰ��������У� 1�� 2�� 4��7��3��5��6��8��������������У�4��7��2��1��5��3��8��6}���ؽ�����ͼ��ʾ�Ķ��������������ͷ��㡣

//�㷨˼�룺ǰ��ĵ�һ���ڵ���Ǹ��ڵ㣬Ȼ�����������ҵ����ڵ㣬��߾������������ұ߾�����������Ȼ��ݹ顣

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
		//û���ҵ�
		return NULL;
	}
		
	int leftlen = it - inorder.begin();
	int rightlen = inorder.end() - it - 1;

	if (leftlen > 0)
	{
		//�����õ���vector����ʱ����ע������vector�ĳ�ʼ����
		//begin(),end(),end()����������һλ��1�����������ڳ�ʼ����ʱ��Ҫ�Ѹ�ֵ��
		//���һ����ַ��1����Ȼ��������
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

