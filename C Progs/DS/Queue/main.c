#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Queue
{
    int data[MAX];
    int front, rear;
};

typedef struct Queue Q;

void enQueue (Q *q, int num)
{
    if ( q->rear == MAX-1 )
    {
        printf ("\n Overflow");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->data[q->rear] = num;
}

int deQueue (Q *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("\n UnderFlow");
        return -1;
    }
    int val = q->data[q->front];
    q->front++;
    return val;
}

int peek (Q *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf ("\n Underflow");
        return -1;
    }
    else
    {
        return q->data[q->front];
    }
}

void display (Q *q)
{
    int i;
    printf ("\n");
    if (q->front == -1 || q->front > q->rear)
    {
        printf ("\n Queue is Empty");
    }
    else
    {
        for (i = q->front; i <= q->rear; i++)
        {
            printf ("\t %d", q->data[i]);
        }
    }
}


int main()
{
    Q q;
    q.front = q.rear = -1;

    int option, val;
    do
    {
        printf ("\n\n ***** MAIN MENU *****");
        printf ("\n 1. Insert an element");
        printf ("\n 2. Delete an element");
        printf ("\n 3. Peek");
        printf ("\n 4. Display the queue");
        printf ("\n 5. Exit \n\n");
        scanf ("%d", &option);

        switch (option)
        {
            case 1:
                        printf("\n Enter the element: ");
                        scanf ("%d", &val);
                        enQueue(&q, val);
                        break;
            case 2:
                        val = deQueue(&q);
                        if (val != -1)
                        {
                            printf("\n The number deleted is: %d", val);
                        }
                        break;
            case 3:
                        val = peek(&q);
                        if (val != -1)
                        {
                            printf ("\n The first element in queue is %d ", val);
                        }
                        break;
            case 4:
                        display(&q);
                        break;
            case 5:
                        printf ("\t \t ***** Adios!!! *****");
                        break;
            default:
                        printf ("Invalid Input");
                        break;
        }
    }while (option != 5);
}
