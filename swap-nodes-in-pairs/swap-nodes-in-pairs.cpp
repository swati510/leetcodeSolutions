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
    ListNode* swapPairs(ListNode* head) {
        int flag=0;
        ListNode*temp=head;
        while(temp&&temp->next){
            int val=temp->next->val;
            temp->next->val=temp->val;
            temp->val=val;
            temp=temp->next->next;
            
        }
        return head;
        
    }
};