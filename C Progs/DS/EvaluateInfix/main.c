// convert postfix exp to prefix exp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct stack
{
  char* data[MAX];
  int top;
} STACK;

void push(STACK *, char*);
char* pop(STACK *);

int main()
{

  STACK stack;
  stack.top = -1;

  printf("enter postfix expression to convert:\n");
  char postfix[20];
  fgets(postfix,20,stdin);

  char *prefix = (char*)malloc(sizeof(char)*20);
  char *op1 = (char*)malloc(sizeof(char)*5);
  char *op2 = (char*)malloc(sizeof(char)*5);

  int i = 0;
  while (postfix[i] != '\0')
  {
    char symbol = postfix[i];
    char *symbolStr = (char*)malloc(sizeof(char));
    *symbolStr = symbol;

    if (symbol > '0' && symbol < '9')
    {
      push(&stack, symbolStr);
    }
    else
    {
      op2 = pop(&stack);
      op1 = pop(&stack);

      char *temp = (char*) malloc (sizeof(char)*10);
      temp = strcat(op1,op2);

      push(&stack,strcat(symbolStr,temp));
    }

    i++;
  }

    printf("postfix exp: %s\n", postfix);
    printf("prefix exp : %s\n", pop(&stack));

  return 0;
}

void push(STACK *s, char *c)
{
  if (s->top >= MAX-1) {
    printf("overflow");
    return;
  }
  s->top++;
  s->data[s->top] = c;
}

char* pop(STACK *s) {
  if(s->top < 0){
    printf("underflow!\n");
  }
  else{
    char *x = s->data[s->top];
    s->top--;
    return x;
  }

}
