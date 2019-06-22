//#pragma once
//
//#include <vector>
//#include <unordered_map>
//
//class Solution
//{
//public:
//	Solution();
//	~Solution();
//
//	std::vector<int> twoSum(std::vector<int>& nums, int target)
//	{
//		std::vector<int> answer;
//		std::unordered_map<int, int> indexMap;
//
//		for (size_t i = 0; i < nums.size(); ++i)
//		{
//			int leftOver = target - nums[i];
//
//			if (indexMap.find(leftOver) != indexMap.end())
//			{
//				answer.push_back(i);
//				answer.push_back(indexMap[leftOver]);
//				return answer;
//			}
//
//
//			indexMap[nums[i]] = i;
//		}
//
//		return std::vector<int>{-1, -1};
//	}
//};
//
//
//
//Solution::Solution()
//{
//}
//
//
//Solution::~Solution()
//{
//}
