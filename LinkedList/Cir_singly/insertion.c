#include<stdio.h>
#include<stdlib.h>

// Node structure for a circular linked list
struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void create(int n);
void display();
void addFirst(int data);
void addLast(int data);
void add_atIndx(int idx, int data);

int main() {
    int n, data;

    // Create a circular linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    // Insert data at the beginning of the circular linked list     
    printf("\nEnter data to insert at first : ");
    scanf("%d", &data);
    addFirst(data);

    // Insert data at the end of the circular linked list     
    printf("\nEnter data to insert at end : ");
    scanf("%d", &data);
    addLast(data);

    // Insert data at any index of the circular linked list 
    int idx;
    printf("\nEnter index and data : ");
    scanf("%d %d", &idx, &data);
    add_atIndx(idx, data);

    printf("\nData in the list :\n");
    display();

    return 0;
}

// creates a circular linked list
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

                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            printf("CIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
        }
    }
}

// prints the entire LinkedList
void display() {
    if (head == NULL) {
        printf("Circular Linked List is Empty\n");
        return;
    }
    printf("Circular Linked List: ");
    struct node* curr = head;
    do {
        printf("%d-> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("HEAD\n");
}

// to insert node at start of LinkedList
void addFirst(int data) {
    struct node* newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Unable to allocate memory.");
    } else {
        newNode->data = data;
        newNode->next = head;

        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode; // Make newNode as the last node
        head = newNode;       // Make newNode as first node
    }
}

// to insert node at given position
void add_atIndx(int idx, int data) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(idx==0) { addFirst(data); return;}

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
        curr->next = newNode;
    }
}

// to insert node at end of LinkedList
void addLast(int data) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; // Make newNode as the last node
        newNode->next = head; // Make newNode point to the head, circular link
    }
}