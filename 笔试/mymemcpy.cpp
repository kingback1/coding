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
#include <assert.h>

using namespace std;

void *mymemcpy(void *dst, const void *src, size_t num)
{
	assert((dst != NULL) && (src != NULL));

	if (dst >= (char *)src + num || src> (char *)dst + num);
	char *psrc = (char *)src;//byte 既为unsigned char类型  
	char *pdst = (char *)dst;
	while (num-->0)*pdst++ = *psrc++;
	return dst;
}

void *memcpy1(void *dst, const void *src, size_t len)
{
	if (NULL == dst || NULL == src){
		return NULL;
	}

	void *ret = dst;

	if (dst <= src || (char *)dst >= (char *)src + len){
		//没有内存重叠，从低地址开始复制
		while (len--){
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else{
		//有内存重叠，从高地址开始复制
		src = (char *)src + len - 1;
		dst = (char *)dst + len - 1;
		while (len--){
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
	return ret;
}

void *kingmemcpy(void *dst, void *src, int n)
{
	assert(dst != NULL && src != NULL);
	
	char *pdst = (char*)dst;
	char *psrc = (char*)src;

	//没有内存重叠
	if (pdst <= psrc || pdst > psrc + n)
	{
		while (n)
		{
			*pdst = *psrc;
			psrc++;
			pdst++;
			n--;
		}
	}
	else
	{
		pdst = pdst + n - 1;
		psrc = psrc + n - 1;

		while (n)
		{
			*pdst = *psrc;
			psrc--;
			pdst--;
			n--;
		}
	}

	return pdst;
}

void * mymemcpy2(void *dest, void *src, size_t count)
{
	if (dest == NULL || src == NULL)
		return NULL;
	char *pdest = static_cast <char*>(dest);
	char *psrc = static_cast <char*>(src);
	int n = count;

	if (pdest > psrc && pdest < psrc + count)
	{
		for (size_t i = n - 1; i != -1; --i)
		{
			pdest[i] = psrc[i];
		}
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			pdest[i] = psrc[i];
		}
	}

	return dest;
}

void *Memcpy(void *dst, const void *src, size_t size)
{
	char *psrc;
	char *pdst;

	if (NULL == dst || NULL == src)
	{
		return NULL;
	}

	if ((src < dst) && (char *)src + size >(char *)dst) // 自后向前拷贝
	{
		psrc = (char *)src + size - 1;
		pdst = (char *)dst + size - 1;
		while (size--)
		{
			*pdst-- = *psrc--;
		}
	}
	else
	{
		psrc = (char *)src;
		pdst = (char *)dst;
		while (size--)
		{
			*pdst++ = *psrc++;
		}
	}

	return dst;
}

void *Memcpy2(void *dst, const void *src, size_t size)
{
	if (dst == NULL || src == NULL)
		return NULL;
	char *pdest = static_cast <char*>(dst);
	const char *psrc = static_cast <const char*>(src);
	int n = size;
	if (pdest > psrc && pdest < psrc + size)
	{
		for (size_t i = n - 1; i != -1; --i)
		{
			pdest[i] = psrc[i];//高到低
		}
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			pdest[i] = psrc[i];//低到高
		}
	}
	return dst;
}

int main()
{

	char buf[100] = "abcdefghijk";
	char de[100];

	short i = 0;
	i = i + 1;

	kingmemcpy(buf + 2, buf, 5);
	printf("%s\n", buf + 2);
	//cout << endl;
	//memcpy1(buf + 2, buf, 5);
	//printf("%s\n", buf + 2);
	//cout << endl;
	//mymemcpy2(buf + 2, buf, 5);
	//printf("%s\n", buf + 2);
	//cout << endl;
	//Memcpy(buf + 2, buf, 5);
	//printf("%s\n", buf + 2);
	//cout << endl;
	//Memcpy2(buf + 2, buf, 5);
	//printf("%s\n", buf + 2);

	system("pause");
	return 0;
}


