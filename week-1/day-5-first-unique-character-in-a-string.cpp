// First Unique Character in a String
// Solution
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> v(26,0);
        
        for(char c:s) {
            v[c-'a']++;
        }
        
        for(int i=0; i<s.length();i++) {
            if(v[s[i]-'a']==1) {
                cout<<i;
                return i;
            }
                
        }
        return -1;
    }
};