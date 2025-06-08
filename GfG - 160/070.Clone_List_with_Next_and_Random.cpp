/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/clone-a-linked-list-with-next-and-random-pointer
*/

/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* curr=head;
        while(curr){
            Node* newNode=new Node(curr->data);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=curr->next->next;
        }
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        
        curr=head;
        Node* copyHead=head->next;
        Node* copyCurr=copyHead;
        while(copyCurr->next){
            curr->next=curr->next->next;
            copyCurr->next=copyCurr->next->next;
            curr=curr->next;
            copyCurr=copyCurr->next;
        }
        curr->next=NULL;
        return copyHead;
    }
};