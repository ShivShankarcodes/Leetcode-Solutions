class Solution {
public:
    long long mxSum ;

    class Quad {
        public:
            long long max;
            long long min;
            bool isBST;
            long long sum;
    };

    Quad sumBST(TreeNode* root){
        if(root == NULL)
            return {LLONG_MIN,LLONG_MAX,true,0};
        
        Quad left = sumBST(root->left);
        Quad right = sumBST(root->right);

        long long val = root->val;
        long long mx = max(val,max(left.max,right.max));
        long long mn = min(val,min(left.min,right.min));
        bool isBST (val > left.max && val < right.min && left.isBST && right.isBST);
        long long sum = val + left.sum + right.sum;

        if(isBST) mxSum = max(sum,mxSum);
        return {mx,mn,isBST,sum};
    }
    int maxSumBST(TreeNode* root) {
        mxSum = 0;
        sumBST(root);
        return mxSum;
    }
};