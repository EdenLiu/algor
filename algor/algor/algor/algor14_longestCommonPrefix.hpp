#ifndef _algor14_longestCommonPrefix_h
#define _algor15_longestCommonPrefix_h

/**
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

巧妙的结题思路：
1.在判断时，需要按短的那个字符串结束
**/
#include "algor_std.h"
namespace algor14
{
	using namespace std;

	class Solution {
	public:
		string getlongestCommonPrefix(const string& str1, const string& str2)
		{
			size_t i;
			for (i = 0; i < str1.size(); i++)
			{
				if (str1[i] != str2[i])
				{
					break;
				}
			}

			return str1.substr(0,i);
		}
		string longestCommonPrefix(vector<string>& strs) {
			if (0 == strs.size())
			{
				return "";
			}
			//垂直扫描
			const string& result = strs[0];
			for (size_t i = 0; i < result.size(); i++)
			{
				char c = result[i];
				for (size_t j = 1; j < strs.size(); j++)
				{
					const string& tmp = strs[j];
					if (tmp.size() == i || tmp[i] != c)
					{
						return result.substr(0, i);
					}
				}
			}

			return result;
			//水平扫描
			/*for (size_t i = 1; i < strs.size(); i++)
			{
				result = getlongestCommonPrefix(strs[i], result);
				if (result.empty())
				{
					return "";
				}
			}

			return result;*/
		}
	};
}
#endif