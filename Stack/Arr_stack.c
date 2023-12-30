#include<stdio.h>
#define N 5

int stack[N];
int top=-1;

void push(int data);
void pop();
void peek();
void display();

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
	if(top==N-1){
		printf("Stack Overflow\n");
		return;
	} 
	top++;
	stack[top]=data;
}

void pop(){
	int val;
	if(top==-1){
		printf("Stack underflow\n");
		return;
	}
	val=stack[top];
	top--;
	printf("pop: %d\n",val);
}

void display(){
	int i;
	if(top==-1){
		printf("Stack underflow\n");
		return;
	}
	printf("\nStack:\n");
	for(i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	} 
	printf("\n");
}

void peek(){
	if(top==-1){
		printf("Stack underflow\n");
		return;
	}
	printf("Peek: %d\n",stack[top]);
}
