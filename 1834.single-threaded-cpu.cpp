/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
class Solution {
	struct task {
		int index;
		int start;
		int duration;
	};

	struct CompStart {
		bool operator() (const task& lhs, const task& rhs) {
			if (lhs.start == rhs.start)		// compare start time
				return lhs.duration > rhs.duration;
			return lhs.start > rhs.start;
		}
	};

	struct CompDuration {
		bool operator() (const task& lhs, const task& rhs) {
			if (lhs.duration == rhs.duration)		// compare duration
				return lhs.index > rhs.index;
			return lhs.duration > rhs.duration;
		}
	};

public:
	vector<int> getOrder(vector<vector<int>>& tasks) {
		vector<task> task_list;
		for (int i = 0; i < tasks.size(); i++)
			task_list.push_back({ i, tasks[i][0], tasks[i][1] });

		priority_queue<
			task,
			vector<task>,
			CompStart> wait(task_list.begin(), task_list.end());

		priority_queue<
			task,
			vector<task>,
			CompDuration> work;

		vector<int> ans;
		long time = 1, process = 1;

		// even waiting queue is empty, still processing until working queue is empty, too
		while (!wait.empty() || process) {
			while (!wait.empty() && time >= wait.top().start) {
				work.push(wait.top());
				wait.pop();
			}

			// if no tasks in working queue, force enqueue first task of waiting queue
			// and set the time to task's start time
			if (work.empty()) {
				work.push(wait.top());
				time = wait.top().start;
				wait.pop();
			}

			// only process one task in one iteration, because there may be shorter
			// duration task in waiting queue
			if (!work.empty()) {
				time += work.top().duration;
				ans.push_back(work.top().index);
				work.pop();
			}

			if (wait.empty() && work.empty())
				process = 0;
		}

		return ans;
	}
};
// @lc code=end
