//#include <iostream>
//#include "Solution.h"
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main()
//{
//	std::vector<int> given {3, 3};
//	int target = 6;
//	std::vector<int> answer;
//
//	Solution sol;
//	answer = sol.twoSum(given, target);
//
//	cout << "Answer is ";
//
//	for (size_t i = 0; i < answer.size(); ++i)
//	{
//		cout << answer[i] << ", ";
//	}
//
//	cout << endl;
//
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <math.h>
#include "Problem_3.hpp"
#include "Problem_19.h"
#include "Problem_24.h"
#include "Problem_61.h"
#include "Problem_148.h"

using std::cout;
using std::cin;
using std::endl;

/*
// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		size_t carryOver = 0;
		ListNode* pFirst = nullptr;
		ListNode* pCurrent = nullptr;

		// Expectation : O(n)
		while (l1 || l2)
		{
			int sum = GetVal(l1) + GetVal(l2) + carryOver;

			// Get new carry over
			carryOver = sum / 10;
			sum %= 10;

			if (!pFirst)
			{
				pCurrent = pFirst = new ListNode(sum);
			}
			else
			{
				pCurrent->next = new ListNode(sum);
				pCurrent = pCurrent->next;
			}

			if(l1->next)
				l1 = l1->next;
			if(l2->next)
				l2 = l2->next;
		}

		return pFirst;

		//int sum = GetTotalValue_Recursive(l1, 0) + GetTotalValue_Recursive(l2, 0);

		//ListNode* pFirst = nullptr;
		//ListNode* pPrev = nullptr;

		//while (sum > 0)
		//{
		//	ListNode* pNewNode = new ListNode(sum % 10);
		//	sum /= 10;

		//	if (pPrev == nullptr)
		//		pFirst = pNewNode;

		//	if (pPrev != nullptr)
		//		pPrev->next = pNewNode;
		//}

		//return pFirst;
	}

	int GetVal(ListNode* pNode)
	{
		return pNode ? pNode->val : 0;
	}

	//void Helper(ListNode* pPrev, int sum)
	//{
	//	ListNode* pNewNode = new ListNode(sum % 10);
	//	sum /= 10;

	//	if (pPrev != nullptr)
	//		pPrev->next = pNewNode;
	//}

	//O(log N)
	int GetTotalValue_Recursive(ListNode* pNode, size_t digit)
	{
		if (pNode == nullptr)
			return 0;
	
		int sum = pNode->val * pow(10, digit);
		return sum + GetTotalValue_Recursive(pNode->next, ++digit);
	}

	// O(n)
	/*int GetTotalValue(ListNode* pNode)
	{
		int sum = 0;
		int digit = -1;

		while (pNode != nullptr)
		{
			sum += pNode->val * pow(10, ++digit);
			pNode = pNode->next;
		}

		return sum;
	}
};


int main()
{
	ListNode first(2);
	first.next = new ListNode(4);
	first.next->next = new ListNode(3);

	ListNode second(5);
	second.next = new ListNode(6);
	second.next->next = new ListNode(4);
	
	Solution sol;

	ListNode* pTest = sol.addTwoNumbers(&first, &second);

	while (pTest)
	{
		cout << pTest->val << " -> ";
		pTest = pTest->next;
	}

	system("pause");
	return 0;
}*/
using namespace std;

// A utility function to swap two elements  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or  
		// equal to pivot  
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	//Problem_3::Run();
	Problem_148::Run();
	
	//int arr[] = { 5, 3, 6, 0, 1, 4, 2 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//quickSort(arr, 0, n - 1);
	//cout << "Sorted array: \n";
	//printArray(arr, n);


	system("pause");
	return 0;
}

