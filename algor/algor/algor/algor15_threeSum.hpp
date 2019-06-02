#ifndef _algor15_threeSum_h
#define _algor15_threeSum_h

/**
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣

����, �������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ��
[
  [-1, 0, 1],
  [-1, -1, 2]
]

����Ľ���˼·��
1.Ҫ����֮��Ϊ�㣬������������Ϊ0��������������Ҫ���������͸���
���������Ȱ������������ֿ�
��������
����������

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