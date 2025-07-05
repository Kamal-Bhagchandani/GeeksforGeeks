/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/merge-k-sorted-linked-lists
*/

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeTwo(Node* head1,Node* head2){
        Node* dummy = new Node(-1);
        Node* curr=dummy;
        while(head1 && head2){
            if(head1->data<=head2->data){
                curr->next=head1;
                head1=head1->next;
            }
            else{
                curr->next=head2;
                head2=head2->next;
            }
            curr=curr->next;
        }
        if(head1)
            curr->next=head1;
        else
            curr->next=head2;
            
        return dummy->next;
    }
    Node* mergeListsRec(int i,int j,vector<Node*>& arr){
        if(i==j)
            return arr[j];
            
        int mid=i+(j-i)/2;
        
        Node* head1 = mergeListsRec(i,mid,arr);
        Node* head2 = mergeListsRec(mid+1,j,arr);
        Node* head=mergeTwo(head1,head2);
        
        return head;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if (arr.size()==0)
            return NULL;
            
        return mergeListsRec(0,arr.size()-1,arr);
    }
};