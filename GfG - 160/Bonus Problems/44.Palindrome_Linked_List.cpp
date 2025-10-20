/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/LL-bonus-problem/problem/check-if-linked-list-is-pallindrome
*/

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  private:
    Node* reverseLL(Node* head){
        Node* prev = NULL;
        while(head){
            Node* headNext = head->next;
            head->next = prev;
            prev = head;
            head = headNext;
        }
        
        return prev;
    }
    
    bool check(Node* head1, Node* head2){
        while(head1 && head2){
            if(head1->data != head2->data)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return true;
    }
  public:
    bool isPalindrome(Node *head) {
        //  code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* head2 = reverseLL(slow->next);
        slow->next = NULL;
        
        bool res = check(head,head2);
        
        head2 = reverseLL(head2);
        slow->next = head2;
        
        return res;
    }
};