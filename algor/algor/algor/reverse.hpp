#ifndef _algor7_reverse_h
#define _algor7_reverse_h

/**
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为[-2^31,2^31-1]。请
根据这个假设，如果反转后整数溢出那么就返回 0。
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