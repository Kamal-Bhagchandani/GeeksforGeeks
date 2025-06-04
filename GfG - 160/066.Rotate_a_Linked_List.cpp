/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/rotate-a-linked-list
*/

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        if( k==0 || head==NULL)
            return head;
        
        Node* temp=head;
        int length=1;
        while(temp->next!=NULL){
            temp=temp->next;
            length++;
        }
        temp->next=head;
        
        k=k%length;
        
        for(int i=0;i<k;i++){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};