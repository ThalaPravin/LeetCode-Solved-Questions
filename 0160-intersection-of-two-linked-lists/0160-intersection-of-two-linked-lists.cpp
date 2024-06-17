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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=1;
        int n2=1;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
            temp1=temp1->next;
            n1++;
        }
        while(temp2!=NULL){
            temp2=temp2->next;
            n2++;
        }
        int diff=0;
        if(n1>n2){
            diff=abs(n1-n2);
            for(int i=0;i<diff;i++){
                headA=headA->next;
            }
        }
        else{
            diff=abs(n2-n1);
            for(int i=0;i<diff;i++){
                headB=headB->next;
            }
        }
        temp1=headA;
        temp2=headB;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};