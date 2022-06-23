/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
	// works, but TLE
/*
	size_t maxCoursesSelected = 0;
	void backtrack (
			vector<pair<int, int>>& selected,
			vector<pair<int, int>>& selectable,
			vector<bool>& consumed,
			size_t lastDays)
	{
		// if all selectable courses are selected
		if (selected.size() == selectable.size()) return;

		for (int i = 0; i < selectable.size(); i++) {
			// select the course if it is not consumed and the duration doesn't exceeds deadline
			if (!consumed[i] && lastDays + selectable[i].first <= selectable[i].second) {
				// accumulate the days
				lastDays += selectable[i].first;
				// select it!
				selected.push_back(selectable[i]);
				consumed[i] = true;
				maxCoursesSelected = max(maxCoursesSelected, selected.size());

				backtrack(selected, selectable, consumed, lastDays);

				// restore status for next iteration
				consumed[i] = false;
				selected.pop_back();
				lastDays -= selectable[i].first;
			}
		}
	}

public:
	int scheduleCourse(vector<vector<int>>& courses) {
		vector<pair<int, int>> co, se;
		for (auto c : courses) co.push_back(pair<int, int>(c[0], c[1]));
		sort(co.begin(), co.end(), [](const auto& a, const auto& b) {
			return a.first == b.first ?
					a.second < b.second : a.first < b.first;
		});

		vector<bool> consume(co.size(), false);
		size_t days = 0;
		backtrack(se, co, consume, days);
		return maxCoursesSelected;
	}
*/
	struct PairCompare {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b){
			return a.first < b.first;
		}
	};
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		vector<pair<int, int>> co;
		for (auto c : courses) co.push_back(pair<int, int>(c[0], c[1]));
		sort(co.begin(), co.end(), [](const auto& a, const auto& b) {
			return a.second < b.second;
		});

		priority_queue <
			pair<int, int>,
			vector<pair<int, int>>,
			PairCompare> selectedCourses;
		int selectedLastDays = 0;

		for (auto c : co) {
			selectedCourses.push(c);			// select this course
			selectedLastDays += c.first;		// accumulate days

			// check if the days exceeds the deadline
			if (selectedLastDays > c.second) {
				// need to cancel the course and restore the days
				selectedLastDays -= selectedCourses.top().first;
				selectedCourses.pop();
			}
		}
		return selectedCourses.size();
	}
};
// @lc code=end

