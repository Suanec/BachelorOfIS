#pragma once
#pragma warning(disable: 4018)
#pragma warning(disable: 4146)
#pragma warning(disable: 4244)

#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<stdint.h>
#include<stddef.h>

#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<list>
#include<forward_list>
#include<queue>
#include<stack>
#include<deque>
#include<functional>
#include<iterator>
#include<array>
#include<memory>
#include<numeric>
#include<utility>
#include<math.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};