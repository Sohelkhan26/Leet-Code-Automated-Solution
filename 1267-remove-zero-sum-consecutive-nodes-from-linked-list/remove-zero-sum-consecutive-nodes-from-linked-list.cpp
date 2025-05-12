class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        head = new ListNode(-1 , head);
        unordered_map <int , ListNode*> prev;
        int sum = 0;
        ListNode *curr = head;
        while(curr){
            sum += curr -> val;
            prev[sum] = curr;
            curr = curr -> next;
        }
        curr = head , sum = 0;
        while(curr){
            sum += curr -> val;
            curr -> next = prev[sum] -> next;
            curr = curr -> next;
        }
        return head -> next;
    }
};

/*
Follows a two loop approach. Stores the last occurance of sum.
Again traversing from left to right, if sum exist in the map, then the intermediate subarray needs to be removed. Doesn't require handling intermediate prefix sum erasure from map.
*/