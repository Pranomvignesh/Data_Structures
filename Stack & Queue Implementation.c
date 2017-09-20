#include<stdio.h>
#include<stdlib.h>
int count;
struct node{
int data;
struct node *next;
}*head=NULL,*Current;
void create()
{
head=(struct node*)malloc(sizeof(struct node));
head=NULL;
}
void push()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n\tEnter the element to be pushed\n\t");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    display();
    count++;
}
void deQueue()
{
    if(head==NULL)
    {printf("\n\tQueue is Empty\n");
    return ;
    }
    struct node* temp=head;
    temp=temp->next;
    //printf("dequeued element [%d]\n",head->data);
    free(head);
    head=temp;
    count--;
    display();

}
void display()
{
    struct node *traverse=head;
    if(head==NULL)
    {
    printf("\n\tQueue is empty\n");
    return;
     }
     printf("\n\t");
    while(traverse!=NULL){
        printf("[ %d ]=>",traverse->data);
        traverse=traverse->next;
    }
    printf("NULL\n");

}
void Enqueue()
{
    char option;

    do{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n\tEnter the element no %d\n\t",++count);
    scanf("%d",&newnode->data);
           if(head==NULL)
            {
                head=newnode;
                Current=head;
            }
            else
           {
            Current->next=newnode;
            Current=newnode;

           }
    newnode->next=NULL;
    printf("\n\tDo you want to add another element:(Y/N): ");
    scanf(" %c",&option);

    }while((option=='y'||option=='Y')&&(option!='n'||option!='N'));
    display();

}
int main()
{
    printf("\t\tSTACK AND QUEUE IMPLEMENTATION");
    int option;
    create();
    while(option!=4){

    printf("\n\tEnter choice ");
    printf("\n\t1.Enqueue");
    printf("\n\t2.Display");
    printf("\n\t3.DeQueue");
    printf("\n\t4.Exit");
    printf("\n\t5.Push");
    printf("\n\t6.Pop");
    printf("\n\t7.No.of Elements in the list\n\n\t");

    scanf("%d",&option);

    switch(option){
    case 1:
        Enqueue();
        break;
    case 2:
        display();
        break;
    case 3:
        deQueue();
        break;
    case 4:
        return 0;
    case 5:
        push();
        break;
    case 6:
        deQueue();
        break;
    case 7:
        printf("\n\tNo.of Elements :%d\n",count);
        break;
    default:
        printf("\n\tEnter correct choice\n");

    }

}
}
