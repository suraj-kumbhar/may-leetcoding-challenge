// Interval List Intersections
// Solution
// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)



// Example 1:



// Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
// Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.


// Note:

// 0 <= A.length < 1000
// 0 <= B.length < 1000
// 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

// class Solution {
// public:
//     vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
//         vector<vector<int>> v;
//         int i=0;
//         int j=0;
//         int m=A.size();
//         int n=B.size();
//         while(i<m&&j<n) {
//             cout<<i<<" "<<j<<"\n";
//             int minX=A[i][0];
//             int minY=B[i][0];
//             int maxX=A[i][1];
//             int maxY=B[i][1];
//             cout<<"minX : "<<minX<<" minY : "<<minY<<" maxX : "<<maxX<<" maxy : "<<maxY<<"\n";
//             vector<int> t;
//             if(minX<minY) {
//                 cout<<"condi 1\n";
//                 if(maxX>=minY) {
//                     t.push_back(minY);
//                     t.push_back(maxX);
//                 }

//                 if(maxX<maxY) {
//                     i++;
//                 }
//                 else if(maxX>maxY) {
//                     j++;
//                 }
//                 else if(maxX==maxY) {
//                     i++;
//                     j++;
//                 }
//             }
//             else if(minX>minY) {
//                 cout<<"condi 2\n";
//                 if(maxY>=minX) {
//                     t.push_back(minX);
//                     t.push_back(maxY);
//                 }
//                 if(maxX<maxY) {
//                     i++;
//                 }
//                 else if(maxX>maxY) {
//                     j++;
//                 }
//                 else {
//                     i++;
//                     j++;
//                 }
//             }

//             if(t.size()==2) {
//                 v.push_back(t);
//             }
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> v;
        int a = 0;
        int b = 0;
        int m = A.size();
        int n = B.size();
        vector<int> t(2);

        while (a < m && b < n) {
            if (B[b][0] <= A[a][1] && A[a][0] <= B[b][1]) {
                t[0] = max(A[a][0], B[b][0]);
                t[1] = min(A[a][1], B[b][1]);
                v.push_back(t);
            }
            if (A[a][1] > B[b][1])
            {
                b += 1;
            }
            else {
                a += 1;
            }
        }
        return v;
    }
};