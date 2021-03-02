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
    ListNode* reverseNodes(ListNode* head,int sz,int k){
        if(sz<k)return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *thead=head;
        ListNode *cur=thead;
        ListNode * next;
        for(int i=0;i<k;i++){
            next =cur->next;
            cur->next=dummy->next;
            dummy->next=cur;
            cur=next;
        }
        thead->next=reverseNodes(next,sz-k,k);
        return dummy->next;
       
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz=0;
        ListNode *tmp=head;
        while(tmp){
            sz++;
            tmp=tmp->next;
        }
        // ListNode* dummy=new ListNode(0);
        //dummy->next=head;
        return reverseNodes(head,sz,k);
    }
};