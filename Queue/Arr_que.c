#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int data);
void dequeue();
void peek();
void display();

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6); // This will show "Queue Overflow"
    display();
    dequeue();
    peek();
    display();

    return 0;
}

void enqueue(int data) {
    if (rear == N - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int val = queue[front];
    front++;

    if (front > rear) {
        front = rear = -1;
    }

    printf("Dequeued element: %d\n", val);
}

void display() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void peek() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Peek: %d\n", queue[front]);
}