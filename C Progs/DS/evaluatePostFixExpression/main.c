#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char data[10];
    char top;
};

typedef struct stack STACK;

void push (STACK *s, char item)
{
    if (s->top == 9)
    {
        printf("OVERFLOW");
        return;
    }
    s->top++;
    s->data[s->top] = item;
}

char pop (STACK *s)
{
    char item;
    if (s->top == -1)
    {
        printf("UNDERFLOW");
        return -1;
    }
    item = s->data[s->top];
    s->top--;
    return item;
}

int main()
{
   char PE[20], symbol;
   int i = 0, op1, op2, r;

   STACK s;

   printf("Enter the PostFix expression:");
   gets (PE);

   while (PE[i] != '\0')
   {
       symbol = PE[i];
       if (symbol >= '0' && symbol <= '9')
       {
           push (&s, (symbol- 48));
       }
       else
       {
           op2 = pop(&s);
           op1 = pop(&s);

           switch (symbol)
           {
               case '*': r = op1 * op2;
                         break;
               case '/': r = op1 / op2;
                        break;
               case '+': r = op1 + op2;
                        break;
                case '-': r = op1 - op2;
                        break;
           }
           push (&s, r);
       }
       i++;
   }
   printf("%d", r);
}
