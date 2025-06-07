/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/add-two-numbers-represented-by-linked-lists
*/

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* trimLeadingZeros(Node* head){
        while(head && head->data==0){
            head=head->next;
        }
        return head;
    }
    int length(Node* head){
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    Node* reverseList(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        while(curr){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1=trimLeadingZeros(num1);
        num2=trimLeadingZeros(num2);
        
        int len1=length(num1);
        int len2=length(num2);
        if (len1<len2)
            return addTwoLists(num2,num1);
        
        num1=reverseList(num1);
        num2=reverseList(num2);
        
        Node* res=num1;
        int carry=0;
        
        while(num2 || carry!=0){
            num1->data+=carry;
            
            if(num2){
                num1->data+=num2->data;
                num2=num2->next;
            }
            carry=num1->data/10;
            num1->data=num1->data%10; 
            
            if(num1->next==NULL && carry!=0){
                num1->next=new Node(0);
            }
            num1=num1->next;
        }
        return reverseList(res);
    }
};