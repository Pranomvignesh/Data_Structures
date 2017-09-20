#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count;
int flag;

struct node
{
    char character;
    struct node *next;
}*top,*current;

void create();
void push(char);
void pop();

int main()
{
    create();
    int i;
   char expression[200];
    printf("Enter the expression:");
    scanf("%s",expression);
    for(i=0;i<strlen(expression);i++)
       {
       switch(expression[i])
       {
       case '(':
       case '{':
       case '[':
         flag=1;
         push(expression[i]);
        break;
        case ')':flag=2; if(top->character=='('){flag=1;pop();}break;
        case '}':flag=2; if(top->character=='{'){flag=1;pop();}break;
        case ']':flag=2; if(top->character=='['){flag=1;pop();}break;
        }
       }
    if(flag==0)printf("\n\tNo brackets available!!!\n");
    else if(flag==2)printf("\n\tIncorrectly parenthesized\n");
    else if(count==0)printf("\n\tCorrectly parenthesized\n");
    else printf("\n\tIncorrectly parenthesized\n");
    return 0;
}

void create()
{
    top=(struct node*)malloc(sizeof(struct node));
    top->character='\0';
    top->next=NULL;
}

void push(char paranthesis)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->character=paranthesis;
    newnode->next=top;
    top=newnode;
    count++;
}

void pop()
{
    struct node *temp=top;
    temp=temp->next;
    free(top);
    top=temp;
    count--;
}
