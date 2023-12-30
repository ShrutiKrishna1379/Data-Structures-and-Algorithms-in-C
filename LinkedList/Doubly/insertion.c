#include <stdio.h>
#include <stdlib.h>
//struct node* head = NULL;
struct node
{
    int data;
    struct node* next;
    struct node* prev;
}*head;

void create(int n);
void display();
void addFirst(int data);
void addLast(int data);
void add_atIndx(int idx, int data);

int main() 
{
    int n, data;

    // Create a doubly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list:\n");
    display();

    // Insert data at the beginning of the doubly linked list
    printf("\nEnter data to insert at first: ");
    scanf("%d", &data);
    addFirst(data);

    // Insert data at the end of the doubly linked list
    printf("\nEnter data to insert at end: ");
    scanf("%d", &data);
    addLast(data);

    // Insert data at any index of the doubly linked list
    int idx;
    printf("\nEnter index and data: ");
    scanf("%d %d", &idx, &data);
    add_atIndx(idx, data);

    printf("\nData in the list:\n");
    display();

    return 0;
}

// Creates a node
void create(int n) {
    struct node* newNode, *temp;
    int data, i;
    if(n>=1){
        head = (struct node*)malloc(sizeof(struct node));

        // If unable to allocate memory for head node
        if (head == NULL)
            printf("Unable to allocate memory.");
        else {
            // Input data of node from the user
            printf("Enter the data of node 1: ");
            scanf("%d", &data);

            head->data = data;
            head->next = NULL;
            head->prev = NULL;

            temp = head;
            // Create n nodes and add to linked list
            for (i = 2; i <= n; i++) {
                newNode = (struct node*)malloc(sizeof(struct node));

                // If memory is not allocated for newNode
                if (newNode == NULL) {
                    printf("Unable to allocate memory.");
                    break;
                } else {
                    printf("Enter the data of node %d: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->next = NULL;
                    newNode->prev = temp;

                    temp->next = newNode; // Link previous node i.e. temp to the newNode

                    temp = temp->next;
                }
            }
            printf("DOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
    }
}

// Prints the entire linked list
void display() {
    if (head == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    printf("Doubly LinkedList: ");
    struct node* curr = head;
    while (curr != NULL) // Start from the first node
    {
        printf("%d<->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// To insert a node at the start of the linked list
void addFirst(int data) 
{
    struct node* newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Unable to allocate memory.");
    } else {
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode; // Make newNode as the first node
    }
}

// To insert a node at a given position
void add_atIndx(int idx, int data) {
    struct node* newNode;
    // Creating a new node
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) // If the list is empty, we return
    {
        head = newNode;
        return;
    } else {
        struct node* curr = head;
        int c = 0;
        while (c < idx - 1) {
            if (curr->next != NULL) {
                curr = curr->next;
                c++;
            } else {
                printf("Index out of bound.\n");
                return;
            }
        }
        // New node pointing to the node at that position
        newNode->next = curr->next;
        newNode->prev = curr;
        // Previous node's next pointer pointing to the new node
        if (curr->next != NULL) {
            curr->next->prev = newNode;
        }
        // Previous node's next pointer pointing to the new node
        curr->next = newNode;
    }
}

// To insert a node at the end of the linked list
void addLast(int data) {
    struct node* newNode;
    // Creating a new node
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode; // If the list is empty, we return
        return;
    } else {
        struct node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Tail node's next pointer pointing to the new node
        curr->next = newNode;
        // New node's previous pointer pointing to the tail node
        newNode->prev = curr;
    }
}