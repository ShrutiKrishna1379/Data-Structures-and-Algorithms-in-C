#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data);
void dequeue();
void peek();
void display();
int isEmpty();

void main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
    display();
	dequeue();
	peek();
	display();
}

void enqueue(int data){
	struct node *temp;
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
     
    if ((front==NULL)&&(rear==NULL)) {
        front=rear=temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

int isEmpty(){
    if (front == NULL) 
        return 1;
    else
        return 0;
}

void dequeue(){
	struct node *temp;
    temp = front;
	if(isEmpty()){
		printf("\nQueue is Empty");
    } else {
        front = front->next;
        printf("Dequeued element: %d\n", temp->data);   
        free(temp); 
        if(front==NULL) rear=NULL;
    }
}

void display(){
	if(isEmpty()){
		printf("\nQueue is Empty");
    } else {
        printf("\nQueue:");
	    struct node* curr = front;
	    while(curr!=NULL) // start from first node
	    {
	    	printf("%d ",curr->data);
	    	curr = curr->next;
	    }
        printf("\n\n");
    }    
}

void peek(){
	if (isEmpty()) {
        printf("\nQueue is Empty\n");
        return;
    } else {
	    printf("Peek: %d\n",front->data);
    }
}