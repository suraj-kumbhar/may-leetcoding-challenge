// Remove K Digits
// Solution
// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.


// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         if (num.length() <= k) return "0";
//         string ret;
//         for (auto d : num) {
//             while (k && ret.length() && ret.back() > d) {
//                 ret.pop_back();
//                 --k;
//             }
//             ret.push_back(d);
//         }
//         ret.resize(ret.length() - k);
//         int beg = 0;
//         while (beg < ret.length() - 1 && ret[beg] == '0') ++beg;
//         return ret.substr(beg, ret.length() - beg + 1);
//     }
// };

// static auto fastio = [](){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return nullptr;
// }();


class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.length();

        if (k == 0) return s;
        int i = 0;

        while (k) {
            i = (i > 0) ? i - 1 : i;
            while (i < n - 1 && s[i] <= s[i + 1])
                i++;
            s.erase(s.begin() + i);
            k--;
        }

        auto nonZero = s.find_first_not_of("0");
        s.erase(0, nonZero);

        if (s == "") return "0";

        return s;
    }
};

static auto fastio = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();


