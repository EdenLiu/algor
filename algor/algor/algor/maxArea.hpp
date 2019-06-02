#ifndef _algor11_maxArea_h
#define _algor11_maxArea_h

/**
���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ���������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)���ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��

˵�����㲻����б�������� n ��ֵ����Ϊ 2��
ʾ��:

����: [1,8,6,2,5,4,8,3,7]
���: 49
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