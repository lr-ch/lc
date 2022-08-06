/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start

/*
 * example.1:
 *  buckets = 8, minutesToDie = 1, minutesToTest = 1
 *         p1      p2     p3
 *   b0    --      --     --
 *   b1    --      --     T1
 *   b2    --      T1     --
 *   b3    --      T1     T1
 *   b4    T1      --     --
 *   b5    T1      --     T1
 *   b6    T1      T1     --
 *   b7    T1      T1     T1
 *
 *   p1 drinks b4, b5, b6, b7 @ T1
 *   p2 drinks b2, b3, b6, b7 @ T1
 *   p3 drinks b1, b3, b5, b7 @ T1
 *
 *   if no pigs die, b0 is poisonous
 *      only p3    , b1 is poisonous
 *      only p2    , b2 is poisonous
 *         .          .
 *         .          .
 *         .          .
 *
 * example.2:
 *  buckets = 9, minutesToDie = 1, minutesToTest = 2
 *         p1      p2
 *   b0    --      T1
 *   b1    T1      --
 *   b2    --      T1
 *   b3    T1      --
 *   b4    T1      T1
 *
 *   if no pigs die , go next round test for b5 ~ b8
 *   if p1 & p2 die , b4 is poisonous
 *      only p1 dies, b1 or b3 is poisonous -> use p2 to go next round test
 * b1/b3   XX(die) T2
 *      only p2 dies, b0 or b2 is poisonous -> use p1 to go next round test
 * b0/b2   T2      XX(die)
 *
 *   if no pigs die in T1, means the poisonous bucket is in b5 ~ b8
 *   b5    --      --
 *   b6    T2      --
 *   b7    --      T2
 *   b8    T2      T2
 *
 *   if no pigs die, b5 is poisonous
 *         .          .
 *         .          .
 *         .          .
 *
 * Conslusion:
 *  The most buckets B can be tested by pigs P in T round tests is
 *          B = (T + 1) ^ P
 */

class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int trialTimes = minutesToTest / minutesToDie;
		int pigs = 0;

		for (; pow(trialTimes + 1, pigs) < buckets; pigs++);
		return pigs;
	}
};
// @lc code=end
