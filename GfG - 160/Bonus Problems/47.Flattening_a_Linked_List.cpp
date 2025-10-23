/*
Question Link: vwww.geeksforgeeks.org/batch/gfg-160-problems/track/LL-bonus-problem/problem/flattening-a-linked-list
*/

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/
struct comp{
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        priority_queue<Node*,vector<Node*>, comp> pq;
        
        Node* head = NULL;
        Node* tail = NULL;
        
        while(root){
            pq.push(root);
            root = root->next;
        }
        
        while(!pq.empty()){
            auto minNode = pq.top();
            pq.pop();
            
            if(!head){
                head = minNode;
                tail = minNode;
            }
            else{
                tail->bottom = minNode;
                tail = tail->bottom;
            }
            if(minNode->bottom){
                pq.push(minNode->bottom);
                minNode->bottom = NULL;
            }
        }
        
        return head;
    }
};