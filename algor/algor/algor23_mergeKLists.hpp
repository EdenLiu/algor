#ifndef _algor23_mergeKLists_h
#define _algor23_mergeKLists_h

/**
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
巧妙的结题思路：


**/
#include "algor_std.h"
namespace algor23
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

			ListNode* l3 = new ListNode(2);
			l3->next = new ListNode(6);
			vector<ListNode*> n{ l1,l2,l3 };
			mergeKLists(n);
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
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			size_t size = lists.size();
			if (size == 0)
			{
				return nullptr;
			}
			else if (size == 1)
			{
				return lists[0];
			}

			ListNode* l1 = lists[0];
			ListNode* l2 = lists[1];
			ListNode* ret = mergeTwoLists(l1, l2);;

			for (size_t i = 2; i < size; i++)
			{
				ret = mergeTwoLists(ret, lists[i]);
			}

			return ret;
		}
	};
}
#endif