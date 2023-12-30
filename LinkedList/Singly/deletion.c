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
void deleteFirst();
void deleteLast();
void delete_atIndx(int idx);

int main()
{
	int n, idx;

    //Create a singly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    //Delete data at the beginning of the singly linked list     
    deleteFirst();
    
    //Delete data at the end of the singly linked list     
    deleteLast();

    //Delete data at any index of the singly linked list  
    printf("\nEnter index to delete data : ");
    scanf("%d", &idx);
    delete_atIndx(idx);

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
    printf("NULL\n");
}

// to delete first node of LinkedList
void deleteFirst()
{ 
	if(head==NULL) //if List is empty we return
	{
		printf("Linked List is empty | Nothing to delete \n");
		return;
	}
	else
	{
		struct node* curr = head; 
		head = head->next; // head node pointing to second node
		free(curr); // deleting prev head node
	}
}

// to delete last node of LinkedList
void deleteLast()
{
	if(head==NULL) //if List is empty we return
	{
		printf("Linked List is empty | Nothing to delete\n");
		return;
	}
	else if(head->next==NULL) 
	{
        //deleteFirst();
		struct node* curr = head;
		head = curr->next;
		free(curr);
	}
	else
	{
		struct node* curr = head;
		struct node* prev = NULL;
		while(curr->next!=NULL)// traverse till last but one node
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL; // next field of last but one field is made as NULL
		free(curr); // deleting last node
	}	
}

// to delete node at given position
void delete_atIndx(int idx)
{
	struct node* curr=head;                                                                               
	if(head==NULL) //we return if List is empty
	{
		printf("Linked List is empty \n"); 
		return;
	}
	else if(idx == 0) 
	{
        //deleteFirst();
		curr = head;
		head=curr->next; // head pointing to second node
		free(curr); // deleting old first node
	}
	else
	{
		struct node* prev;
		for(int i=0;i<idx;i++)
		{
			prev = curr;
			curr = curr->next;
            if(curr==NULL) {printf("Index out of bound.\n"); return;}
		}
		prev->next = curr->next; //prev node pointing to pos+1 node
		free(curr); //deleting node at pos
	}
}