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
void addFirst(int data);
void addLast(int data);
void add_atIndx(int idx,int data);

int main()
{
    int n, data;

    //Create a singly linked list of n nodes
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list : \n");
    display();

    //Insert data at the beginning of the singly linked list     
    printf("\nEnter data to insert at first : ");
    scanf("%d", &data);
    addFirst(data);
    
    //Insert data at the end of the singly linked list     
    printf("\nEnter data to insert at end : ");
    scanf("%d", &data);
    addLast(data);

    //Insert data at any index of the singly linked list 
    int idx;    
    printf("\nEnter index and data : ");
    scanf("%d %d", &idx,&data);
    add_atIndx(idx,data);

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

// to insert node at start of LinkedList
void addFirst(int data)
{
	struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 

        head = newNode;          // Make newNode as first node
    }
}

// to insert node at given position
void add_atIndx(int idx,int data)
{
	struct node* newNode;
        // creating a new node
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data=data;
	newNode->next = NULL;
    
    if(idx==0) { addFirst(data); return;}

	if(head==NULL) // if list empty we return
	{
		head = newNode;
	        return;
	}
	else
	{
		struct node* curr = head;
		int c=0;
		while(c<idx-1)
		{
            if(curr->next!=NULL){
                curr = curr->next;
                c++;
            }else{
                printf("Index out of bound.\n");
                return;
            }
		}
                //new node pointing to node in that pos
		newNode->next = curr->next;
                //prevptr pointing to new node
		curr->next = newNode;
	}
}

// to insert node at end of LinkedList
void addLast(int data)
{
	struct node* newNode;
        //creating new node
	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->data=data;
	newNode->next = NULL;

	if(head==NULL)
	{
		head = newNode; //if list is empty, we return
	        return;
	}
	else{
		struct node* curr = head;  
		while(curr->next!=NULL)
		{
			curr = curr->next;
		}
               // tail node pointing to new node
		curr->next = newNode;
	}
}
