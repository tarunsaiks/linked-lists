// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-Linked-list/1
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        Node *slow_ptr = head;
        Node *fast_ptr = head;
        
        while(slow_ptr && fast_ptr && fast_ptr->next != NULL){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr->data;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for(int i = 0; i < N-1; i++){
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        cout<<ob.getMiddle(head)<<endl;
    }
    return 0;
}