#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
}*head;

void create(int n);
void display();
void deleteFirst();
void deleteLast();
void delete_atIndx(int idx);

int main()
{
    int n, idx;

    // Create a doubly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    // Delete data at the beginning of the doubly linked list     
    deleteFirst();

    // Delete data at the end of the doubly linked list     
    deleteLast();

    // Delete data at any index of the doubly linked list  
    printf("\nEnter index to delete data : ");
    scanf("%d", &idx);
    delete_atIndx(idx);

    printf("\nData in the list :\n");
    display();

    return 0;
}

// Creates a node
void create(int n)
{
    struct node* newNode, * temp;
    int data, i;
    if(n>=1){
        head = (struct node*)malloc(sizeof(struct node));
    
        // If unable to allocate memory for the head node
        if (head == NULL) printf("Unable to allocate memory.");
    
        else
        {
            // Input data of the node from the user
            printf("Enter the data of node 1: ");
            scanf("%d", &data);
    
            head->data = data;
            head->next = NULL;
            head->prev = NULL;
    
            temp = head;
            // Create n nodes and add to the linked list
            for (i = 2; i <= n; i++) {
                newNode = (struct node*)malloc(sizeof(struct node));
    
                /* If memory is not allocated for newNode */
                if (newNode == NULL)
                {
                    printf("Unable to allocate memory.");
                    break;
                }
                else
                {
                    printf("Enter the data of node %d: ", i);
                    scanf("%d", &data);
    
                    newNode->data = data;
                    newNode->next = NULL;
                    newNode->prev = temp;
    
                    temp->next = newNode; // Link the previous node i.e., temp to the newNode
    
                    temp = temp->next;
                }
            }
            printf("DOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
    }
}

// Prints the entire linked list
void display()
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    printf("Doubly LinkedList: ");
    struct node* curr = head;
    while (curr != NULL) // Start from the first node
    {
        printf("%d<-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Deletes the first node of the linked list
void deleteFirst()
{
    if (head == NULL) // If the List is empty we return
    {
        printf("Linked List is empty | Nothing to delete \n");
        return;
    }
    else
    {
        struct node* curr = head;
        head = head->next; // Head node pointing to the second node
        if (head != NULL) {
            head->prev = NULL; // Update the previous pointer of the new head to NULL
        }
        free(curr); // Deleting the previous head node
    }
}

// Deletes the last node of the linked list
void deleteLast()
{
    if (head == NULL) // If the List is empty we return
    {
        printf("Linked List is empty | Nothing to delete\n");
        return;
    }
    else if (head->next == NULL)
    {
        //deleteFirst();
        struct node* curr = head;
        head = curr->next;
        free(curr);
        if (head != NULL) {
            head->prev = NULL; // Update the previous pointer of the new head to NULL
        }
    }
    else
    {
        struct node* curr = head;
        while (curr->next != NULL)// Traverse till the last but one node
        {
            curr = curr->next;
        }
        curr->prev->next = NULL; // Next field of the last but one node is made as NULL
        free(curr); // Deleting the last node
    }
}

// Deletes the node at a given position
void delete_atIndx(int idx)
{
    struct node* curr = head;
    if (head == NULL) // We return if the List is empty
    {
        printf("Linked List is empty \n");
        return;
    }
    else if (idx == 0)
    {
        //deleteFirst();
        curr = head;
        head = curr->next; // Head pointing to the second node
        if (head != NULL) {
            head->prev = NULL; // Update the previous pointer of the new head to NULL
        }
        free(curr); // Deleting the node at index 0
    }
    else
    {
        struct node* prev;
        for (int i = 0; i < idx; i++)
        {
            prev = curr;
            curr = curr->next;
            if (curr == NULL) { printf("Index out of bound.\n"); return; }
        }
        prev->next = curr->next; // Previous node pointing to the pos+1 node
        if (curr->next != NULL) {
            curr->next->prev = prev; // Update the previous pointer of the pos+1 node
        }
        free(curr); // Deleting the node at index pos
    }
}