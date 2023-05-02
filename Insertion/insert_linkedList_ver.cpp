/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    
    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
    if(prev_node == NULL) {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void append(Node** head_ref, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = NULL;

    Node *last = *head_ref;

    if(*head_ref == NULL) {
        (*head_ref) = new_node;
        return;
    }

    while(last->next!=NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void printList(Node* head)
{
    if(head==NULL){
        cout << "the listed list cannot be NULL";
        return;
    }

    while(head->next!=NULL){
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << head->data;
    cout << endl;
}

int main()
{
    Node*head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning 
    // So Linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    //Insert 4 at the end
    // So linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8 after 7
    // So linked list becones 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    printList(head);
}
