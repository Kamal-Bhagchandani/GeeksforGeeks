/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/find-the-first-node-of-loop-in-linked-list--170645
*/

// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};