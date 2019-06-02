#ifndef _algor14_longestCommonPrefix_h
#define _algor15_longestCommonPrefix_h

/**
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z ��

����Ľ���˼·��
1.���ж�ʱ����Ҫ���̵��Ǹ��ַ�������
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
			//��ֱɨ��
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
			//ˮƽɨ��
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