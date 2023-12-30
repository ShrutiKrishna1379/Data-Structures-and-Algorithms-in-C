#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly circular linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void create(int n);
void display();
void addFirst(int data);
void addLast(int data);
void add_atIndx(int idx, int data);

int main() {
    int n, data;

    // Create a doubly circular linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    // Insert data at the beginning of the doubly circular linked list     
    printf("\nEnter data to insert at first : ");
    scanf("%d", &data);
    addFirst(data);

    // Insert data at the end of the doubly circular linked list     
    printf("\nEnter data to insert at end : ");
    scanf("%d", &data);
    addLast(data);

    // Insert data at any index of the doubly circular linked list 
    int idx;
    printf("\nEnter index and data : ");
    scanf("%d %d", &idx, &data);
    add_atIndx(idx, data);

    printf("\nData in the list :\n");
    display();

    return 0;
}

// creates a doubly circular linked list
void create(int n) {
    struct node* newNode, * temp;
    int data, i;
    if (n >= 1) {
        head = (struct node*)malloc(sizeof(struct node));

        if (head == NULL)
            printf("Unable to allocate memory.");

        else {
            printf("Enter the data of node 1: ");
            scanf("%d", &data);

            head->data = data;
            head->next = head;
            head->prev = head;

            temp = head;

            for (i = 2; i <= n; i++) {
                newNode = (struct node*)malloc(sizeof(struct node));

                if (newNode == NULL) {
                    printf("Unable to allocate memory.");
                    break;
                } else {
                    printf("Enter the data of node %d: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->next = head;
                    newNode->prev = temp;

                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            printf("DOUBLY CIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
        }
    }
}

// prints the entire doubly circular linked list
void display() {
    if (head == NULL) {
        printf("Doubly Circular Linked List is Empty\n");
        return;
    }
    printf("Doubly Circular Linked List: ");
    struct node* curr = head;
    do {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("HEAD\n");
}

//to insert node at start of doubly circular linked list
void addFirst(int data) {
    struct node* newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Unable to allocate memory.");
    } else {
        newNode->data = data;
        newNode->next = head;
        newNode->prev = head->prev;

        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// to insert node at given position in doubly circular linked list
void add_atIndx(int idx, int data) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        return;
    } else {
        struct node* curr = head;
        int c = 0;
        while (c < idx - 1) {
            if (curr->next != head) {
                curr = curr->next;
                c++;
            } else {
                printf("Index out of bound.\n");
                return;
            }
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }
}

// to insert node at end of doubly circular linked list
void addLast(int data) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        return;
    } else {
        struct node* temp = head->prev;
        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        head->prev = newNode;
    }
}