/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slw=head;
        ListNode* fst=head;

        while(fst!=NULL && fst->next!=NULL){
            slw=slw->next;
            fst=fst->next->next;
            if(slw==fst) return true;
        }
        return false;
    }
};