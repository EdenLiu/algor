#ifndef _algor4_findMedianSortedArrays_h
#define _algor4_findMedianSortedArrays_h

/**
4. Ѱ�����������������λ��
	 ����������СΪ m �� n ���������� nums1 �� nums2��

	�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��

	����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�

	ʾ�� 1:

	nums1 = [1, 3]
	nums2 = [2]

	����λ���� 2.0
	ʾ�� 2:

	nums1 = [1, 2]
	nums2 = [3, 4]

	����λ���� (2 + 3)/2 = 2.5
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
			vector<int>& numA = foo ? nums2 : nums1;//���ٵ�����
			vector<int>& numB = foo ? nums1 : nums2;//��������
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