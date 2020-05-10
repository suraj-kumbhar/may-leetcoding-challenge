// Cousins in Binary Tree
// Solution
// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

// Return true if and only if the nodes corresponding to the values x and y are cousins.

 

// Example 1:


// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:


// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:



// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
 

// Note:

// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.
 

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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root||root->val==x||root->val==y) return false;
        int dX=-1;
        int dY=-1;
        int pX=0;
        int pY=0;
        parentAndDepth(root,0,dX,dY,pX,pY,x,y);
        return ((dX==dY)&&(pX!=pY));
    }
    void parentAndDepth(TreeNode* root,int h,int &dX,int &dY,int &pX,int &pY, int x, int y) {
        if(!root) return;
        
        if(root->right) {
            if(root->right->val==x) {
                dX=h+1;
                pX=root->val;
            }
            else if(root->right->val == y) {
                dY=h+1;
                pY=root->val;
            }
        }
        if(root->left) {
            if(root->left->val==x) {
                dX=h+1;
                pX=root->val;
            }
            else if(root->left->val == y) {
                dY=h+1;
                pY=root->val;
            }
        }
        if((dY!=-1)&&(dX!=-1)) return;
        
        parentAndDepth(root->left,h+1,dX,dY,pX,pY,x,y);
        parentAndDepth(root->right,h+1,dX,dY,pX,pY,x,y);
        
    }
};