
#ifndef _algor2_addTwoNumbers_h
#define _algor2_addTwoNumbers_h


/*
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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