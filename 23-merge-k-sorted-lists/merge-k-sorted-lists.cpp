class Solution {
public:
        // Method-3 (Using Heap)
    typedef pair<int,ListNode*> pil;
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        priority_queue<pil,vector<pil>,greater<pil>> pq;
        for(ListNode* node : arr){
            if(node != NULL) pq.push({node->val,node});
        }

        while (pq.size() > 0){
            pil top = pq.top();
            int val = top.first;
            ListNode* node = top.second;
            pq.pop();
            if(node->next != NULL) 
                pq.push({node->next->val,node->next});
            temp->next = node;
            temp = node;
        }
        return dummy->next;
    }
            // Method 2
    // ListNode* merge(ListNode* head1 , ListNode* head2){
    //     ListNode* dummy = new ListNode(0);
    //     ListNode* i = head1;
    //     ListNode* j = head2;
    //     ListNode* k = dummy;
    //     while(i != NULL && j != NULL){
    //         if(i->val < j->val){
    //             k->next = i;
    //             i = i->next;
    //             k = k->next;
    //         }
    //         else{
    //             k->next = j;
    //             j = j->next;
    //             k = k->next;
    //         }
    //     }
    //     if(i == NULL) k->next = j;
    //     else k->next = i;
    //     return dummy->next;
    // }
    //     // Method 2
    // ListNode* mergeKLists(vector<ListNode*>& arr) {
    //     if(arr.size() == 0) return NULL;
    //     vector<ListNode*> temp; // create a empty vector
    //     while( arr.size() + temp.size() > 1){
    //         while(arr.size() > 1){
    //             ListNode* a = arr[arr.size()-1];
    //             arr.pop_back();
    //             ListNode* b = arr[arr.size()-1];
    //             arr.pop_back();
    //             ListNode* c = merge(a,b);
    //             temp.push_back(c);
    //         }
    //         while(temp.size() > 1){
    //             ListNode* a = temp[temp.size() - 1];
    //             temp.pop_back();
    //             ListNode* b = temp[temp.size() - 1];
    //             temp.pop_back();
    //             ListNode* c = merge(a,b);
    //             arr.push_back(c);
    //         }
    //         if( arr.size() == 1 && temp.size() == 1) {
    //             temp.push_back(arr[0]);
    //             arr.pop_back();
    //         }
    //     }
    //     if(arr.size() != 0) return arr[0];
    //     else  return temp[0];
    // }
    
        // Method 1
    // ListNode* mergeKLists(vector<ListNode*>& arr) { 
    //     if(arr.size() == 0) return NULL;
    //     while(arr.size() > 1){
    //         ListNode* a = arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* b = arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* c = merge(a,b);
    //         arr.push_back(c);
    //     }
    //     return arr[0];
    // }
    
};
