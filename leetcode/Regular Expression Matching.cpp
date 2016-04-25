// algorithm1.cpp : 定义控制台应用程序的入口点。
//

//https://leetcode.com/problems/regular-expression-matching/
//Regular Expression Matching
//
//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") → false
//isMatch("aa", "aa") → true
//isMatch("aaa", "aa") → false
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true


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

bool StringMatch(string s, string p)
{
	if (p.size() == 0)
	{
		return s.size() == 0;
	}

	if (p.size() == 1)
	{
		if (s.size() == 0)
			return false;
		else
		{
			return (s[0] == p[0] || p[0] == '.') && StringMatch(s.substr(1), p.substr(1));
		}	
	}

	if (p[1] != '*')
	{
		if (s.size() < 2)
			return false;
		else
		{
			return (s[0] == p[0] || p[0] == '.') && StringMatch(s.substr(1), p.substr(1));
		}
	}

	while ((s[0] == p[0] || p[0] == '.') && s.size())
	{
		if (StringMatch(s.substr(1), p))
		{
			return true;
		}

		s = s.substr(1);
		p = p.substr(2);
	}

	return StringMatch(s, p.substr(2));
}

int main()
{
	StringMatch("aa", ".*");


	system("pause");
	return 0;
}

