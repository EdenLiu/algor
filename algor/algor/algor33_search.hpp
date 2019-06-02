#ifndef _algor33_search_h
#define _algor33_search_h

/**
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
巧妙的结题思路：
二分法查找
问题点：二分法的中间点需不需要考虑奇数偶数的不同？
答：不需要

先找到旋转的点，如何寻找？
传入left和right下标
如果left的值小于right的值，直接返回0，因为不是乱序
如果不是，继续往下走
如果pivot> pivot +1 说明找到了旋转点返回pivot+1
否则，如果pivot < left  right = pivot - 1
if pivot > left left = pivot + 1


易错点：
while(left < right)
应该是 while(left <= right)
因为就算相等,后面再运行一次就会推出循环
**/
#include "algor_std.h"
namespace algor33
{
	using namespace std;

	class Solution {
	public:
		void Run()
		{
			vector<int> n{ 0,1,2,4,5,6,7 };
			search(n ,1);
		}
		int find_pivot_index(int left, int right , vector<int>& nums)
		{
			if (nums[left] < nums[right])
			{
				return 0;
			}

			int pivot = 0;
			while (left <= right)
			{
				pivot = (left + right) / 2;
				if (nums[pivot] > nums[pivot + 1])
				{
					return pivot + 1;
				}

				if (nums[pivot] < nums[left])
				{
					right = pivot - 1;
				}
				else
				{
					left = pivot + 1;
				}
			}

			return 0;
		}
		int search(vector<int>& nums, int target , int left, int right) {
			int pivot = -1;
			while (left <= right)
			{
				pivot = (left + right) / 2;
				if (nums[pivot] > target)
				{
					right = pivot - 1;
				}
				else if (nums[pivot] < target)
				{
					left = pivot + 1;
				}
				else
				{
					return pivot;
				}
			}

			return -1;
		}
		int search(vector<int>& nums, int target) {
			size_t max = nums.size();

			if (max == 0)
			{
				return -1;
			}
			else if (max == 1)
			{
				return nums[0] == target ? 0 : -1;
			}

			int pivot_index = find_pivot_index(0 , max - 1 ,nums);
			if (pivot_index == 0)
			{
				return search(nums, target, 0, max - 1);
			}
			if (target >= nums[0])
			{
				return search(nums ,target ,0 , pivot_index);
			}
			else
			{
				return search(nums, target, pivot_index, max - 1);
			}
		}
	};
}
#endif