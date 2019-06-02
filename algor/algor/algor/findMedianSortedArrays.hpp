#ifndef _algor4_findMedianSortedArrays_h
#define _algor4_findMedianSortedArrays_h

/**
4. 寻找两个有序数组的中位数
	 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

	请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

	你可以假设 nums1 和 nums2 不会同时为空。

	示例 1:

	nums1 = [1, 3]
	nums2 = [2]

	则中位数是 2.0
	示例 2:

	nums1 = [1, 2]
	nums2 = [3, 4]

	则中位数是 (2 + 3)/2 = 2.5
**/

#include <vector>
namespace algor4
{
	using namespace std;
	
	class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			size_t size1 = nums1.size();
			size_t size2 = nums2.size();
			if (0 == size1)
			{
				return size2 % 2 ? nums2[size2 / 2] : ((double)nums2[size2 / 2] + (double)nums2[(size2 / 2) - 1]) / 2;
			}
			else if (size2 == 0)
			{
				return size1 % 2 ? nums1[size1 / 2] : ((double)nums1[size1 / 2] + (double)nums1[(size1 / 2) - 1]) / 2;
			}
			size_t i = 0, j = 0;
			bool foo = size1 > size2;
			size_t imax = foo ? size2 : size1;
			vector<int>& numA = foo ? nums2 : nums1;//项少的数组
			vector<int>& numB = foo ? nums1 : nums2;//项多的数组
			size_t numASize = numA.size();
			size_t numBSize = numB.size();
			size_t imin = 0;
			size_t halflen = (size1 + size2 + 1) / 2;
			double leftmax = 0;
			double rightmin = 0;
			bool foo1 = (size1 + size2) % 2 == 1;
			while (imin <= imax)
			{
				i = (imax + imin) / 2;
				j = halflen - i;

				if (i < imax && numB[j - 1] > numA[i])
				{
					imin = i + 1;
				}
				else if (i > imin && numA[i - 1] > numB[j])
				{
					imax = imax - 1;
				}
				else
				{
					if (i == 0)
					{
						leftmax = numB[j - 1];
					}
					else if (j == 0)
					{
						leftmax = numA[i - 1];
					}
					else
					{
						leftmax = numA[i - 1] > numB[j - 1] ? numA[i - 1] : numB[j - 1];
					}
					if (foo1)
					{
						return leftmax;
					}

					if (i >= numASize)
					{
						rightmin = numB[j];
					}
					else if (j >= numBSize)
					{
						rightmin = numA[i];
					}
					else
					{
						rightmin = numB[j] > numA[i] ? numA[i] : numB[j];
					}

					return (rightmin + leftmax) / 2;
				}
			}

			return 0;

		}
	};
}
#endif