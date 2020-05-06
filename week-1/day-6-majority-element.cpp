// Majority Element
// Solution
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> m;
//         int n=nums.size()/2;
//         for(int i:nums) {
//             m[i]=(m.find(i)!=m.end())?++m[i]:1;
//             if(m[i]>n)  return i;
//         }
//         return -1;
//     }
    
// };


class Solution {
public:
    Solution() {ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        int maxCount=1;
        int maxDig=nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==maxDig) maxCount++;
            else maxCount--;
            if(maxCount==0) {
                maxCount=1;
                maxDig=nums[i];
            }
        }
        return maxDig;
        
    }
};
