#ifndef _algor20_isValidt_h
#define _algor20_isValidt_h

/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
巧妙的结题思路：
1.利用栈，遇到(，{，[的时候入栈，当遇到非(，{，[的时候，取最外面入栈的字符，判断当前字符是否匹配


**/
#include "algor_std.h"
namespace algor20
{
	using namespace std;

	class Solution {
	public:
		void Run()
		{
			string s("{[]}");
			bool out;
			out = isValid(s);
		}
		bool isValid(string s) {
			bool flag = true;
			unsigned char c;
			const unsigned char sym = '(';
			const unsigned char sym1 = '[';
			const unsigned char sym2 = '{';
			vector<unsigned char> syms;
			map<unsigned char , unsigned char> n;
			n[sym] = ')';
			n[sym1] = ']';
			n[sym2] = '}';
			for (size_t i = 0 ; i < s.size() ; ++i)
			{
				c = s[i];
				if (c == sym || c == sym1 || c == sym2)
				{
					syms.push_back(c);
				}
				else
				{
					if (syms.size() > 0 && c == n[syms.back()])
					{
						syms.pop_back();
					}
					else
					{
						flag = false;
						break;
					}
				}
			}

			return syms.size() ? false : flag;
		}
	};
}
#endif