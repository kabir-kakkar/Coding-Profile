#include <stdio.h>
#include <stdlib.h>

struct STACK
{
    int data[10];
    int top;
};

typedef struct STACK stack;

void push (stack *s, int val)
{
    if (s->top == 10)
    {
        printf("Overflow");
        return;
    }
    s->data[++s->top] = val;
}

void display (stack *s)
{
    int temp = s->top;
    while (temp != -1)
    {
        printf ("%d \t ", s->data[temp--]);
    }
}

int pop (stack *s)
{
    if (s->top == -1)
    {
        printf("\n UNDERFLOW \n");
        return;
    }
    else
    {
        return s->data[s->top--];
    }
}

void main ()
{
    stack s;
    s.top = -1;
    int choice, val;

   while(1)
   {
      printf("\n****** MENU ******\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);

      switch(choice)
      {
        case 1: printf("Enter the value to be insert: ");
                scanf("%d", &val);
                push(&s, val);
                break;
        case 2: val = pop(&s);
                printf(" popped %d \n ", val);
                break;
	    case 3: display(&s); break;
	    case 4: exit(0);
	    default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}


