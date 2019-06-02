#ifndef _algor15_threeSum_h
#define _algor15_threeSum_h

/**
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

巧妙的结题思路：
1.要三数之和为零，除非三个数都为0，三个数中至少要包含正数和负数
所以我们先把正数，负数分开
先做排序
再两边收缩

**/
#include "algor_std.h"
namespace algor15
{
	using namespace std;

	class Solution {
	public:
		void Run()
		{
			//[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
			vector<int> in{-1,0,1,2,-1,-4};
			vector<vector<int>> out;
			out = threeSum(in);
		}
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> result;
			size_t size = nums.size();
			if (size < 3)
			{
				return result;
			}
			
			sort(nums.begin(), nums.end());
			if (nums[0] > 0 || nums[size - 1] < 0)
			{
				return result;
			}
			
			int sum = 0;
			int value;
			for (size_t i = 0  ; i < size -2 && nums[i] <= 0; ++i)
			{
				sum = nums[i];
				size_t l = i + 1;
				size_t n = size - 1;
				if (i > 0 && nums[i] == nums[i - 1])
				{
					continue;
				}
				bool flag = false;
				while (l < n)
				{
					value = nums[l] + nums[n];
					if (value  == -sum)
					{
						if (l == i + 1 || n == size - 1)
						{
							result.push_back(vector<int> {sum, nums[l], nums[n]});
							++l;
							--n;
						}
						else if (nums[l] == nums[l-1])
						{
							++l;
						}
						else if (nums[n] == nums[n + 1])
						{
							--n;
						}
						else
						{
							result.push_back(vector<int> {sum, nums[l], nums[n]});
							++l;
							--n;
						}

					}
					else if (value > -sum)
					{
						--n;
					}
					else
					{
						++l;
					}
				}
			}
			return result;
		}
	};
}
#endif