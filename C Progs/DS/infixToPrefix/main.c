#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20

struct stack
{
    char data[MAX];
    char top;
};

typedef struct stack STACK;

void push (STACK *s, char item)
{
    if (s->top == MAX-1)
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

int priority(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
                    return 1;
        case '*':
        case '/':
        case '%':
                    return 2;
        case '(':
        case ')':
        case '#':
                    return 0;
    }
}

int isOperator(char symbol)
{
        switch(symbol)
        {
                case '+':
                case '-':
                case '*':
                case '/':
                case '(':
                case ')':
                            return 1;
                default:
                            return 0;
        }
}

int main()
{
        char infix[20],prefix[20];
        STACK s;
        s.top = -1;
        printf("Enter the valid infix string:\n");
        gets(infix);

        int i,symbol,j=0;

        strrev(infix);
        s.data[++s.top]='#';

        for(i=0;i<strlen(infix);i++)
        {
                symbol=infix[i];

                if(isOperator(symbol)==0)
                {
                    prefix[j++]=symbol;
                }
                else
                {
                    if(symbol==')')
                    {
                            push(&s, symbol);
                    }
                    else if(symbol=='(')
                    {
                            while(s.data[s.top]!=')')
                            {
                                    prefix[j++]=pop(&s);
                            }
                            pop(&s);//pop out (.
                    }
                    else
                    {
                        if(priority(symbol) > priority(s.data[s.top]))
                        {
                            push(&s, symbol);
                        }
                        else
                        {
                            while(priority(symbol)<= priority(s.data[s.top]))
                            {
                                    prefix[j++]=pop(&s);
                            }
                            push(&s, symbol);
                        }//end of else.
                    }//end of else.
                }//end of else.
        }//end of for.

        while(s.data[s.top]!='#')
        {
            prefix[j++]=pop(&s);
        }

        prefix[j]='\0';//null terminate string.
        strrev(prefix);

        printf("The corresponding prefix string is:\n");
        puts(prefix);

        return 0;
}

