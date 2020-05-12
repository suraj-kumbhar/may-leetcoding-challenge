// Single Element in a Sorted Array
// Solution
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.



// Example 1:

// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: [3,3,7,7,10,11,11]
// Output: 10


// Note: Your solution should run in O(log n) time and O(1) space.
//xor solution

// class Solution {
// public:
// 	int singleNonDuplicate(vector<int>& nums) {
// 		int res = 0;
// 		for (int i : nums) res = res ^ i;
// 		return res;
// 	}
// };

//optimized solution using binary search
class Solution {
public:
	int singleNonDuplicate(vector<int>& v) {
		int n = v.size();
		if (n == 1) return v[0];
		if (v[0] != v[1])  return v[0];
		if (v[n - 1] != v[n - 2]) return v[n - 1];
		int l = 0;
		int r = n - 1;
		int m;
		while (l <= r) {
			m = l + (r - l) / 2;
			if (v[m] != v[m - 1] && v[m] != v[m + 1])  return v[m];

			if (m % 2 == 0) {
				if (v[m] == v[m - 1]) r = m;
				else if (v[m] == v[m + 1]) l = m;
			}
			else if (m % 2 == 1) {
				if (v[m] == v[m + 1]) r = m - 1;
				else if (v[m] == v[m - 1]) l = m + 1;
			}
		}
		return -1;
	}
};