#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkTranverese(struct Node *ptr) //tranverse of link list
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}





int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));   //in heap 
    second = (struct Node*)malloc(sizeof(struct Node)); //heap
    third = (struct Node*)malloc(sizeof(struct Node));  //heap
    fourth = (struct Node*)malloc(sizeof(struct Node)); //heap

    head->data = 8;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 90;
    third->next = fourth;

    fourth->data = 900;
    fourth->next = NULL;

    linkTranverese(head);

    return 0;
}
