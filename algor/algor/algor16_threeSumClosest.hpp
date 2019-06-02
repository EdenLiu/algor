#ifndef _algor16_threeSumClosest_h
#define _algor16_threeSumClosest_h

/**
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
巧妙的结题思路：
1.寻找最接近target的和sum，可以理解为 abs(sum-target)的值最小
先排序数组，使用双指针l,n，如果(value=sum-target) == 0 找到结果返回target
如果value > 0 ，--n;value < 0 ++l 使其接近target值，并一直保持abs（value）的最小值以及当时的sum
最终返回abs（value）最小值时的sum

**/
#include "algor_std.h"
namespace algor16
{
	using namespace std;

	class Solution {
	public:
		void Run()
		{
			//[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
			vector<int> in{ -1,2,1, - 4 };
			int out;
			out = threeSumClosest(in,1);
		}
		int threeSumClosest(vector<int>& nums, int target) {
			size_t size = nums.size();
			sort(nums.begin(), nums.end());
			int value = 0;
			size_t pos = UINT32_MAX;
			int result = 0;
			for (size_t i = 0; i < size - 2; i++)
			{
				int l = i + 1;
				int n = size - 1;
				if (i > 0 && nums[i] == nums[i - 1])
				{
					continue;
				}
				while (l < n)
				{
					value = nums[i] + nums[l] + nums[n] - target;
					if (value == 0)
					{
						return target;
					}
					else if (value > 0)
					{
						--n;
					}
					else
					{
						++l;
					}
					
					if (pos >= abs(value))
					{
						result = value + target;
						pos = abs(value);
					}
				}
				
			}
			return result;
		}
	};
}
#endif