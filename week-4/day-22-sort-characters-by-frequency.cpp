// Sort Characters By Frequency
// Solution
// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        vector<pair<char, int>> v;
        for (auto i : m) {
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), [](pair<char, int>& p1, pair<char, int>& p2) {
            return p1.second > p2.second;
        });
        string ans = "";
        for (auto i : v) {
            for (int j = 0; j < i.second; j++) {
                ans += i.first;
            }
        }

        return ans;
    }
};