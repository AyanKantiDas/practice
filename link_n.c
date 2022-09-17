#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void linkTransverese()
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        while(ptr != NULL)
        {
            printf("DATA: \n");
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        
    }
    
}

void insertAtFirst()
{
    int value;
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the number to be inserted at first: ");
    scanf("%d", &value);
    ptr->next = head;
    ptr->data = value;
    head = ptr;
}

void insertAtindex()
{
    struct Node *ptr, *newnode;//newnode = index
    int pos, value, i = 1;
    newnode = malloc(sizeof(struct Node));

    printf("\nEnter the position and the data : ");
    scanf("%d %d ", &pos, &value);

    ptr = head;
    newnode->data = value;
    newnode->next = 0;
    while(i < pos - 1)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}


void insertAtEnd()
{
   int value;
   struct Node *ptr, *q;
   ptr = malloc(sizeof(struct Node));

   printf("\nEnter the number to be inserted at the end : ");
   scanf("%d", &value);

   ptr->next = 0;
   ptr->data = value;
   q = head;
   while(q->next != NULL)
   {
    q = q->next;
   }
   q->next = ptr;
}


void deleteAtFirst()
{

    struct Node *ptr ;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void deleteAtIndex()
{
    struct Node *ptr, *position;
    int i = 1, pos;

    if(head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        printf("\nEnter index: ");
        scanf("%d", &pos);
        position = malloc(sizeof(struct Node));
        ptr = head;

        while(i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }

        position = ptr->next;
        ptr->next = position->next;

        free(position);
    }
}


void deleteAtLast()
{
    struct Node *ptr, *prevnode;
    if(head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        ptr = head;
        while(ptr->next != 0)
        {
            prevnode = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        prevnode->next = 0;
    }
}


void reverse_display()
{
   struct Node *t1, *t2, *ptr;
   t1 = t2 = NULL;

   if(head == NULL)
   {
    printf("\nThe List is empty\n");
   }
   else
   {
    while(head != NULL)
    {
        t2 = head->next;
        head->next = t1;
        t1 = head;
        head = t2;
    }
    head = t1;

    ptr = head;
    printf("Reversed linked list is : ");

    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
   }
}

void sort()
{
    struct Node *current = head;
    struct Node *index = NULL;
    int temp;

    if(head == NULL)
    {
        return;
    }
    else
    {
        while(current != NULL)
        {
            index = current->next;
            while(index != NULL)
            {
                if(current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}


void even()
{
    struct Node *current = head;
    struct Node *index = NULL;
    int temp;

    if(head == NULL)
    {
        return;
    }
    else
    {
        while(current != NULL)
        {
            {
                if(current->data / 2 == 0)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
        }
    }
}

void create()
{
    //if(head == NULL)
    //{
        struct Node *temp, *ptr;
        int n;
        int val;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if(n != 0)
        {
            
            head = (struct Node *)malloc(sizeof(struct Node));
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &val);
            head->data = val;
            head->next = NULL;
            temp = head;
            for(int i = 1; i < n; i++)
            {
                ptr = (struct Node *)malloc(sizeof(struct Node));
                printf("\nEnter number to be inserted : ");
                scanf("%d", &val);
                ptr->data = val;
                ptr->next = NULL;
                temp->next = ptr;
                temp = temp->next;
            }
        }
        printf("\nThe list is created\n");
    //}
    //else
          //printf("\nThe list is already created\n");
}

int main()
{
    int choice;
    while (1) {
  
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at"
               " starting\n");
        printf("\t3  For insertion at"
               " end\n");
        printf("\t4  For insertion at "
               "any position\n");
        printf("\t5  For deletion of "
               "first element\n");
        printf("\t6  For deletion of "
               "last element\n");
        printf("\t7  For deletion of "
               "element at any position\n");
        printf("\t8 To sort element\n");
        printf("\t9 To reverse the "
               "linked list\n");
        printf("\t10 To exit\n");
        printf("\t11 create list first\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
  
        switch (choice) {
        case 1:
            linkTransverese();
            break;
        case 2:
            insertAtFirst();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtindex();
            break;
        case 5:
            deleteAtFirst();
            break;
        case 6:
            deleteAtLast();
            break;
        case 7:
            deleteAtIndex();
            break;
        case 8:
            sort();
            break;
        case 9:
            reverse_display();
            break;
        case 10:
            exit(1);
            break;
        case 11:
            create();
            break;   
        case 12:
            even();     
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
