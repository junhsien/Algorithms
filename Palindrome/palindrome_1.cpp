// The idead is to use a stack and push all the nodes into the stack, 
// then again iterate over the linked list to validate if the linked 
// list is palindrome or note
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Node{
public:
    int data;
    Node(int d) { data = d;}
    Node* ptr;
};

bool isPalin(Node *head)
{
    // Temp pointer
    Node *slow = head;
    
    // Declare a stack
    stack<int> s;
    
    // Push all elements of the list to the stack
    while(slow!=NULL)
    {
        s.push(slow->data);
        
        // Move ahead
        slow = slow->ptr;
    }
    
    // iterate in the list again and check by popping from the stack
    while(head != NULL) {
       
        // Get the top most element
        int i = s.top();
        
        // Pop the element
        s.pop();
        
        // Check if data is not same as popped element
        if(head->data != i) {
            return false;
        }
        
        // Move ahead
        head = head->ptr;
    }
    
    return true;
    
}

int main()
{
    // Addition of linked list
    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);
    
    // Initialize the next pointer of every current pointer
    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node *temp = &one;
    
    // call function to check palindrome or note
    bool result = isPalin(&one);
    
    if(result == true)
        printf("isPalindrome is true\n");
    else
        printf("isPalindrome is false\n");
        

    return 0;
}
