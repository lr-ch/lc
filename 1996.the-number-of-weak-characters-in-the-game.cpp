/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */

// @lc code=start
/*
 * Time Limit Exceeded
 *  40/44 cases passed (N/A)
 */
class SolutionTLE {
public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
			if (a[0] == b[0])
				return a[1] < b[1];
			return a[0] < b[0];
		});

		int count = 0, prosize = properties.size();
		for (int i = 0; i < prosize - 1; i++)
			for (int j = prosize - 1; j >= 0; j--)
				if (properties[i][0] < properties[j][0] && properties[i][1] < properties[j][1]) {
					count++;
					break;
				}

		return count;
	}
};

class Solution {
	struct attrib {
		int atk;
		int def;
		attrib(vector<int>& v) : atk(v[0]), def(v[1]) {};
		bool operator <(const attrib& rhs) const {
			if (this->atk == rhs.atk) return this->def < rhs.def;
			return this->atk > rhs.atk;
		}
		string to_string() {
			return "(" + ::to_string(this->atk) + ", " + ::to_string(this->def) + ")";
		}
	};

	void dump(vector<attrib>& vp) {
		for (auto& p : vp)
			cout << p.to_string() << endl;
		cout << "---------------" << endl;
	}

public:
	int numberOfWeakCharacters(vector<vector<int>>& properties) {
		vector<attrib> props(properties.begin(), properties.end());
		sort(props.begin(), props.end());
	//	dump(props);

		int count = 0, max_def = INT_MIN;
		for (auto& p : props) {
			if (p.def < max_def) {
			//	cout << p.to_string();
				count++;
			} else
				max_def = p.def;
		}

		return count;
	}
};
// @lc code=end
