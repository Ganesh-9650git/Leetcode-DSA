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
    ListNode* rev(ListNode* head){
        ListNode* temp=head;
        ListNode* prevnode=NULL;
        while(temp!=NULL){
            ListNode* nextnode=temp->next;
            temp->next=prevnode;
            prevnode=temp;
            temp=nextnode;;

        }
        return prevnode;
    }

    ListNode* findk(ListNode* head,int k){
        k=k-1;
        ListNode* temp=head;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=NULL;
        ListNode* nextnode;
        while(temp!=NULL){
        ListNode* knode=findk(temp,k);
        if(knode==NULL){
            if(prevnode!=NULL){
                prevnode->next=temp;
            }
            break;
        }
        nextnode=knode->next;
        knode->next=NULL;
        rev(temp);
        if(temp==head){
            head=knode;
        }
        else{
            prevnode->next=knode;
        }
        prevnode=temp;
        temp=nextnode;
        }
        return head;
    }
};