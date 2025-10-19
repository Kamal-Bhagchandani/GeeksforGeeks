/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/LL-bonus-problem/problem/intersection-point-in-y-shapped-linked-lists
*/

/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    int getCount(Node* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        
        return cnt;
    }
    Node* getIntersection(int diff,Node* head1, Node* head2){
        Node* curr1 = head1;
        Node* curr2 = head2;
        
        for(int i=0;i<diff;i++){
            if(!curr1)
                return NULL;
            curr1 = curr1->next;
        }
        
        while(curr1 && curr2){
            if(curr1 == curr2){
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return NULL;
    }
    
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int len1 = getCount(head1);
        int len2 = getCount(head2);
        
        int diff = 0;
        
        if(len1>len2){
            diff = len1 - len2;
            return getIntersection(diff,head1,head2);
        }
        else{
            diff = len2 - len1;
            return getIntersection(diff,head2,head1);
        }
    }
};