/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
	stack<pair<int, int>> s;	// <day, price>
public:
	StockSpanner() {

	}

	int next(int price) {
		int span = 1;
		while (!s.empty() && s.top().second <= price) {
			span += s.top().first;
			s.pop();
		}
		s.push({ span, price });
		return span;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

