#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node* create()
{
 int data;
 struct node *p;
 printf("\n ENTER DATA \n");
 scanf("%d",&data);
 p=(struct node*)malloc(sizeof(struct node));
 p->data=data;
 p->next=NULL;
 return(p);
}
void insert()
{
    struct node* p;
    int item;
    p=create();
    if(front==NULL&&rear==NULL)
    {
        front=rear=p;
    }
    else
    {
        rear->next=p;
        rear=rear->next;
    }
}
void deletedata()
{
 struct node* p;
 p=front;
 if(front==NULL)
    printf("\n LIST IS EMPTY \n");
 else
 {
     printf("%d deleted\n",front->data);
     front=front->next;
     p->next=NULL;
     free(p);
 }
}
void display()
{
    struct node*p;
    p=front;
    if(front==NULL)
        printf("\n LIST IS EMPTY \n");
    else
    {
        while(p)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}
void peek()
{
    if(front==NULL)
        printf("\n LIST IS EMPTY \n");
    else
        printf("\n %d",front->data);
}
int menu()
{
    int choice;
    printf("1.TO INSERT ELEMEMT\n");
    printf("2.TO DELETE\n");
    printf("3.TO DISPLAY LIST ELEMENTS\n");
    printf("4.TO VIEW ELEMENT PRESENT AT FRONT\n");
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
            insert();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 2:
            deletedata();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
            display();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 4:
            peek();
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
