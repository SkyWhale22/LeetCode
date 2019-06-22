#pragma once
#include <iostream>

/*============================================================================================================================================
	Accepted

	Runtime: 4 ms, faster than 94.78 % of C++ online submissions for Remove Nth Node From End of List.
	Memory Usage : 8.6 MB, less than 46.50 % of C++ online submissions for Remove Nth Node From End of List.
============================================================================================================================================*/
namespace Problem_19
{
	// Definition for singly-linked list.
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	//-----------------------------------------------------------------
	//	Given a linked list, remove the n - th node from the end of listand return its head.
	//	
	//	Example:
	//	Given linked list : 1->2->3->4->5, and n = 2.
	//
	//	After removing the second node from the end, the linked list becomes 1->2->3->5.
	//
	//	Note :
	//	Given n will always be valid.
	//
	//	Follow up :
	//	Could you do this in one pass ?
	//-----------------------------------------------------------------
	class Solution 
	{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) 
		{
			ListNode* pTarget = Search(head, n);
			ListNode* pCurrent = head;

			if (head == pTarget)
			{
				head = pCurrent = pTarget->next;
				
				pTarget = nullptr;

				return head;
			}

			else
			{
				while (pCurrent)
				{
					if (pCurrent->next == pTarget)
					{
						pCurrent->next = pTarget->next;
						break;
					}

					pCurrent = pCurrent->next;
				}
			}

			delete pTarget;

			return head;		
		}

		ListNode* Search(ListNode* pNode, int n)
		{
			int totalSize = 1;
			GetTotalSize(pNode, totalSize);
			int targetIndex = totalSize - n;

			for (size_t i = 0; i < targetIndex; ++i)
			{
				// If current node has neighbor node.
				if (pNode->next)
					pNode = pNode->next;
			}

			return pNode;
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
	};

	static void PrintList(ListNode* pNode)
	{
		while (pNode)
		{
			std::cout << pNode->val << "->";
			pNode = pNode->next;
		}
		std::cout << std::endl;
	}

	static void Run()
	{
		Solution sol;
		ListNode head(1);
		head.next = new ListNode(2);
		head.next->next = new ListNode(3);
		head.next->next->next = new ListNode(4);
		head.next->next->next->next = new ListNode(5);
		
		head = *(sol.removeNthFromEnd(&head, 5));
		PrintList(&head);
	}
};

