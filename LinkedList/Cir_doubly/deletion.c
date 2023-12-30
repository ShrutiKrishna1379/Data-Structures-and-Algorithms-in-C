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

int main() {
    int n, idx;

    // Create a circular doubly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    // Delete data at the beginning of the circular doubly linked list     
    deleteFirst();

    // Delete data at the end of the circular doubly linked list     
    deleteLast();

    // Delete data at any index of the circular doubly linked list  
    printf("\nEnter index to delete data : ");
    scanf("%d", &idx);
    delete_atIndx(idx);

    printf("\nData in the list :\n");
    display();

    return 0;
}

// Creates a node in a circular doubly linked list
void create(int n) {
    struct node* newNode, * temp;
    int data, i;
    if(n>=1){
        head = (struct node*)malloc(sizeof(struct node));
    
        // If unable to allocate memory for the head node
        if (head == NULL) printf("Unable to allocate memory.");
    
        else {
            // Input data of the node from the user
            printf("Enter the data of node 1: ");
            scanf("%d", &data);
    
            head->data = data;
            head->next = head;
            head->prev = head;
    
            temp = head;
            // Create n-1 nodes and add to the circular doubly linked list
            for (i = 2; i <= n; i++) {
                newNode = (struct node*)malloc(sizeof(struct node));
    
                /* If memory is not allocated for newNode */
                if (newNode == NULL) {
                    printf("Unable to allocate memory.");
                    break;
                } else {
                    printf("Enter the data of node %d: ", i);
                    scanf("%d", &data);
    
                    newNode->data = data;
                    newNode->next = head; // Link last node to the head to make the list circular
                    newNode->prev = temp;
    
                    temp->next = newNode; // Link previous node i.e., temp to the newNode
    
                    head->prev = newNode; // Update the previous pointer of the head to the new last node
    
                    temp = temp->next;
                }
            }
            printf("CIRCULAR DOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
    }
}

// Prints the entire circular doubly linked list
void display() {
    if (head == NULL) {
        printf("Circular Doubly Linked List is Empty\n");
        return;
    }
    printf("Circular Doubly LinkedList: ");
    struct node* curr = head;
    do {
        printf("%d<-> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("HEAD\n");
}

// Deletes the first node of the circular doubly linked list
void deleteFirst() {
    if (head == NULL) // If the List is empty we return
    {
        printf("Circular Doubly Linked List is empty | Nothing to delete \n");
        return;
    } else {
        struct node* curr = head;
        head = head->next; // Head node pointing to the second node
        head->prev = curr->prev; // Update the previous pointer of the new head to the previous pointer of the old head

        curr->prev->next = head; // Update the next pointer of the last node to the new head

        free(curr); // Deleting the previous head node
    }
}

// Deletes the last node of the circular doubly linked list
void deleteLast() {
    if (head == NULL) // If the List is empty we return
    {
        printf("Circular Doubly Linked List is empty | Nothing to delete\n");
        return;
    } else {
        struct node* curr = head;
        struct node* prev = NULL;

        // Traverse to the last node and keep track of the previous node
        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next; // Next field of the last but one field is made as the new head
        head->prev = prev; // Update the previous pointer of the head to the new last node

        free(curr); // Deleting the last node
    }
}

// Deletes the node at a given position in the circular doubly linked list
void delete_atIndx(int idx) {
    struct node* curr = head;
    if (head == NULL) // We return if the List is empty
    {
        printf("Circular Doubly Linked List is empty \n");
        return;
    } else if (idx == 0) {
        deleteFirst();
    } else {
        struct node* prev;
        for (int i = 0; i < idx; i++) {
            prev = curr;
            curr = curr->next;
            if (curr == head) {
                printf("Index out of bound.\n");
                return;
            }
        }
        prev->next = curr->next; // Previous node pointing to the pos+1 node
        curr->next->prev = prev; // Update the previous pointer of the pos+1 node
        free(curr); // Deleting the node at index pos
    }
}
