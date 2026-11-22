class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        bool bst = true;
        while(curr){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = NULL;
                    if(prev != NULL && prev->val >= curr->val) bst = false;
                    prev = curr;
                    curr = curr->right;
                }
            }else{
                if(prev != NULL && prev->val >= curr->val) bst = false;
                prev = curr;
                curr = curr->right;
            }
        }
        return bst;
    }


        // Method-2
    // class Triplet{
    //     public:
    //     long long max;
    //     long long min;
    //     bool isBST;
    // };

    // Triplet valid(TreeNode* root){
    //     if(root == NULL) return {LLONG_MIN , LLONG_MAX , true};
    //     long long val = root->val;
    //     Triplet left = valid(root->left);
    //     Triplet right = valid(root->right);
    //     long long mx = max(val,max(left.max , right.max));
    //     long long mn = min(val,min(left.min,right.min));
    //     bool isBST(val > left.max && val < right.min && left.isBST && right.isBST);
    //     return {mx,mn,isBST};
    // }

    // bool isValidBST(TreeNode* root) {
    //     return valid(root).isBST;
    // }


        // Method-1
    // void inorder(TreeNode* root , vector<int>& ans){
    //     if(root == NULL) return;
    //     inorder(root->left , ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }
    // bool isValidBST(TreeNode* root) {
    //     vector<int> ans;
    //     inorder(root,ans);
    //     int i=0;
    //     while(i<ans.size()-1){
    //         if(ans[i] >= ans[i+1])  return false;
    //         i++;
    //     }
    //     return true;
    // }
};