#ifndef _algor43_multiply_h
#define _algor43_multiply_h

/**
�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��

ʾ�� 1:

����: num1 = "2", num2 = "3"
���: "6"
ʾ�� 2:

����: num1 = "123", num2 = "456"
���: "56088"
˵����

num1 �� num2 �ĳ���С��110��
num1 �� num2 ֻ�������� 0-9��
num1 �� num2 �������㿪ͷ������������ 0 ����
����Ľ���˼·��
�ʼ�õ���ģ������ķ�����һλһλ��ȥ���ټӣ����Ч�ʲ�����8%

���԰ѽ�������һ������������С���������ַ����������


**/
#include "algor_std.h"
namespace algor43
{
	using namespace std;

	class Solution {
	public:
		void Run()
		{
			string n("12");
			string n1("923");
			multiply(n ,n1);
		}
		string add(const string& num1, const string& num2)
		{
			string result;
			const string& longstring = num1.size() > num2.size() ? num1 : num2;
			const string& shortstring = num1.size() > num2.size() ? num2 : num1;
			size_t i = shortstring.size();
			size_t j = longstring.size();
			unsigned char prevalue = 0;
			unsigned char sum = 0;
			unsigned char val = 0;
			unsigned char ten = 10;
			while (i > 0)
			{
				sum = shortstring[i - 1] - '0' + longstring[j - 1] - '0' + prevalue;
				val = sum % ten;
				prevalue = sum / ten;
				result.insert(result.begin(),(val + '0'));
				--i;
				--j;
			}
			
			while (j > 0)
			{
				sum = longstring[j - 1] - '0' + prevalue;
				val = sum % 10;
				prevalue = sum / 10;
				result.insert(result.begin(), (val + '0'));
				--j;
			}

			if (prevalue != 0)
			{
				result.insert(result.begin(), (prevalue + '0'));
			}

			return result;
		}

		string multiply(string num1, string num2) {
			if (num1 == "0" || num2 == "0")
			{
				return "0";
			}

			const string& longstring = num1.size() > num2.size() ? num1 : num2;
			const string& shortstring = num1.size() > num2.size() ? num2 : num1;
			string result("0");
			unsigned char prevalue = 0;
			unsigned char multiply = 0;
			unsigned char val = 0;
			unsigned char ten = 10;
			for (size_t i = shortstring.size(); i > 0; --i)
			{
				size_t j = longstring.size();
				string tmp;
				while (j > 0)
				{
					multiply = ((shortstring[i - 1] - '0') * (longstring[j - 1] - '0')) + prevalue;
					val = multiply % ten;
					prevalue = multiply / ten;
					tmp.insert(tmp.begin(), (val + '0'));
					--j;
				}

				if (prevalue != 0)
				{
					tmp.insert(tmp.begin(), (prevalue + '0'));
					prevalue = 0;
				}
				tmp.append(shortstring.size() - i, '0');
				result = add(tmp , result);
			}

			return result;
			
		}
	};
}
#endif