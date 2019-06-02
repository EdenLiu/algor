#ifndef _algor16_threeSumClosest_h
#define _algor16_threeSumClosest_h

/**
����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�

���磬�������� nums = [-1��2��1��-4], �� target = 1.

�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).
����Ľ���˼·��
1.Ѱ����ӽ�target�ĺ�sum���������Ϊ abs(sum-target)��ֵ��С
���������飬ʹ��˫ָ��l,n�����(value=sum-target) == 0 �ҵ��������target
���value > 0 ��--n;value < 0 ++l ʹ��ӽ�targetֵ����һֱ����abs��value������Сֵ�Լ���ʱ��sum
���շ���abs��value����Сֵʱ��sum

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