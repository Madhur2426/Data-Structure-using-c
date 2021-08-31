#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int info ;
    struct node *next;
    struct node* prev;
};
struct node *start=NULL;
void insertatfirst()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter a number");
    scanf("%d",&n->info);
    n->prev=NULL;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        start->prev=n;
        n->next=start;
        start=n;
    }
}
void deletefirstnode()
{
    struct node* r;
    if(start==NULL)
        printf("\n List is empty \n");
    else
    {
        r=start;
        start=start->next;
        start->prev=NULL;
        free(r);
    }
}
void insertatlast()
{
    struct node *n,*r;
    n=(struct node*)malloc(sizeof(struct node));
    printf("Enter a number");
    scanf("%d",&n->info);
    n->prev=NULL;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        r=start;
        while(r->next!=NULL)
          r=r->next;
        r->next=n;
        n->prev=r;
    }
}
void deletelastnode()
{
    struct node *r,*p;
    if(start==NULL)
        printf("\n LIST IS EMPTY \n");
    else
    {
        r=start;
        p=start;
        while(r->next!=NULL)
        {
            p=r;
            r=r->next;
        }
        p->next=NULL;
        free(r);
    }
}
void display()
{
    struct node *r;
    if(start==NULL)
        printf("\n LIST IS EMPTY \n");
    else
    {
        r=start;
        while(r!=NULL)
        {
            printf("%d\t",r->info);
            r=r->next;
        }
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
            break;
            case 2:insertatlast();
            break;
            case 3:deletefirstnode();
            break;
            case 4:deletelastnode();
            break;
            case 5:display();
            getch();
            break;
            case 6:exit(0);
            break;
            default:printf("invalid choice \n");
        }
    }
}
