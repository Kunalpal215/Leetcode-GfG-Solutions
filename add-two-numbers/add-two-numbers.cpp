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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int rem=0;
    ListNode* temp=new ListNode(0);
    ListNode* head=temp;
    while(l1!=NULL && l2!=NULL){
        int add=l1->val+l2->val+rem;
        ListNode* nextNode=new ListNode(add%10);
        add/=10;
        rem=add;
        head->next=nextNode;
        head=head->next;
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        int add=l1->val+rem;
        ListNode* newNode=new ListNode(add%10);
        add/=10;
        rem=add;
        head->next=newNode;
        head=head->next;
        l1=l1->next;
    }
    while(l2!=NULL){
        int add=l2->val+rem;
        ListNode* newNode=new ListNode(add%10);
        add/=10;
        rem=add;
        head->next=newNode;
        head=head->next;
        l2=l2->next;
    }
    if(rem>0){
        ListNode* newNode=new ListNode(rem);
        head->next=newNode;
    }
    ListNode* toDelete = temp;
    temp=temp->next;
    delete toDelete;
    return temp;
}
};