class Solution {
public:
    // Method-1
    void inorder(TreeNode* root ,int& ans , int& k2){
        if(root == NULL) return;
        inorder(root->left,ans,k2 );
        k2--;
        if(k2 == 0) ans = root->val;
        inorder(root->right,ans,k2);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int k2 = k;
        inorder(root,ans,k2);
        return ans; 
    }
    // Method-2
    // void inorder(TreeNode* root , vector<int>& ans){
    //     if(root == NULL) return;
    //     inorder(root->left , ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> ans;
    //     inorder(root,ans);
    //     return ans[k-1];
    // }
};