/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Backtrack {
	int toInt(vector<int>& v) {
		int res = 0;
		for (const auto& i : v)
			res = res * 10 + i;
		return res;
	}

	void backtrack(vector<int>& path, int n, int k) {
		if (n == 0) {
			ans.push_back(toInt(path));
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (path.back() - i == k || i - path.back() == k) {
				path.push_back(i);
				backtrack(path, n - 1, k);
				path.pop_back();
			}
		}
	}

	vector<int> ans;
public:
	vector<int> numsSameConsecDiff(int n, int k) {
		vector<int> digits(n);

		for (int i = 1; i <= 9; i++) {
			digits.push_back(i);
			backtrack(digits, n - 1, k);
			digits.pop_back();
		}
		return ans;
	}
};

class BacktrackOpt {
	void bt(vector<int>& ans, int tmp, int n, int k) {
		if (!n) {
			ans.push_back(tmp);
			return;
		}

		for (int i = 0; i <= 9; i++) {
			int last_digit = tmp % 10;
			if (last_digit - i == k || i - last_digit == k) {
				tmp = tmp * 10 + i;
				bt(ans, tmp, n - 1, k);
				tmp = tmp / 10;
			}
		}
	}

public:
	vector<int> numsSameConsecDiff(int n, int k) {
		vector<int> ans;

		for (int i = 1; i <= 9; i++)
			bt(ans, i, n - 1, k);

		return ans;
	}
};

class SolutionBFS {
public:
	vector<int> numsSameConsecDiff(int n, int k) {
		vector<int> ans;
		queue<pair<int, int>> nums; // <digits, length of digits>

		for (int i = 1; i <= 9; i++)
			nums.push({ i, 1 });

		while (!nums.empty()) {
			auto item = nums.front();
			nums.pop();

			int tmp = item.first, last_digit = tmp % 10;
			for (int j = 0; j <= 9; j++, item.second <= n) {
				if (last_digit - j == k || j - last_digit == k) {
					item.first = tmp * 10 + j;
					item.second++;

					if (item.second == n)
						ans.push_back(item.first);
					else
						nums.push(item);

					item.first /= 10;
					item.second--;
				}
			}
		}

		return ans;
	}
};
class Solution {
public:
	vector<int> numsSameConsecDiff(int n, int k) {
		deque<int> nums;

		for (int i = 1; i <= 9; nums.push_back(i), i++);

        while (--n) {
            int size = nums.size();
            while (size--) {
                int tmp = nums.front(), last_digit = tmp % 10;
                nums.pop_front();

                for (int j = 0; j <= 9; j++) {
                    if (last_digit - j == k || j - last_digit == k) {
                        tmp = tmp * 10 + j;
                        nums.push_back(tmp);
                        tmp /= 10;
                    }
                }
            }
        }

        return vector<int>(nums.begin(), nums.end());
	}
};
// @lc code=end
