#pragma once

#include <iostream>

/*============================================================================================================================================
	Accepted

	Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
	Memory Usage: 8.7 MB, less than 42.97% of C++ online submissions for Swap Nodes in Pairs.
============================================================================================================================================*/
namespace Problem_24
{
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	//===========================================================
	//	Given a linked list, swap every two adjacent nodesand return its head.
	//	You may not modify the values in the list's nodes, only nodes itself may be changed.
	//
	//	Example:
	//		Given 1->2->3->4, you should return the list as 2->1->4->3.
	//===========================================================
	class Solution 
	{
	public:
		ListNode* swapPairs(ListNode* head) 
		{
			bool shouldSwap = false;
			bool isFirst = true;

			ListNode* pPrevOfPrev = nullptr;
			ListNode* pPrev = nullptr;
			ListNode* pCurrent = head;

			while (pCurrent)
			{
				if (shouldSwap)
				{
					// Swap two nodes
					ListNode* pTemp = pCurrent;
					pCurrent = pPrev;
					pCurrent->next = pTemp->next;
					pPrev = pTemp;
					pPrev->next = pCurrent;

					if(pPrevOfPrev)
						pPrevOfPrev->next = pPrev;
					
					if (isFirst)
					{
						head = pPrev;
						isFirst = false;
					}
				}

				// Move to next
				pPrevOfPrev = pPrev;
				pPrev = pCurrent;
				pCurrent = pCurrent->next;
				shouldSwap = !shouldSwap;
			}

			PrintList(head);
			return head;
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
		ListNode head(1);
		head.next = new ListNode(2);
		head.next->next = new ListNode(3);
		head.next->next->next = new ListNode(4);

		sol.swapPairs(&head);
	}
}