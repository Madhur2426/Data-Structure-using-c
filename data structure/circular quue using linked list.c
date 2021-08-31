#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* front=NULL;
struct node* rear=NULL;
struct node *create()
{
    int data;
 struct node*q;
 q=(struct node*)malloc(sizeof(struct node));
    printf("\n ENTER DATA \n");
    scanf("%d",&data);
    q->data=data;
    q->next=NULL;
    return(q);
}
void insert()
{
    struct node*p,*q;
    p=front;
    q=create();
    if(p==NULL)
    {
        front=q;
        rear=q;
        rear->next=front;
    }
    else
    {
        rear->next=q;
        rear=q;
        rear->next=front;
    }
}
int del()
{
    int data;
    struct node*p;
    p=front;
    if(front==NULL)
        printf("\n EMPTY QUEUE LIST \n");
    else if(front==rear)
    {
        data=front->data;
        front=NULL;
        rear=NULL;
        free(p);
        return(data);
    }
    else
    {
        data=front->data;
     front=front->next;
    p->next=NULL;
    rear->next=front;
    free(p);
    return(data);
    }
return(-9999);
}
void display()
{
    int i;
    struct node *p;
    p=front;
    if(p==NULL)
        printf("\n QUEUE LIST IS EMPTY \n");
   else
   {
   while(p!=rear)
   {
       printf("%d \t",p->data);
       p=p->next;
   }
   printf("%d",p->data);
}
}
int menu()
{
    int choice;
    printf("1. TO INSERT IN QUEUE LINK LIST \n");
    printf("2. TO DELETE IN QUEUE LINK LIST \n");
    printf("3. TO DISPLAY QUEUE LINK LIST DATA \n");
    printf("4. TO EXIT \n");
    printf("\n ENER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
     int c,remove;
    while(1)
   {
    system("cls");
       c=menu();
   switch(c)
   {
       case 1:
            insert();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 2:
            remove=del();
            if(remove==-9999)
                printf("%d",remove);
            else
            printf("%d DELETED \n",remove);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
            display();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
        case 4:exit(0);
           break;
        default:
            printf("\n invalid choice\n");
   }
   getch();
}
}
