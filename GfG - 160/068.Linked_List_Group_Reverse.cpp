/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list-in-groups-of-given-size
*/

/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* curr = head;
        Node* newHead = NULL;
        Node* tail = NULL;
        
        while(curr){
            Node* groupHead=curr;
            Node* prev=NULL;
            int count=0;
            
            while(curr && count<k){
                Node* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                count++;
            }
            if(newHead==NULL){
                newHead=prev;
            }
            if(tail != NULL){
                tail->next=prev ;
            }
            tail=groupHead; 
        }
        return newHead;
    }
};