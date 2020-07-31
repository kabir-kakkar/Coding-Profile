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

void display (NODE* start) {
    while (start != NULL) {
        printf("-> \t %d", start->data);
        start = start->next;
    }
}

NODE *merge_ll (NODE *s1, NODE *s2, NODE *s3) {
    int v1, v2;
    NODE *ptr;
    s3 = (NODE*)malloc(sizeof(NODE));

    while (s1 != NULL || s2 != NULL) {
        v1 = s1 -> data;
        v2 = s2 -> data;

        if (s3 == NULL) {
            s3 -> next = NULL;
        } else {
            while (s3->next != NULL)
                s3 = s3->next;
        }

        if (v1 < v2) {
            s3 -> data = v1;
        } else {
            s3 -> data = v2;
        }

        s1 = s1->next;
        s2 = s2->next;

        s3 -> next = NULL;
    }

    return s3;
}

int main()
{
    NODE *s1, *s2, *s3;

    printf("Enter s1: (sorted) \n");
    s1 = create_ll(s1);

    printf("Enter s2: (sorted) \n");
    s2 = create_ll(s2);

    s3 = merge_ll (s1, s2, s3);
   // s3 = rev_ll (s3);
    printf("\n");
    display(s3);

    return 0;
}
