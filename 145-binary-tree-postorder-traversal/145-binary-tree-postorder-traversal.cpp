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
        
    // Recursive solution

    void solveRecur(TreeNode* root , vector<int> &main){
        if(root==NULL)
            return;
        solveRecur(root->left,main);
        solveRecur(root->right,main);
        main.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        // For recursive part
//         vector<int> main;
//         solveRecur(root,main);
//         return main;
        
        // Iterative Solution using two stacks
        
        // vector<int> postorder;
        // if(root==NULL) return postorder;
        // stack<TreeNode*> s1,s2;
        // s1.push(root);
        // while(!s1.empty()){
        //     root = s1.top();
        //     s1.pop();
        //     s2.push(root);
        //     if(root->left != NULL)
        //         s1.push(root->left);
        //     if(root->right != NULL)
        //         s1.push(root->right);
        // }
        // while(!s2.empty())
        // {
        //     postorder.push_back(s2.top()->val);
        //     s2.pop();
        // }
        // return postorder;
        
    
        // Iterative Solution using one stack

    
        vector<int> postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*> s;
        
        while(root!=NULL || !s.empty()){
            if(root!=NULL){
                s.push(root);
                root = root->left;
            }
            else{
                TreeNode* temp  = s.top()->right;
                if(temp==NULL)
                {
                    temp = s.top();
                    s.pop();
                    postorder.push_back(temp->val);
                    
                    while(!s.empty() && temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else
                    root = temp;
                }
            }
        
        return postorder;

    }
};