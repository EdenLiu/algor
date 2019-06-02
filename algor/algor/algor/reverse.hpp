#ifndef _algor7_reverse_h
#define _algor7_reverse_h

/**
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

ʾ�� 1:

����: 123
���: 321
 ʾ�� 2:

����: -123
���: -321
ʾ�� 3:

����: 120
���: 21
ע��:

�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ[-2^31,2^31-1]����
����������裬�����ת�����������ô�ͷ��� 0��
**/

namespace algor7
{
	using namespace std;

	class Solution {
	public:
		int reverse(int x) {
			int sum = 0;
			int remainder = 0;

			while (x != 0)
			{
				remainder = x % 10;
				x /= 10;
				
				if ((sum > 214748364) || (sum == 214748364 && remainder > 7)
					|| (sum < -214748364) || (sum == -214748364 && remainder < -8))
				{
					return 0;
				}
				sum *= 10;
				sum += remainder;
			}

			return sum;
		}

		/*bool isminus = x < 0;
		int sum = 0;
		int remainder = 0;

		while (x != 0)
		{
			remainder = x % 10;
			x /= 10;
			sum *= 10;
			if (remainder < 0)
			{
				remainder *= -1;
			}
			sum += remainder;
			if (sum >= 214748364)
			{
				if (sum == 214748364)
				{
					remainder = x % 10;
					if (remainder < 0)
					{
						remainder *= -1;
					}
					if ((isminus ? remainder > 8: isminus > 7))
					{
						return 0;
					}
				}
				else
				{
					if (x != 0)
					{
						return 0;
					}
					else
					{
						break;
					}
				}


			}

		}

		if (isminus)
		{
			sum *= -1;
		}
		return sum;*/
	};
}
#endif