#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
    int data;
    NODE *next;
};

NODE* create_ll (NODE* start) {
    NODE *newNode, *ptr;

    int num;
    printf("\n Enter data\n");
    scanf("%d", &num);

    while (num != -1) {
        newNode = (NODE*)malloc(sizeof(NODE));
        newNode->data = num;

        if (start == NULL) {
            newNode -> next = NULL;
            start = newNode;
        } else {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("\n Enter data");
        scanf("%d", &num);
    }
    return start;
}

void display (NODE* start)
{
    while (start != NULL)
    {
        printf(" %d -> ", start->data);
        start = start->next;
    }
    printf(" NULL ");
}

NODE* merge_ll (NODE* a, NODE* b)
{
    NODE* result = NULL;

    if (a == NULL)
        return (b);
    if (b == NULL)
        return (a);

    if (a->data < b->data) {
        result = a;
        result->next = merge_ll(a->next, b);
    } else {
        result = b;
        result->next = merge_ll (a, b->next);
    }
    return result;
}

NODE* rev_ll (NODE *start)
{
    NODE *cur = start;
    NODE *prev = NULL;
    NODE *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main ()
{
    NODE *s1= NULL, *s2 = NULL, *s3 = NULL;
    printf("Enter s1: (sorted) \n");
    s1 = create_ll(s1);

    printf("Enter s2: (sorted) \n");
    s2 = create_ll(s2);

    s3 = merge_ll (s1, s2);
    printf("\n");
    display(s3);
    printf("\n");
    s3 = rev_ll(s3);
    display(s3);
    return 0;
}
