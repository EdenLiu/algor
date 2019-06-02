// algor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "findMedianSortedArrays.hpp"
#include "longestPalindrome.hpp"
#include "reverse.hpp"
#include "myAtoi.hpp"
#include "algor15_threeSum.hpp"
#include "algor16_threeSumClosest.hpp"
#include "algor20_isValid.hpp"
#include "algor21_mergeTwoLists.hpp"
#include "algor23_mergeKLists.hpp"
#include "algor26_removeDuplicates.hpp"
#include "algor43_multiply.hpp"
int main()
{
    std::cout << "Hello World!\n"; 
	//{
	//	std::vector<int> nums1, nums2;
	//	nums1.push_back(2);
	//	nums1.push_back(3);
	//	nums1.push_back(4);
	//	nums2.push_back(1);
	//	//nums2.push_back(5);

	//	algor4::Solution n;
	//	double mid = n.findMedianSortedArrays(nums1, nums2);
	//}
	//

	//{
	//	algor5::Solution n;
	//	std::string str("a");
	//	std::string longestPalindrome = n.longestPalindrome(str);
	//}
	//
	//{
	//	algor7::Solution n;
	//	int i = INT_MIN;
	//	n.reverse(1563847412);
	//	
	//}

	//{
	//	algor8::Solution n;
	//	n.myAtoi("-2147483648");
	//}

	{
		algor43::Solution n;
		n.Run();
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
