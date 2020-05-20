// Kth Smallest Element in a BST
// Solution
// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

//    Hide Hint #1
// Try to utilize the property of a BST.
//    Hide Hint #2
// Try in-order traversal. (Credits to @chan13)
//    Hide Hint #3
// What if you could modify the BST node's structure?
//    Hide Hint #4
// The optimal runtime complexity is O(height of BST).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode* root, int& k, int& ans) {
        if (!root) {
            return;
        }

        if (k > 0 && root->left) {
            inOrderTraversal(root->left, k, ans);
        }

        if (k == 1) {
            ans = root->val;
        }
        // cout<<root->val<<" "<<k<<"\n";
        k--;

        if (k > 0 && root->right) {
            inOrderTraversal(root->right, k, ans);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inOrderTraversal(root, k, ans);
        return ans;
    }
};