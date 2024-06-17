class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==0) return NULL;

        int length=0;
        ListNode*temp=head;
        ListNode*tail=NULL;

        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
            length++;
        }
        k= k % length;
       
        temp=head;
        for(int i=1;i<(length-k);i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};