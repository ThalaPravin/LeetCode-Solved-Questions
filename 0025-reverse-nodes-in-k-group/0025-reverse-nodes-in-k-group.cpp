/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* krev(ListNode* head, int k){
        if(head == NULL){
            return NULL;
        }
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;

        ListNode* check = head;
        for (int i = 0; i < k; ++i) {
            if (!check) return head; // Not enough nodes left, return head
            check = check->next;
        }
        while(curr != NULL && cnt < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if(next != NULL){
            head -> next = krev(next, k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return krev(head,k);
        
    }
};