//{ Driver Code Starts
//Initial template for C++

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
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    void solve(Node* head,int &carry)
    {
        if(head == NULL)
        {
            return;
        }
        if(head->next == NULL)
        {
            head->data = (head->data + 1);
            carry = head->data/10;
            head->data = head->data%10;
            return;
        }
        solve(head->next,carry);
        head->data = (head->data+carry);
        carry = head->data/10;
        head->data = head->data%10;
    }
    
    Node* addOne(Node *head) 
    {
        int carry = 0;
        solve(head,carry);
        if(carry != 0)
        {
            Node* newnode = new Node(carry);
            newnode->next = head;
            return newnode;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends