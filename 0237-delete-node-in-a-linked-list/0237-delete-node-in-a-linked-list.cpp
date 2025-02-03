
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node -> next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete nextNode;
    }
};