#pragma once
//
//#include <iostream>
//
///*============================================================================================================================================
//============================================================================================================================================*/
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
			//QuickSort(head, head, GetLastNode(head));
			ListNode* pHead = nullptr;
			int totalSize = 0;
			GetTotalSize(head, ++totalSize);
			QuickSort(head, 0, totalSize - 1, pHead);
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

		//ListNode* QuickSort(ListNode* pHead, ListNode* pLow, ListNode* pHigh)
		//{
		//	ListNode* pNewHead = nullptr;

		//	if (pLow != nullptr && pHigh != nullptr && pLow != pHigh)
		//	{
		//		ListNode* pPivot = Partition(pHead, pLow, pHigh, &pNewHead);

		//		//std::cout << "--- After Partition -----------------------------------------" << std::endl;
		//		//PrintList(pNewHead);

		//		std::cout << "\n\n\nQuickSort Function - Left" << std::endl;
		//		std::cout << "Head: " << pNewHead->val << ", Low: " << pNewHead->val << ", High: " << std::endl;

		//		pNewHead = QuickSort(pNewHead, pNewHead, FindNodeBefore(pNewHead, pPivot));
		//		
		//		std::cout << "\n\n\nQuickSort Function - Right" << std::endl;
		//		std::cout << "Head: " << pNewHead->val << ", pivot: " << pPivot->val << ", Low: " << pPivot->next->val << ", High: " << GetLastNode(pNewHead)->val << std::endl;
		//		//std::cout << "--- Last Node: " << GetLastNode(pNewHead)->val <<"-----------------------------------------" << std::endl;
		//		pNewHead = QuickSort(pNewHead, pPivot->next, GetLastNode(pNewHead));
		//		std::cout << "\n\n\n";
		//	}

		//	if (pNewHead == nullptr)
		//		pNewHead = pHead;

		//	return pNewHead;
		//}

		ListNode* QuickSort(ListNode* pHead, int low, int high, ListNode* pTempHead)
		{
			ListNode* pNewHead = pTempHead;

			if(low < high)
			{
				//ListNode* pPivot = Partition(pHead, pLow, pHigh, &pNewHead);
				int pivot = Partition(pHead, low, high, &pNewHead);

				//std::cout << "--- After Partition -----------------------------------------" << std::endl;
				//PrintList(pNewHead);


				QuickSort(pNewHead, low, pivot - 1, pNewHead);
				QuickSort(pNewHead, pivot + 1, high, pNewHead);
			}

			if (pNewHead == nullptr)
				pNewHead = pHead;

			return pNewHead;
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

		int Partition(ListNode* pHead, int low, int high, ListNode** newHead)
		{
			//std::cout << "Head: " << pHead->val << ", Low: " << pLow->val << ", High: " << pHigh->val << std::endl;
			int pivot = GetNthNode(pHead, high)->val;
			ListNode* pLow = GetNthNode(pHead, low);
			int i = low-1;
			ListNode* pCurrent = pLow;
			//ListNode* pNodeBeforePivot = FindNodeBefore(pHead, pPivot);

			for (int j = low; j <= high - 1; ++j)
			{
				if (GetNthNode(pHead, j)->val <= pivot)
				{
					++i;

					pHead = SwapNodes(pHead, GetNthNode(pHead, i), GetNthNode(pHead, j));
				}

				//pCurrent = pCurrent->next;
				PrintList(pHead);
			}

			//if(i + 1 < high - 1)
			pHead = SwapNodes(pHead, GetNthNode(pHead, i + 1), GetNthNode(pHead, high));

			if((*newHead) == nullptr)
				*(newHead) = pHead;

			PrintList(*newHead);
			return i + 1;
		}

		//ListNode* Partition(ListNode* pHead, ListNode* pLow, ListNode* pHigh, ListNode** newHead)
		//{
		//	//std::cout << "Head: " << pHead->val << ", Low: " << pLow->val << ", High: " << pHigh->val << std::endl;
		//	ListNode* pPivot = pHigh;
		//	int i = -1;
		//	ListNode* pCurrent = pLow;
		//	ListNode* pNodeBeforePivot = FindNodeBefore(pHead, pPivot);

		//	if (pCurrent == pNodeBeforePivot)
		//	{
		//		if ((*newHead) == nullptr)
		//			*(newHead) = pHead;

		//		return GetNthNode(*newHead, i + 1);
		//	}


		//	while (pCurrent != nullptr && pCurrent != pNodeBeforePivot)
		//	{
		//		if (pCurrent->val <= pPivot->val)
		//		{
		//			++i;

		//			pHead = SwapNodes(pHead, GetNthNode(pHead, i), pCurrent);
		//		}

		//		pCurrent = pCurrent->next;
		//	}

		//	pHead = SwapNodes(pHead, GetNthNode(pHead, i + 1), pPivot);

		//	if((*newHead) == nullptr)
		//		*(newHead) = pHead;

		//	return GetNthNode(*newHead, i + 1);
		//}

		ListNode* SwapNodes(ListNode* pHead, ListNode* pLhs, ListNode* pRhs)
		{
			if (pHead == pLhs && pHead == pRhs || pLhs == pRhs)
				return pHead;

			ListNode* pTemp = pRhs->next;
			ListNode* pNewHead = pHead;
			ListNode* pBeforeRhs = FindNodeBefore(pHead, pRhs);

			if (pHead == pLhs)
			{
				if (pLhs->next == pRhs)
				{
					pRhs->next = pLhs;
					pLhs->next = pTemp;
					pNewHead = pRhs;
				}
				else
				{
					pRhs->next = pLhs->next;
					pBeforeRhs->next = pLhs;
					pLhs->next = pTemp;
					pNewHead = pRhs;
				}
			}
			else
			{
				ListNode* pBeforeLhs = FindNodeBefore(pHead, pLhs);
				pBeforeLhs->next = pRhs;
				pBeforeRhs->next = pLhs;
				pRhs->next = pLhs->next;
				pLhs->next = pTemp;
			}

			return pNewHead;
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
		ListNode head(5);
		ListNode body1(3);
		head.next = &body1;
		ListNode body2(6);
		body1.next = &body2;
		ListNode body3(0);
		body2.next = &body3;
		ListNode body4(1);
		body3.next = &body4;
		ListNode body5(4);
		body4.next = &body5;
		ListNode body6(2);
		body5.next = &body6;

		//ListNode body5(6);
		//body4.next = &body5;

		//ListNode tail(7);
		//body5.next = &tail;

		// 1->2->3->4
		//std::cout << "==== Before sorting ============================================" << std::endl;
		//sol.PrintList(&head);
		//std::cout << "================================================================" << std::endl;

		//ListNode* pNewHead = sol.SwapNodes(&head, &head, &body1);
		//sol.PrintList(pNewHead);

		ListNode* pSorted = sol.sortList(&head);
		// expected: 
		std::cout << "==== After sorting =============================================" << std::endl;
		sol.PrintList(pSorted);
		//std::cout << "================================================================" << std::endl;
	}
}
