#ifndef _algor5_longestPalindrome_h
#define _algor5_longestPalindrome_h

/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�
ʾ�� 2��

����: "cbbd"
���: "bb"
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
					if (status)//�ǻ���
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