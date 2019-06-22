#pragma once

#include <iostream>

/*============================================================================================================================================
============================================================================================================================================*/
namespace Problem_148
{
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	//===========================================================
	//	TODO:
	//	Sort a linked list in O(n log n) time using constant space complexity.
	//===========================================================
	class Solution
	{
	public:
		ListNode* sortList(ListNode* head)
		{
			int totalSize = 0;
			GetTotalSize(head, ++totalSize);
			ListNode* pInitPivot = GetNthNode(head, totalSize / 2);
			QuickSort(head, head, GetLastNode(head));

			return head;
		}

		/* Quick Sort Pseudo code O(n log n)
		------------------------------------------------------
		@param	A	array
		@param	p	pivot
		@param	r	length of array
		------------------------------------------------------
		QuickSort(A, p, r)
		if p < r
			q = Partition(A, p, r)
			QuickSort(A, p, q-1)
			QuickSort(A, q+1, r)
		*/

		void QuickSort(ListNode* pHead, ListNode* pPivot, ListNode* pHigh)
		{
			if (pPivot->val < pHigh->val)
			{
				ListNode* pNewPivot = Partition(pHead, pPivot, pHigh);
				QuickSort(pHead, pPivot, FindNodeBefore(pHead, pNewPivot));
				QuickSort(pHead, pNewPivot->next, pHigh);
			}
		}

		ListNode* GetNthNode(ListNode* pNode, int n)
		{
			/*int totalSize = 1;
			GetTotalSize(pNode, totalSize);
			int targetIndex = totalSize - n;
*/
			for (size_t i = 0; i < n; ++i)
			{
				// If current node has neighbor node.
				if (pNode->next)
					pNode = pNode->next;
			}

			return pNode;
		}

		ListNode* GetLastNode(ListNode* pHead)
		{
			if (pHead->next)
				return GetLastNode(pHead->next);

			return pHead;
		}

		/* Partition Pseudo code 
		------------------------------------------------------
		@param	A	array
		@param	p	partition
		@param	r	length of array
		------------------------------------------------------
		Parition(A, p, r)
		x = A[r]
		i = p - 1
		for j = p to r - 1
			if A[j] <= x
				i = i + 1
				exchange A[i] with A[j]

		exchange A[i+1] with A[r]
		return i+1
		*/
		ListNode* Partition(ListNode* pHead, ListNode* pPivot, ListNode* pHigh)
		{
			ListNode* pX = pHigh;
			//ListNode* pI = FindNodeBefore(pHead, pPivot);
			ListNode* pLow = pPivot->next;
			ListNode* pCurrent = pPivot;

			while (pCurrent != nullptr && pCurrent != pHigh)
			{
				if (pCurrent->val <= pX->val)
				{
					pLow = pLow->next;
					SwapNodes(pHead, pPivot, pHigh);
				}

				pCurrent = pCurrent->next;
			}

			SwapNodes(pHead, pLow->next, pHigh);
			return pLow->next;
		}

		void SwapNodes(ListNode* pHead, ListNode* pLhs, ListNode* pRhs)
		{
			ListNode* pBeforeLhs = FindNodeBefore(pHead, pLhs);
			ListNode* pBeforeRhs = FindNodeBefore(pHead, pRhs);
			ListNode* pTemp = pRhs->next;

			pBeforeLhs->next = pRhs;
			pRhs->next = pLhs->next;
			pBeforeRhs->next = pLhs;
			pLhs->next = pTemp;
		}

		ListNode* FindNodeBefore(ListNode* pHead, ListNode* pTarget)
		{
			if (!pHead || !pHead->next || !pTarget)
				return nullptr;

			if (pHead->next != pTarget)
				return FindNodeBefore(pHead->next, pTarget);

			return pHead;
		}

		void GetTotalSize(ListNode* pNode, int& size)
		{
			if (pNode->next)
				GetTotalSize(pNode->next, ++size);
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
		ListNode body1(3);
		head.next = &body1;
		ListNode body2(2);
		body1.next = &body2;
		ListNode body3(4);
		body2.next = &body3;
		ListNode body4(5);
		body3.next = &body4;

		//ListNode body5(6);
		//body4.next = &body5;

		//ListNode tail(7);
		//body5.next = &tail;

		// 1->2->3->4
		sol.PrintList(&head);
		ListNode* pSorted = sol.sortList(&head);
		// expected: 
		sol.PrintList(pSorted);


	}
}