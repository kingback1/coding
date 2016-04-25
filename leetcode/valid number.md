leetcode :https://leetcode.com/problems/valid-number/

Validate if a given string is numeric.

Some examples :

"0" = > true

" 0.1 " = > true

"abc" = > false

"1 a" = > false

"2e10" = > true

![img](/img/leetcode/valid number.png)

```

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

int countPoint = 0;
int countE = 0;
int countS = 0;

void isOnePoint(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			countPoint++;
		}
		if (s[i] == 'e' || s[i] == 'E')
		{
			countE++;
		}
		if (s[i] == '+' || s[i] == '-')
		{
			countS++;
		}

	}
}

bool isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}
	return false;
}

bool isN(string s, int &n)
{
	if (s.size() == 0)
	{
		return true;
	}

	if (isDigit(s[0]))
	{
		n++;
		return isN(s.substr(1), n);
	}

	if (s[0] == '.' || s[0] == ' ')
		return isN(s.substr(1), n);
	if (s[0] == 'e')
	{
		if (s.size() == 1)
		{
			return false;
		}
		else if ((s[1] == '+' || s[1] == '-') && s.size() == 2)
			return false;
		else if ((s[1] == '+' || s[1] == '-') && s.size() > 2)
		{
			return isN(s.substr(2), n);
		}
		else
		{
			return isN(s.substr(1), n);
		}
		
	}

	return false;
}

bool isNumber(string s) 
{
	int i = 0;
	while (s[i] == ' ')
	{
		i++;
	}

	if (i==s.size())
	{
		return false;
	}

	if (countE > 1 || countPoint > 1)
		return false;
	
	int n = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i+1] == 'e')
		{
			return false;
		}

		return isN(s.substr(i+1), n) && n!=0;
	}

	if (s[i] == 'e')
	{
		return false;
	}

	if (s[i] == '.')
	{
		return isN(s.substr(i + 1), n) && n != 0;
	}

	return isN(s, n);
}

bool isNumber1(string s)
{
	int i = 0;

	//去除空格
	while (s[i] == ' ')
	{
		i++;
	}

	if (s[i] == '+' || s[i] == '-')
		i++;

	int n_p = 0, n_d = 0;
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
	{
		
		if (s[i] == '.')
		{
			n_p++;
		}
		else
		{
			n_d++;
		}
		i++;
	}
	
	if (n_p>1 || n_d<1)
	{
		return false;
	}
	
	if (s[i] == 'e')
	{
		i++;
		if (s[i] == '+' || s[i] == '-')
			i++;

		int d = 0;
		while ((s[i] >= '0' && s[i] <= '9'))
		{
			i++;
			d++;
		}
		if (d<1)
		{
			return false;
		}
	}

	while (s[i] == ' ')
	{
		i++;
	}

	return s[i] == 0;
}

//用有限状态机
class Solution {
public:

	bool isDigit(char ch)
	{
		if (ch >= '0' && ch <= '9')
		{
			return true;
		}
		return false;
	}

	bool state9(string s)
	{
		int i = 0;
		while (s[i] == ' ')
			i++;

		return s[i] == 0;
	}

	bool state8(string s)
	{
		if (s.size() == 0)
		{
			return true;
		}

		if (isDigit(s[0]))
		{
			return state8(s.substr(1));
		}

		return state9(s);
	}

	bool state7(string s)
	{
		if (s.size() == 0)
		{
			return false;
		}

		if (isDigit(s[0]))
		{
			return state8(s.substr(1));
		}

		return false;
	}

	bool state6(string s)
	{
		if (s.size() == 0)
		{
			return false;
		}

		if (s[0] == '+' || s[0] == '-')
		{
			return state7(s.substr(1));
		}

		if (isDigit(s[0]))
		{
			return state8(s.substr(1));
		}

		return false;
	}

	bool state5(string s)
	{
		if (s.size() == 0)
			return true;

		if (isDigit(s[0]))
		{
			return state5(s.substr(1));
		}

		if (s[0] == 'e')
		{
			return state6(s.substr(1));
		}

		if (s[0] == ' ')
		{
			return state9(s.substr(1));
		}

		return false;
	}

	bool state4(string s)
	{
		if (s.size() == 0)
			return false;

		if (isDigit(s[0]))
		{
			return state5(s.substr(1));
		}

		return false;
	}

	bool state3(string s)
	{
		if (s.size() == 0)
			return true;
		if (isDigit(s[0]))
		{
			return state3(s.substr(1));
		}

		if (s[0] == '.')
		{
			if (state4(s.substr(1)))
			{
				return true;
			}
			else
			{
				return state5(s.substr(1));
			}
		}

		if (s[0] == 'e')
		{
			return state6(s.substr(1));
		}

		if (s[0] == ' ')
		{
			return state9(s.substr(1));
		}

		return false;
	}

	bool state2(string s)
	{
		if (s.size() == 0)
		{
			return false;
		}

		if (s[0] == '.')
		{
			return state4(s.substr(1));
		}

		if (isDigit(s[0]))
		{
			return state3(s.substr(1));
		}

		return false;
	}

	bool state1(string s)
	{
		int i = 0;
		while (s[i] == ' ')
			i++;

		if (s[i] == '+' || s[i] == '-')
		{
			return state2(s.substr(i + 1));
		}

		if (isDigit(s[i]))
		{
			return state3(s.substr(i + 1));
		}

		if (s[i] == '.')
		{
			return state4(s.substr(i + 1));
		}

		return false;
	}

	bool isNumber(string s)
	{
		if (s.size() == 0)
		{
			return false;
		}

		return state1(s);
	}
};


bool isN(string s)
{
	int pos = 0;

	while (s[pos] == ' ')
	{
		pos++;
	}

	if (s[pos] == '+' || s[pos] == '-')
	{
		pos++;
	}

	int countN = 0;
	int countP = 0;
	while (isdigit(s[pos]) || s[pos]=='.')
	{
		if (isdigit(s[pos]))
		{
			countN++;
		}
		if (s[pos] == '.')
		{
			countP++;
		}

		pos++;
	}

	if (!countN || countP>1)
	{
		return false;
	}

	if (s[pos] == 'e')
	{
		pos++;
		int countN = 0;
		while (isdigit(s[pos]))
		{
			countN++;

			pos++;
		}
		if (!countN)
		{
			return false;
		}
	}

	while (s[pos] == ' ')
	{
		pos++;
	}

	return s[pos] == 0;
}

int main()
{
	Solution a;
	while (true)
	{
		string s;
		getline(cin, s);

		cout << a.isNumber(s) << endl;
	}
	
	system("pause");
	return 0;
}

```
