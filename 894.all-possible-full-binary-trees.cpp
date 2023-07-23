/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class SolutionRecur {
public:
	vector<TreeNode*> allPossibleFBT(int n) {
		/* base cases
		 *   n = 1    n = 3
		 *     1        1
		 *             / \
		 *            2   3
		 */
		if (n == 1) return {new TreeNode()};
		if (n < 3) return {};

		vector<TreeNode *> res;
		for (int i = 1; i < n; i += 2)
			for (const auto& left : allPossibleFBT(i))
				for (const auto& right : allPossibleFBT(n - i - 1))
					res.emplace_back(new TreeNode(0, left, right));

		return res;
	}
};

class SolutionDpMemo {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
		// ref. Fibonacci with F[n]
        vector<vector<TreeNode *>> dp(n + 1);	// dp[i] trees with i nodes
        dp[1] = {new TreeNode(0)};
        for (int i = 3; i <= n; i += 2)			// total
            for (int j = 1; j < i; j += 2) {	// number of left tree nodes
                int k = i - j - 1;				// number of right tree nodes
                for (const auto& left : dp[j])
                    for (const auto& right : dp[k])
                        dp[i].push_back(new TreeNode(0, left, right));
            }
        return dp[n];
     }
};

class Solution {
	/*
	 * Accepted
	 *  - 20/20 cases passed (231 ms)
	 *  - Your runtime beats 5.05 % of cpp submissions
	 *  - Your memory usage beats 6.04 % of cpp submissions (61.8 MB)
	 */
	SolutionRecur recur;

	/*
	 * Accepted
	 *  - 20/20 cases passed (95 ms)
	 *  - Your runtime beats 86.81 % of cpp submissions
	 *  - Your memory usage beats 60.04 % of cpp submissions (28.5 MB)
	 */
	SolutionDpMemo dp;
public:
	vector<TreeNode*> allPossibleFBT(int n) {
	//	return recur.allPossibleFBT(n);
		return dp.allPossibleFBT(n);
	}
};
// @lc code=end
