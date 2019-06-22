#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::string;

class Problem_3
{
public:
	class Solution
	{
	public:
		int lengthOfLongestSubstring(string s)
		{
			std::vector<char> longest;
			std::vector<char> current;

			for (size_t i = 0; i < s.size(); ++i)
			{
				char ch = s[i];

				if (current.empty())
				{
					current.emplace_back(ch);
					continue;
				}

				if (std::find(current.begin(), current.end(), ch) == current.end())
				{
					current.emplace_back(ch);
				}
				else
				{
					if(longest.size() < current.size())
						longest = current;
					current.clear();
					current.emplace_back(ch);
				}

				
			}

			if (longest.size() < current.size())
				longest = current;
			return longest.size();
		}
	};

	static void Run()
	{
		Solution sol;
		//std::cout << sol.lengthOfLongestSubstring("abcabcbb") << std::endl;
		//std::cout << sol.lengthOfLongestSubstring("bbbb") << std::endl;
		//std::cout << sol.lengthOfLongestSubstring("pwwkew") << std::endl;
		//std::cout << sol.lengthOfLongestSubstring("aab") << std::endl;
		std::cout << sol.lengthOfLongestSubstring("dvdf") << std::endl;

	}
};

//
//class Solution
//{
//public:
//	int lengthOfLongestSubstring(string s)
//	{
//		std::vector<char> chars;
//
//		for (size_t i = 0; i < s.size(); ++i)
//		{
//			char current = s[i];
//
//			if (chars.empty())
//			{
//				chars.emplace_back(current);
//				continue;
//			}
//
//			// has (ch) == false
//			if (std::find(chars.begin(), chars.end(), current) == chars.end())
//			{
//				// IsFirst == false
//				if (current != chars.front())
//				{
//					chars.emplace_back(current);
//				}
//			}
//			// has (ch) == true
//			//else
//			//{
//			//	// IsFirst == false
//			//	if (current != chars.front())
//			//	{
//			//		chars.clear();
//			//	}
//			//	// IsFirst == true;
//			//	else
//			//	{
//			//		break;
//			//	}
//			//}
//		}
//		return chars.size();
//	}
//};