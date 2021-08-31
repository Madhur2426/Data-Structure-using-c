#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
 int info;
 struct node* next;
};
struct node *createnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return(p);
}
struct node* start=NULL;
void insertnode()
{
    struct node *p;
    p=createnode();
    printf("enter a number\n");
    scanf("%d",&p->info);
    p->next=NULL;
    if(start==NULL)
        start=p;
    else
    {
        p->next=start;
        start=p;
    }
}
void insertlastnode()
{
    struct node *p,*t;
    p=createnode();
    printf("enter a number\n");
    scanf("%d",&p->info);
    p->next=NULL;
    if(start==NULL)
        start=p;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=p;
    }
}
void deletelastnode()
{
    struct node* todelete,*secondlastnode;
    if(start==NULL)
        printf("LIST IS EMPTY\n");
    else
    {
        todelete=start;
        secondlastnode=start;
        while(todelete->next!=NULL)
        {
            secondlastnode=todelete;
            todelete=todelete->next;
        }
      if(todelete==start)
        start=NULL;
      else
        secondlastnode->next=NULL;
      free(todelete);
      printf("\n LAST NODE DELETED \n");
}
}
void viewlist()
{
    struct node *p;
    p=start;
    if(start==NULL)
        printf("LIST IS EMPTY\n");
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
}
void deletefirst()
{
    struct node *p;
    if(start==NULL)
        printf("list is empty\n");
    else
    {
        p=start;
        start=start->next;
    free(p);
    }
}
void printmiddle()
{
    struct node* t,*q;
    int c=0,p,s=1;
    t=start;
    if(start==NULL)
        printf("\nEMPTY LIST\n");
    else
    {
        q=start;
    while(t->next!=NULL)
    {
        c++;
        t=t->next;
    }
    c++;
    if(c%2==0)
    {
        p=c/2;
        p=p+1;
        while(s!=p)
        {
        q=q->next;
        s++;
        }
        printf("%d",q->info);
    }
    else
    {
        p=c/2;
        p=p+1;
        while(s!=p)
         {
        q=q->next;
        s++;
         }
        printf("%d",q->info);
    }
    }
}
int count()
{
    int c=0;
    struct node *t=start;
    while(t->next!=NULL)
        {
            c++;
            t=t->next;
        }
        c++;
        return(c);
}
void printmidd()
{
    struct node *t,*q;
    static int i,p;
    int c=count();
    int arr[c];
    t=start;
    if(start==NULL)
        printf("\n EMPTY LIST \n");
    else
    {
        q=start;
            for(i=0;i<c;i++)
            {
                arr[i]=q->info;
                q=q->next;
            }
         if(c%2==0)
        {
            p=c/2;
            printf("%d",arr[p]);
        }
        else
        {
        p=c/2;
        printf("%d",arr[p]);
        }
        }
    }
    void reverse()
    {
        struct node *prevnode,*currentnode,*nextnode;
        prevnode=NULL;
        currentnode=nextnode=start;
        if(start==NULL)
            printf("\n LIST IS EMPTY \n");
        while(nextnode!=NULL)
        {
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
        start=prevnode;
        viewlist();
    }
void sortlist()
{
    struct node *t,*q,*s,*p;
    if(start==NULL)
        printf("\n EMPTY LIST \n");
    else
    {
    t=start;
    q=t->next;
    p=createnode();
    p->next=NULL;
    s=createnode();
    s->next=NULL;
        while(t->next!=NULL)
        {
            while(q)
            {
                if((t->info)>(q->info))
                {
                    p->info=t->info;
                    s->info=q->info;
                    t->info=s->info;
                    q->info=p->info;
                }
                q=q->next;
            }
            t=t->next;
            q=t->next;
        }
        viewlist();
    }
}
int checksort()
{
    struct node *p,*q;
    if(start==NULL)
        printf("\n LIST IS EMPTY \n");
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            q=p->next;
            while(q!=NULL)
            {
                if((p->info)>(q->info))
                 return(1);
                 q=q->next;
            }
        p=p->next;
    }
    }
    return(0);
}
void removeduplicate()
{
 struct node *p,*q,*r;
 if(start==NULL)
 printf("\n LIST IS EMPTY \n");
 else if(checksort())
 {
     printf("\n LIST IS NOT SORTED \n");
 }
 else
 {
     p=start;
    while(p->next!=NULL)
     {
         q=p->next;
         while(q!=NULL)
         {
             if(p->info==q->info)
             {
                 r=q;
                 q=q->next;
                 if(r->next!=NULL)
                 r->next=NULL;
                 if(q!=NULL)
                 p->next=q;
                 if(q==NULL)
                 p->next=NULL;
                 free(r);
                 continue;
             }
             q=q->next;
         }
         p=p->next;
     }
}
}
int menu()
{
    int menu;
    printf("1.INSERT NODE\n");
    printf("2. INSERT LAST NODE\n");
    printf("3. DELETE FIRST NODE\n");
    printf("4. DELETE LAST NODE\n");
    printf("5. VIEW LIST\n");
    printf("6. EXIT\n");
    printf("7. TO PRINT MIDDLE ELEMENT\n");
    printf("8. TO PRINT MID ELEMENT BY ARRAY LOGIC\n");
    printf("9. TO REVERSE THE LINKED LIST\n");
    printf("10. TO SORT THE LIST\n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&menu);
    return(menu);
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
       insertnode();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 2:
        insertlastnode();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
           deletefirst();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 4:
           deletelastnode();
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 5:
            viewlist();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
        case 6:
            exit(0);
            break;
        case 7:
            printmiddle();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
        case 8:
            printmidd();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
        case 9:
            reverse();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
        case 10:
            sortlist();
             printf("\nENTER ANY KEY TO CONTINUE\n");
            break;
        default:
            printf("\n invalid choice\n");
   }
   getch();
}
}
