#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node* createnode()
{
struct node*p;
p=(struct node*)malloc(sizeof(struct node));
p->next=NULL;
return(p);
}
struct node*addatbeg(struct node*last)
{
 struct node*p,*q;
 p=createnode();
 printf("\nENTER DATA\n");
scanf("%d",&p->data);
 if(last==NULL)
 {
     last=p;
     last->next=last;
 }
 else
 {
     q=last->next;
     p->next=q;
     last->next=p;
 }
 return(last);
}
struct node* addtoempty(struct node* last)
{
 struct node*p,*q;
 p=createnode();
 if(last==NULL)
 {
printf("\nENTER DATA\n");
scanf("%d",&p->data);
 last=p;
 last->next=last;
 return(last);
 }
 else
 {
     printf("\nlist is not empty\n");
     return(last);
 }
}
struct node* addatend(struct node*last,int item)
{
   struct node*p,*q;
    p=createnode();
    p->data=item;
    if(last==NULL)
    {
        last=p;
        last->next=last;
    }
    else
    {
        q=last->next;
        p->next=q;
        last->next=p;
        last=p;
    }
    return(last);
}
struct node* addafter(struct node* last,int item)
{
    int value,c=0;
    struct node *p,*q;
    p=last;
    if(last==NULL)
        {
        printf("\n EMPTY LIST \n");
        return(last);
        }
    else if(p->next==last)
    {
        printf("\n ENTER DATA TO BE INSERTED AFTER \n ");
        scanf("%d",&value);
        if(p->data==value)
        {
            last=addatend(last,item);
            printf("\n NODE INSETRED SUCCESSFULY \n");
            c=1;
        }
        if(c==0)
        printf("\n %d NOT FOUND \n",value);
        return(last);
    }
    else
    {
        printf("\n ENTER DATA TO BE INSERTED AFTER \n");
        scanf("%d",&value);
        while(p->next!=last)
        {
            if(p->data==value)
            {
                last=addatend(last,item);
                printf("\n NODE INSETRED SUCCESSFULY AFTER \n");
                c=1;
                break;
            }
            p=p->next;
        }
        if(c==0)
            printf("\n %d NOT FOUND IN THE LIST \n",value);
        return(last);
    }
}
struct node* delatbeg(struct node *last)
{
 struct node *p,*q;
 p=last;
 if(last==NULL)
 {
     printf("\n LIST IS EMPTY \n");
     return(last);
 }
 else if(p->next==last)
    {
        printf("\n NODE DELETED\n ");
        last=NULL;
        free(p);
        return(last);
    }
 else
 {
     p=p->next;
     q=p->next;
     last->next=q;
     p->next=NULL;
     free(p);
     printf("\n NODE DELETED \n");
     return(last);
 }
}

void viewlist(struct node* last)
{
    struct node *q;
    if(last==NULL)
        printf("\n LIST IS EMPTY \n");
    else
    {
    q=last->next;
    do
    {
    printf("%d\t",q->data);
    q=q->next;
    }
    while(q!=last->next);
    }
}
int menu()
{
    int choice;
    printf("\n 1.TO ADD NODE AT THE BEGINNING OF THE CLL \n");
    printf("2.TO ADD NODE TO AN EMPTY CLL\n");
    printf("3.TO ADD NODE AT THE END OF CLL\n");
    printf("4.TO ADD NODE AFTER A SPECIFIC VALUE IN THE CLL\n");
    printf("5.TO VIEW THE CLL LIST\n");
    printf("6. TO EXIT CLL\n");
    printf("7. TO DELETE NODE AT THE BEGINNING \n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    int c,item,value;
    struct node *last=NULL;
    printf("\nENTER ANY KEY TO CONTINUE\n");
        while(1)
            {
                system("cls");
                c=menu();
                switch(c)
                {
                case 1:last=addatbeg(last);
                printf("\nENTER ANY KEY TO CONTINUE\n");
                break;
                case 2:last=addtoempty(last);
                printf("\nENTER ANY KEY TO CONTINUE\n");
                break;
                case 3:
                printf("\n ENTER VALUE TO BE ADDED \n");
                scanf("%d",&item);
                last=addatend(last,item);
                printf("\nENTER ANY KEY TO CONTINUE\n");
                break;
                case 4:
                printf("\n ENTER VALUE TO BE ADDED \n");
                scanf("%d",&item);
                last=addafter(last,item);
                printf("\n ENTER ANY KEY TO CONTINUE\n");
                break;
                case 5:viewlist(last);
                printf("\nENTER ANY KEY TO CONTINUE\n");
                break;
                case 6:exit(0);
                break;
                case 7:last=delatbeg(last);
                break;
                default:
                    printf("\n INVALID CHOICE\n");
            }
             getch();
            }
    }
