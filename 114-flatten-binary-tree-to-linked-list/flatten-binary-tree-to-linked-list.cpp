class Solution {
public:
    // Method-2 Recursively
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;
        if(left != NULL) root->right = left;
        else root->right = right;

        TreeNode* temp = left;
        while(temp != NULL && temp->right != NULL) temp = temp->right;
        if(temp != NULL) temp->right = right;
    }

    // Method-1
    // void preorder(TreeNode* root,vector<TreeNode*>& ans){
    //     if(root == NULL) return;
    //     ans.push_back(root);
    //     preorder(root->left,ans);
    //     preorder(root->right,ans);
    // }
    // void flatten(TreeNode* root) {
    //     vector<TreeNode*> ans;
    //     preorder(root,ans);
    //     int n = ans.size();
    //     for(int i=0;i<n-1;i++){
    //         ans[i] -> right = ans[i+1];
    //         ans[i] -> left = NULL;
    //     }
    // }
};