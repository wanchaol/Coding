#include <iostream>
#include <stack>
using namespace std;

/**
 *
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
class Solution {
public:
  
    //recursive sol
    bool symhelp(TreeNode* left, TreeNode* right) {
        if(left == nullptr || right == nullptr)
            return left == right;
        
        if(left->val != right->val)
            return false;
        
        return symhelp(left->left, right->right) && symhelp(left->right, right->left);
        
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        //recursive sol
        //return symhelp(root->left, root->right);
        
        //iterative sol, use stack
        stack<TreeNode*> stk;
        
        if(root->left != nullptr){
            if(root->right == nullptr)
                return false;
            else {
                stk.push(root->left);
                stk.push(root->right);
            }
        }
        else {
            if(root->right != nullptr)
                return false;
            else
                return true;
        }
        
        TreeNode *left, *right; 
        
        while(!stk.empty()) {
            
            if(stk.size()%2 != 0)
                return false;
         
            right = stk.top();
			stk.pop();
            left = stk.top();
			stk.pop();
         
            if(left->val != right->val)
                return false;
            
            if(right->right!=nullptr)
            {
                if(left->left!=nullptr) {
                    stk.push(left->left);
                    stk.push(right->right);
                }
                else
                    return false;
            }
            else {
                if(left->left!=nullptr)
                    return false;
            }
            
            if(right->left!=nullptr)
            {
                if(left->right!=nullptr) {
                    stk.push(left->right);
                    stk.push(right->left);
                }
                else
                    return false;
            }
            else {
                if(left->right!=nullptr)
                    return false;
            }
            
            
        }
        
    }
};
