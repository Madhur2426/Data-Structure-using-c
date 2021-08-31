#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct node
{
    int data;
    struct node *next;
};
struct node* start=NULL;
struct node* create()
{
 struct node *l;
 l=(struct node*)malloc(sizeof(struct node));
 printf("\n ENTER DATA \n");
 scanf("%d",&l->data);
 l->next=NULL;
 return(l);
}
void insert()
{
    struct node *l,*k;
    l=create();
    if(start==NULL)
        start=l;
    else if(l->data>start->data)
    {
        l->next=start;
        start=l;
    }
    else
    {
        k=start;
        while(k->next!=NULL&&l->data<(k->next)->data)
            k=k->next;
        l->next=k->next;
        k->next=l;
    }
}
int dequeue()
{
    int x;
    struct node *k;
    if(start==NULL)
        printf("\n LIST IS EMPTY \n");
    else
    {
        k=start;
        x=k->data;
        start=k->next;
        free(k);
        return(x);
    }
    return(-9999);
}
void display()
{
    struct node *k;
    k=start;
    if(start==NULL)
        printf("\n LIST IS EMPTY \n ");
    else
    {
        while(k!=NULL)
        {
        printf("%d\t",k->data);
        k=k->next;
    }
}
}
int menu()
{
    int choice ;
    printf("1.TO INSERT \n");
    printf("2.TO DELETE \n");
    printf("3.TO DISPLAY \n");
    printf("4.TO EXIT \n");
    printf("\n ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
     int c,dq;
    while(1)
   {
    system("cls");
     COORD d;
    d.X=20;
    d.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),d);
    printf("----------ELEMEMTS ARE ARRANGED IN DESCENDING ORDER--------------\n");
       c=menu();
   switch(c)
   {
       case 1:insert();
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
        case 2:dq=dequeue();
        if(dq==-9999)
            printf("\n-9999\n");
            else
             printf("\n%d DELETED \n",dq);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
        case 3:display();
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
