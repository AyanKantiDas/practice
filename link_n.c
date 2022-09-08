#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *ptr = NULL, *q;
void create(int);

void linkTransverese(struct Node *ptr)
{
    q = ptr;
    while(q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data )
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insertAtindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != (index-1))
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;

}

struct Node *insertAfterNode(int item, struct Node *head, int data)
{
    struct Node *p = head;
    while(p != NULL)
    {
        if(ptr->data == item)
        {
            struct Node *ptr =(struct Node*)malloc(sizeof(struct Node));
            ptr->data = data;
            ptr->next = p->next;
            p->next = ptr;
            return head; 
     
        }
        p = p->next;
    }
                   
}

struct Node *deleteAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *a = head->next;
    for(int i = 0; i < index -1; i++)
    {
        ptr = ptr->next;
        a = a->next;
    }
    ptr->next = a->next;
    free(a);
    return head;
}

struct Node *deleteAtLast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *a = head->next;
    while(a->next != NULL)
    {
        ptr = ptr->next;
        a = a->next;
    }
    ptr->next = NULL;
    free(a);
    return head;
}

struct Node *deleteGivenValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *a = head->next;
    while(a->data != value && a->next != NULL)
    {
        ptr = ptr->next;
        a = a->next;
    }
    if(a->data == value)
    {
        ptr->next = a->next;
        free(a);
    }
    return head;
}

struct Node *reverse_display(struct Node *head)
{
    if(head)
    {
        reverse_display(head->next);
        printf("%d ",head->data);
    }
    return head;
}


void create(int val)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(ptr == NULL)
    {
        ptr = temp;
    }
    else
    {
        q = ptr;
        while(q->next != NULL)
        {
            q = q->next;
        }
        q->next = temp;
    }
}



int main()
{
    struct Node *head;
    
    int n, val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    if(n != 0)
    {
        printf("Enter the values: ");
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &val);
            create(val);
        }
    }
    else 
    {
        printf("Empty link list ");
    }  
    printf("The link list : ");  
    linkTransverese(ptr);


    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);
    ptr = insertAtFirst(ptr, data); 
    printf("The link list after insert at first : ");  
    linkTransverese(ptr);


    ptr = deleteAtFirst(ptr);
    printf("\nthe first element deleted: ");
    linkTransverese(ptr);


    int index;
    printf("\nEnter the index: ");
    scanf("%d", &index);
    ptr = insertAtindex(ptr, data, index); 
    printf("\ninserting at any index: ");
    linkTransverese(ptr);


    ptr = insertAtEnd(ptr, data);
    printf("\nlink list after inserting at end: ");
    linkTransverese(ptr);

    int item;
    printf("ENter the item no: ");
    scanf("%d", &item);
    ptr = insertAfterNode (ptr, item , data);   
    printf("\nlink list after inserting after a node: ");
    linkTransverese(ptr);

    ptr = deleteAtIndex(ptr, index);
    printf("\nlink list after delete at index: ");
    linkTransverese(ptr);

    ptr = deleteAtLast(ptr);
    printf("\n link list after delete at last: ");
    linkTransverese(ptr);

    ptr = deleteGivenValue(ptr, data);
    printf("\nlink list after delete at given value: ");
    linkTransverese(ptr);

    printf("\nthe reverse link list is ");
    ptr = reverse_display(ptr);
    
   
   

    return 0;

}
