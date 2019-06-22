#pragma once

#include <iostream>

/*============================================================================================================================================
============================================================================================================================================*/
namespace Problem_61
{
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	/*===========================================================
		Given a linked list, rotate the list to the right by k places, where k is non-negative.

		Example 1:
			Input: 1->2->3->4->5->NULL, k = 2
			Output: 4->5->1->2->3->NULL

		Explanation:
			rotate 1 steps to the right: 5->1->2->3->4->NULL
			rotate 2 steps to the right: 4->5->1->2->3->NULL
		
		Example 2:
			Input: 0->1->2->NULL, k = 4
			Output: 2->0->1->NULL

		Explanation:
			rotate 1 steps to the right: 2->0->1->NULL
			rotate 2 steps to the right: 1->2->0->NULL
			rotate 3 steps to the right: 0->1->2->NULL
			rotate 4 steps to the right: 2->0->1->NULL
	=========================================================*/
	class Solution
	{
	public:
		ListNode* rotateRight(ListNode* head, int k)
		{
			if (!head)
				return nullptr;

			if (k <= 0)
				return head;

			ListNode* pCurrent = head;

			// O(n)
			ListNode* pTarget = Search(head, k);

			// Get last node of sub list
	
			while (pCurrent)
			{
				if (pCurrent->next == pTarget)
				{
					pCurrent->next = nullptr;
					ListNode* tail = GetTail(pTarget);

					tail->next = head;
					head = pTarget;
				}

				pCurrent = pCurrent->next;
			}

			// Return the head. 

			PrintList(head);
			return head;
		}

		void GetTotalSize(ListNode* pNode, int& size)
		{
			if (pNode->next)
				GetTotalSize(pNode->next, ++size);

			/*while (pNode)
			{
				++size;
				pNode = pNode->next;
			}*/
		}

		ListNode* Search(ListNode* pNode, int n)
		{
			int totalSize = 1;
			GetTotalSize(pNode, totalSize);
			int targetIndex = 0;
				
			if (n > totalSize)
				targetIndex = totalSize  + (2 * (n % totalSize));
			else
				targetIndex = totalSize - n;

			// if targetIndex is lower than 0, make it positive.
			if (targetIndex < 0)
				targetIndex *= -1;

			for (size_t i = 0; i < targetIndex; ++i)
			{
				// If current node has neighbor node.
				if (pNode->next)
					pNode = pNode->next;
			}

			return pNode;
		}

		ListNode* GetTail(ListNode* pNode)
		{
			if (pNode->next)
				return GetTail(pNode->next);
			
			return pNode;
		}

		void PrintList(ListNode* pNode)
		{
			while (pNode)
			{
				std::cout << pNode->val << "->";
				pNode = pNode->next;
			}
			std::cout << std::endl;
		}
	};



	static void Run()
	{
		Solution sol;
		ListNode head(0);
		head.next = new ListNode(1);
		head.next->next = new ListNode(2);
		head.next->next->next = new ListNode(3);
		head.next->next->next->next = new ListNode(4);
		/*head.next->next->next->next->next = new ListNode(5);
		head.next->next->next->next->next->next = new ListNode(6);
		head.next->next->next->next->next->next->next = new ListNode(7);
*/
		sol.rotateRight(&head, 10);	
	}
}