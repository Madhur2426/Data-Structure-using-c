#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
struct node*create()
{
 struct node*q;
 q=(struct node*)malloc(sizeof(struct node));
 printf("\n ENTER VALUE \n");
 scanf("%d",&q->data);
 q->next=NULL;
 return(q);
}
void insertfront()
{
    struct node* p;
    p=create();
    if(front==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
    p->next=front;
    front=p;
    }
}
void insertrear()
{
    struct node* p;
    p=create();
    if(rear==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}
void delfront()
{
    int c=0;
    struct node* del;
    if(front==NULL)
        printf("\n UNDERFLOW \n");
    else
    {
      del=front;
      front=front->next;
      free(del);
      c=1;
    }
    if(c==1)
        printf("\n DELETED \n");
}
void delrear()
{
    int c=0;
    struct node* del,*p,*r;
    if(rear==NULL)
        printf("\n UNDERFLOW \n");
    else if(front->next==NULL)
    {
        c=1;
        del=rear;
        rear=NULL;
        front=NULL;
        free(del);
    }
    else
    {
        p=front;
        r=front;
        while(p->next!=NULL)
        {
            r=p;
            p=p->next;
        }
        del=p;
        rear=r;
        r->next=NULL;
        free(del);
        c=1;
    }
    if(c==1)
        printf("\n DELETED \n");
}
void display()
{
 struct node* i;
 i=front;
 if(i==NULL)
 printf("\n UNDERLOW \n");
 else
{
 while(i!=rear)
 {
     printf("%d\t",i->data);
     i=i->next;
}
printf("%d\t",i->data);
}
}
int menu()
{
    int choice;
    printf("1.TO ENTER ELEMNTS AT FRONT\n");
    printf("2.TO ENTER ELEMENT AT REAR \n");
    printf("3.TO DELETE FROM FRONT\n");
    printf("4.TO DELETE FROM REAR\n");
    printf("5.TO DISPLAY ELEMENTS\n");
    printf("6.TO EXIT \n");
    printf("\n ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    int c;
    struct node *dq;
    while(1)
   {
    system("cls");
       c=menu();
   switch(c)
   {
       case 1:insertfront();
              printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 2:insertrear();
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 3:delfront();
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 4:delrear();
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 5:display();
             printf("\n ENTER ANY KEY TO CONTINUE \n");
             break;
       case 6:exit(1);
             break;
        default:
             printf("\n invalid choice\n");
   }
   getch();
}
}
