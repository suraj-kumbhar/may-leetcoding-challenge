// Construct Binary Search Tree from Preorder Traversal
// Solution
// Return the root node of a binary search tree that matches the given preorder traversal.

// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

// It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

// Example 1:

// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]



// Constraints:

// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 10^8
// The values of preorder are distinct.


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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = 0;
        int i = 0;
        build_tree(&root, i, preorder, -1e9, 1e9);
        return root;
    }

    void build_tree(TreeNode** n, int& i, const vector<int>& v, const int& min_range, const int& max_range) {
        if (i >= v.size() || v[i] < min_range || max_range < v[i]) return;
        *n = new TreeNode(v[i++]);
        build_tree(&((*n)->left ), i, v, min_range, (*n)->val);
        build_tree(&((*n)->right), i, v, (*n)->val, max_range);
    }

};