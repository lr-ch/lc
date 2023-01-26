/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
	struct City {
		int to;
		int price;
		City(int t, int p) : to(t), price(p) {}
	};

public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<int> min_costs(n, 0);		// costs[i] = the minimun cost fly to city[i]
		vector<vector<City>> cities(n);		// cities[i] = all the flight lines toward other city
		for (const auto& f : flights)
			cities[f[0]].push_back(City(f[1], f[2]));

		queue<pair<int, int>> q;            // <current city, current cost>
		q.push({ src, 0 });

		while (!q.empty() && k >= 0) {
			int qsize = q.size();
			while (qsize--) {
				auto city = q.front();
				q.pop();

				for (const auto& next : cities[city.first]) {
				//	cout << "fly to city " << next.to << ", need " << next.price << endl;
					int cost_city_to = city.second + next.price;
					if (min_costs[next.to] == 0 || cost_city_to < min_costs[next.to]) {
						min_costs[next.to] = cost_city_to;
						q.push({ next.to, cost_city_to});
					}
				}
			}
			k--;
		}

		return min_costs[dst] == 0 ? -1 : min_costs[dst];
	}
};
// @lc code=end
