#ifndef _algor20_isValidt_h
#define _algor20_isValidt_h

/**
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:

����: "()"
���: true
ʾ�� 2:

����: "()[]{}"
���: true
ʾ�� 3:

����: "(]"
���: false
ʾ�� 4:

����: "([)]"
���: false
ʾ�� 5:

����: "{[]}"
���: true
����Ľ���˼·��
1.����ջ������(��{��[��ʱ����ջ����������(��{��[��ʱ��ȡ��������ջ���ַ����жϵ�ǰ�ַ��Ƿ�ƥ��


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