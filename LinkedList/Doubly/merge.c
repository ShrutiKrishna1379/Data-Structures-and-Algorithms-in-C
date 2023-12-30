#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
} * head1, *head2,*head;

struct node* create(int n);
void display(struct node* head);
struct node* merge(struct node* head1,struct node* head2);

int main() {
    int n;

    // Create a doubly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    head1=create(n);
    printf("\nData in the first list : \n");
    display(head1);

    printf("\nEnter the total number of nodes: ");
    scanf("%d", &n);
    head2=create(n);
    printf("\nData in the second list : \n");
    display(head2);

    head=merge(head1,head2);
  
    printf("\nData in the merge list : \n");
    display(head);

    return 0;
}

// Creates a node
struct node* create(int n) {
    struct node* newNode, * temp;
    int data, i;
    if(n>=1){
        head = (struct node*)malloc(sizeof(struct node));
    
        // If unable to allocate memory for head node
        if (head == NULL){ printf("Unable to allocate memory."); return NULL;}
    
        else {
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
                else {
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
        return head;
    }
}

// Prints the entire linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    struct node* curr = head;
    while (curr != NULL) // Start from the first node
    {
        printf("%d<-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

struct node* merge(struct node* head1,struct node* head2){
    struct node* head = NULL;
    struct node* curr = head;

    while (head1 != NULL)
    {
        
            if (head == NULL)
            {
                head = head1;
                curr = head1;
            }
            else
            {
                curr->next = head1;
                head1->prev = curr;
                curr = head1;
            }
            head1 = head1->next;
    }   
    while (head2 != NULL)
    {
        curr->next = head2;
        head2->prev = curr;
        curr = head2;
        head2 = head2->next;
    }

    return head;
}