#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
struct queue
{
    int front;
    int rear;
    int capacity;
    int *arr;
};
struct queue *create()
{
 struct queue*q;
 int cap;
 printf("\n ENTER CAPACITY \n");
 scanf("%d",&cap);
 q=(struct queue*)malloc(sizeof(struct queue));
 q->front=-1;
 q->rear=-1;
 q->capacity=cap;
 q->arr=(int*)malloc(sizeof(int)*cap);
 return(q);
}
int isempty(struct queue*q)
{
    if(q->rear==-1&&q->front==-1)
        return(1);
    else
        return(0);
}
int isfull(struct queue*q)
{
    if(q->front==0&q->rear==q->capacity-1)
        return(1);
    else if((q->rear+1)%q->capacity==q->front)
        return(1);
    else
        return(0);
}
void insert(struct queue*q)
{
    int x;
    if(q->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isfull(q))
        printf("\n OVERFLOW \n");
    else
    {
        printf("\n ENTER VALUE \n");
        scanf("%d",&x);
        if(q->front==-1&&q->rear==-1)
        {
            q->front=0;
            q->rear=0;
            q->arr[q->rear]=x;
        }
        else if(q->rear==q->capacity-1&&q->front!=0)
        {
            q->rear=0;
            q->arr[q->rear]=x;
        }
        else
        {
            q->rear=(q->rear+1)%q->capacity;
            q->arr[q->rear]=x;
        }
    }
}
int delqueue(struct queue*q)
{
    int x;
    if(q->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isempty(q))
        printf("\n UNDERFLOW \n");
    else
    {
        if(q->front==0&&q->rear==0)
        {
          x=q->arr[q->front];
          q->front=-1;
          q->rear=-1;
          return(x);
        }
        else if(q->front==q->rear)
        {
            x=q->arr[q->front];
            q->front=-1;
            q->rear=-1;
            return(x);
        }
        else if(q->front==q->capacity-1)
        {
            x=q->arr[q->front];
            q->front=0;
            return(x);
        }
        else
        {
            x=q->arr[q->front];
            q->front++;
            return(x);
        }
    }
    return(-99999);
}
int getrear(struct queue *q)
{
    if(q->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isempty(q))
        printf("\n UNDERFLOW \n");
    else
    {
        printf("%d",q->arr[q->rear]);
    }
}
void display(struct queue *q)
{
    int i;
    if(isempty(q))
        printf("\n QUEUE IS EMPTY \n");
    else
    {
        for(i=q->front;i!=q->rear;)
        {
            printf("%d \t",q->arr[i]);
            if(i==q->capacity-1)
                i=0;
            else
                i++;
        }
        printf("%d",q->arr[i]);
    }
}
int menu()
{
    int choice;
    printf("1.TO INSERT IN CIRCULAR QUEUE \n");
    printf("2.TO DELETE IN CIRCULAR QUEUE \n");
    printf("3.TO VIEW CIRCULAR QUEUE ELEMENTS \n");
    printf("4.TO PRINT VALUE ON REAR \n");
    printf("5.TO EXIT \n");
    printf("\n ENTER YOUR CHOICE ");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    int c,remove;
    struct queue *q;
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
            remove=delqueue(q);
            if(remove==-99999)
                printf("\n -9999999 \n");
            else
            printf("%d DELETED \n",remove);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
       case 3:
            display(q);
            printf("\nENTER ANY KEY TO CONTINUE\n");
           break;
        case 4:getrear(q);
           break;
        case 5:exit(0);
           break;
        default:
            printf("\n invalid choice\n");
   }
   getch();
}
}
