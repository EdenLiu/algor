#ifndef _algor9_isPalindrome_h
#define _algor9_isPalindrome_h

/**
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

巧妙的结题思路：
我们如何知道反转数字的位数已经达到原始数字位数的一半？
将原始数字除以10，将翻转后的数字乘以10，当原始数字小于翻转数字时，说明已经处理了一半的字符

遇到奇数位的数字，可以将翻转后的数字除以10 去除中间位的影响

结尾为0并且不为0的数字不是回味
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