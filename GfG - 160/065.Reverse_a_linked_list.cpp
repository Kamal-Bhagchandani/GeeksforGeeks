/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list
*/


/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        if (head==NULL  || head->next==NULL) return head;
        Node *rest= reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
};