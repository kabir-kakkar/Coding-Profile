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

char isDigit (char symbol)
{
    if (symbol >= '0' && symbol <= '9')
        return 1;
    else
        return 0;
}

int Priority (STACK *s, char symbol)
{
    switch (s->data[s->top])
    {
        case '-':
        case '+':
                    if (symbol == '+' || symbol == '-' || symbol == ')')
                        return 1;
                    else
                        return 0;
        case '%':
        case '*':
        case '/':
                    if (symbol == '(')
                            return 0;
                    else
                            return 1;
        case '(':
                        return 0;
    }
}

int Empty (STACK s)
{
  return s.top == -1;
}

int main()
{
    int k, i = 0, j = 0;
    STACK s;
    char in[50], pos[50], symbol, op, temp;

    s.top = -1;

    printf("Enter infix expression: ");
    gets(in);

    for (i = 0; in[i] != '\0'; i++)
    {
        symbol = in[i];
        if (isDigit(symbol))
            pos[j++] = symbol;
        else
        {
            while (!Empty(s) && Priority(&s, symbol))
            {
                op = pop(&s);
                pos[j++] = op;
            }
            if(Empty(s) || symbol == '(')
            {
                push (&s, symbol);
                printf ("%c", symbol);
            }
            else
                pop (&s);
        }
    }

    while (!Empty(s))
    {
            op = pop(&s);
            pos[j++] = op;
    }

    pos[j] = '\0';

    printf ("\n the postfix expression is: ");
    puts(pos);
}
