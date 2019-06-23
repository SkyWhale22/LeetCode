#pragma once
//
//#include <iostream>
//
/*============================================================================================================================================
	Failed

	Better solution is below
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
			//QuickSort(head, head, GetLastNode(head));
			ListNode* pHead = nullptr;
			int totalSize = GetTotalSize(head);
			pHead = QuickSort(head, 0, totalSize - 1, pHead);
			return pHead;
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


				pNewHead = QuickSort(pNewHead, low, pivot - 1, pNewHead);
				pNewHead = QuickSort(pNewHead, pivot + 1, high, pNewHead);
			}

			//if (pNewHead != nullptr)
			//	pNewHead = pHead;

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

			//if((*newHead) != nullptr)
			*(newHead) = pHead;

			//PrintList(*newHead);
			//PrintList(pHead);

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
				}
				else
				{
					pRhs->next = pLhs->next;
					pBeforeRhs->next = pLhs;
					pLhs->next = pTemp;
				}
				pNewHead = pRhs;
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

		int GetTotalSize(ListNode* pNode)
		{
			int size = 0;
			while (pNode)
			{
				++size;
				pNode = pNode->next;
			}

			return size;
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
		/*ListNode body1(2);
		head.next = &body1;
		ListNode body2(1);
		body1.next = &body2;
		ListNode body3(3);
		body2.next = &body3;*/
		//ListNode body4(0);
		//body3.next = &body4;
		//ListNode body5(4);
		//body4.next = &body5;
		//ListNode body6(2);
		//body5.next = &body6;

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

//--------------------------
// Much Better
//--------------------------
namespace Problem_148_Best_Case
{
	struct ListNode{
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	class Solution {
	public:
		ListNode* merge(ListNode* list1, ListNode* list2) {
			// Merge by inserting elements of list 2 at their proper position in list 1
			ListNode* current1 = list1;
			ListNode* current2 = list2;
			ListNode* prev1 = nullptr;

			while (list2) {          // while there are elements in list 2
				if (current1) {
					if (current1->val <= current2->val) { // move ahead if you are not less than 
														 // the current element of list 1
						prev1 = current1;
						current1 = current1->next;
					}
					else {        // Insert before current element of list 1
						list2 = current2->next;     // Don't lose pointer to the second list

						if (prev1 == nullptr) {      // New head
							current2->next = list1;
							list1 = current2;
							prev1 = current2;
						}
						else {
							current2->next = prev1->next;
							prev1->next = current2;
							prev1 = current2;
						}

						current2 = list2;       // Next element for comparison
					}
				}
				else {            // Elements remaining are greater than list 1. Simply append
					prev1->next = list2;
					break;
				}
			}

			return list1;
		}

		ListNode* split(ListNode* head, int length) {
			// Divide the list into two halves
			ListNode* slow = head;
			ListNode* fast = head->next->next;
			while (fast && fast->next) {     // When the fast pointer reaches/crosses the end
											// the slow pointer will be in the middle 
											// i.e end of the first list
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* list2 = slow->next;
			slow->next = nullptr;
			return list2;
		}

		ListNode* mergesort(ListNode* head, int length) {
			if (length <= 1)
				return head;

			ListNode* list1 = head;
			ListNode* list2 = split(head, length);

			list1 = mergesort(list1, length / 2);
			list2 = mergesort(list2, length - length / 2);
			return merge(list1, list2);
		}

		ListNode* sortList(ListNode* head) {
			if (!head)
				return nullptr;

			int n{ 0 };
			ListNode* current = head;
			while (current) {
				++n;
				current = current->next;
			}

			head = mergesort(head, n);
			return head;
		}

	};
}

namespace Problem_148_GeeksForGeeks
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
			QuickSort(&head);
			return head;
		}

		ListNode* GetTail(ListNode* pCur)
		{
			while (pCur != NULL && pCur->next != NULL)
				pCur = pCur->next;
			return pCur;
		}

		ListNode* Partition(ListNode* pHead, ListNode* pEnd, ListNode** ppNewHead, ListNode** ppNewEnd)
		{
			ListNode* pPivot = pEnd;
			ListNode* pPrev = nullptr;
			ListNode* pCur = pHead;
			ListNode* pTail = pPivot;

			// During partition, both the head and end of the list might change 
			// which is updated in the newHead and newEnd variables 
			while (pCur != pPivot)
			{
				if (pCur->val < pPivot->val)
				{
					// First node that has a value less than the pivot - becomes 
					// the new head 
					if ((*ppNewHead) == nullptr)
						(*ppNewHead) = pCur;

					pPrev = pCur;
					pCur = pCur->next;
				}
				else // If cur node is greater than pivot 
				{
					// Move cur node to next of tail, and change tail 
					if (pPrev)
						pPrev->next = pCur->next;
					ListNode* pTemp = pCur->next;
					pCur->next = nullptr;
					pTail->next = pCur;
					pTail = pCur;
					pCur = pTemp;
				}
			}

			// If the pivot data is the smallest element in the current list, 
			// pivot becomes the head 
			if ((*ppNewHead) == nullptr)
				(*ppNewHead) = pPivot;

			// Update newEnd to the current last node 
			(*ppNewEnd) = pTail;

			// Return the pivot node 
			return pPivot;
		}

		//here the sorting happens exclusive of the end node 
		ListNode* QuickSortRecur(ListNode* pHead, ListNode* pEnd)
		{
			// base condition 
			if (!pHead || pHead == pEnd)
				return pHead;

			ListNode* pNewHead = nullptr, *pNewEnd = nullptr;

			// Partition the list, newHead and newEnd will be updated 
			// by the partition function 
			ListNode* pPivot = Partition(pHead, pEnd, &pNewHead, &pNewEnd);

			// If pivot is the smallest element - no need to recur for 
			// the left part. 
			if (pNewHead != pPivot)
			{
				// Set the node before the pivot node as NULL 
				ListNode* pTemp = pNewHead;
				while (pTemp->next != pPivot)
					pTemp = pTemp->next;
				pTemp->next = nullptr;

				// Recur for the list before pivot 
				pNewHead = QuickSortRecur(pNewHead, pTemp);

				// Change next of last node of the left half to pivot 
				pTemp = GetTail(pNewHead);
				pTemp->next = pPivot;
			}

			// Recur for the list after the pivot element 
			pPivot->next = QuickSortRecur(pPivot->next, pNewEnd);

			return pNewHead;
		}

		// The main function for quick sort. This is a wrapper over recursive 
		// function quickSortRecur() 
		void QuickSort(ListNode** ppHeadRef)
		{
			(*ppHeadRef) = QuickSortRecur(*ppHeadRef, GetTail(*ppHeadRef));
			return;
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
		ListNode head(4);
		ListNode body1(2);
		head.next = &body1;
		ListNode body2(1);
		body1.next = &body2;
		ListNode body3(3);
		body2.next = &body3;

		ListNode* pSorted = sol.sortList(&head);
		// expected: 
		std::cout << "==== After sorting =============================================" << std::endl;
		sol.PrintList(pSorted);
		//std::cout << "================================================================" << std::endl;
	}

}