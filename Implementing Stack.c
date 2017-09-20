#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top,*top1,*temp;

void push(int data);
void pop();
void empty();
void display();
void create();

int count = 0;

void main()
{
    int no, choice;

    printf("\n\t 1 - Push");
    printf("\n\t 2 - Pop");
    printf("\n\t 3 - Top");
    printf("\n\t 4 - Empty");
    printf("\n\t 5 - Exit");
    printf("\n\t 6 - Display");
    printf("\n\t 7 - Stack Count");

    create();

    while(1){
        printf("\n\n\t Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\tEnter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("\n\tNo elements in stack");
            else
            {
                printf("\n\t Top element : %d", top->data);
            }
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
            break;
        case 6:
            display();
            break;
        case 7:
            printf("\n\t No. of Elements in the Stack is :%d\n",count);
            break;
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

void create()
{
    top = NULL;
}

void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->next = NULL;
        top->data = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->next = top;
        temp->data = data;
        top = temp;
    }
    count++;
}

void display()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\n\tStack is empty");
        return;
    }
    else printf("\n\t\tSTACK\n");
    while (top1 != NULL)
    {
        printf("\t\t\t%d\n", top1->data);
        top1 = top1->next;
    }
 }

void pop()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\n\t Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n\t Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
}

void empty()
{
    if (top == NULL)
        printf("\n\tStack is empty");
    else
        printf("\n\tStack is not empty with %d elements", count);
}

