#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void create(int n);
void display();
void deleteFirst();
void deleteLast();
void delete_atIndx(int idx);

int main() {
    int n, idx;

    // Create a circular linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    // Delete data at the beginning of the circular linked list     
    deleteFirst();
    
    // Delete data at the end of the circular linked list     
    deleteLast();

    // Delete data at any index of the circular linked list  
    printf("\nEnter index to delete data : ");
    scanf("%d", &idx);
    delete_atIndx(idx);

    printf("\nData in the list :\n");
    display();

    return 0;
}

// creates a node in a circular linked list
void create(int n) {
    struct node* newNode, * temp;
    int data, i;
    if(n>=1){
        head = (struct node*)malloc(sizeof(struct node));
    
        if (head == NULL) printf("Unable to allocate memory.");
    
        else {
            // Input data of node from the user
            printf("Enter the data of node 1: ");
            scanf("%d", &data);
    
            head->data = data;
            head->next = head;
    
            temp = head;
            // Create n-1 nodes and add to the circular linked list
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
    
                    temp->next = newNode; // Link previous node i.e. temp to the newNode
    
                    temp = temp->next;
                }
            }
            printf("CIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
        }
    }
}

// prints the entire circular LinkedList
void display() {
    if (head == NULL) {
        printf("Circular Linked List is Empty\n");
        return;
    }
    printf("Circular LinkedList: ");
    struct node* curr = head;
    do {
        printf("%d-> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("HEAD\n");
}

// to delete the first node of a circular LinkedList
void deleteFirst() {
    if (head == NULL) // if List is empty we return
    {
        printf("Circular Linked List is empty | Nothing to delete \n");
        return;
    } else {
        struct node* curr = head;
        struct node* temp = head;

        // Traverse to the last node to update its next pointer
        while (temp->next != head) {
            temp = temp->next;
        }

        head = head->next; // head node pointing to the second node
        temp->next = head; // Update next pointer of the last node to the new head

        free(curr); // deleting prev head node
    }
}

// to delete the last node of a circular LinkedList
void deleteLast() {
    if (head == NULL) // if List is empty we return
    {
        printf("Circular Linked List is empty | Nothing to delete\n");
        return;
    } else {
        struct node* curr = head;
        struct node* prev = NULL;

        // Traverse to the last node and keep track of the previous node
        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
        }

        // If there is only one node, delete the first node
        if (prev == NULL) {
            deleteFirst();
            return;
        }

        prev->next = curr->next; // next field of last but one field is made as the new head
        free(curr); // deleting last node
    }
}

// to delete a node at a given position in a circular LinkedList
void delete_atIndx(int idx) {
    struct node* curr = head;
    if (head == NULL) // we return if List is empty
    {
        printf("Circular Linked List is empty \n");
        return;
    } else if (idx == 0) {
        deleteFirst();
    } else {
        struct node* prev = NULL;
        for (int i = 0; i < idx; i++) {
            prev = curr;
            curr = curr->next;
            if (curr == head) {
                printf("Index out of bound.\n");
                return;
            }
        }
        prev->next = curr->next; // prev node pointing to pos+1 node
        free(curr); // deleting node at pos
    }
}
