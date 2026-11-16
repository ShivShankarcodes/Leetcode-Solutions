class Solution {
public:
    TreeNode* convert(vector<int>& arr,int low ,int high){
        if(low > high) return NULL;
        int mid =(low + high)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = convert(arr,low,mid-1);
        root->right = convert(arr,mid+1,high);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n = arr.size();
        return convert(arr,0,n-1);
    }
};