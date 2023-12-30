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
void reverse_p();
struct node* reverse(struct node* head);

void main()
{
	int n;

    //Create a singly linked list of n nodes
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
    printf("NULL\n");
}

void reverse_p(){
    if (head == NULL) return;
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        //update
        prev=curr;
        curr=next;
    }
    head=prev; 
}

struct node* reverse(struct node* head) 
{   
    if (head == NULL || head->next == NULL) {
      return head;
    }
  
    struct node* new_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
  
    return new_head;
}