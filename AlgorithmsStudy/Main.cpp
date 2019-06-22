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

int main()
{
	//Problem_3::Run();
	Problem_148::Run();
	
	system("pause");
	return 0;
}

