#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* top=NULL;
struct node* create()
{
 struct node *p;
 p=(struct node*)malloc(sizeof(struct node));
 printf("\n ENTER DATA \n");
 scanf("%d",&p->data);
 p->next=NULL;
 return(p);
}
void push()
{
    struct node *p;
    p=create();
    if(top)
    {
        p->next=top;
        top=p;
    }
    else
        top=p;
}
void display()
{
    struct node* p;
    if(top==NULL)
        printf("\n UNDERFLOW \n");
    else
    {
        p=top;
        while(p!=NULL)
        {
            printf("%d \n",p->data);
            p=p->next;
        }
    }
}
void peek()
{
    if(top==NULL)
        printf("\n UNDERFLOW \n");
    else
        printf("%d \n",top->data);
}
void pop()
{
    int data;
    struct node *p;
    if(top==NULL)
        printf("\n UNDERFLOW \n");
    else
    {
        p=top;
        top=top->next;
        if(p->next!=NULL)
        p->next=NULL;
        free(p);
    }
}
int menu()
{
    int choice;
    printf("1. TO INSERT ELEMENT IN STACK\n");
    printf("2. TO SEE THE FIRST ELEMENT OF STACK\n");
    printf("3. TO DELETE AN ELEMENT IN STACK\n");
    printf("4. TO DISPLAY STACK ELEMENTS\n");
    printf("5.TO EXIT\n");
    printf("\n ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
 int c;
   printf("\nENTER ANY KEY TO CONTINUE\n");
   while(1)
   {
    system("cls");
       c=menu();
   switch(c)
   {
       case 1:
            push();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 2:
            peek();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
            pop();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 4:
            display();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 5:
            exit(0);
            break;
        default:
            printf("\n invalid choice\n");
   }
   getch();
}
}
