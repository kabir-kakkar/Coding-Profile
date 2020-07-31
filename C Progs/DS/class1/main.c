#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

//prototype
NODE* create (NODE*);
void display (NODE*);
void insertBefore (NODE*);
void insertAfter(NODE*);
NODE* deleteBeg(NODE*);
void deleteEnd(NODE*);

int main()
{
    NODE* start = NULL;
    printf("Enter values, Press 0 to exit");
    start = create (start);
    display (start);
    //start = deleteBeg(start);
    //display (start);

}

NODE* create (NODE* start)
{
    int choice = 1;
    NODE *newNode, *prev;
    while (choice == 1)
    {
        newNode = (NODE*)malloc (sizeof(NODE));
        printf("\n Enter information: ");
        scanf("%d", &newNode->data);


        if(start == NULL)
        {
            start = newNode;
            newNode -> next = NULL;

        }
        else
        {
            prev = start;
            while (prev->next != NULL)
                prev = prev->next;
            prev -> next = newNode;
            newNode -> next = NULL;
        }
        printf ("Press 1 to enter more ");
        scanf ("%d", &choice);
    }
    return start;
}

void display (NODE* start)
{
    printf ("\n");
    while (start != NULL)
    {
        printf ("%d \t", start->data);
        start = start-> next;
    }
}

void insertBefore (NODE *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
}

void insertAfter (NODE *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    preptr = ptr;
    while (preptr -> data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr -> next = new_node;
    new_node -> next = ptr;
}

NODE *deleteBeg (NODE *start)
{
    NODE *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

void deleteEnd (NODE *start)
{
    NODE *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr -> next = NULL;
    free(ptr);
}
