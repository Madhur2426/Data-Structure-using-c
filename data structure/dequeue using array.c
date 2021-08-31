#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dequeue
{
    int front;
    int rear;
    int capacity;
    int *arr;
};
struct dequeue *create()
{
int cap;
struct dequeue *dq;
printf("\n ENTER CAPACITY \n");
scanf("%d",&cap);
dq=(struct dequeue*)malloc(sizeof(struct dequeue));
dq->capacity=cap;
dq->front=-1;
dq->rear=-1;
dq->arr=(int*)malloc(sizeof(int)*cap);
return(dq);
}
int isfull(struct dequeue *dq)
{
    if((dq->rear+1)%dq->capacity==dq->front)
        return(1);
    else
        return(0);
}
int isempty(struct dequeue* dq)
{
    if(dq->front==-1&&dq->rear==-1)
        return(1);
    else
        return(0);
}
void enqueuefront(struct dequeue *dq)
{
    int x;
    if(dq->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isfull(dq))
        printf("\n OVERFLOW \n");
    else
    {
     printf("\n ENTER DATA \n");
     scanf("%d",&x);
     if(dq->front==-1&&dq->rear==-1)
     {
         dq->rear=0;
         dq->front=0;
         dq->arr[dq->front]=x;
     }
     else if(dq->front==0)
     {
         dq->front=dq->capacity-1;
         dq->arr[dq->front]=x;
     }
     else
     {
         dq->front--;
         dq->arr[dq->front]=x;
     }
    }
}
void enqueuerear(struct dequeue* dq)
{
    int x;
    if(dq->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isfull(dq))
        printf("\n OVERFLOW \n");
    else
    {
        printf("\n ENTER DATA \n");
        scanf("%d",&x);
        if(dq->rear==-1)
        {
           dq->front=0;
           dq->rear=0;
           dq->arr[dq->rear]=x;
        }
        else
        {
            dq->rear++;
            dq->arr[dq->rear]=x;
        }
    }
}
int dequeuefront(struct dequeue *dq)
{
    int del;
    if(dq->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isempty(dq))
        printf("\n UNDERFLOW \n");
    else
    {
        if(dq->front==0&&dq->rear==0)
        {
            del=dq->arr[dq->front];
            dq->front=-1;
            dq->rear=-1;
            return(del);
        }
        else if(dq->front==dq->rear)
        {
            del=dq->arr[dq->front];
            dq->rear=-1;
            dq->front=-1;
            return(del);
        }
        else if(dq->front==dq->capacity-1)
        {
            del=dq->arr[dq->front];
            dq->front=0;
            return(del);
        }
        else
        {
            del=dq->arr[dq->front];
            dq->front++;
            return(del);
        }
    }
    return(-99999);
}
int dequeuerear(struct dequeue *dq)
{
    int del;
    if(dq->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isempty(dq))
        printf("\n UNDERFLOW \n");
    else
    {
        if(dq->front==0&&dq->rear==0)
        {
            del=dq->arr[dq->rear];
            dq->front=-1;
            dq->rear=-1;
            return(del);
        }
        else if(dq->front==dq->rear)
        {
            del=dq->arr[dq->rear];
            dq->rear=-1;
            dq->front=-1;
            return(del);
        }
        else if(dq->rear==dq->capacity-1)
        {
            del=dq->arr[dq->rear];
            dq->rear--;
            return(del);
        }
       else if(dq->rear==0)
        {
        del=dq->arr[dq->rear];
        dq->rear=dq->capacity-1;
        return(del);
        }
        else
        {
            del=dq->arr[dq->rear];
            dq->rear--;
            return(del);
        }
    }
    return(-99999);
}
void display(struct dequeue* dq)
{
    int i;
    if(dq->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isempty(dq))
        printf("\n UNDERFLOW \n");
    else
    {
       i=dq->front;
       while(i!=dq->rear)
       {
           printf("%d \t",dq->arr[i]);
           i=(i+1)%dq->capacity;
       }
       printf("%d",dq->arr[dq->rear]);
    }
}
void getfront(struct dequeue *dq)
{
    if(dq->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isempty(dq))
    printf("\n UNDERFLOW \n");
    else
   {
    printf("VALUE IS-----%d \n",dq->arr[dq->front]);
    printf("INDEX IS-----%d \n",dq->front);
}
}
void getrear(struct dequeue *dq)
{
     if(dq->capacity<0)
        printf("\n INVALID CAPACITY \n");
    else if(isempty(dq))
    printf("\n UNDERFLOW \n");
    else
    {
    printf("VALUE IS-----%d \n",dq->arr[dq->rear]);
    printf("INDEX IS-----%d \n",dq->rear);
}
}
int menu()
{
    int choice;
    printf("1.TO INSERT FROM FRONT \n");
    printf("2.TO INSERT FROM REAR \n");
    printf("3.TO SEE VALUE AT FRONT \n");
    printf("4.TO SEE VALUE AT REAR \n");
    printf("5.TO DELETE FROM FRONT \n");
    printf("6.TO DELETE FROM REAR \n");
    printf("7.TO DISPLAY DEQUEUE ELEMENTS \n");
    printf("8.TO EXIT \n");
    printf("\n ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    return(choice);
}
void main()
{
    int c,delfront,delrear;
    struct dequeue *dq;
    dq=create();
    while(1)
   {
    system("cls");
       c=menu();
   switch(c)
   {
       case 1: enqueuefront(dq);
              printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 2:enqueuerear(dq);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 3:getfront(dq);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 4:getrear(dq);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
        case 5:delfront=dequeuefront(dq);
            if(delfront==-99999)
                printf("\n -9999999 \n");
            else
             printf("%d DELETED \n",delfront);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
        case 6:delrear=dequeuerear(dq);
             if(delrear==-99999)
                printf("\n -99999 \n");
             else
                printf("%d DELETED \n",delrear);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 7:display(dq);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
       case 8:exit(0);
             printf("\nENTER ANY KEY TO CONTINUE\n");
             break;
        default:
             printf("\n invalid choice\n");
   }
   getch();
}
}
