#ifndef _algor11_maxArea_h
#define _algor11_maxArea_h

/**
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
**/
#include <vector>
namespace algor8
{
	using namespace std;

	class Solution {
	public:
		int maxArea(vector<int>& height) {
			int iArea = 0;
			int curArea = 0;
			for (size_t i = 1; i < height.size(); i++)
			{
				for (size_t j = 0; j < i; j++)
				{
					curArea = (i - j)*(height[i] > height[j] ? height[j] : height[i]);
					iArea = iArea > curArea ? iArea : curArea;
				}
			}

			return iArea;
		}
	};
}

#endif