/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* &h1, Node* &h2){
        Node* left = h1;
        Node* right = h2;
        
        Node* temp = new Node(-1);
        Node* prev = temp;
        
        while(left && right){
            if(left-> data < right->data){
                temp->bottom = left;
                temp = left;
                left = left->bottom;
            }else{
                temp-> bottom = right;
                temp = right;
                right = right->bottom;
            }
        }
        while(left){
            temp -> bottom = left;
            temp = left;
            left = left -> bottom;
        }
        while(right){
            temp -> bottom = right;
            temp = right;
            right = right -> bottom;
        }
        
        return prev->bottom;
    }
    
    Node *flatten(Node *root) {
        if(!root || !root->next) return root;
        
        Node* h1 = root;
        Node* h2 = root->next;
        
        while(h2){
            h1->next = NULL;
            h1 = merge(h1, h2);
            h2 = h2->next;
        }
        
        return h1;
    }
};