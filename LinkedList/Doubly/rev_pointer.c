#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
} * head;

void create(int n);
void display();
void reverse_p();
struct node* reverse(struct node* head);

int main() {
    int n;

    // Create a doubly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    printf("\nReverse list : \n");
    reverse_p();
    display();

    printf("\nReverse list : \n");
    head=reverse(head);
    display();

    return 0;
}

// Creates a node
void create(int n) {
    struct node* newNode, * temp;
    int data, i;
    if(n>=1){
        head = (struct node*)malloc(sizeof(struct node));
    
        // If unable to allocate memory for head node
        if (head == NULL) printf("Unable to allocate memory.");
    
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
        printf("%d<-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void reverse_p() {
    if (head == NULL) return;
    struct node* temp = NULL;
    struct node* curr = head;

    // Swap next and prev pointers for all nodes of the doubly linked list
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // Update the head pointer to the last node
    if (temp != NULL) {
        head = temp->prev;
    }
}

struct node* reverse(struct node* head) 
{   
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct node *new_head = reverse(head->next);
  head->next->prev = head;
  head->next->next = head;
  head->prev = NULL;
  head->next = NULL;

  return new_head;
}