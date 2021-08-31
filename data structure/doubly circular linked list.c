#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
 int info;
 struct node* next;
 struct node* prev;
};
struct node *start=NULL;
struct node *createnode()
{
    struct node *p;
    int data;
    p=(struct node*)malloc(sizeof(struct node));
    printf("\n ENTER DATA \n");
    scanf("%d",&data);
    p->info=data;
    p->next=NULL;
    p->prev=NULL;
    return(p);
}
void insertatfirst()
{
    struct node *p=createnode();
    struct node*k=start;
    if(start==NULL)
        {
            start=p;
            p->next=start;
            p->prev=start;
        }
    else
    {
       while(k->next!=start)
        k=k->next;
        p->next=start;
        start->prev=p;
        k->next=p;
        start=p;
    }
}
void deletelastnode()
{
    struct node* r,*i;
    if(start==NULL)
        printf("\n List is empty \n");
    else if(start->next==start)
    {
        r=start;
        start=NULL;
        free(r);
    }
    else
    {
        r=start;
        while(r->next!=start)
        {
            i=r;
            r=r->next;
        }
        i->next=start;
        start->prev=i;
        r->next=NULL;
        r->prev=NULL;
        free(r);
    }
}
void insertatlast()
{
    struct node *k;
    struct node *r;
    if(start==NULL)
       {
           r=createnode();
           start=r;
           r->next=start;
           r->prev=start;
       }
    else
    {
        k=start;
        r=createnode();
        while(k->next!=start)
        k=k->next;
        start->prev=r;
        k->next=r;
        r->next=start;
        r->prev=k;
    }
}
void deletefirstnode()
{
    struct node* r,*k;
    if(start==NULL)
        printf("\n List is empty \n");
    else if(start->next==start)
    {
        r=start;
        r->next=NULL;
        r->prev=NULL;
        start=NULL;
        free(r);
    }
    else
    {
        r=start;
        k=start;
         while(k->next!=start)
        k=k->next;
        k->next=r->next;
        start=start->next;
        r->next=NULL;
        r->prev=NULL;
        start->prev=k;
        free(r);
    }
}
void display()
{
    struct node *p=start;
    if(start==NULL)
        printf("\n LIST IS EMPTY \n");
    else
    {
    while(p->next!=start)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
     printf("%d\t",p->info);
}
}
int menu()
{
    int choice;
    printf("1.TO INSERT AT STARTING \n");
    printf("2.TO INSERT AT LAST\n");
    printf("3.TO DELETE THE STARTING NODE \n");
    printf("4.TO DELETE THE LAST NODE \n");
    printf("5.TO DISPLAY LIST DATA \n");
    printf("6.TO EXIT \n");
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    while(1)
    {
        system("cls");
        switch(menu())
        {
            case 1: insertatfirst();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
            case 2:insertatlast();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
            case 3:deletefirstnode();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
            case 4:deletelastnode();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
            case 5:display();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
            case 6:exit(0);
            break;
            default:printf("invalid choice \n");
        }
        getch();
    }
}
