// C program to reverse a string using stack
#include<stdio.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top=-1;
void push(char ch)
{
    if(top==MAX-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top]=ch;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}
int main()
{
    char str[MAX];
    printf("Enter a string : ");
    scanf("%s",str);
    for (int i = 0; i < strlen(str); i++) 
    {
        push(str[i]);
    }
    printf("Reversed string: ");
    while (top != -1) 
    {
        printf("%c", pop());
    }

    return 0;
}
   
// C program to check for balanced parentheses using stack
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char ch) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
    } else 
    {
        stack[++top] = ch;
    }
}
char pop() 
{
    if (top == -1) 
    {
        return 0;
    } else 
    {
        return stack[top--];
    }
}
int isMatchingPair(char open, char close) 
{
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() 
{
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);
    for (int i = 0; i < strlen(expr); i++) 
    {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') 
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (top == -1) 
            {
                printf("Not Balanced\n");
                return 0;
            }
            char popped = pop();
            if (!isMatchingPair(popped, ch)) 
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if (top == -1) 
    {
        printf("Balanced Expression\n");
    } else 
    {
        printf("Not Balanced\n");
    }
    return 0;
}

// C program to implement circular queue
#include<stdio.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top=-1;
void push(char ch)
{
    if(top==MAX-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top]=ch;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}
int main()
{
    char str[MAX];
    printf("Enter a string : ");
    scanf("%s",str);
    for (int i = 0; i < strlen(str); i++) 
    {
        push(str[i]);
    }
    printf("Reversed string: ");
    while (top != -1) 
    {
        printf("%c", pop());
    }

    return 0;
}

// C program to implement circular queue
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int x) 
{
    if ((rear + 1) % MAX == front) 
    {
        printf("Queue Full\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("Inserted: %d\n", x);
}
void dequeue() 
{
    if (front == -1) 
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) 
    {
        front = rear = -1; // reset
    } else 
    {
        front = (front + 1) % MAX;
    }
}
void peek() 
{
    if (front == -1) {

        printf("Queue Empty\n");
    } else 
    {
        printf("Front element: %d\n", queue[front]);
    }
}
void display() 
{
    if (front == -1) 
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while (1) 
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() 
{
    int choice, x;
    while (1) 
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}


// C program to simulate printer queue using array
#include <stdio.h>
#include <string.h>
#define MAX 5

char queue[MAX][50];
int front = -1, rear = -1;
void enqueue(char doc[]) 
{
    if (rear == MAX - 1) 
    {
        printf("Queue Full\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    strcpy(queue[rear], doc);
    printf("Document added: %s\n", doc);
}
void dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("No documents to print\n");
        return;
    }
    printf("Printing: %s\n", queue[front]);
    front++;
}
void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("No pending documents\n");
        return;
    }
    printf("Pending documents:\n");
    for (int i = front; i <= rear; i++) 
    {
        printf("%s\n", queue[i]);
    }
}
int main() 
{
    int choice;
    char doc[50];
    while (1) 
    {
        printf("\n1. Add Document\n2. Print Document\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter document name: ");
                scanf("%s", doc);
                enqueue(doc);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}