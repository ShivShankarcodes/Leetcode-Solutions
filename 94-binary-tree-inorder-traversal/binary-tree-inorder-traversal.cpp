class Solution {
public:

    // Method-2
    void morris(TreeNode* root , vector<int>& ans){
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right && pred->right != curr)
                    pred = pred->right;
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }else{
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        morris(root,ans);
        return ans;
    }

    // Method-1
    // void dfs(TreeNode* root , vector<int>& ans){
    //     if(root == NULL) return;
    //     dfs(root->left , ans);
    //     ans.push_back(root->val);
    //     dfs(root->right , ans);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     dfs(root,ans);
    //     return ans;
    // }
};