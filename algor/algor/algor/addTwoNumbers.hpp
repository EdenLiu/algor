
#ifndef _algor2_addTwoNumbers_h
#define _algor2_addTwoNumbers_h


/*
2. �������
�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
*/
namespace algor2
{
/**
 * Definition for singly-linked list.
  */
	 struct ListNode {
		 int val;
		 ListNode *next;
		 ListNode(int x) : val(x), next(nullptr) {}
	 };

	class Solution {
	public:
		ListNode* getNode(int a, int b)
		{

		}
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

			ListNode* l3 = nullptr;
			ListNode* l4 = new ListNode(0);
			ListNode* ret = l4;
			int val = 0;
			int a = 0, b = 0, c = 0;
			while (l1 != nullptr || l2 != nullptr)
			{
				a = (l1) ? l1->val : 0;
				b = (l2) ? l2->val : 0;
				val = a + b + c;
				l3 = new ListNode(val % 10);
				c = val / 10;
				if (l1)
				{
					l1 = l1->next;
				}
				if (l2)
				{
					l2 = l2->next;
				}
				l4->next = l3;
				l4 = l3;
			}

			if (c > 0)
			{
				l4->next = new ListNode(c);
			}
			return ret->next;
		}
	};
}

#endif