#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node* top = NULL;

void push(int data);
void pop();
void peek();
void display();
int isEmpty();

void main(){
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
    display();
	pop();
	peek();
	display();
}

void push(int data){
	struct node *temp;
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->data = data;
     
    if (top == NULL) {
        top = temp;
        top->next = NULL;
    } else {
        temp->next = top;
        top = temp;
    }
}

int isEmpty(){
    if (top == NULL) 
        return 1;
    else
        return 0;
}

void pop(){
	struct node *temp;
    if (isEmpty(top)) {
        printf("\nStack is Empty\n");
        return;
    } else {
        temp = top;
        top = top->next;
        printf("pop: %d\n", temp->data);   
        free(temp); 
    }
}

void display(){
	if (isEmpty(top)) {
        printf("\nStack is Empty\n");
        return;
    } else {
        printf("\nStack:");
	    struct node* curr = top;
	    while(curr!=NULL) // start from first node
	    {
	    	printf("\n%d",curr->data);
	    	curr = curr->next;
	    }
        printf("\n\n");
    }    
}

void peek(){
	if (isEmpty(top)) {
        printf("\nStack is Empty\n");
        return;
    } else {
	    printf("peek: %d\n",top->data);
    }
}