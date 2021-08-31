#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
q->arr=(int*)malloc(sizeof (int)*cap);
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
    int x;
    if(q->capacity<0)
    printf("\n INVALID CAPACITY \n");
   else if(isfull(q))
        printf("\n queue is full \n");
        else
        {
            printf("\n enter data \n");
            scanf("%d",&x);
        if(q->front==-1&&q->rear==-1)
        {
            q->front=0;
            q->rear=0;
            q->arr[q->rear]=x;
        }
        else if(q->front==0&&q->rear==0)
        {
            q->rear++;
            q->arr[q->rear]=x;
        }
        else
        {
            q->rear++;
            q->arr[q->rear]=x;
        }
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
    return(-99999);
}
  void queueDisplay(struct queue *q)
    {
        int i;
        if (isempty(q))
            printf("\nQueue is Empty\n");
        else
        {
        for (i=q->front;i<=q->rear;i++)
            printf(" %d \t", q->arr[i]);
    }
    }
int menu()
{
    int choice;
    printf("\n1.TO INSERT IN QUEUE\n");
    printf("2.TO DELETE FROM QUEUE \n");
    printf("3.TO DISPLAY QUEUE ELEMENTS \n");
    printf("4.TO EXIT\n");
    printf("\n ENTER CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    struct queue*q;
    int c,remove;
   printf("\nENTER ANY KEY TO CONTINUE\n");
   q=create();
   while(1)
   {
    system("cls");
       c=menu();
   switch(c)
   {
       case 1:
            insert(q);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 2:
            remove=dequeue(q);
            if(remove==-99999)
                printf("\n -9999999 \n");
            else
            printf("%d DELETED \n",remove);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
            queueDisplay(q);
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
