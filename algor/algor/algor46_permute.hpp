#ifndef _algor46_permute_h
#define _algor46_permute_h

/**
����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
����Ľ���˼·��
ʹ�û����㷨��(�����������)

**/
#include "algor_std.h"
namespace algor46
{
	using namespace std;

	class Solution {
	public:
		void Run()
		{
			vector<int> n{ 0,1,2,4,5,6,7 };
			permute(n);
		}

		void per(vector<int>& nums, size_t k, vector<vector<int>>& result)
		{
			if (k == nums.size())
			{
				result.push_back(nums);
				return;
			}

			for (size_t i = k; i < nums.size(); i++)
			{
				swap(nums[k],nums[i]);
				per(nums, k + 1, result);
				swap(nums[i], nums[k]);
			}
		}

		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> result;
			
			per(nums, 0,result);

			return result;
		}
	};
}
#endif