// Find All Anagrams in a String
// Solution
// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int len = s.size();
        int window = p.size();
        vector<int> ans;
        if (len < window) {
            return ans;
        }
        int left = 0;
        int right = 0;
        while (right < window) {
            phash[p[right] - 'a'] += 1;
            hash[s[right++] - 'a'] += 1;
        }
        right -= 1;
        while (right < len) {
            if (phash == hash) {
                ans.push_back(left);
            }
            right += 1;
            if (right != len) {
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -= 1;
            left += 1;
        }
        return ans;
    }
};