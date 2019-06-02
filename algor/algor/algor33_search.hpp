#ifndef _algor33_search_h
#define _algor33_search_h

/**
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��

����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��

����Լ��������в������ظ���Ԫ�ء�

����㷨ʱ�临�Ӷȱ����� O(log n) ����

ʾ�� 1:

����: nums = [4,5,6,7,0,1,2], target = 0
���: 4
ʾ�� 2:

����: nums = [4,5,6,7,0,1,2], target = 3
���: -1
����Ľ���˼·��
���ַ�����
����㣺���ַ����м���費��Ҫ��������ż���Ĳ�ͬ��
�𣺲���Ҫ

���ҵ���ת�ĵ㣬���Ѱ�ң�
����left��right�±�
���left��ֵС��right��ֵ��ֱ�ӷ���0����Ϊ��������
������ǣ�����������
���pivot> pivot +1 ˵���ҵ�����ת�㷵��pivot+1
�������pivot < left  right = pivot - 1
if pivot > left left = pivot + 1


�״�㣺
while(left < right)
Ӧ���� while(left <= right)
��Ϊ�������,����������һ�ξͻ��Ƴ�ѭ��
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