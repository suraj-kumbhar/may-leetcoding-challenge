// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

//Solution with O(n) space complexity

// class Solution {
// public:
//     bool canConstruct(string a, string b) {
//         unordered_map<char,int> m;
//         for(char c: b) {
//             if(m[c]==0) {
//                 m[c]=1;
//             }
//             else {
//                 m[c]++;
//             }
//         }
//         for(char c:a) {
//             if(m[c]<=0) {
//                 return false;
//             }
//             else {
//                 m[c]--;
//             }
//         }
//         return true;
//     }
// };

// Solution with O(1) space complexity

class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> v(26);
        for(char c: b) {
            v[c-'a']++;
        }
        for(char c:a) {
            if(v[c-'a']<=0) {
                return false;
            }
            v[c-'a']--;
        }
        return true;
    }
};