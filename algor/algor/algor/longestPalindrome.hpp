#ifndef _algor5_longestPalindrome_h
#define _algor5_longestPalindrome_h

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
#include <string>
namespace algor5
{
	using namespace std;
	class Solution {
	public:
		bool isPalindrome(char* str ,int len)
		{
			if (1 == len || 0 == len)
				return true;
			if (str[0] != str[len - 1])
				return false;
			return isPalindrome(str+1 , len - 2);

		}
		string longestPalindrome(string s) {
			int len = s.length();
			int curlen = 0;
			char* str = const_cast<char*>(s.c_str());;
			bool status = false;
			int maxlen = 0;
			int start = 0;

			for (size_t i = len; i > 0; --i)
			{
				if (i < maxlen)
				{
					break;
				}
				for (size_t j = 0; j < i; ++j)
				{
					curlen = i - j;
					if (curlen < maxlen)
					{ 
						break;
					}
					status = isPalindrome(str + j , curlen);
					if (status)//是回文
					{
						if (curlen > maxlen)
						{
							maxlen = curlen;
							start = j;
						}
					}
				}
			}

			return maxlen > 0 ? string(str + start, maxlen) : "";
		}
	};
}


#endif