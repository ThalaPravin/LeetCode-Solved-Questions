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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int cnt=1;
        while(temp->next!=NULL) {
            cnt++;
            temp=temp->next;
        }

        if(cnt%2==0)cnt=(cnt/2)+1;
        else cnt= (cnt+1 )/2;

        ListNode* ans=head;
        cnt--;
        while(cnt--){
            ans=ans->next;
        }
        return ans;

    }
};