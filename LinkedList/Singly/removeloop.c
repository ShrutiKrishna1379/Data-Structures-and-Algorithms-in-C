#include<stdio.h>
#include<stdlib.h>

//struct node* head = NULL;
struct node
{
	int data;
	struct node* next;
}*head;

void create(int n);
void display();
void createLoop(int idx,int n);
void removeLoop();

int main()
{
	int n,idx;

    //Create a singly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    printf("Enter index for creating loop: ");
    scanf("%d", &idx);
    createLoop(idx,n);
    removeLoop();
   
    printf("\nData in the list :\n");
    display();
   
    return 0;
}

//creates a node
void create(int n)
{
	struct node *newNode, *temp;
    int data, i;
    if(n>=1){
        head = (struct node *)malloc(sizeof(struct node));

        // If unable to allocate memory for head node
        if(head == NULL) printf("Unable to allocate memory.");

        else
        {
            //Input data of node from the user
            printf("Enter the data of node 1: ");
            scanf("%d", &data);

            head->data = data; 
            head->next = NULL; 

            temp = head;
              //Create n nodes and adds to linked list
            for(i=2; i<=n; i++){
                newNode = (struct node *)malloc(sizeof(struct node));

                /* If memory is not allocated for newNode */
                if(newNode == NULL)
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

                    temp->next = newNode; // Link previous node i.e. temp to the newNode

                    temp = temp->next; 
                }
            }
            printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
    }
}

// prints the entire LinkedList
void display()
{
	if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
    printf("LinkedList: ");
	struct node* curr = head;
	while(curr!=NULL) // start from first node
	{
		printf("%d-> ",curr->data);
		curr = curr->next;
	}
    printf("NULL\n\n");
}

void createLoop(int idx,int n) {
    if(idx<n){
        struct node* temp = head;
        for (int i=0;i<idx-1;i++) {
          temp = temp->next;
        }
        if(idx==1) temp = temp->next;
        struct node* kth_node = temp;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = kth_node;
        printf("Loop Created Successfully\n\n");
    }else{
        printf("Index out of bound. Therefore loop is not created.\n\n");
    }
  
}

void removeLoop() {
    struct node* slow_p = head;
    struct node* fast_p = head;

    // Detect the loop using Floyd's cycle-finding algorithm
    while (fast_p != NULL && fast_p->next != NULL) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if (slow_p == fast_p) {
            printf("Loop Detected.\n");
            break; // Loop detected
        }
    }

    // If loop is found
    if (slow_p == fast_p) {

        if(fast_p == head){
            struct node *temp = head;
            while (temp->next != head) {
              temp = temp->next;
            }
            temp->next = NULL;
            printf("Loop Removed Successfully\n");
            return;
        }

        slow_p = head;
        
        // Move slow_p to the point of intersection
        while (slow_p->next != fast_p->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }

        // Make fast_p->next as NULL to remove the loop
        fast_p->next = NULL;
        printf("Loop Removed Successfully\n");
    } else {
        printf("No Loop Detected, Nothing to Remove\n");
    }
}

