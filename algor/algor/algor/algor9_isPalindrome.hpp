#ifndef _algor9_isPalindrome_h
#define _algor9_isPalindrome_h

/**
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

ʾ�� 1:

����: 121
���: true
ʾ�� 2:

����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
ʾ�� 3:

����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������

����Ľ���˼·��
�������֪����ת���ֵ�λ���Ѿ��ﵽԭʼ����λ����һ�룿
��ԭʼ���ֳ���10������ת������ֳ���10����ԭʼ����С�ڷ�ת����ʱ��˵���Ѿ�������һ����ַ�

��������λ�����֣����Խ���ת������ֳ���10 ȥ���м�λ��Ӱ��

��βΪ0���Ҳ�Ϊ0�����ֲ��ǻ�ζ
**/
#include <vector>
namespace algor7
{
	using namespace std;

	class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0)
			{
				return false;
			}

			int sum = 0;

			while (x > sum)
			{
				sum *= 10;
				sum += x % 10;
				x /= 10;
			}

			return sum == x || x == sum / 10;
		}

		
		/*if (x < 0)
		{
			return false;
		}
		int sum = 0;
		vector<int> num;
		while (x != 0)
		{
			num.push_back(x % 10);
			x /= 10;
		}
		size_t size = num.size();
		for (size_t i = 0; i < (size / 2); i++)
		{
			if (num[i] != num[size - i - 1])
			{
				return false;
			}
		}
		return true;*/
	};
}
#endif