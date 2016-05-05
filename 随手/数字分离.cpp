// algorithm1.cpp : 定义控制台应用程序的入口点。
//

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

int main()
{
	int n = 123456;
	char str[10];
	
	//整型数转为字符串，sprintf返回的是字符串长度，不包括额外的空串长度。str也是有效长度。
	int len = sprintf_s(str, "%d", n);

	//n转化为了string，这时就可以用string分离数字，避免取余运算去分离
	string s(str);

	//C库整型数转字符串，str包括了无效空字符，所以长度是10
	//_itoa_s(n, str, 10);

	char ss[] = "0123";
	int nn = 0;

	//字符串转整型数，整型数会去掉在高位的0
	sscanf_s(ss, "%d", &nn);

	//C库字符串转整型数，会去掉在高位的0
	nn = atoi(ss);

	system("pause");
	return 0;
}

