class Solution {
public:
        // Method-2
    class Triplet{
        public:
        long long mx;
        long long mn;
        bool isBST;
    };

    Triplet valid(TreeNode* root){
        if(root == NULL) return {LLONG_MIN , LLONG_MAX , true};
        long long val = root->val;
        Triplet left = valid(root->left);
        Triplet right = valid(root->right);
        long long mx = max(val,max(left.mx , right.mx));
        long long mn = min(val,min(left.mn,right.mn));
        bool isBST(val > left.mx && val < right.mn && left.isBST && right.isBST);
        return {mx,mn,isBST};
    }

    bool isValidBST(TreeNode* root) {
        return valid(root).isBST;
    }


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