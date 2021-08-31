#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct queue
{
    int front;
    int rear;
    int capacity;
    int *arr;
};
struct queue *create()
{
struct queue *q;
 int cap;
 printf("\n enter capacity\n ");
 scanf("%d",&cap);
q=(struct queue*)malloc(sizeof(struct queue));
q->front=-1;
q->rear=-1;
q->capacity=cap;
q->arr=(int*)malloc(sizeof(int)*cap);
return(q);
}
int isfull(struct queue *q)
{
    if(q->front==0&&q->rear==q->capacity-1)
        return(1);
    else
        return(0);
}
int isempty(struct queue *q)
{
    if(q->front==-1&&q->rear==-1)
        return(1);
    else
        return(0);
}
void insert(struct queue *q)
{
    int x,c=0;
    if(q->capacity<0)
    printf("\n INVALID CAPACITY \n");
   else if(isfull(q))
        printf("\n queue is full \n");
   else if(isempty(q))
   {
       printf("\n ENTER DATA \n");
       scanf("%d",&x);
       q->rear=0;
       q->front=0;
       q->arr[q->rear]=x;
   }
   else
        {
            printf("\n ENTER DATA \n");
            scanf("%d",&x);
            if(x>q->arr[q->rear])
            {
                c=1;
                q->rear++;
                q->arr[q->rear]=x;
            }
            if(c==1)
                printf("\n ELEMENT INSERTED \n");
            else
                printf("\n ELEMENT HAS A LOWER PRIORITY \n");
        }
}
int dequeue(struct queue *q)
{
    int del;
    if(isempty(q))
        printf("\n QUEUE IS EMPTY \n");
        else
        {
    if(q->front==0&&q->rear==0)
        {
            del=q->arr[q->front];
            q->front--;
            q->rear--;
            return(del);
        }
    else if(q->front==q->rear)
        {
            del=q->arr[q->front];
            q->front=-1;
            q->rear=-1;
            return(del);
        }
    else
        {
            del=q->arr[q->front];
            q->front++;
            return(del);
        }
        }
        return(-9999);
}
void viewqueue(struct queue *q)
{
    int i;
    if(isempty(q))
        printf("\n UNDERFLOW \n");
    else
    {
    for(i=q->front;i!=q->rear;i++)
        printf("%d\t",q->arr[i]);
        printf("%d",q->arr[i]);
}
}
int menu()
{
    int choice;
    printf("1.TO INSERT IN PRIORITY QUEUE \n");
    printf("2.TO DELETE ELEMNTS IN PRIORITY QUEUE \n");
    printf("3.TO VIEW LIST \n");
    printf("4.TO EXIT \n");
    printf("\n ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    int c,dq;
    struct queue *q;
    q=create();
    while(1)
   {
    system("cls");
     COORD d;
    d.X=20;
    d.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),d);
    printf("----------ELEMEMTS ARE ARRANGED IN ASCENDING ORDER--------------\n");
       c=menu();
   switch(c)
   {
       case 1:insert(q);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
        case 2:dq=dequeue(q);
        if(dq==-9999)
            printf("\n-9999\n");
            else
             printf("\n%d DELETED \n",dq);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
        case 3:viewqueue(q);
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
