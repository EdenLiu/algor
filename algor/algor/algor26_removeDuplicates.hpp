#ifndef _algor26_removeDuplicates_h
#define _algor26_removeDuplicates_h

/**
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

ʾ�� 1:

�������� nums = [1,1,2],

����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ�� 2:

���� nums = [0,0,1,1,1,2,2,3,3,4],

����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
˵��:

Ϊʲô������ֵ��������������Ĵ���������?

��ע�⣬�����������ԡ����á���ʽ���ݵģ�����ζ���ں������޸�����������ڵ������ǿɼ��ġ�

����������ڲ���������:

// nums ���ԡ����á���ʽ���ݵġ�Ҳ����˵������ʵ�����κο���
int len = removeDuplicates(nums);

// �ں������޸�����������ڵ������ǿɼ��ġ�
// ������ĺ������صĳ���, �����ӡ�������иó��ȷ�Χ�ڵ�����Ԫ�ء�
for (int i = 0; i < len; i++) {
	print(nums[i]);
}
����Ľ���˼·��
˫ָ��s����ָ�룬������� i�ǿ�ָ�룬����ȫ��

**/
#include "algor_std.h"
namespace algor26
{
	using namespace std;

	class Solution {
	public:
		void Run()
		{
			vector<int> n{ 1,1,1,2,2,3,3 };
			removeDuplicates(n);
		}
		int removeDuplicates(vector<int>& nums) {
			if (0 == nums.size())
			{
				return 0;
			}

			size_t s = 0, f = 1;
			for (size_t i = 1; i < nums.size(); i++)
			{
				if (nums[s] != nums[i])
				{
					s++;
					nums[s] = nums[i];
				}
				
			}

			return s + 1;
		}

		//��һ����
		/*�������erase���ͱ�����.size()�������жϣ���Ȼ�ͻ�Խ����������Ҳ�����++i*/
		/*for (size_t i = 1; i < nums.size(); )
		{
			if (nums[i - 1] == nums[i])
			{
				nums.erase(nums.begin() + i);
				continue;
			}
			i++;
		}

		return nums.size();*/
	};
}
#endif