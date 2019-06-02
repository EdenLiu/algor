#ifndef _algor21_mergeTwoLists_h
#define _algor21_mergeTwoLists_h

/**
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
巧妙的结题思路：


**/
#include "algor_std.h"
namespace algor21
{
	using namespace std;

	/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	class Solution {
	public:
		void Run()
		{
			ListNode* l1 = new ListNode(1);
			l1->next = new ListNode(2);
			l1->next->next = new ListNode(4);

			ListNode* l2 = new ListNode(1);
			l2->next = new ListNode(3);
			l2->next->next = new ListNode(4);

			mergeTwoLists(l1,l2);
		}
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode node(0);
			ListNode* n = &node;
			ListNode* ret = n;
			while (true)
			{
				if (nullptr != l1 && nullptr != l2)
				{
					if (l1->val > l2->val)
					{
						n->next = l2;
						n = l2;
						l2 = l2->next;
					}
					else
					{
						n->next = l1;
						n = l1;
						l1 = l1->next;
						
					}
					continue;
				}
				else if (nullptr == l1)
				{
					n->next = l2;
				}
				else
				{
					n->next = l1;
				}
				break;
			}
			
			return ret->next;
		}
	};
}
#endif